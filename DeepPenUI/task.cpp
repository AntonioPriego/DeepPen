#include "task.h"
#include "tools.h"
#include "mainwindow.h"
#include <QDebug>

void Task::operate(MainWindow *window)
{
    qInfo() << "Tarea";
    int i;
    QString greenValue=0;

    for (i=0; i<1000; i++) {
        greenValue = QString::number( (89+i)%255 );
        qInfo() << "gv:" << greenValue;

        window->refreshSyncButton(greenValue);
        delay(100);
    }
}
