#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QDebug>
#include <QPixmap>
#include <QDesktopServices>
#include <QMainWindow>
#include <QTextBrowser>
#include <QSerialPort>
#include <QSerialPortInfo>

//#include <QWebView>
//#include <QWebEngineView>
//#include <QtWebEngineWidgets>
//#include <QWebEngineProfile>
#include "readerthread.h"
#include "connectorthread.h"
#include "device.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void refreshSyncButton(QString greenValue);

private slots:
    //BUTTONS SIGNALS
    void on_ButtonReadMode_clicked();
    void on_ButtonBlackboard_clicked();
    void on_ButtonAboutDev_clicked();
    void on_ButtonSync_clicked();
    void on_ButtonToggle_clicked();
    void resetButtonsClicked();

    //UI SETTERS
    void setSectionTitle(QString title);
    void setTooltips();
    void setFoldSidebar();
    void setUnfoldSidebar();
    void setButtonSyncClickable(bool clickable);
    void setPage(int index);
    void setToolTips();
    void setStartupImage();
    void setPersonalPhoto();
    void setBlackboard();

    void on_clearButton_clicked();

    void on_linkedinButton_clicked();

    void on_githubButton_clicked();

private:
    Ui::MainWindow *ui;

    ReaderThread *readerThread;
    ConnectorThread *connectorThread;

    //STACKED WIDGET INDEXS
    static const int STARTUPINDEX        = 0;
    static const int LETTERBYLETTERINDEX = 1;
    static const int BLACKBOARDINDEX     = 3;
    static const int ABOUTDEVINDEX       = 2;


    //SIDEBAR CONDITIONS
    int expandedMenuWidth = 240;
    int compactMenuWidth  = 80;
    QIcon unfoldIcon = QIcon("./icons/deployArrowWhite.png");
    QIcon foldIcon   = QIcon("./icons/undeployArroyWhite.png");
    QIcon aIcon          = QIcon("./icons/letter_shifted.png");
    QIcon blackboardIcon = QIcon("./icons/blackboard_shifted.png");
    QIcon aboutIcon      = QIcon("./icons/aboutDev.png");
    QString textButtonModesCompact[3] = {"Letter by...    "     ,"Blackboard..."  ,"About..."};
    QString textButtonModesExpand[3]  = {"Letter by letter Mode","Blackboard Mode","About developer"};
    QString buttonStyleIdle = "QPushButton {                          "
                              "     color: rgb(231, 231, 231);        "
                              "     background-color:rgb(35, 35, 35); "
                              "     border: 0px solid;                "
                              "     padding-left: 10px;               "
                              "  }                                    "
                              "  QPushButton:hover {                  "
                              "     background-color: rgb(45, 45, 45);"
                              "  }                                    "
                              "  QPushButton:pressed{                 "
                              "     background-color:rgb(90, 90, 90) ;"
                              "  }                                    "
                              "color: rgb(231, 231, 231);"
                              "background-color:rgb(35, 35, 35);";
};


#endif // MAINWINDOW_H
