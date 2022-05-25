#include "readerthread.h"

// Constructor
ReaderThread::ReaderThread(QObject *parent) : QThread{parent}
{
    serialPort.setPortName(portName);
    if(!serialPort.setBaudRate(QSerialPort::Baud9600 , QSerialPort::Input))
        qDebug() << serialPort.errorString();
    if(!serialPort.setDataBits(QSerialPort::Data7))
        qDebug() << serialPort.errorString();
    if(!serialPort.setParity(QSerialPort::EvenParity))
        qDebug() << serialPort.errorString();
    if(!serialPort.setFlowControl(QSerialPort::HardwareControl))
        qDebug() << serialPort.errorString();
    if(!serialPort.setStopBits(QSerialPort::OneStop))
        qDebug() << serialPort.errorString();
    if(!serialPort.open(QIODevice::ReadOnly))
        qDebug() << serialPort.errorString();
}

// The thread loop
void ReaderThread::run()
{
    bool newRead = false;
    QByteArray dataPort;

    while (true) {
        checkAvailability();

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

            emit isConnected(portOpen);
        }
        else
            emit isConnected(portOpen);

        // Finally, it emits the string with the new letter
        // if it has been read
        if (newRead) {
            qDebug() << readString;
            emit sendReaded(readString);

            newRead = false;
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
        if (list[i].portName() == portName) {
            portOpen = true;
            if (serialPort.portName() != portName) {
                serialPort.close();
                serialPort.setPortName(portName);
                serialPort.open(QIODevice::ReadOnly);
                qDebug() << "SERIAL PORT CONNECTED";
            }
        }
        else if (list[i].portName() == portAltName) {
            portOpen = true;
            if (serialPort.portName() != portAltName) {
                serialPort.close();
                serialPort.setPortName(portAltName);
                serialPort.open(QIODevice::ReadOnly);
                qDebug() << "SERIAL PORT CONNECTED";
            }
        }
        else
            qDebug() << "SERIAL PORT DISCONNECTED: " << serialPort.errorString();
    }
}

// Clean the current readString
void ReaderThread::cleanReadString()
{
    readString = "";
    emit sendReaded(readString);
}
