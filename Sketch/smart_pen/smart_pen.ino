/* =================== deep_pen.ino =====================
    Sketch for SmartPen
    By Antonio Priego Raya
    Code created for the SmartPen project:
    https://github.com/AntonioPriego/SmartPen

========================================================= */

#include <PDM.h>
#include "smart_pen_model_data.h"
#include "rasterize_stroke.h"
#include "stroke_collector.cpp"
#include "labels.cpp"

// #define DEBUG_MODE //(stroke_collector.cpp [line 24])
#define LED_RED   22     
#define LED_BLUE  23     
#define LED_GREEN 24
#define LED_PWR   25

/************************************* BLE SETUP *************************************/
// Device properties
const char* deviceName           = "SmartPen";
const char* serviceUuid          = "00001101-0000-1000-8000-0080smartpen";
const char* rxCharacteristicUuid = "00001142-0000-1000-8000-0080smartpen";
const char* txCharacteristicUuid = "00001143-0000-1000-8000-0080smartpen";

// BLE service 
BLEService letterSenderService(serviceUuid);

// Setup rx data format & active signal boolean
const int WRITE_BUFFER_SIZE         = 16;
bool      rxSignal                  = false;

// Creating rx & tx characteristics
BLECharacteristic     rxChar(rxCharacteristicUuid, BLEWriteWithoutResponse | BLEWrite, WRITE_BUFFER_SIZE, false);
BLEByteCharacteristic txChar(txCharacteristicUuid, BLERead | BLENotify | BLEBroadcast);



/********************************* EVENT MANAGEMENT *********************************/
void onBLEConnected(BLEDevice central) {
  if (DEBUG_MODE) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());
  }
}

void onBLEDisconnected(BLEDevice central) {
  if (DEBUG_MODE){
    Serial.print("Disconnected event from central: ");
    Serial.println(central.address());
  }
}

void onRxCharValueUpdate(BLEDevice central, BLECharacteristic characteristic) {
  if (DEBUG_MODE)
    Serial.println("RX Updated");
  rxSignal = true;
  rxChar.writeValue(int32_t(','),true);
}


/********************************* SETUP FUNCTION *********************************/
// Setting the area of memory reserved to tensor input-output actions
constexpr int TensorAreaSize = 30 * 1024;
uint8_t tensor_area[TensorAreaSize];


// TFLite tool for logging
tflite::ErrorReporter* error_reporter = nullptr;
const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;


void SetupIMU()
{
  // ContinouosMode -> setting continuous filling FIFO for the IMU readings
  IMU.setContinuousMode();

  acceleration_sample_rate = IMU.accelerationSampleRate(); //From stroke_collector
  gyroscope_sample_rate = IMU.gyroscopeSampleRate();       //From stroke_collector
}

void setup()
{
  Serial.begin(9600);

  if (!IMU.begin()) {
    if (DEBUG_MODE)
      Serial.println("Error: Could not start IMU");
    while (true);
  }
  
  SetupIMU();

  if (!BLE.begin()) {
    if (DEBUG_MODE)
      Serial.println("Error: Could not start BLE");
    while (true);
  }

  // Create BLE settings, service and characteristics
  BLE.setLocalName(deviceName);
  BLE.setAdvertisedService(letterSenderService);
  letterSenderService.addCharacteristic(rxChar);
  letterSenderService.addCharacteristic(txChar);
  BLE.addService(letterSenderService);

  // BLE connection handlers.
  BLE.setEventHandler(BLEConnected, onBLEConnected);
  BLE.setEventHandler(BLEDisconnected, onBLEDisconnected);
  rxChar.setEventHandler(BLEWritten, onRxCharValueUpdate);
  
  // Report the bluetooth presence of the board to others
  BLE.advertise();


  
  // Same for stroke collector characteristic
  BLE.setLocalName(deviceName);
  BLE.setDeviceName(deviceName);
  BLE.setAdvertisedService(service);
  service.addCharacteristic(strokeCharacteristic);
  BLE.addService(service);
  BLE.advertise();
  
  // TFLite tool for logging (micro)
  static tflite::MicroErrorReporter micro_error_reporter;
  error_reporter = &micro_error_reporter;

  // Set the model defined in smart_pen_model_data.cpp
  model = tflite::GetModel(smart_pen_model_data);

  if (model->version() != TFLITE_SCHEMA_VERSION) {
    if (DEBUG_MODE) 
      TF_LITE_REPORT_ERROR(error_reporter, "Model provided schema version not as expected(Incompatible)");

    return;
  }
  
  // Add to the repertory the micro operations to be performed by the model
  static tflite::MicroMutableOpResolver<4> micro_op_resolver;
  micro_op_resolver.AddConv2D();
  micro_op_resolver.AddMean();
  micro_op_resolver.AddFullyConnected();
  micro_op_resolver.AddSoftmax();

  // Create the interpreter to run the model and memory reserve
  static tflite::MicroInterpreter static_interpreter(
      model, micro_op_resolver, tensor_area, TensorAreaSize, error_reporter);
  interpreter = &static_interpreter;
  interpreter->AllocateTensors();

  // Initialize led pins as an output
  pinMode(LED_RED  , OUTPUT);
  pinMode(LED_BLUE , OUTPUT);
  pinMode(LED_GREEN, OUTPUT);  
  pinMode(LED_PWR  , OUTPUT);
}



