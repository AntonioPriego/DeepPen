#ifndef READERTHREAD_H
#define READERTHREAD_H

#include <QSerialPort>
#include <QThread>
#include <QDebug>
#include <QSerialPortInfo>

class ReaderThread : public QThread
{
    Q_OBJECT
public:
    explicit ReaderThread(QObject *parent = nullptr);
    QSerialPort serialPort;

    void cleanReadString();

private:    
    QSerialPortInfo *portInfo = new QSerialPortInfo;
    QString portName    = "ttyACM0"; // initial port name
    QString portAltName = "ttyACM1"; // unplug and plug port name
    QString readString  = "";
    bool portOpen       = true;

    void checkAvailability();

protected:
    void run();

signals:
    void sendReaded(QString _readed);
    void isConnected(bool status);
};

#endif // READERTHREAD_H
