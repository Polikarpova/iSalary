/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tabManagers;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTableView *managersTable;
    QPushButton *newManagerButton;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTabWidget *managersDataTab;
    QWidget *tab;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *familia;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *otchestvo;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QDateEdit *dateOfBirth;
    QGroupBox *sexGroup;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *maleRButton;
    QRadioButton *femaleRButton;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QSpinBox *seria;
    QLabel *label_12;
    QSpinBox *number;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QLineEdit *pasport;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QDateEdit *datePasport;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLineEdit *propiska;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    QLineEdit *INN;
    QWidget *tab_1;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLineEdit *login;
    QLabel *label_14;
    QLineEdit *password;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *changeManagerButton;
    QWidget *page2;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *cancelManagerButton;
    QPushButton *saveManagerButton;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableView;
    QPushButton *newProductButton;
    QGridLayout *gridLayout_5;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_17;
    QLineEdit *productName;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_18;
    QLineEdit *productPercent;
    QStackedWidget *stackedWidget_2;
    QWidget *page_1;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *deleteProductButton;
    QPushButton *changeProductButton;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *cancelProductButton;
    QPushButton *saveProductButton;
    QWidget *tab_3;
    QWidget *tab_7;
    QWidget *tab_5;
    QWidget *tab_6;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *quitButton;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(899, 567);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideMiddle);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tabManagers = new QWidget();
        tabManagers->setObjectName(QStringLiteral("tabManagers"));
        gridLayout_3 = new QGridLayout(tabManagers);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(tabManagers);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_2->addWidget(label);

        managersTable = new QTableView(tabManagers);
        managersTable->setObjectName(QStringLiteral("managersTable"));

        verticalLayout_2->addWidget(managersTable);

        newManagerButton = new QPushButton(tabManagers);
        newManagerButton->setObjectName(QStringLiteral("newManagerButton"));

        verticalLayout_2->addWidget(newManagerButton);


        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(tabManagers);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout->addWidget(label_2);

        managersDataTab = new QTabWidget(tabManagers);
        managersDataTab->setObjectName(QStringLiteral("managersDataTab"));
        managersDataTab->setEnabled(true);
        managersDataTab->setAcceptDrops(false);
        managersDataTab->setLayoutDirection(Qt::LeftToRight);
        managersDataTab->setIconSize(QSize(16, 16));
        managersDataTab->setUsesScrollButtons(true);
        managersDataTab->setDocumentMode(false);
        managersDataTab->setTabsClosable(false);
        managersDataTab->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        name = new QLineEdit(tab);
        name->setObjectName(QStringLiteral("name"));
        name->setEnabled(false);
        name->setDragEnabled(false);
        name->setReadOnly(false);

        horizontalLayout_3->addWidget(name);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        familia = new QLineEdit(tab);
        familia->setObjectName(QStringLiteral("familia"));
        familia->setEnabled(false);

        horizontalLayout_4->addWidget(familia);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        otchestvo = new QLineEdit(tab);
        otchestvo->setObjectName(QStringLiteral("otchestvo"));
        otchestvo->setEnabled(false);

        horizontalLayout_5->addWidget(otchestvo);


        gridLayout->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        dateOfBirth = new QDateEdit(tab);
        dateOfBirth->setObjectName(QStringLiteral("dateOfBirth"));
        dateOfBirth->setEnabled(false);
        dateOfBirth->setWrapping(false);
        dateOfBirth->setFrame(true);
        dateOfBirth->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateOfBirth->setKeyboardTracking(true);
        dateOfBirth->setProperty("showGroupSeparator", QVariant(false));
        dateOfBirth->setMinimumDate(QDate(1900, 9, 14));
        dateOfBirth->setCalendarPopup(true);

        horizontalLayout->addWidget(dateOfBirth);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        sexGroup = new QGroupBox(tab);
        sexGroup->setObjectName(QStringLiteral("sexGroup"));
        sexGroup->setEnabled(false);
        sexGroup->setAutoFillBackground(false);
        sexGroup->setFlat(false);
        sexGroup->setCheckable(false);
        horizontalLayout_2 = new QHBoxLayout(sexGroup);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        maleRButton = new QRadioButton(sexGroup);
        maleRButton->setObjectName(QStringLiteral("maleRButton"));

        horizontalLayout_2->addWidget(maleRButton);

        femaleRButton = new QRadioButton(sexGroup);
        femaleRButton->setObjectName(QStringLiteral("femaleRButton"));
        femaleRButton->setEnabled(false);

        horizontalLayout_2->addWidget(femaleRButton);


        gridLayout->addWidget(sexGroup, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        seria = new QSpinBox(tab);
        seria->setObjectName(QStringLiteral("seria"));
        seria->setEnabled(false);
        seria->setMinimum(1000);
        seria->setMaximum(9999);

        horizontalLayout_6->addWidget(seria);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_6->addWidget(label_12);

        number = new QSpinBox(tab);
        number->setObjectName(QStringLiteral("number"));
        number->setEnabled(false);
        number->setMinimum(100000);
        number->setMaximum(999999);

        horizontalLayout_6->addWidget(number);


        gridLayout->addLayout(horizontalLayout_6, 5, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_7->addWidget(label_11);

        pasport = new QLineEdit(tab);
        pasport->setObjectName(QStringLiteral("pasport"));
        pasport->setEnabled(false);

        horizontalLayout_7->addWidget(pasport);


        gridLayout->addLayout(horizontalLayout_7, 6, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_8->addWidget(label_9);

        datePasport = new QDateEdit(tab);
        datePasport->setObjectName(QStringLiteral("datePasport"));
        datePasport->setEnabled(false);
        datePasport->setWrapping(false);
        datePasport->setFrame(true);
        datePasport->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        datePasport->setKeyboardTracking(true);
        datePasport->setProperty("showGroupSeparator", QVariant(false));
        datePasport->setMinimumDate(QDate(1900, 9, 14));
        datePasport->setCalendarPopup(true);

        horizontalLayout_8->addWidget(datePasport);


        gridLayout->addLayout(horizontalLayout_8, 7, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_9->addWidget(label_10);

        propiska = new QLineEdit(tab);
        propiska->setObjectName(QStringLiteral("propiska"));
        propiska->setEnabled(false);

        horizontalLayout_9->addWidget(propiska);


        gridLayout->addLayout(horizontalLayout_9, 8, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_10->addWidget(label_13);

        INN = new QLineEdit(tab);
        INN->setObjectName(QStringLiteral("INN"));
        INN->setEnabled(false);

        horizontalLayout_10->addWidget(INN);


        gridLayout->addLayout(horizontalLayout_10, 9, 0, 1, 1);

        managersDataTab->addTab(tab, QString());
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        name->raise();
        familia->raise();
        otchestvo->raise();
        dateOfBirth->raise();
        label_6->raise();
        sexGroup->raise();
        sexGroup->raise();
        sexGroup->raise();
        seria->raise();
        label_12->raise();
        number->raise();
        pasport->raise();
        datePasport->raise();
        propiska->raise();
        label_13->raise();
        INN->raise();
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        gridLayout_2 = new QGridLayout(tab_1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_7 = new QLabel(tab_1);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        login = new QLineEdit(tab_1);
        login->setObjectName(QStringLiteral("login"));
        login->setEnabled(false);

        gridLayout_2->addWidget(login, 0, 1, 1, 1);

        label_14 = new QLabel(tab_1);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_2->addWidget(label_14, 1, 0, 1, 1);

        password = new QLineEdit(tab_1);
        password->setObjectName(QStringLiteral("password"));
        password->setEnabled(false);

        gridLayout_2->addWidget(password, 1, 1, 1, 1);

        managersDataTab->addTab(tab_1, QString());

        verticalLayout->addWidget(managersDataTab);

        stackedWidget = new QStackedWidget(tabManagers);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setMinimumSize(QSize(311, 41));
        stackedWidget->setFrameShape(QFrame::NoFrame);
        stackedWidget->setFrameShadow(QFrame::Raised);
        stackedWidget->setMidLineWidth(1);
        page1 = new QWidget();
        page1->setObjectName(QStringLiteral("page1"));
        horizontalLayout_11 = new QHBoxLayout(page1);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        changeManagerButton = new QPushButton(page1);
        changeManagerButton->setObjectName(QStringLiteral("changeManagerButton"));

        horizontalLayout_11->addWidget(changeManagerButton);

        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QStringLiteral("page2"));
        horizontalLayout_12 = new QHBoxLayout(page2);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        cancelManagerButton = new QPushButton(page2);
        cancelManagerButton->setObjectName(QStringLiteral("cancelManagerButton"));

        horizontalLayout_12->addWidget(cancelManagerButton);

        saveManagerButton = new QPushButton(page2);
        saveManagerButton->setObjectName(QStringLiteral("saveManagerButton"));

        horizontalLayout_12->addWidget(saveManagerButton);

        stackedWidget->addWidget(page2);

        verticalLayout->addWidget(stackedWidget);


        gridLayout_3->addLayout(verticalLayout, 0, 1, 1, 1);

        tabWidget->addTab(tabManagers, QString());
        label->raise();
        label_2->raise();
        managersTable->raise();
        managersDataTab->raise();
        stackedWidget->raise();
        stackedWidget->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        horizontalLayout_19 = new QHBoxLayout(tab_4);
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_15 = new QLabel(tab_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_4->addWidget(label_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        lineEdit = new QLineEdit(tab_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setClearButtonEnabled(false);

        horizontalLayout_14->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_14);

        tableView = new QTableView(tab_4);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_4->addWidget(tableView);

        newProductButton = new QPushButton(tab_4);
        newProductButton->setObjectName(QStringLiteral("newProductButton"));

        verticalLayout_4->addWidget(newProductButton);


        horizontalLayout_19->addLayout(verticalLayout_4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_16 = new QLabel(tab_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        gridLayout_5->addWidget(label_16, 0, 0, 1, 1);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_17 = new QLabel(tab_4);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_18->addWidget(label_17);

        productName = new QLineEdit(tab_4);
        productName->setObjectName(QStringLiteral("productName"));
        productName->setEnabled(false);
        productName->setClearButtonEnabled(false);

        horizontalLayout_18->addWidget(productName);


        gridLayout_5->addLayout(horizontalLayout_18, 1, 0, 1, 1);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_18 = new QLabel(tab_4);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_17->addWidget(label_18);

        productPercent = new QLineEdit(tab_4);
        productPercent->setObjectName(QStringLiteral("productPercent"));
        productPercent->setEnabled(false);
        productPercent->setClearButtonEnabled(false);

        horizontalLayout_17->addWidget(productPercent);


        gridLayout_5->addLayout(horizontalLayout_17, 2, 0, 1, 1);

        stackedWidget_2 = new QStackedWidget(tab_4);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        page_1 = new QWidget();
        page_1->setObjectName(QStringLiteral("page_1"));
        horizontalLayout_15 = new QHBoxLayout(page_1);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        deleteProductButton = new QPushButton(page_1);
        deleteProductButton->setObjectName(QStringLiteral("deleteProductButton"));

        horizontalLayout_15->addWidget(deleteProductButton);

        changeProductButton = new QPushButton(page_1);
        changeProductButton->setObjectName(QStringLiteral("changeProductButton"));

        horizontalLayout_15->addWidget(changeProductButton);

        stackedWidget_2->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        horizontalLayout_16 = new QHBoxLayout(page_2);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        cancelProductButton = new QPushButton(page_2);
        cancelProductButton->setObjectName(QStringLiteral("cancelProductButton"));

        horizontalLayout_16->addWidget(cancelProductButton);

        saveProductButton = new QPushButton(page_2);
        saveProductButton->setObjectName(QStringLiteral("saveProductButton"));

        horizontalLayout_16->addWidget(saveProductButton);

        stackedWidget_2->addWidget(page_2);

        gridLayout_5->addWidget(stackedWidget_2, 3, 0, 1, 1);


        horizontalLayout_19->addLayout(gridLayout_5);

        tabWidget->addTab(tab_4, QString());
        label_15->raise();
        label_16->raise();
        lineEdit->raise();
        tableView->raise();
        newProductButton->raise();
        stackedWidget_2->raise();
        label_17->raise();
        label_18->raise();
        productName->raise();
        productPercent->raise();
        newProductButton->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tabWidget->addTab(tab_7, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tabWidget->addTab(tab_6, QString());

        verticalLayout_3->addWidget(tabWidget);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setStyleSheet(QStringLiteral("QPushButton { background-color: rgb(255, 0, 0); color: rgb(255, 255, 255); }"));

        horizontalLayout_13->addWidget(quitButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_13);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 899, 21));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        tabWidget->setCurrentIndex(0);
        managersDataTab->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270</span></p></body></html>", 0));
        newManagerButton->setText(QApplication::translate("MainWindowClass", "\320\235\320\260\320\275\321\217\321\202\321\214 \320\274\320\265\320\275\320\265\320\264\320\266\320\265\321\200\320\260", 0));
        label_2->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\224\320\260\320\275\320\275\321\213\320\265</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindowClass", "\320\230\320\274\321\217", 0));
        label_4->setText(QApplication::translate("MainWindowClass", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", 0));
        label_5->setText(QApplication::translate("MainWindowClass", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", 0));
        label_6->setText(QApplication::translate("MainWindowClass", "\320\224\320\260\321\202\320\260 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", 0));
        sexGroup->setTitle(QApplication::translate("MainWindowClass", "\320\237\320\276\320\273", 0));
        maleRButton->setText(QApplication::translate("MainWindowClass", "\320\274\321\203\320\266\321\201\320\272\320\276\320\271", 0));
        femaleRButton->setText(QApplication::translate("MainWindowClass", "\320\266\320\265\320\275\321\201\320\272\320\270\320\271", 0));
        label_8->setText(QApplication::translate("MainWindowClass", "\320\241\320\265\321\200\320\270\321\217 \320\277\320\260\321\201\320\277\320\276\321\200\321\202\320\260", 0));
        label_12->setText(QApplication::translate("MainWindowClass", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\260\321\201\320\277\320\276\321\200\321\202\320\260", 0));
        label_11->setText(QApplication::translate("MainWindowClass", "\320\237\320\260\321\201\320\277\320\276\321\200\321\202 \320\262\321\213\320\264\320\260\320\275", 0));
        label_9->setText(QApplication::translate("MainWindowClass", "\320\224\320\260\321\202\320\260 \320\262\321\213\320\264\320\260\321\207\320\270", 0));
        label_10->setText(QApplication::translate("MainWindowClass", "\320\237\321\200\320\276\320\277\320\270\321\201\320\272\320\260", 0));
        label_13->setText(QApplication::translate("MainWindowClass", "\320\230\320\235\320\235", 0));
        managersDataTab->setTabText(managersDataTab->indexOf(tab), QApplication::translate("MainWindowClass", "\320\233\320\270\321\207\320\275\321\213\320\265", 0));
        label_7->setText(QApplication::translate("MainWindowClass", "\320\233\320\276\320\263\320\270\320\275", 0));
        label_14->setText(QApplication::translate("MainWindowClass", "\320\237\320\260\321\200\320\276\320\273\321\214", 0));
        managersDataTab->setTabText(managersDataTab->indexOf(tab_1), QApplication::translate("MainWindowClass", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", 0));
        changeManagerButton->setText(QApplication::translate("MainWindowClass", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        cancelManagerButton->setText(QApplication::translate("MainWindowClass", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        saveManagerButton->setText(QApplication::translate("MainWindowClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabManagers), QApplication::translate("MainWindowClass", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", 0));
        label_15->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\242\320\276\320\262\320\260\321\200\321\213</span></p></body></html>", 0));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        newProductButton->setText(QApplication::translate("MainWindowClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        label_16->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\224\320\260\320\275\320\275\321\213\320\265</span></p></body></html>", 0));
        label_17->setText(QApplication::translate("MainWindowClass", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        productName->setInputMask(QString());
        productName->setText(QString());
        label_18->setText(QApplication::translate("MainWindowClass", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202 \320\272\320\276\320\274\320\270\321\201\321\201\320\270\320\270", 0));
        productPercent->setInputMask(QString());
        productPercent->setText(QString());
        deleteProductButton->setText(QApplication::translate("MainWindowClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        changeProductButton->setText(QApplication::translate("MainWindowClass", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        cancelProductButton->setText(QApplication::translate("MainWindowClass", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        saveProductButton->setText(QApplication::translate("MainWindowClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindowClass", "\320\242\320\276\320\262\320\260\321\200\321\213", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindowClass", "\320\232\320\276\321\200\321\200\320\265\320\272\321\202\320\270\321\200\320\276\320\262\320\272\320\270", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindowClass", "\320\237\321\200\320\276\320\264\320\260\320\266\320\270", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindowClass", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindowClass", "\320\227\320\260\321\200\320\277\320\273\320\260\321\202\320\260", 0));
        quitButton->setText(QApplication::translate("MainWindowClass", "\320\222\321\213\320\271\321\202\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
