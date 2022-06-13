#ifndef CONNECTORTHREAD_H
#define CONNECTORTHREAD_H

#include <QDebug>
#include <QThread>
#include <QLowEnergyController>
#include <QLowEnergyService>
#include <QBluetoothDeviceInfo>
#include <QBluetoothUuid>


class ConnectorThread : public QThread
{
    Q_OBJECT
public:
    explicit ConnectorThread(QObject *parent = nullptr);

private:
    QLowEnergyController *m_control;
    QList<QBluetoothUuid> m_servicesUuid;
    QLowEnergyService *m_service;
    QBluetoothDeviceInfo *m_device;
    QLowEnergyCharacteristic m_readCharacteristic;

    void onDeviceConnected();
    void read();

protected:
    void run();

signals:
    void isConnected(bool connected);

};

#endif // CONNECTORTHREAD_H
