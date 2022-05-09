#include "tools.h"
#include <QTime>
#include <QCoreApplication>


void delay(int msToWait)
{
    QTime finishTime = QTime::currentTime().addMSecs(msToWait);

    while( QTime::currentTime() < finishTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

