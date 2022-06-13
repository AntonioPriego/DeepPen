/* =================== deep_pen.ino =====================
    Sketch for DeepPen
    By Antonio Priego Raya
    Code created for the DeepPen project:
    https://github.com/AntonioPriego/DeepPen

    Code supported on the magic_wand of Pete Warden
    (https://github.com/petewarden/magic_wand)
========================================================= */

#include <PDM.h>
#include "deep_pen_model_data.h"
#include "rasterize_stroke.h"
#include "stroke_collector.cpp"
#include "labels.cpp"

// #define DEBUG_MODE //(stroke_collector.cpp [line 24])

/************************************* BLE SETUP *************************************/
// Device properties
const char* nameOfPeripheral     = "DeepPen";
const char* serviceUuid          = "00001101-0000-1000-8000-00805f9b34fb";
const char* rxCharacteristicUuid = "00001142-0000-1000-8000-00805f9b34fb";
const char* txCharacteristicUuid = "00001143-0000-1000-8000-00805f9b34fb";

// BLE service 
BLEService letterSenderService(serviceUuid);

// Setup rx data format & active signal boolean
const int WRITE_BUFFER_SIZE         = 16;
bool      WRITE_BUFFER_FIZED_LENGTH = false;
bool      rxSignal                  = false;

// Creating rx & tx characteristics
BLECharacteristic     rxChar(rxCharacteristicUuid, BLEWriteWithoutResponse | BLEWrite, WRITE_BUFFER_SIZE, WRITE_BUFFER_FIZED_LENGTH);
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
void setup()
{
  Serial.begin(9600);

  Serial.println("Started");

  if (!IMU.begin()) {
    if (DEBUG_MODE)
      Serial.println("Error: Could not start IMU");
    while (1);
  }
  
  SetupIMU();

  if (!BLE.begin()) {
    if (DEBUG_MODE)
      Serial.println("Error: Could not start BLE");
    while (1);
  }

  String address = BLE.address();

  if (DEBUG_MODE) {
    Serial.print("address = ");
    Serial.println(address);
  }
  address.toUpperCase();

  name = "BLESense-";
  name += address[address.length() - 5];
  name += address[address.length() - 4];
  name += address[address.length() - 2];
  name += address[address.length() - 1];

  if (DEBUG_MODE) {
    Serial.print("name = ");
    Serial.println(name);
  }
  // Create BLE service and characteristics.
  BLE.setLocalName(nameOfPeripheral);
  BLE.setAdvertisedService(letterSenderService);
  letterSenderService.addCharacteristic(rxChar);
  letterSenderService.addCharacteristic(txChar);
  BLE.addService(letterSenderService);

  // Bluetooth LE connection handlers.
  BLE.setEventHandler(BLEConnected, onBLEConnected);
  BLE.setEventHandler(BLEDisconnected, onBLEDisconnected);
  
  // Event driven reads.
  rxChar.setEventHandler(BLEWritten, onRxCharValueUpdate);
  
  // Let's tell devices about us.
  BLE.advertise();


  service.addCharacteristic(strokeCharacteristic);

  BLE.addService(service);

  BLE.advertise();


  // Set up logging. Google style is to avoid globals or statics because of
  // lifetime uncertainty, but since this has a trivial destructor it's okay.
  static tflite::MicroErrorReporter micro_error_reporter;  // NOLINT
  error_reporter = &micro_error_reporter;

  // Map the model into a usable data structure. This doesn't involve any
  // copying or parsing, it's a very lightweight operation.
  model = tflite::GetModel(deep_pen_model_data);

  if (model->version() != TFLITE_SCHEMA_VERSION) {
    if (DEBUG_MODE) 
      TF_LITE_REPORT_ERROR(error_reporter,
                           "Model provided is schema version %d not equal "
                           "to supported version %d.",
                           model->version(), TFLITE_SCHEMA_VERSION);

    return;
  }
  
  // Pull in only the operation implementations we need.
  // This relies on a complete list of all the ops needed by this graph.
  // An easier approach is to just use the AllOpsResolver, but this will
  // incur some penalty in code space for op implementations that are not
  // needed by this graph.
  static tflite::MicroMutableOpResolver<4> micro_op_resolver;  // NOLINT
  micro_op_resolver.AddConv2D();
  micro_op_resolver.AddMean();
  micro_op_resolver.AddFullyConnected();
  micro_op_resolver.AddSoftmax();

  // Build an interpreter to run the model with.
  static tflite::MicroInterpreter static_interpreter(
      model, micro_op_resolver, tensor_arena, kTensorArenaSize, error_reporter);
  interpreter = &static_interpreter;

  // Allocate memory from the tensor_arena for the model's tensors.
  interpreter->AllocateTensors();

  TfLiteTensor* model_input = interpreter->input(0);
  if ((model_input->dims->size != 4) || (model_input->dims->data[0] != 1) ||
      (model_input->dims->data[1] != raster_height) ||
      (model_input->dims->data[2] != raster_width) ||
      (model_input->dims->data[3] != raster_channels) ||
      (model_input->type != kTfLiteInt8)) {
    if (DEBUG_MODE)
      TF_LITE_REPORT_ERROR(error_reporter,
                         "Bad input tensor parameters in model");

    return;
  }

  TfLiteTensor* model_output = interpreter->output(0);
  if ((model_output->dims->size != 2) || (model_output->dims->data[0] != 1) ||
      (model_output->dims->data[1] != num_labels) ||
      (model_output->type != kTfLiteInt8)) {
  if (DEBUG_MODE)
      TF_LITE_REPORT_ERROR(error_reporter,
                         "Bad output tensor parameters in model");

    return;
  }
}



