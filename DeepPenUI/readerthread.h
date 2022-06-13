#ifndef READERTHREAD_H
#define READERTHREAD_H

#include <QSerialPort>
#include <QThread>
#include <QDebug>
#include <QSerialPortInfo>
#include <QLowEnergyController>
#include <QLowEnergyService>
#include <QBluetoothDeviceInfo>
#include <QBluetoothUuid>
#include <QTimer>

#include "device.h"
#include "qqmlhelpers.h"
#include "tools.h"

class ReaderThread : public QThread
{
    Q_OBJECT
public:
    explicit ReaderThread(QObject *parent = nullptr);

    void cleanReadString();

private slots:
    void onReadDone();
    void onDisconnected();

private:
    QSerialPort serialPort;
    QSerialPortInfo *portInfo = new QSerialPortInfo;
    QString portName     = "ttyACM0"; // initial port name
    QString portAltName  = "ttyACM1"; // unplug and plug port name
    QString readString   = "";
    bool disconnectedPrinted = false;
    bool connectedPrnted     = false;
    bool justDisconnected    = true;
    bool readDone            = false;
    bool portOpen            = true;
    bool currentConnected    = false;

    void checkAvailability();
    void wiredConnection();
    void checkPort();


protected:
    void run();

signals:
    void sendReaded(QString _readed);
    void isConnected(bool status);
    void dataReceived(const QByteArray &data);
};

#endif // READERTHREAD_H