/********************************* LOOP FUNCTION *********************************/
void loop()
{
  // Led green during run
  digitalWrite(LED_PWR, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  
  // Listen for BLE peripherals to connect
  BLEDevice central = BLE.central();
  
  // Register of connection to central
  static bool last_connection = false;  
  if (central && !last_connection) {
    if (DEBUG_MODE) {
      Serial.print("Connected to central: ");
      Serial.println(central.address());
    }
  }
  last_connection = central;

  
  if (!IMU.accelerationAvailable() && !IMU.gyroscopeAvailable()) {
    // Led red when something is wrong
    digitalWrite(LED_RED, HIGH);
    return;
  }

  // Movement sensors read
  int accelerometer_samples_read, gyroscope_samples_read;
  ReadAccelerometerAndGyroscope(&accelerometer_samples_read, &gyroscope_samples_read);

  // Send part of the stroke to data collector if connected
  bool just_letter_detected = false;
  if (gyroscope_samples_read > 0) {
    EstimateGyroscopeDrift(current_gyroscope_drift);
    UpdateOrientation(gyroscope_samples_read, current_gravity, current_gyroscope_drift);
    UpdateStroke(gyroscope_samples_read, &just_letter_detected);
    if (central && central.connected())
      strokeCharacteristic.writeValue(stroke_struct_buffer, stroke_struct_byte_count);
  }

  if (accelerometer_samples_read > 0) {
    EstimateGravityDirection(current_gravity);
    UpdateVelocity(accelerometer_samples_read, current_gravity);
  }

  if (just_letter_detected) {
    RasterizeStroke(stroke_points, *stroke_transmit_length, 0.6f, 0.6f, raster_width, raster_height, raster_buffer);
    
    
    TfLiteTensor* model_input = interpreter->input(0);
    for (int i=0; i<raster_byte_count; ++i) {
      model_input->data.int8[i] = raster_buffer[i];
    }

    TfLiteStatus invoke_status = interpreter->Invoke();
    if (invoke_status != kTfLiteOk) {
      if (DEBUG_MODE)
        TF_LITE_REPORT_ERROR(error_reporter, "Invoke failed");
      return;
    }
   
    TfLiteTensor* output = interpreter->output(0);

    int8_t max_score;
    int max_index;
    for (int i=0; i<num_labels; ++i) {
      const int8_t score = output->data.int8[i];
      if ((i == 0) || (score > max_score)) {
        max_score = score;
        max_index = i;
      }
    }

    const char *recognized = foundLabel  (max_index);
    char letter            = foundLabelBT(max_index);


    // Send letter via BLE characteristic
    txChar.writeValue(letter);
    
    //Send letter via serial port
    TF_LITE_REPORT_ERROR(error_reporter, "%s", recognized);
    

    // Led blue during 800ms after letter recognition
    digitalWrite(LED_BLUE , HIGH);
    digitalWrite(LED_GREEN, LOW);
    delay(800);
    digitalWrite(LED_BLUE , LOW);
  }
  else if (rxSignal) { // Not just triggered and rxSignal received
    txChar.writeValue('.');
    rxSignal = false;
  }
}
