/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *TopBar;
    QHBoxLayout *horizontalLayout;
    QFrame *FrameToggle;
    QVBoxLayout *verticalLayout_2;
    QPushButton *ButtonToggle;
    QLabel *_;
    QFrame *forSTposition1;
    QLabel *SectionTitle;
    QFrame *forSTposition3;
    QFrame *forSTposition2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QFrame *FrameTop;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QRadioButton *ConectedStatusRB;
    QPushButton *ButtonSync;
    QFrame *Content;
    QHBoxLayout *horizontalLayout_2;
    QFrame *FrameSidebar;
    QVBoxLayout *verticalLayout_3;
    QFrame *FrameTopSidebar;
    QVBoxLayout *verticalLayout_4;
    QPushButton *ButtonReadMode;
    QPushButton *ButtonBlackboard;
    QPushButton *ButtonAboutDev;
    QFrame *FramePages;
    QVBoxLayout *verticalLayout_5;
    QStackedWidget *stackedWidget;
    QWidget *StartupPage;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *StartupImage;
    QLabel *ProjectDescription;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QLabel *StartupTitle;
    QLabel *DevName;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QWidget *LetterByLetterPage;
    QVBoxLayout *verticalLayout_7;
    QLabel *Written;
    QLabel *recognisedLetters;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *clearButton;
    QWidget *BlackBoardPage;
    QLabel *blackboardText;
    QWidget *AboutDevPage;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_9;
    QLabel *personalPhoto;
    QLabel *devName;
    QSpacerItem *verticalSpacer_2;
    QLabel *projectInfo;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *linkedinLayout;
    QLabel *linkedinLabel;
    QPushButton *linkedinButton;
    QVBoxLayout *githubLayout;
    QLabel *githubLabel;
    QPushButton *githubButton;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1010, 600);
        MainWindow->setMinimumSize(QSize(1000, 600));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(45, 45, 45);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        TopBar = new QFrame(centralwidget);
        TopBar->setObjectName(QString::fromUtf8("TopBar"));
        TopBar->setMaximumSize(QSize(16777215, 45));
        TopBar->setStyleSheet(QString::fromUtf8("background-color: rgb(37, 37, 37);\n"
"border-bottom-color: rgb(20, 20, 20);\n"
"color: rgb(231, 231, 231);"));
        TopBar->setFrameShape(QFrame::NoFrame);
        TopBar->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(TopBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        FrameToggle = new QFrame(TopBar);
        FrameToggle->setObjectName(QString::fromUtf8("FrameToggle"));
        FrameToggle->setMaximumSize(QSize(80, 35));
        FrameToggle->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"	color: rgb(231, 231, 231);\n"
"    background-color:rgb(170, 85, 255);\n"
"	border: 0px solid;\n"
" }\n"
" QPushButton:hover {\n"
"    background-color: rgb(190, 105, 255);\n"
" }\n"
" QPushButton:pressed{\n"
"    background-color:rgb(210, 135, 255) ; \n"
" }"));
        FrameToggle->setFrameShape(QFrame::NoFrame);
        FrameToggle->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(FrameToggle);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        ButtonToggle = new QPushButton(FrameToggle);
        ButtonToggle->setObjectName(QString::fromUtf8("ButtonToggle"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ButtonToggle->sizePolicy().hasHeightForWidth());
        ButtonToggle->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Universalis ADF Std")});
        font.setPointSize(10);
        font.setBold(true);
        ButtonToggle->setFont(font);
        ButtonToggle->setCursor(QCursor(Qt::PointingHandCursor));
        ButtonToggle->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../DeepPen/icons/deployArrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonToggle->setIcon(icon);

        verticalLayout_2->addWidget(ButtonToggle);


        horizontalLayout->addWidget(FrameToggle);

        _ = new QLabel(TopBar);
        _->setObjectName(QString::fromUtf8("_"));

        horizontalLayout->addWidget(_);

        forSTposition1 = new QFrame(TopBar);
        forSTposition1->setObjectName(QString::fromUtf8("forSTposition1"));
        forSTposition1->setFrameShape(QFrame::NoFrame);
        forSTposition1->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(forSTposition1);

        SectionTitle = new QLabel(TopBar);
        SectionTitle->setObjectName(QString::fromUtf8("SectionTitle"));
        SectionTitle->setEnabled(true);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Universalis ADF Std")});
        font1.setPointSize(22);
        font1.setBold(false);
        SectionTitle->setFont(font1);
        SectionTitle->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(SectionTitle);

        forSTposition3 = new QFrame(TopBar);
        forSTposition3->setObjectName(QString::fromUtf8("forSTposition3"));
        forSTposition3->setFrameShape(QFrame::NoFrame);
        forSTposition3->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(forSTposition3);

        forSTposition2 = new QFrame(TopBar);
        forSTposition2->setObjectName(QString::fromUtf8("forSTposition2"));
        forSTposition2->setFrameShape(QFrame::NoFrame);
        forSTposition2->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(forSTposition2);

        frame = new QFrame(TopBar);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"	color: rgb(231, 231, 231);\n"
"    background-color:rgb(25, 25, 25);\n"
"	border: 2px solid;\n"
"	border-color:rgb(55, 89, 55);\n"
" }\n"
" QPushButton:hover {\n"
"    background-color: rgb(45, 45, 45);\n"
" }\n"
" QPushButton:pressed{\n"
"    background-color:rgb(90, 90, 90) ;\n"
" }\n"
"\n"
" border-width:1px;\n"
" border-radius:17.2px;"));
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        FrameTop = new QFrame(frame);
        FrameTop->setObjectName(QString::fromUtf8("FrameTop"));
        FrameTop->setFrameShape(QFrame::NoFrame);
        FrameTop->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(FrameTop);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(FrameTop);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Universalis ADF Std")});
        label->setFont(font2);

        horizontalLayout_3->addWidget(label);

        ConectedStatusRB = new QRadioButton(FrameTop);
        ConectedStatusRB->setObjectName(QString::fromUtf8("ConectedStatusRB"));
        ConectedStatusRB->setFont(font2);
        ConectedStatusRB->setStyleSheet(QString::fromUtf8("QRadioButton:checked {\n"
"    color: rgb(0, 255, 127);\n"
"}\n"
"QRadioButton:unchecked {\n"
"    color: rgb(255, 64, 64);\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 10px;\n"
"    height: 10px;\n"
"    border-radius: 7px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: rgb(0, 255, 127);\n"
"    border: 2px solid  rgb(35, 35, 35);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"    background-color: rgb(255, 64, 64);\n"
"    border: 2px solid  rgb(35, 35, 35);\n"
"}"));
        ConectedStatusRB->setCheckable(false);
        ConectedStatusRB->setChecked(false);
        ConectedStatusRB->setAutoRepeat(false);
        ConectedStatusRB->setAutoExclusive(false);

        horizontalLayout_3->addWidget(ConectedStatusRB);


        horizontalLayout_4->addWidget(FrameTop);

        ButtonSync = new QPushButton(frame);
        ButtonSync->setObjectName(QString::fromUtf8("ButtonSync"));
        QFont font3;
        ButtonSync->setFont(font3);
        ButtonSync->setCursor(QCursor(Qt::PointingHandCursor));
        ButtonSync->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icons/sync.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonSync->setIcon(icon1);
        ButtonSync->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(ButtonSync);


        horizontalLayout->addWidget(frame);


        verticalLayout->addWidget(TopBar);

        Content = new QFrame(centralwidget);
        Content->setObjectName(QString::fromUtf8("Content"));
        Content->setFrameShape(QFrame::NoFrame);
        Content->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(Content);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        FrameSidebar = new QFrame(Content);
        FrameSidebar->setObjectName(QString::fromUtf8("FrameSidebar"));
        FrameSidebar->setMinimumSize(QSize(80, 0));
        FrameSidebar->setMaximumSize(QSize(70, 16777215));
        FrameSidebar->setStyleSheet(QString::fromUtf8("background-color: rgb(40, 40, 40);\n"
"border-right-color: rgb(20, 20, 20);\n"
""));
        FrameSidebar->setFrameShape(QFrame::NoFrame);
        FrameSidebar->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(FrameSidebar);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        FrameTopSidebar = new QFrame(FrameSidebar);
        FrameTopSidebar->setObjectName(QString::fromUtf8("FrameTopSidebar"));
        FrameTopSidebar->setCursor(QCursor(Qt::ArrowCursor));
        FrameTopSidebar->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"	color: rgb(231, 231, 231);\n"
