#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tools.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set Window Title
    this->setWindowTitle("SmartPen");

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

    //Set Photo on AboutDev
    setPersonalPhoto();

    //Set Blackboard HTML
    setBlackboard();

    // Linking thread to 'recognisedLetters' label
    readerThread = new ReaderThread(this);
    readerThread->start();
    connect(readerThread, &ReaderThread::sendReaded, [&](QString _read) {
        ui->recognisedLetters->setText(_read);
        qDebug() << "Pasa:" << _read;
    } );

    // Linking thread to connected status
    connect(readerThread, &ReaderThread::isConnected, [&](bool status) {
        setButtonSyncClickable(!status);
    } );
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
    //bool SmartPen::connectToSmartPen(this);

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
    ui->ButtonToggle->setToolTip    ("Fold and unfold the mode sidebar");
    ui->ButtonAboutDev->setToolTip  ("Info about the project and the developer");
    ui->ButtonReadMode->setToolTip  ("Displays the letters recognized by SmartPen one by one");
    ui->ButtonBlackboard->setToolTip("Displays the SmartPen path as if it were a blackboard");
    ui->ButtonSync->setToolTip      ("Synchronizes with the SmartPen when powered on");
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
                                      "}"
                                      );
    }

    ui->ConectedStatusRB->setEnabled(false);   //To preserve the check status
                                               //  If enabled, the status change when hover

    ui->ConectedStatusRB->setCheckable(true);  //Initially non checkable bc user cannot change it
    ui->ConectedStatusRB->setChecked(!clickable);
    delay(100); //without this delay, it is not checked
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
    QPixmap penImage("./images/placeholderPen.png");

    ui->StartupImage->setPixmap(penImage.scaled(ui->StartupImage->width(),
                                                ui->StartupImage->height(),
                                                Qt::KeepAspectRatio));
}

void MainWindow::setPersonalPhoto()
{
    QPixmap personalPhoto("./images/personalPhoto.png");

    ui->personalPhoto->setPixmap(personalPhoto.scaled(ui->personalPhoto->width(),
                                                     ui->personalPhoto->height(),
                                                     Qt::KeepAspectRatio));
}

void MainWindow::on_clearButton_clicked()
{
    readerThread->cleanReadString();
}


void MainWindow::on_linkedinButton_clicked()
{
    QString url = "https://www.linkedin.com/in/antonio-priego-raya-ba4a04206/";
    QDesktopServices::openUrl(QUrl(url));
}


void MainWindow::on_githubButton_clicked()
{
    QString url = "https://github.com/AntonioPriego";
    QDesktopServices::openUrl(QUrl(url));
}

void MainWindow::setBlackboard()
{
    //ui->blackboardHtml->setSource(QUrl("./html/tmp.html"));


    //QWebView *view = ui->blackboardHtml;
    //view->load(QUrl("qrc://html//tmp.html/"));
    //view->show();

    //ui->blackboardHtml->load(QUrl("qrc://images//sample page.html/"));
    //ui->blackboardHtml->show();

    //qDebug()<<( ui->stackedWidget->count() );

    //QWebEngineView* web = new QWebEngineView();
    //QWebEngineProfile *profile = new QWebEngineProfile();
    //rofile->setHttpUserAgent("--enable-experimental-web-platform-features");

    //QWebEnginePage *page = new QWebEnginePage(profile, web);
    //page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    //web->setPage(page);
    //web->load(QUrl("chrome://flags/#enable-experimental-web-platform-features"));
    //web->load(QUrl("file:///home/tony/Universidad/TFG/C%C3%B3digo_arduino/DataCollector/Smart_DataCollector.html"));
    //web->show();
//--enable-experimental-web-platform-features

    //web->page()->settings();

    //ui->stackedWidget->addWidget(web);

    //qDebug()<<( ui->stackedWidget->count() );
}










