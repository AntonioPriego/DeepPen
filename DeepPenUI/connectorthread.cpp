#include "connectorthread.h"

ConnectorThread::ConnectorThread(QObject *parent) : QThread{parent}
{
    QBluetoothUuid uuid(QString("4798e0f2-300a-4d68-af64-8a8f5258404e"));
    m_device = new QBluetoothDeviceInfo( uuid,"BLESense-8040",QBluetoothDeviceInfo::MajorDeviceClass::ComputerDevice);
}


void ConnectorThread::run()
{
    if (m_control) {
        m_control->disconnectFromDevice();
        delete m_control;
        m_control = 0;
    }
    m_control = new QLowEnergyController(*m_device, this);
    connect(m_control, SIGNAL(serviceDiscovered(QBluetoothUuid)),
            this, SLOT(onServiceDiscovered(QBluetoothUuid)));
    connect(m_control, SIGNAL(discoveryFinished()),
            this, SLOT(onServiceScanDone()));
    connect(m_control, SIGNAL(error(QLowEnergyController::Error)),
            this, SLOT(onControllerError(QLowEnergyController::Error)));
    connect(m_control, SIGNAL(connected()),
            this, SLOT(onDeviceConnected()));
    connect(m_control, SIGNAL(disconnected()),
            this, SLOT(onDeviceDisconnected()));

    m_control->connectToDevice();
    qDebug() << "llega: ";
    qDebug() << m_control->remoteDeviceUuid().toString();

    emit isConnected(true);
}

void ConnectorThread::onDeviceConnected()
{
    m_servicesUuid.clear();
    m_control->discoverServices();
}

void ConnectorThread::read(){
    if(m_service && m_readCharacteristic.isValid())
        m_service->readCharacteristic(m_readCharacteristic);
}