/********************************* LOOP FUNCTION *********************************/
void loop()
{
  BLEDevice central = BLE.central();
  
  // if a central is connected to the peripheral:
  static bool was_connected_last = false;  
  if (central && !was_connected_last) {
    if (DEBUG_MODE) {
      Serial.print("Connected to central: ");
      // print the central's BT address:
      Serial.println(central.address());
    }
  }
  was_connected_last = central;
  
  const bool data_available = IMU.accelerationAvailable() || IMU.gyroscopeAvailable();
  if (!data_available) {
    return;
  }

  int accelerometer_samples_read;
  int gyroscope_samples_read;
  ReadAccelerometerAndGyroscope(&accelerometer_samples_read, &gyroscope_samples_read);

  bool done_just_triggered = false;
  if (gyroscope_samples_read > 0) {
    EstimateGyroscopeDrift(current_gyroscope_drift);
    UpdateOrientation(gyroscope_samples_read, current_gravity, current_gyroscope_drift);
    UpdateStroke(gyroscope_samples_read, &done_just_triggered);
    if (central && central.connected()) {
      strokeCharacteristic.writeValue(stroke_struct_buffer, stroke_struct_byte_count);
    }
  }

  if (accelerometer_samples_read > 0) {
    EstimateGravityDirection(current_gravity);
    UpdateVelocity(accelerometer_samples_read, current_gravity);
  }

  if (done_just_triggered) {
    
    RasterizeStroke(stroke_points, *stroke_transmit_length, 0.6f, 0.6f, raster_width, raster_height, raster_buffer);
    if (DEBUG_MODE)
      for (int y = 0; y < raster_height; ++y) {
        char line[raster_width + 1];
        for (int x = 0; x < raster_width; ++x) {
          const int8_t* pixel = &raster_buffer[(y * raster_width * raster_channels) + (x * raster_channels)];
          const int8_t red = pixel[0];
          const int8_t green = pixel[1];
          const int8_t blue = pixel[2];
          
          if ((red > -128) || (green > -128) || (blue > -128))
            line[x] = '*';
          else
            line[x] = ' ';
        }
        line[raster_width] = 0;
        Serial.println(line);
      }
    
    TfLiteTensor* model_input = interpreter->input(0);
    for (int i = 0; i < raster_byte_count; ++i) {
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
    for (int i = 0; i < num_labels; ++i) {
      const int8_t score = output->data.int8[i];
      if ((i == 0) || (score > max_score)) {
        max_score = score;
        max_index = i;
      }
    }

    const char *recognized = foundLabel(max_index);
    char letra;
    if      (labels[max_index] == "0")
      letra='a';
    else if (labels[max_index] == "1")
      letra='b';
    else if (labels[max_index] == "2")
      letra='c';
    else if (labels[max_index] == "3")
      letra='d';
    else if (labels[max_index] == "4")
      letra='e';
    else if (labels[max_index] == "5")
      letra='f';
    else if (labels[max_index] == "6")
       letra='g';
    else if (labels[max_index] == "7")
      letra='h';
    else if (labels[max_index] == "8")
      letra='i';
    else if (labels[max_index] == "9")
      letra='j';
    else if (labels[max_index] == "10")
      letra='k';
    else if (labels[max_index] == "11")
      letra='l';
    else if (labels[max_index] == "12")
      letra='m';
    else if (labels[max_index] == "13")
      letra='n';
    else if (labels[max_index] == "14")
      letra='o';
    else if (labels[max_index] == "15")
      letra='p';
    else if (labels[max_index] == "16")
      letra='1';
    else if (labels[max_index] == "17")
      letra='r';
    else if (labels[max_index] == "18")
      letra='s';
    else if (labels[max_index] == "19")
      letra='t';
    else if (labels[max_index] == "20")
      letra='u';
    else if (labels[max_index] == "21")
      letra='v';
    else if (labels[max_index] == "22")
      letra='w';
    else if (labels[max_index] == "23")
      letra='x';
    else if (labels[max_index] == "24")
      letra='y';
    else if (labels[max_index] == "25")
      letra='z';
    else
      letra='0';

    txChar.writeValue(letra);
    
    //TF_LITE_REPORT_ERROR(error_reporter, "Caracter detectado: %s (%d)", recognized, max_score);
    TF_LITE_REPORT_ERROR(error_reporter, "%s", recognized);
  }
  else if (rxSignal) { // Not just triggered and rxSignal received
    txChar.writeValue('.');
    rxSignal = false;
  }
}
