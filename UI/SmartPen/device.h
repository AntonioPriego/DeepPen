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
    void addLowEnergyService(const QBluetoothUuid &serviceUuid);
    void connectToService();
    void connectToDevice();
    char newLetter();

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

    void onStateChanged(QLowEnergyController::ControllerState state);
    void onServiceDetailsDiscovered(QLowEnergyService::ServiceState newState);
    void onDeviceConnected();
    void onServiceScanDone();

private slots:
        void onErrorReceived(QLowEnergyController::Error);
        void onDeviceDisconnected();
};

#endif // DEVICE_H
