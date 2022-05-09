#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "deeppen.h"
#include "tools.h"

#include <QDebug>
#include <QPixmap>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set Window Title
    this->setWindowTitle("DeepPen");

    //Set StyleSheet for QToolTips
    setTooltips();

    //Set ToolTips
    setTooltips();

    //Set StartupImage
    setStartupImage();

    //Expand Sidebar
    setUnfoldSidebar();

    //Set Startup Page
    setPage(STARTUPINDEX);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ButtonToggle_clicked()
{
    //switch between fold and unfold Sidebar
    if(ui->FrameToggle->width() == expandedMenuWidth)
        setFoldSidebar();
    else
        setUnfoldSidebar();
}

void MainWindow::refreshSyncButton(QString greenValue)
{
    ui->ButtonSync->setStyleSheet("QPushButton {"
                                      "color: rgb(231, 231, 231);"
                                      "background-color:rgb(25, 25, 25);"
                                      "border: 2px solid;"
                                      "border-color:rgb(55,"+greenValue+", 55);"
                                  "}"
                                  "QPushButton:hover {"
                                      "background-color: rgb(45, 45, 45);"
                                  "}"
                                  "QPushButton:pressed{"
                                      "background-color:rgb(90, 90, 90) ;"
                                  "}"
                                      "border-width:1px;"
                                      "border-radius:17.2px;"
                                  );
}

void MainWindow::on_ButtonReadMode_clicked()
{
    setPage(LETTERBYLETTERINDEX);

    resetButtonsClicked();
    ui->ButtonReadMode->setStyleSheet("background-color:rgb(62, 37, 74);");
}

void MainWindow::on_ButtonBlackboard_clicked()
{
    setPage(BLACKBOARDINDEX);

    resetButtonsClicked();
    ui->ButtonBlackboard->setStyleSheet("background-color:rgb(62, 37, 74);");
}

void MainWindow::on_ButtonAboutDev_clicked()
{
    setPage(ABOUTDEVINDEX);

    resetButtonsClicked();
    ui->ButtonAboutDev->setStyleSheet("QPushButton {                          "
                                      "     color: rgb(231, 231, 231);        "
                                      "     background-color:rgb(62, 37, 74); "
                                      "     border: 0px solid;                "
                                      "     padding-left: 10px;               "
                                      "  }                                    "
                                      "  QPushButton:hover {                  "
                                      "     background-color:rgb(62, 37, 74);"
                                      "  }                                    "
                                      "  QPushButton:pressed{                 "
                                      "     background-color:rgb(62, 37, 74) ;"
                                      "  }                                    ");
}

void MainWindow::on_ButtonSync_clicked()
{
    //bool DeepPen::connectToDeepPen(this);

    qDebug() << "Pulsado Sync";

    setButtonSyncClickable(false);
}

void MainWindow::setSectionTitle(QString title)
{
    ui->SectionTitle->setText(title);
}

void MainWindow::resetButtonsClicked()
{
    ui->ButtonReadMode->setStyleSheet  (buttonStyleIdle);
    ui->ButtonBlackboard->setStyleSheet(buttonStyleIdle);
    ui->ButtonAboutDev->setStyleSheet  (buttonStyleIdle);
}

void MainWindow::setTooltips()
{
    ui->ButtonToggle->setToolTip("Fold and unfold the mode sidebar");
    ui->ButtonAboutDev->setToolTip("Info about the project and the developer");
    ui->ButtonReadMode->setToolTip("Displays the letters recognized by DeepPen one by one");
    ui->ButtonBlackboard->setToolTip("Displays the DeepPen path as if it were a blackboard");
    ui->ButtonSync->setToolTip("Synchronizes with the DeepPen when powered on");
}