"    background-color:rgb(35, 35, 35);\n"
"	border: 0px solid;\n"
"	text-align: left;\n"
"	padding-left: 10px;\n"
" }\n"
" QPushButton:hover {\n"
"    background-color: rgb(45, 45, 45);\n"
" }\n"
" QPushButton:pressed{\n"
"    background-color:rgb(90, 90, 90) ;\n"
" }"));
        FrameTopSidebar->setFrameShape(QFrame::NoFrame);
        FrameTopSidebar->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(FrameTopSidebar);
        verticalLayout_4->setSpacing(1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(1, 1, 1, 1);
        ButtonReadMode = new QPushButton(FrameTopSidebar);
        ButtonReadMode->setObjectName(QString::fromUtf8("ButtonReadMode"));
        ButtonReadMode->setMinimumSize(QSize(0, 35));
        ButtonReadMode->setFont(font2);
        ButtonReadMode->setCursor(QCursor(Qt::PointingHandCursor));
        ButtonReadMode->setLayoutDirection(Qt::LeftToRight);
        ButtonReadMode->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../DeepPen/icons/letter_shifted.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonReadMode->setIcon(icon2);
        ButtonReadMode->setIconSize(QSize(35, 35));
        ButtonReadMode->setFlat(false);

        verticalLayout_4->addWidget(ButtonReadMode);

        ButtonBlackboard = new QPushButton(FrameTopSidebar);
        ButtonBlackboard->setObjectName(QString::fromUtf8("ButtonBlackboard"));
        ButtonBlackboard->setMinimumSize(QSize(0, 35));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Universalis ADF Std")});
        font4.setBold(false);
        font4.setItalic(false);
        font4.setStrikeOut(false);
        ButtonBlackboard->setFont(font4);
        ButtonBlackboard->setCursor(QCursor(Qt::PointingHandCursor));
        ButtonBlackboard->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icons/blackboard_shifted.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonBlackboard->setIcon(icon3);
        ButtonBlackboard->setIconSize(QSize(35, 35));

        verticalLayout_4->addWidget(ButtonBlackboard, 0, Qt::AlignTop);


        verticalLayout_3->addWidget(FrameTopSidebar, 0, Qt::AlignTop);

        ButtonAboutDev = new QPushButton(FrameSidebar);
        ButtonAboutDev->setObjectName(QString::fromUtf8("ButtonAboutDev"));
        ButtonAboutDev->setMinimumSize(QSize(0, 35));
        ButtonAboutDev->setMaximumSize(QSize(16777215, 16777215));
        ButtonAboutDev->setFont(font2);
        ButtonAboutDev->setCursor(QCursor(Qt::PointingHandCursor));
        ButtonAboutDev->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"	color: rgb(231, 231, 231);\n"
"    background-color:rgb(35, 35, 35);\n"
"	border: 0px solid;\n"
"	padding-left: 10px;\n"
" }\n"
" QPushButton:hover {\n"
"    background-color: rgb(45, 45, 45);\n"
" }\n"
" QPushButton:pressed{\n"
"    background-color:rgb(90, 90, 90) ;\n"
" }"));
        ButtonAboutDev->setIconSize(QSize(20, 20));

        verticalLayout_3->addWidget(ButtonAboutDev);


        horizontalLayout_2->addWidget(FrameSidebar);

        FramePages = new QFrame(Content);
        FramePages->setObjectName(QString::fromUtf8("FramePages"));
        FramePages->setFrameShape(QFrame::NoFrame);
        FramePages->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(FramePages);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(FramePages);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        StartupPage = new QWidget();
        StartupPage->setObjectName(QString::fromUtf8("StartupPage"));
        QFont font5;
        font5.setBold(false);
        StartupPage->setFont(font5);
        gridLayout = new QGridLayout(StartupPage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        StartupImage = new QLabel(StartupPage);
        StartupImage->setObjectName(QString::fromUtf8("StartupImage"));
        StartupImage->setMinimumSize(QSize(270, 395));

        horizontalLayout_6->addWidget(StartupImage);

        ProjectDescription = new QLabel(StartupPage);
        ProjectDescription->setObjectName(QString::fromUtf8("ProjectDescription"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ProjectDescription->sizePolicy().hasHeightForWidth());
        ProjectDescription->setSizePolicy(sizePolicy1);
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Universalis ADF Std")});
        font6.setPointSize(13);
        ProjectDescription->setFont(font6);
        ProjectDescription->setStyleSheet(QString::fromUtf8("color: rgb(230, 230, 230);"));
        ProjectDescription->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        ProjectDescription->setMargin(10);

        horizontalLayout_6->addWidget(ProjectDescription, 0, Qt::AlignHCenter|Qt::AlignTop);


        verticalLayout_6->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        StartupTitle = new QLabel(StartupPage);
        StartupTitle->setObjectName(QString::fromUtf8("StartupTitle"));
        StartupTitle->setEnabled(true);
        sizePolicy1.setHeightForWidth(StartupTitle->sizePolicy().hasHeightForWidth());
        StartupTitle->setSizePolicy(sizePolicy1);
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Universalis ADF Std")});
        font7.setPointSize(28);
        font7.setBold(false);
        font7.setItalic(false);
        StartupTitle->setFont(font7);
        StartupTitle->setLayoutDirection(Qt::LeftToRight);
        StartupTitle->setStyleSheet(QString::fromUtf8("color: rgb(231, 231, 231);\n"
"outline:2px black;"));
        StartupTitle->setScaledContents(false);
        StartupTitle->setAlignment(Qt::AlignCenter);
        StartupTitle->setWordWrap(false);

        horizontalLayout_7->addWidget(StartupTitle);


        verticalLayout_6->addLayout(horizontalLayout_7);

        DevName = new QLabel(StartupPage);
        DevName->setObjectName(QString::fromUtf8("DevName"));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Universalis ADF Std")});
        font8.setPointSize(11);
        font8.setItalic(true);
        DevName->setFont(font8);
        DevName->setStyleSheet(QString::fromUtf8("color: rgb(231, 231, 231);"));

        verticalLayout_6->addWidget(DevName, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        horizontalLayout_5->addLayout(verticalLayout_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        stackedWidget->addWidget(StartupPage);
        LetterByLetterPage = new QWidget();
        LetterByLetterPage->setObjectName(QString::fromUtf8("LetterByLetterPage"));
        LetterByLetterPage->setMinimumSize(QSize(0, 100));
        verticalLayout_7 = new QVBoxLayout(LetterByLetterPage);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        Written = new QLabel(LetterByLetterPage);
        Written->setObjectName(QString::fromUtf8("Written"));
        Written->setMaximumSize(QSize(16777215, 25));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Universalis ADF Std")});
        font9.setPointSize(15);
        font9.setBold(true);
        Written->setFont(font9);
        Written->setStyleSheet(QString::fromUtf8("color: rgb(211, 215, 207);"));

        verticalLayout_7->addWidget(Written);

        recognisedLetters = new QLabel(LetterByLetterPage);
        recognisedLetters->setObjectName(QString::fromUtf8("recognisedLetters"));
        recognisedLetters->setMinimumSize(QSize(0, 0));
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Universalis ADF Std")});
        font10.setPointSize(14);
        font10.setItalic(true);
        font10.setUnderline(true);
        recognisedLetters->setFont(font10);
        recognisedLetters->setCursor(QCursor(Qt::IBeamCursor));
        recognisedLetters->setStyleSheet(QString::fromUtf8("color: rgb(211, 215, 207);\n"
"\n"
"background-image: url(./images/texture.png);"));
        recognisedLetters->setFrameShape(QFrame::NoFrame);
        recognisedLetters->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_7->addWidget(recognisedLetters);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setSizeConstraint(QLayout::SetMinimumSize);
        clearButton = new QPushButton(LetterByLetterPage);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setMinimumSize(QSize(0, 25));
        clearButton->setMaximumSize(QSize(65, 16777215));
        clearButton->setFont(font2);
        clearButton->setCursor(QCursor(Qt::PointingHandCursor));
        clearButton->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"	color: rgb(231, 231, 231);\n"
"    background-color:rgb(35, 35, 35);\n"
"	border: 0.5px solid;\n"
" }\n"
" QPushButton:hover {\n"
"    background-color: rgb(45, 45, 45);\n"
" }\n"
" QPushButton:pressed{\n"
"    background-color:rgb(90, 90, 90) ;\n"
" }"));

        horizontalLayout_9->addWidget(clearButton);


        verticalLayout_7->addLayout(horizontalLayout_9);

        stackedWidget->addWidget(LetterByLetterPage);
        BlackBoardPage = new QWidget();
        BlackBoardPage->setObjectName(QString::fromUtf8("BlackBoardPage"));
        blackboardText = new QLabel(BlackBoardPage);
        blackboardText->setObjectName(QString::fromUtf8("blackboardText"));
        blackboardText->setGeometry(QRect(10, 0, 408, 101));
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Universalis ADF Std")});
        font11.setPointSize(22);
        blackboardText->setFont(font11);
        blackboardText->setStyleSheet(QString::fromUtf8("color: rgb(186, 189, 182);"));
        stackedWidget->addWidget(BlackBoardPage);
        AboutDevPage = new QWidget();
        AboutDevPage->setObjectName(QString::fromUtf8("AboutDevPage"));
        gridLayout_2 = new QGridLayout(AboutDevPage);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        personalPhoto = new QLabel(AboutDevPage);
        personalPhoto->setObjectName(QString::fromUtf8("personalPhoto"));
        personalPhoto->setMinimumSize(QSize(300, 150));
        personalPhoto->setMaximumSize(QSize(300, 150));
        personalPhoto->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(personalPhoto);

        devName = new QLabel(AboutDevPage);
        devName->setObjectName(QString::fromUtf8("devName"));
        devName->setMaximumSize(QSize(300, 80));
        devName->setFont(font2);
        devName->setStyleSheet(QString::fromUtf8("color: rgb(186, 189, 182);"));
        devName->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_9->addWidget(devName);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);


        horizontalLayout_8->addLayout(verticalLayout_9);

        projectInfo = new QLabel(AboutDevPage);
        projectInfo->setObjectName(QString::fromUtf8("projectInfo"));
        projectInfo->setMinimumSize(QSize(600, 0));
        projectInfo->setMaximumSize(QSize(16777215, 16777215));
        projectInfo->setFont(font2);
        projectInfo->setStyleSheet(QString::fromUtf8("color: rgb(186, 189, 182);"));
        projectInfo->setAlignment(Qt::AlignJustify|Qt::AlignTop);

        horizontalLayout_8->addWidget(projectInfo);


        verticalLayout_8->addLayout(horizontalLayout_8);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_4);

        linkedinLayout = new QVBoxLayout();
        linkedinLayout->setObjectName(QString::fromUtf8("linkedinLayout"));
        linkedinLabel = new QLabel(AboutDevPage);
        linkedinLabel->setObjectName(QString::fromUtf8("linkedinLabel"));
        QFont font12;
        font12.setFamilies({QString::fromUtf8("Universalis ADF Std")});
        font12.setPointSize(9);
        linkedinLabel->setFont(font12);
        linkedinLabel->setLayoutDirection(Qt::LeftToRight);
        linkedinLabel->setStyleSheet(QString::fromUtf8("color: rgb(186, 189, 182);"));
        linkedinLabel->setAlignment(Qt::AlignCenter);

        linkedinLayout->addWidget(linkedinLabel);

        linkedinButton = new QPushButton(AboutDevPage);
        linkedinButton->setObjectName(QString::fromUtf8("linkedinButton"));
        linkedinButton->setMinimumSize(QSize(0, 40));
        linkedinButton->setMaximumSize(QSize(40, 16777215));
        linkedinButton->setCursor(QCursor(Qt::PointingHandCursor));
        linkedinButton->setLayoutDirection(Qt::LeftToRight);
        linkedinButton->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"	color: rgb(231, 231, 231);\n"
