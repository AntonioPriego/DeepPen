#include <QObject>
#include "mainwindow.h"

#ifndef TASK_H
#define TASK_H

class Task : public QObject
{
Q_OBJECT
public:
    Task(){};
    ~Task(){};
public slots:
    void operate(MainWindow *window);
signals:
    void operationFinished();
};

#endif // TASK_H
