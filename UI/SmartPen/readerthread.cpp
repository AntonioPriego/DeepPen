#include "readerthread.h"

// Constructor
ReaderThread::ReaderThread(QObject *parent) : QThread{parent}
{
    //serialPort.setPortName(portName);
    if(!serialPort.setBaudRate(QSerialPort::Baud9600 , QSerialPort::Input))
        qDebug() << serialPort.errorString();
    if(!serialPort.setDataBits(QSerialPort::Data8))
        qDebug() << serialPort.errorString();
    if(!serialPort.setParity(QSerialPort::NoParity))
        qDebug() << serialPort.errorString();
    if(!serialPort.setFlowControl(QSerialPort::NoFlowControl))
        qDebug() << serialPort.errorString();
    if(!serialPort.setStopBits(QSerialPort::OneStop))
        qDebug() << serialPort.errorString();
}

// The thread loop
void ReaderThread::run()
{
    int itWithoutSignal = 0; // tool to palliate the BT library desconections
    Device *device;
    device   = new Device;
    connect(device, &Device::readDone,     this, &ReaderThread::onReadDone);
    connect(device, &Device::disconnected, this, &ReaderThread::onDisconnected);
    device->startDeviceDiscovery(); // Setting the device when detected

    while(true) {
        if (portOpen) {
            wiredConnection();
        }
        else { // whithout this check, doesn't work with BT disabled
            if (justDisconnected) {
                device->startDeviceDiscovery(); // Setting the device when detected

                justDisconnected = false;
                //emit isConnected(false);
            }

            readDone = false;

            device->scanServices();

            while(!readDone) {
                checkPort();
                itWithoutSignal++;

                if (itWithoutSignal > 14)       // 14 is near the max iterations without
                    currentConnected = false;   // signals during error desconections
            }

            char btLetter = device->newLetter();
            if (btLetter >= 'a'  &&  btLetter <='z') {
                qDebug() << "LETTER:::: " << btLetter;
                readString += btLetter;
                currentConnected = true;
                emit sendReaded(readString);
                itWithoutSignal = 0;
            }
            else if (btLetter == '.') {   // '.' is 'working' signal
                currentConnected = true;
                itWithoutSignal = 0;
            }

            qDebug() << "BTLETTER: " << btLetter;

            emit isConnected(currentConnected);
        }
    }
}

// Check if the device is connected
// 2 possible port names to check
void ReaderThread::checkAvailability()
{
    QList<QSerialPortInfo> list = portInfo->availablePorts();

    portOpen = false;
    for (int i=0; i<list.length(); i++) {
        if ((list[i].portName() == portName  ||  list[i].portName() == portAltName) || !portOpen) {
            portOpen = true;
            if (serialPort.portName() != list[i].portName()) {
                serialPort.close();
                serialPort.setPortName(list[i].portName());
                qDebug() << "SERIAL PORT CONNECTED: "
                         << serialPort.open(QIODevice::ReadOnly)
                         << serialPort.portName();
            }
        }
        else
            portOpen = false;
    }


    if (!portOpen) {
        if (!disconnectedPrinted) {
            qDebug() << "SERIAL PORT DISCONNECTED: " << serialPort.errorString();
            disconnectedPrinted = true;
        }
    }
    else {
        disconnectedPrinted = false;
    }
}

// Clean the current readString
void ReaderThread::cleanReadString()
{
    readString = "";
    emit sendReaded(readString);
}

void ReaderThread::wiredConnection()
{
    bool newRead = false;
    QByteArray dataPort;

    checkAvailability();
    msleep(100);

    // Once the port availability is checked,
    // it reads the port and emit connected and read
    // the possible read letter if available.
    // If not available, it emit only not connected.
    if (portOpen) {
        dataPort = serialPort.readAll();
        for (int i = 0; i < dataPort.size(); i++)
            if (dataPort.at(i)  &&  dataPort[i]>='a' &&  dataPort[i]<='z') {
                readString += dataPort[i];
                newRead = true;
            }
    }
    emit isConnected(portOpen);

    // Finally, it emits the string with the new letter
    // if it has been read
    if (newRead) {
        qDebug() << readString;
        emit sendReaded(readString);
    }
}

void ReaderThread::onReadDone() { readDone = true; }

void ReaderThread::onDisconnected() { justDisconnected = true; }

void ReaderThread::checkPort()
{
    checkAvailability();
    msleep(100);

    emit isConnected(currentConnected);
}
