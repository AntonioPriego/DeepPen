#include "mainwindow.h"

#ifndef DEEPPEN_H
#define DEEPPEN_H


class DeepPen
{
public:
    DeepPen();
    static void connectToDeepPen(MainWindow *window);

private:
    bool synchronized;
};

#endif // DEEPPEN_H