"    background-color:rgb(45, 45, 45);\n"
" }\n"
" QPushButton:hover {\n"
"    background-color: rgb(45, 45, 45);\n"
" }\n"
" QPushButton:pressed{\n"
"    background-color:rgb(45, 45, 45) ;\n"
" }"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("icons/linkedinIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        linkedinButton->setIcon(icon4);
        linkedinButton->setIconSize(QSize(40, 40));
        linkedinButton->setFlat(true);

        linkedinLayout->addWidget(linkedinButton);


        horizontalLayout_12->addLayout(linkedinLayout);

        githubLayout = new QVBoxLayout();
        githubLayout->setObjectName(QString::fromUtf8("githubLayout"));
        githubLabel = new QLabel(AboutDevPage);
        githubLabel->setObjectName(QString::fromUtf8("githubLabel"));
        githubLabel->setFont(font12);
        githubLabel->setLayoutDirection(Qt::LeftToRight);
        githubLabel->setStyleSheet(QString::fromUtf8("color: rgb(186, 189, 182);"));
        githubLabel->setAlignment(Qt::AlignCenter);

        githubLayout->addWidget(githubLabel);

        githubButton = new QPushButton(AboutDevPage);
        githubButton->setObjectName(QString::fromUtf8("githubButton"));
        githubButton->setMinimumSize(QSize(0, 40));
        githubButton->setMaximumSize(QSize(40, 16777215));
        githubButton->setCursor(QCursor(Qt::PointingHandCursor));
        githubButton->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"	color: rgb(231, 231, 231);\n"
"    background-color:rgb(45, 45, 45);\n"
" }\n"
" QPushButton:hover {\n"
"    background-color: rgb(45, 45, 45);\n"
" }\n"
" QPushButton:pressed{\n"
"    background-color:rgb(45, 45, 45) ;\n"
" }"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("icons/githubIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        githubButton->setIcon(icon5);
        githubButton->setIconSize(QSize(40, 40));
        githubButton->setFlat(true);

        githubLayout->addWidget(githubButton);


        horizontalLayout_12->addLayout(githubLayout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_5);


        verticalLayout_8->addLayout(horizontalLayout_12);


        gridLayout_2->addLayout(verticalLayout_8, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 1, 0, 1, 1);

        stackedWidget->addWidget(AboutDevPage);

        verticalLayout_5->addWidget(stackedWidget);


        horizontalLayout_2->addWidget(FramePages);


        verticalLayout->addWidget(Content);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ButtonToggle->setText(QCoreApplication::translate("MainWindow", "Fold", nullptr));
        _->setText(QString());
        SectionTitle->setText(QCoreApplication::translate("MainWindow", "Startup", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Current Status:", nullptr));
        ConectedStatusRB->setText(QCoreApplication::translate("MainWindow", "Disconected", nullptr));
        ButtonSync->setText(QString());
        ButtonReadMode->setText(QCoreApplication::translate("MainWindow", "Letter by...    ", nullptr));
        ButtonBlackboard->setText(QCoreApplication::translate("MainWindow", "Blackboard...", nullptr));
        ButtonAboutDev->setText(QCoreApplication::translate("MainWindow", "About...", nullptr));
        StartupImage->setText(QString());
        ProjectDescription->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><br/></p><p align=\"justify\">According to the function the text is supposed to</p><p align=\"justify\">be started from the bottom left but it starts too low and</p><p align=\"justify\">left. I know I can find a point by trial error so it doesn\342\200\231t gets</p><p align=\"justify\">cut off- you can -20 to the height and it will be fine enough</p><p align=\"justify\">for this one. But it will only fix this specific text! It wont be</p><p align=\"justify\">the same for any label with a different size or text or font.</p></body></html>", nullptr));
        StartupTitle->setText(QCoreApplication::translate("MainWindow", "DeepPen Software", nullptr));
        DevName->setText(QCoreApplication::translate("MainWindow", "By Antonio Priego Raya", nullptr));
        Written->setText(QCoreApplication::translate("MainWindow", "Written:", nullptr));
        recognisedLetters->setText(QString());
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        blackboardText->setText(QCoreApplication::translate("MainWindow", "Objetivo secundario en desarrollo", nullptr));
        personalPhoto->setText(QString());
        devName->setText(QCoreApplication::translate("MainWindow", "Antonio Priego Raya\n"
"\n"
"Universidad de Granada", nullptr));
        projectInfo->setText(QCoreApplication::translate("MainWindow", "Descripci\303\263n TFG", nullptr));
        linkedinLabel->setText(QCoreApplication::translate("MainWindow", "Linkedin", nullptr));
        linkedinButton->setText(QString());
        githubLabel->setText(QCoreApplication::translate("MainWindow", "GitHub", nullptr));
        githubButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