void MainWindow::setFoldSidebar()
{
    //TopBar
    ui->FrameToggle->setMaximumWidth(compactMenuWidth);
    ui->ButtonToggle->setIcon(unfoldIcon);

    //SideBar
    ui->FrameSidebar->setMaximumWidth(compactMenuWidth);
    ui->FrameSidebar->setMinimumWidth(compactMenuWidth);

    //Text in Mode buttons
    ui->ButtonReadMode->setText(textButtonModesCompact[0]);
    ui->ButtonBlackboard->setText(textButtonModesCompact[1]);
    ui->ButtonAboutDev->setText(textButtonModesCompact[2]);

    //Show/Hide button icons
    ui->ButtonReadMode->setIcon(QIcon());
    ui->ButtonBlackboard->setIcon(QIcon());
    ui->ButtonAboutDev->setIcon(QIcon());

    //Change Toggle Button text and icon position
    ui->ButtonToggle->setText("Unfold");
    ui->ButtonToggle->setLayoutDirection(Qt::RightToLeft);
}

void MainWindow::setUnfoldSidebar()
{
    //TopBar
    ui->FrameToggle->setMaximumWidth(expandedMenuWidth);
    ui->ButtonToggle->setIcon(foldIcon);

    //SideBar
    ui->FrameSidebar->setMaximumWidth(expandedMenuWidth);
    ui->FrameSidebar->setMinimumWidth(expandedMenuWidth);

    //Text in Mode buttons
    ui->ButtonReadMode->setText(textButtonModesExpand[0]);
    ui->ButtonBlackboard->setText(textButtonModesExpand[1]);
    ui->ButtonAboutDev->setText(textButtonModesExpand[2]);

    //Show/Hide button icons
    ui->ButtonReadMode->setIcon(aIcon);
    ui->ButtonBlackboard->setIcon(blackboardIcon);
    ui->ButtonAboutDev->setIcon(aboutIcon);


    //Change Toggle Button text
    ui->ButtonToggle->setText("Fold Sidebar");
    ui->ButtonToggle->setLayoutDirection(Qt::LeftToRight);
}

void MainWindow::setButtonSyncClickable(bool clickable)
{
    if (clickable) {
        ui->ConectedStatusRB->setText("Disconnected");
        ui->ButtonSync->setStyleSheet("");
    }
    else{
        ui->ConectedStatusRB->setText("Connected");
        ui->ButtonSync->setStyleSheet("QPushButton {"
                                          "background-color:rgb(60, 60, 60);"
                                          "border-color:rgb(100, 100, 100);"
                                      "});"
                                      );
    }

    ui->ConectedStatusRB->setEnabled(false);   //To preserve the check status
                                               //  If enabled, the status change when hover

    ui->ConectedStatusRB->setCheckable(true);  //Initially non checkable bc user cannot change it
    ui->ConectedStatusRB->setChecked(!clickable);
    delay(10); //without this delay, it is not checked
    ui->ConectedStatusRB->setCheckable(false); //Set non checkable again

    ui->ButtonSync->setEnabled(clickable);
}


void MainWindow::setPage(int index)
{
    switch (index){
        case STARTUPINDEX:
            ui->SectionTitle->setText("Startup");
            break;
        case LETTERBYLETTERINDEX:
            ui->SectionTitle->setText("Letter by letter");
            break;
        case BLACKBOARDINDEX:
            ui->SectionTitle->setText("Blackboard");
            break;
        case ABOUTDEVINDEX:
            ui->SectionTitle->setText("About developer");
            break;
    }

    ui->stackedWidget->setCurrentIndex(index);
}

void MainWindow::setToolTips()
{
    setStyleSheet("QToolTip {"
                               "background-color: black;"
                               "color: white;"
                               "border: black solid 1px"
                           "}"
                  );
}

void MainWindow::setStartupImage()
{
    QPixmap penImage("../DeepPen/icons/placeholderPen.png");

    ui->StartupImage->setPixmap(penImage.scaled(ui->StartupImage->width(),
                                                ui->StartupImage->height(),
                                                Qt::KeepAspectRatio));
}
