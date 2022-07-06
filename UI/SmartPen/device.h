#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>

#include <qbluetoothdevicediscoveryagent.h>
#include <QLowEnergyController>
#include <QBluetoothLocalDevice>
#include "tools.h"

const QString SERIALPORT_SERVICE_UUID = "{00001101-0000-1000-8000-00805f9b34fb}";

class Device : public QObject
{
    Q_OBJECT
public:
    explicit Device(QObject *parent = nullptr);
    ~Device();

    void startDeviceDiscovery();
    void setDevice(const QBluetoothDeviceInfo &info);
    const QBluetoothDeviceInfo *getDevice();
    void setServices();
    void addLowEnergyService(const QBluetoothUuid &serviceUuid);
    void connectToService();
    void deviceConnected();
    void scanServices();
    void serviceScanDone();
    void serviceDetailsDiscovered(QLowEnergyService::ServiceState newState);
    char newLetter();
    void stateChanged(QLowEnergyController::ControllerState state);
    bool isBTEnabled();

Q_SIGNALS:
    void characteristicsUpdated();
    void readDone();
    void disconnected();

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QLowEnergyController *controller = nullptr;

    QBluetoothLocalDevice localDevice;
    QBluetoothDeviceInfo *device;
    QLowEnergyService *service;

    char letter;

private slots:
        void errorReceived(QLowEnergyController::Error);
        void deviceDisconnected();
};

#endif // DEVICE_H
