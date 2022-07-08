#include "device.h"

// Constructor
Device::Device(QObject *parent)
    : QObject{parent}
{
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    discoveryAgent->setLowEnergyDiscoveryTimeout(5000);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &Device::setDevice);
}

// Destructor
Device::~Device()
{
    delete discoveryAgent;
    delete controller;
    delete device;
    delete service;
}

// To start bluetooth devices discovery
void Device::startDeviceDiscovery()
{
    localDevice.powerOn();
    discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);

    if (!discoveryAgent->isActive()) {
        qDebug("ERROR: DISCOVERY AGENT INACTIVE\n");
        return;
    }
}

// To define the device to work with (SmartPen)
void Device::setDevice(const QBluetoothDeviceInfo &info)
{
    if (info.name() == "Arduino"  ||  info.name() == "SmartPen"  ||  info.name() == "DeepPen") {
        if (info.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration) {
            qDebug() << "\tBOARD DETECTED: " << info.name() << "(" << info.address() << ")";
            device = new QBluetoothDeviceInfo(info);
        }
    }
    else
        qDebug() << "\tBOARD DETECTED: other boards" << "(" << info.name() << ")";
}

// To connect to SmartPen and connect signals
void Device::connectToDevice()
{
    if (!device->isValid()) {
        qDebug() << "SCAN NOT WORKING: Device not valid";
        return;
    }

    if (controller) {
        delete controller;
    }
    // Connecting signals and slots for connecting to LE services.
    controller = QLowEnergyController::createCentral(*device);
    connect(controller, &QLowEnergyController::connected,
            this, &Device::onDeviceConnected);
    connect(controller, &QLowEnergyController::errorOccurred,
            this, &Device::onErrorReceived);
    connect(controller, &QLowEnergyController::disconnected,
            this, &Device::onDeviceDisconnected);
    connect(controller, &QLowEnergyController::serviceDiscovered,
            this, &Device::addLowEnergyService);
    connect(controller, &QLowEnergyController::discoveryFinished,
            this, &Device::onServiceScanDone);
    connect(controller, &QLowEnergyController::stateChanged,
            this, &Device::onStateChanged);

    controller->setRemoteAddressType(QLowEnergyController::PublicAddress);
    controller->connectToDevice();
}

// To add the LE service
void Device::addLowEnergyService(const QBluetoothUuid &serviceUuid)
{    if (serviceUuid.toString() == SERIALPORT_SERVICE_UUID) {
        service = controller->createServiceObject( serviceUuid );

        if (!service) {
            qDebug() << "ERROR: CANNOT CREATE SERVICE FOR UUID\n";
            return;
        }
    }
}

// To connect a service from the SmartPen connected
void Device::connectToService()
{
    if (service->state() == QLowEnergyService::RemoteService) {
        connect(service, &QLowEnergyService::stateChanged,
                this, &Device::onServiceDetailsDiscovered);

        service->discoverDetails();
    }
}

// Function when SmartPen connect
void Device::onDeviceConnected()
{
    controller->discoverServices();
}

// Function when all the services are scanned
void Device::onServiceScanDone()
{
    if (service->state() == QLowEnergyService::RemoteService)
        connectToService();
}

// Function when a new service is discovered
void Device::onServiceDetailsDiscovered(QLowEnergyService::ServiceState newState)
{
    if (newState != QLowEnergyService::RemoteServiceDiscovered) {
        if (newState != QLowEnergyService::RemoteServiceDiscovering) {
            QMetaObject::invokeMethod(this, "characteristicsUpdated",
                                      Qt::QueuedConnection);
        }
        return;
    }
    service = qobject_cast<QLowEnergyService *>(sender());
    if (!service)
        return;


    const QList<QLowEnergyCharacteristic> chars = service->characteristics();
    for (const QLowEnergyCharacteristic &ch : chars) {
        if (ch.uuid().toUInt16() == 4419) { //tx Sketch characteristic
            qDebug() << "CHARACTERICTIC uuid: " << ch.uuid()
                     << " - value: " << ch.value();
            letter = ch.value().at(0);
            if (ch.value().at(0) != '.')
                qDebug() << "NEW LETTER on charac value: " << ch.value();
        }
        else if (ch.uuid().toUInt16() == 4418) { //rx Sketch characteristic
            service->writeCharacteristic(ch, QByteArray::fromHex("1"),QLowEnergyService::WriteWithoutResponse);
        }
    }

    emit readDone();
    emit characteristicsUpdated();
    delete service;
}

// Returns the new letter if it exists, otherwise it returns a comma.
char Device::newLetter()
{
    if (letter != ',') {
        char beforeDelete = letter;
        letter = ',';

        return beforeDelete;
    }

    return letter;
}

// Function when an error with the BLE SmartPen happens
void Device::onErrorReceived(QLowEnergyController::Error)
{
    qDebug() << "Error: " << controller->errorString();;
}

// Function when the SmartPen is disconnected
void Device::onDeviceDisconnected()
{
    qDebug() << "Device disconnected";
}

// Function when change the BLE controller state
void Device::onStateChanged(QLowEnergyController::ControllerState state)
{
    if (state == QLowEnergyController::UnconnectedState) {
        qDebug() << state;
        emit disconnected();
        emit readDone();
    }
}
