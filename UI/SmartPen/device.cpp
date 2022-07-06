#include "device.h"


Device::Device(QObject *parent)
    : QObject{parent}
{
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    discoveryAgent->setLowEnergyDiscoveryTimeout(5000);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &Device::setDevice);
}

Device::~Device()
{
    delete discoveryAgent;
    delete controller;
    delete device;
    delete service;
}

void Device::startDeviceDiscovery()
{
    localDevice.powerOn();
    discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);

    if (!discoveryAgent->isActive()) {
        qDebug("ERROR: DISCOVERY AGENT INACTIVE\n");
        return;
    }
}

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

const QBluetoothDeviceInfo *Device::getDevice()
{
    return device;
}

void Device::setServices()
{
    if (!device->isValid()) {
        qDebug() << "ERROR: NOT VALID DEVICE\n";
        return;
    }

    //controller = QLowEnergyController::createCentral(*device);

    scanServices();
}

void Device::scanServices()
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
            this, &Device::deviceConnected);
    connect(controller, &QLowEnergyController::errorOccurred,
            this, &Device::errorReceived);
    connect(controller, &QLowEnergyController::disconnected,
            this, &Device::deviceDisconnected);
    connect(controller, &QLowEnergyController::serviceDiscovered,
            this, &Device::addLowEnergyService);
    connect(controller, &QLowEnergyController::discoveryFinished,
            this, &Device::serviceScanDone);
    connect(controller, &QLowEnergyController::stateChanged,
            this, &Device::stateChanged);

    controller->setRemoteAddressType(QLowEnergyController::PublicAddress);
    //qDebug() << controller->role();
    controller->connectToDevice();
}

void Device::addLowEnergyService(const QBluetoothUuid &serviceUuid)
{    if (serviceUuid.toString() == SERIALPORT_SERVICE_UUID) {
        service = controller->createServiceObject( serviceUuid );

        if (!service) {
            qDebug() << "ERROR: CANNOT CREATE SERVICE FOR UUID\n";
            return;
        }
    }
}

void Device::connectToService()
{
    if (service->state() == QLowEnergyService::RemoteService) {
        connect(service, &QLowEnergyService::stateChanged,
                this, &Device::serviceDetailsDiscovered);

        service->discoverDetails();
    }
}

void Device::deviceConnected()
{
    controller->discoverServices();
}

void Device::serviceScanDone()
{
    if (service->state() == QLowEnergyService::RemoteService)
        connectToService();
}

void Device::serviceDetailsDiscovered(QLowEnergyService::ServiceState newState)
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
                qDebug() << "\t\t\t\t\tNEW LETTER: " << ch.value();
        }
        else if (ch.uuid().toUInt16() == 4418) { //rx Sketch characteristic
            service->writeCharacteristic(ch, QByteArray::fromHex("1"),QLowEnergyService::WriteWithoutResponse);
        }
    }

    emit readDone();
    emit characteristicsUpdated();
    delete service;
}

char Device::newLetter()
{
    if (letter != ',') {
        char beforeDelete = letter;
        letter = ',';

        return beforeDelete;
    }

    return letter;
}

void Device::errorReceived(QLowEnergyController::Error)
{
    qDebug() << "Error: " << controller->errorString();;
}

void Device::deviceDisconnected()
{
    qDebug() << "Device disconnected";
}

void Device::stateChanged(QLowEnergyController::ControllerState state)
{
    if (state == QLowEnergyController::UnconnectedState) {
        qDebug() << state << "\n\n";
        emit disconnected();
        emit readDone();
    }
}


bool Device::isBTEnabled()
{
    return discoveryAgent->isActive();
}
