#include "deeppen.h"
#include "task.h"
#include "mainwindow.h"
#include "tools.cpp"

#include <QObject>
#include <QThread>

DeepPen::DeepPen()
{
    synchronized = false;
}

void DeepPen::connectToDeepPen(MainWindow *window)
{
    qInfo() << "In develpment...";

    QThread* thread = new QThread( );
    Task*    task = new Task();
    task->moveToThread(thread);
    QObject::connect(thread, SIGNAL(started()),  task, SLOT(operate(window)) );
    QObject::connect(task,   SIGNAL(operationFinished()), thread, SLOT(quit()) );
    QObject::connect(thread, SIGNAL(finished()), task, SLOT(deleteLater()) );
    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()) );
    thread->start();

    delay(6000);
}

