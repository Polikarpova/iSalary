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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
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
#include <QtWidgets/QScrollArea>
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
    QHBoxLayout *horizontalLayout_17;
    QStackedWidget *auth_program_stackedWidget;
    QWidget *enter;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_19;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_21;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_3;
    QLineEdit *passwordInput;
    QLineEdit *loginInput;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *errorLabel;
    QPushButton *enterButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QWidget *main;
    QVBoxLayout *verticalLayout_6;
    QStackedWidget *boss_manager_stackedWidget;
    QWidget *owner;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tabManagers;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTableView *managersTable;
    QPushButton *addManagerButton;
    QSpacerItem *verticalSpacer_12;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_2;
    QTabWidget *managersDataTab;
    QWidget *personalDataTab;
    QVBoxLayout *verticalLayout_20;
    QFormLayout *formLayout_4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *firstName;
    QLineEdit *secondName;
    QLineEdit *thirdName;
    QDateEdit *dateOfBirth;
    QGroupBox *sexGroup;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *maleRButton;
    QRadioButton *femaleRButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QSpinBox *pasportSeries;
    QLabel *label_12;
    QSpinBox *pasportNumber;
    QFormLayout *formLayout_3;
    QLabel *label_11;
    QLineEdit *pasportSourse;
    QLabel *label_9;
    QDateEdit *dateOfReceipt;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *registration;
    QLabel *label_13;
    QLineEdit *INN;
    QWidget *accountDataTab;
    QFormLayout *formLayout_5;
    QLabel *label_7;
    QLineEdit *login;
    QLabel *label_14;
    QLineEdit *password;
    QSpacerItem *verticalSpacer_11;
    QSpacerItem *verticalSpacer_8;
    QStackedWidget *managersButtonsStackedWidget;
    QWidget *editManagerTab;
    QVBoxLayout *verticalLayout_22;
    QPushButton *managerEditButton;
    QWidget *saveOrCancelTab;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *cancelManagerButton;
    QPushButton *saveManagerButton;
    QWidget *submitOrCancelAddingTab;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *managerCancelAddButton;
    QPushButton *managerSubmitAddButton;
    QWidget *tabProducts;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_14;
    QLineEdit *productSearch;
    QPushButton *searchButton;
    QSpacerItem *horizontalSpacer_2;
    QTableView *productTable;
    QPushButton *addProductButton;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_16;
    QFormLayout *formLayout_6;
    QLabel *label_17;
    QLineEdit *productName;
    QLabel *label_18;
    QDoubleSpinBox *productPercent;
    QSpacerItem *verticalSpacer_10;
    QStackedWidget *productButtonsStackedWidget;
    QWidget *editCurrentProductTab;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *deleteProductButton;
    QPushButton *editProductButton;
    QWidget *saveCurrentProductTab;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *cancelProductButton;
    QPushButton *saveProductButton;
    QWidget *addNewProduxtTab;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *productCancelAddButton;
    QPushButton *productSubmitAddButton;
    QWidget *tabCorrection;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_32;
    QLabel *label_33;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_34;
    QComboBox *accountingPeriodComboBox;
    QSpacerItem *horizontalSpacer_6;
    QTableView *saleForCorrectionTable;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_35;
    QFormLayout *formLayout_7;
    QLabel *label_36;
    QComboBox *correctionSalerComboBox;
    QLabel *label_37;
    QComboBox *correctionProductComboBox;
    QLabel *label_38;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *correctionPrice;
    QLabel *label_39;
    QLabel *label_40;
    QSpinBox *correctionProductsCount;
    QLabel *label_41;
    QHBoxLayout *horizontalLayout_6;
    QDoubleSpinBox *correctionPercent;
    QLabel *label_42;
    QLabel *label_43;
    QDateEdit *correctionDateOfSale;
    QHBoxLayout *horizontalLayout_32;
    QPushButton *correctionDeleteOrRestoreButton;
    QPushButton *addCorrectionButton;
    QLabel *label_44;
    QScrollArea *correctionHistoryList;
    QWidget *scrollAreaWidgetContents;
    QWidget *tabSales;
    QHBoxLayout *horizontalLayout_35;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_46;
    QHBoxLayout *horizontalLayout_34;
    QLabel *label_45;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_6;
    QDateEdit *salesDateInput;
    QTableView *managersSalesTable;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_48;
    QLabel *label_47;
    QTableView *unconfirmedSalesTable;
    QLabel *label_49;
    QTableView *confirmedSalesTable;
    QWidget *tabStatistic;
    QHBoxLayout *horizontalLayout_37;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_50;
    QHBoxLayout *horizontalLayout_36;
    QLabel *label_51;
    QDateEdit *statisticStartPeriod;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_52;
    QDateEdit *statisticEndPeriod;
    QTableView *statisticTable;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_55;
    QLabel *label_53;
    QTableView *statisticSalesTable;
    QLabel *label_54;
    QCalendarWidget *statisticCalendar;
    QWidget *tabSalary;
    QHBoxLayout *horizontalLayout_18;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_57;
    QHBoxLayout *horizontalLayout_38;
    QLabel *label_56;
    QComboBox *salaryAccountingPeriod;
    QSpacerItem *horizontalSpacer_8;
    QTableView *salaryTable;
    QTableView *salaryTotalTable;
    QPushButton *closeAccountingPeriod;
    QVBoxLayout *verticalLayout_26;
    QLabel *label_58;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_65;
    QLabel *managerFIOLabel;
    QHBoxLayout *horizontalLayout_43;
    QLabel *label_62;
    QSpinBox *salaryPasportSeries;
    QLabel *label_63;
    QSpinBox *salaryPasportNumber;
    QFormLayout *formLayout_10;
    QLineEdit *salaryPasportSourse;
    QLabel *label_60;
    QDateEdit *salaryDateOfReceipt;
    QLabel *label_61;
    QGroupBox *salarySexGroup;
    QHBoxLayout *horizontalLayout_41;
    QRadioButton *salaryMaleRButton;
    QRadioButton *salaryFemaleRButton;
    QFormLayout *formLayout_11;
    QLineEdit *salaryINN;
    QLabel *label_59;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_44;
    QPushButton *salesButton;
    QPushButton *dataButton;
    QWidget *manager;
    QHBoxLayout *horizontalLayout_24;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_24;
    QSpacerItem *verticalSpacer_9;
    QLineEdit *currentSalary;
    QLabel *label_64;
    QLabel *label_25;
    QLabel *label_26;
    QGridLayout *gridLayout_6;
    QLabel *label_27;
    QComboBox *productComboBox;
    QLabel *label_28;
    QSpinBox *priceInput;
    QLabel *label_29;
    QSpinBox *countInput;
    QLabel *label_30;
    QTableView *confirmedSales;
    QLabel *label_31;
    QTableView *unconfirmedSales;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_23;
    QHBoxLayout *horizontalLayout_22;
    QLineEdit *productSearch_2;
    QPushButton *managerProductSearchButton;
    QSpacerItem *horizontalSpacer_5;
    QTableView *managersProductTable;
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
        MainWindowClass->resize(814, 620);
        MainWindowClass->setStyleSheet(QStringLiteral("QMainWindow {background-color: white}"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_17 = new QHBoxLayout(centralWidget);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        auth_program_stackedWidget = new QStackedWidget(centralWidget);
        auth_program_stackedWidget->setObjectName(QStringLiteral("auth_program_stackedWidget"));
        enter = new QWidget();
        enter->setObjectName(QStringLiteral("enter"));
        verticalLayout_8 = new QVBoxLayout(enter);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        label_19 = new QLabel(enter);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setStyleSheet(QStringLiteral(""));

        verticalLayout_7->addWidget(label_19);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_7->addItem(verticalSpacer_3);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        passwordInput = new QLineEdit(enter);
        passwordInput->setObjectName(QStringLiteral("passwordInput"));

        gridLayout_3->addWidget(passwordInput, 3, 0, 1, 1);

        loginInput = new QLineEdit(enter);
        loginInput->setObjectName(QStringLiteral("loginInput"));

        gridLayout_3->addWidget(loginInput, 1, 0, 1, 1);

        label_20 = new QLabel(enter);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_3->addWidget(label_20, 0, 0, 1, 1);

        label_21 = new QLabel(enter);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_3->addWidget(label_21, 2, 0, 1, 1);

        errorLabel = new QLabel(enter);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setStyleSheet(QStringLiteral("QLabel {color: red}"));

        gridLayout_3->addWidget(errorLabel, 4, 0, 1, 1);

        enterButton = new QPushButton(enter);
        enterButton->setObjectName(QStringLiteral("enterButton"));

        gridLayout_3->addWidget(enterButton, 5, 0, 1, 1);


        horizontalLayout_21->addLayout(gridLayout_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_4);


        verticalLayout_7->addLayout(horizontalLayout_21);

        verticalSpacer = new QSpacerItem(20, 218, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_7->addItem(verticalSpacer);


        verticalLayout_8->addLayout(verticalLayout_7);

        auth_program_stackedWidget->addWidget(enter);
        main = new QWidget();
        main->setObjectName(QStringLiteral("main"));
        verticalLayout_6 = new QVBoxLayout(main);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        boss_manager_stackedWidget = new QStackedWidget(main);
        boss_manager_stackedWidget->setObjectName(QStringLiteral("boss_manager_stackedWidget"));
        owner = new QWidget();
        owner->setObjectName(QStringLiteral("owner"));
        verticalLayout_5 = new QVBoxLayout(owner);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tabWidget = new QTabWidget(owner);
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
        horizontalLayout_3 = new QHBoxLayout(tabManagers);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
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

        addManagerButton = new QPushButton(tabManagers);
        addManagerButton->setObjectName(QStringLiteral("addManagerButton"));

        verticalLayout_2->addWidget(addManagerButton);

        verticalSpacer_12 = new QSpacerItem(20, 9, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_12);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        label_2 = new QLabel(tabManagers);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_21->addWidget(label_2);

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
        personalDataTab = new QWidget();
        personalDataTab->setObjectName(QStringLiteral("personalDataTab"));
        verticalLayout_20 = new QVBoxLayout(personalDataTab);
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setContentsMargins(11, 11, 11, 11);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_3 = new QLabel(personalDataTab);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(personalDataTab);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(personalDataTab);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(personalDataTab);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_6);

        firstName = new QLineEdit(personalDataTab);
        firstName->setObjectName(QStringLiteral("firstName"));
        firstName->setEnabled(false);
        firstName->setDragEnabled(false);
        firstName->setReadOnly(false);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, firstName);

        secondName = new QLineEdit(personalDataTab);
        secondName->setObjectName(QStringLiteral("secondName"));
        secondName->setEnabled(false);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, secondName);

        thirdName = new QLineEdit(personalDataTab);
        thirdName->setObjectName(QStringLiteral("thirdName"));
        thirdName->setEnabled(false);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, thirdName);

        dateOfBirth = new QDateEdit(personalDataTab);
        dateOfBirth->setObjectName(QStringLiteral("dateOfBirth"));
        dateOfBirth->setEnabled(false);
        dateOfBirth->setWrapping(false);
        dateOfBirth->setFrame(true);
        dateOfBirth->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateOfBirth->setKeyboardTracking(true);
        dateOfBirth->setProperty("showGroupSeparator", QVariant(false));
        dateOfBirth->setMinimumDate(QDate(1900, 9, 14));
        dateOfBirth->setCalendarPopup(true);

        formLayout_4->setWidget(3, QFormLayout::FieldRole, dateOfBirth);


        verticalLayout_20->addLayout(formLayout_4);

        sexGroup = new QGroupBox(personalDataTab);
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


        verticalLayout_20->addWidget(sexGroup);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_8 = new QLabel(personalDataTab);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout->addWidget(label_8);

        pasportSeries = new QSpinBox(personalDataTab);
        pasportSeries->setObjectName(QStringLiteral("pasportSeries"));
        pasportSeries->setEnabled(false);
        pasportSeries->setMinimum(1000);
        pasportSeries->setMaximum(9999);

        horizontalLayout->addWidget(pasportSeries);

        label_12 = new QLabel(personalDataTab);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout->addWidget(label_12);

        pasportNumber = new QSpinBox(personalDataTab);
        pasportNumber->setObjectName(QStringLiteral("pasportNumber"));
        pasportNumber->setEnabled(false);
        pasportNumber->setMinimum(100000);
        pasportNumber->setMaximum(999999);

        horizontalLayout->addWidget(pasportNumber);


        verticalLayout_20->addLayout(horizontalLayout);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_11 = new QLabel(personalDataTab);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_11);

        pasportSourse = new QLineEdit(personalDataTab);
        pasportSourse->setObjectName(QStringLiteral("pasportSourse"));
        pasportSourse->setEnabled(false);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, pasportSourse);

        label_9 = new QLabel(personalDataTab);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_9);

        dateOfReceipt = new QDateEdit(personalDataTab);
        dateOfReceipt->setObjectName(QStringLiteral("dateOfReceipt"));
        dateOfReceipt->setEnabled(false);
        dateOfReceipt->setWrapping(false);
        dateOfReceipt->setFrame(true);
        dateOfReceipt->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateOfReceipt->setKeyboardTracking(true);
        dateOfReceipt->setProperty("showGroupSeparator", QVariant(false));
        dateOfReceipt->setMinimumDate(QDate(1900, 9, 14));
        dateOfReceipt->setCalendarPopup(true);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, dateOfReceipt);

        label_10 = new QLabel(personalDataTab);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        registration = new QLineEdit(personalDataTab);
        registration->setObjectName(QStringLiteral("registration"));
        registration->setEnabled(false);

        horizontalLayout_9->addWidget(registration);


        formLayout_3->setLayout(2, QFormLayout::FieldRole, horizontalLayout_9);

        label_13 = new QLabel(personalDataTab);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_13);

        INN = new QLineEdit(personalDataTab);
        INN->setObjectName(QStringLiteral("INN"));
        INN->setEnabled(false);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, INN);


        verticalLayout_20->addLayout(formLayout_3);

        managersDataTab->addTab(personalDataTab, QString());
        accountDataTab = new QWidget();
        accountDataTab->setObjectName(QStringLiteral("accountDataTab"));
        formLayout_5 = new QFormLayout(accountDataTab);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        label_7 = new QLabel(accountDataTab);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_7);

        login = new QLineEdit(accountDataTab);
        login->setObjectName(QStringLiteral("login"));
        login->setEnabled(false);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, login);

        label_14 = new QLabel(accountDataTab);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_14);

        password = new QLineEdit(accountDataTab);
        password->setObjectName(QStringLiteral("password"));
        password->setEnabled(false);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, password);

        managersDataTab->addTab(accountDataTab, QString());

        verticalLayout_21->addWidget(managersDataTab);

        verticalSpacer_11 = new QSpacerItem(20, 1000, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_21->addItem(verticalSpacer_11);

        verticalSpacer_8 = new QSpacerItem(16, 1, QSizePolicy::Minimum, QSizePolicy::Ignored);

        verticalLayout_21->addItem(verticalSpacer_8);

        managersButtonsStackedWidget = new QStackedWidget(tabManagers);
        managersButtonsStackedWidget->setObjectName(QStringLiteral("managersButtonsStackedWidget"));
        managersButtonsStackedWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(managersButtonsStackedWidget->sizePolicy().hasHeightForWidth());
        managersButtonsStackedWidget->setSizePolicy(sizePolicy);
        managersButtonsStackedWidget->setMinimumSize(QSize(311, 41));
        managersButtonsStackedWidget->setAcceptDrops(false);
        managersButtonsStackedWidget->setStyleSheet(QStringLiteral(""));
        managersButtonsStackedWidget->setFrameShape(QFrame::NoFrame);
        managersButtonsStackedWidget->setFrameShadow(QFrame::Raised);
        managersButtonsStackedWidget->setMidLineWidth(1);
        editManagerTab = new QWidget();
        editManagerTab->setObjectName(QStringLiteral("editManagerTab"));
        verticalLayout_22 = new QVBoxLayout(editManagerTab);
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setContentsMargins(11, 11, 11, 11);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        managerEditButton = new QPushButton(editManagerTab);
        managerEditButton->setObjectName(QStringLiteral("managerEditButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(managerEditButton->sizePolicy().hasHeightForWidth());
        managerEditButton->setSizePolicy(sizePolicy1);
        managerEditButton->setMinimumSize(QSize(0, 22));
        managerEditButton->setStyleSheet(QStringLiteral(""));

        verticalLayout_22->addWidget(managerEditButton);

        managersButtonsStackedWidget->addWidget(editManagerTab);
        saveOrCancelTab = new QWidget();
        saveOrCancelTab->setObjectName(QStringLiteral("saveOrCancelTab"));
        horizontalLayout_12 = new QHBoxLayout(saveOrCancelTab);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        cancelManagerButton = new QPushButton(saveOrCancelTab);
        cancelManagerButton->setObjectName(QStringLiteral("cancelManagerButton"));

        horizontalLayout_12->addWidget(cancelManagerButton);

        saveManagerButton = new QPushButton(saveOrCancelTab);
        saveManagerButton->setObjectName(QStringLiteral("saveManagerButton"));

        horizontalLayout_12->addWidget(saveManagerButton);

        managersButtonsStackedWidget->addWidget(saveOrCancelTab);
        submitOrCancelAddingTab = new QWidget();
        submitOrCancelAddingTab->setObjectName(QStringLiteral("submitOrCancelAddingTab"));
        horizontalLayout_11 = new QHBoxLayout(submitOrCancelAddingTab);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        managerCancelAddButton = new QPushButton(submitOrCancelAddingTab);
        managerCancelAddButton->setObjectName(QStringLiteral("managerCancelAddButton"));

        horizontalLayout_11->addWidget(managerCancelAddButton);

        managerSubmitAddButton = new QPushButton(submitOrCancelAddingTab);
        managerSubmitAddButton->setObjectName(QStringLiteral("managerSubmitAddButton"));

        horizontalLayout_11->addWidget(managerSubmitAddButton);

        managersButtonsStackedWidget->addWidget(submitOrCancelAddingTab);

        verticalLayout_21->addWidget(managersButtonsStackedWidget);


        horizontalLayout_3->addLayout(verticalLayout_21);

        tabWidget->addTab(tabManagers, QString());
        tabProducts = new QWidget();
        tabProducts->setObjectName(QStringLiteral("tabProducts"));
        horizontalLayout_4 = new QHBoxLayout(tabProducts);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_15 = new QLabel(tabProducts);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_4->addWidget(label_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        productSearch = new QLineEdit(tabProducts);
        productSearch->setObjectName(QStringLiteral("productSearch"));
        productSearch->setClearButtonEnabled(false);

        horizontalLayout_14->addWidget(productSearch);

        searchButton = new QPushButton(tabProducts);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MainWindow/img/searchIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchButton->setIcon(icon);

        horizontalLayout_14->addWidget(searchButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_14);

        productTable = new QTableView(tabProducts);
        productTable->setObjectName(QStringLiteral("productTable"));

        verticalLayout_4->addWidget(productTable);

        addProductButton = new QPushButton(tabProducts);
        addProductButton->setObjectName(QStringLiteral("addProductButton"));

        verticalLayout_4->addWidget(addProductButton);

        verticalSpacer_4 = new QSpacerItem(20, 9, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer_4);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        label_16 = new QLabel(tabProducts);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_23->addWidget(label_16);

        formLayout_6 = new QFormLayout();
        formLayout_6->setSpacing(6);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        label_17 = new QLabel(tabProducts);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_17);

        productName = new QLineEdit(tabProducts);
        productName->setObjectName(QStringLiteral("productName"));
        productName->setEnabled(false);
        productName->setClearButtonEnabled(false);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, productName);

        label_18 = new QLabel(tabProducts);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label_18);

        productPercent = new QDoubleSpinBox(tabProducts);
        productPercent->setObjectName(QStringLiteral("productPercent"));
        productPercent->setEnabled(false);
        productPercent->setMaximum(100);

        formLayout_6->setWidget(1, QFormLayout::FieldRole, productPercent);


        verticalLayout_23->addLayout(formLayout_6);

        verticalSpacer_10 = new QSpacerItem(20, 1000, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_23->addItem(verticalSpacer_10);

        productButtonsStackedWidget = new QStackedWidget(tabProducts);
        productButtonsStackedWidget->setObjectName(QStringLiteral("productButtonsStackedWidget"));
        editCurrentProductTab = new QWidget();
        editCurrentProductTab->setObjectName(QStringLiteral("editCurrentProductTab"));
        horizontalLayout_15 = new QHBoxLayout(editCurrentProductTab);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        deleteProductButton = new QPushButton(editCurrentProductTab);
        deleteProductButton->setObjectName(QStringLiteral("deleteProductButton"));

        horizontalLayout_15->addWidget(deleteProductButton);

        editProductButton = new QPushButton(editCurrentProductTab);
        editProductButton->setObjectName(QStringLiteral("editProductButton"));

        horizontalLayout_15->addWidget(editProductButton);

        productButtonsStackedWidget->addWidget(editCurrentProductTab);
        saveCurrentProductTab = new QWidget();
        saveCurrentProductTab->setObjectName(QStringLiteral("saveCurrentProductTab"));
        horizontalLayout_16 = new QHBoxLayout(saveCurrentProductTab);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        cancelProductButton = new QPushButton(saveCurrentProductTab);
        cancelProductButton->setObjectName(QStringLiteral("cancelProductButton"));

        horizontalLayout_16->addWidget(cancelProductButton);

        saveProductButton = new QPushButton(saveCurrentProductTab);
        saveProductButton->setObjectName(QStringLiteral("saveProductButton"));

        horizontalLayout_16->addWidget(saveProductButton);

        productButtonsStackedWidget->addWidget(saveCurrentProductTab);
        addNewProduxtTab = new QWidget();
        addNewProduxtTab->setObjectName(QStringLiteral("addNewProduxtTab"));
        horizontalLayout_8 = new QHBoxLayout(addNewProduxtTab);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        productCancelAddButton = new QPushButton(addNewProduxtTab);
        productCancelAddButton->setObjectName(QStringLiteral("productCancelAddButton"));

        horizontalLayout_8->addWidget(productCancelAddButton);

        productSubmitAddButton = new QPushButton(addNewProduxtTab);
        productSubmitAddButton->setObjectName(QStringLiteral("productSubmitAddButton"));

        horizontalLayout_8->addWidget(productSubmitAddButton);

        productButtonsStackedWidget->addWidget(addNewProduxtTab);

        verticalLayout_23->addWidget(productButtonsStackedWidget);


        horizontalLayout_4->addLayout(verticalLayout_23);

        tabWidget->addTab(tabProducts, QString());
        tabCorrection = new QWidget();
        tabCorrection->setObjectName(QStringLiteral("tabCorrection"));
        horizontalLayout_7 = new QHBoxLayout(tabCorrection);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_32 = new QLabel(tabCorrection);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_11->addWidget(label_32);

        label_33 = new QLabel(tabCorrection);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_11->addWidget(label_33);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        label_34 = new QLabel(tabCorrection);
        label_34->setObjectName(QStringLiteral("label_34"));

        horizontalLayout_25->addWidget(label_34);

        accountingPeriodComboBox = new QComboBox(tabCorrection);
        accountingPeriodComboBox->setObjectName(QStringLiteral("accountingPeriodComboBox"));

        horizontalLayout_25->addWidget(accountingPeriodComboBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_6);


        verticalLayout_11->addLayout(horizontalLayout_25);

        saleForCorrectionTable = new QTableView(tabCorrection);
        saleForCorrectionTable->setObjectName(QStringLiteral("saleForCorrectionTable"));
        saleForCorrectionTable->setShowGrid(true);
        saleForCorrectionTable->horizontalHeader()->setCascadingSectionResizes(false);

        verticalLayout_11->addWidget(saleForCorrectionTable);


        horizontalLayout_7->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_35 = new QLabel(tabCorrection);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_12->addWidget(label_35);

        formLayout_7 = new QFormLayout();
        formLayout_7->setSpacing(6);
        formLayout_7->setObjectName(QStringLiteral("formLayout_7"));
        label_36 = new QLabel(tabCorrection);
        label_36->setObjectName(QStringLiteral("label_36"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_36);

        correctionSalerComboBox = new QComboBox(tabCorrection);
        correctionSalerComboBox->setObjectName(QStringLiteral("correctionSalerComboBox"));

        formLayout_7->setWidget(0, QFormLayout::FieldRole, correctionSalerComboBox);

        label_37 = new QLabel(tabCorrection);
        label_37->setObjectName(QStringLiteral("label_37"));

        formLayout_7->setWidget(1, QFormLayout::LabelRole, label_37);

        correctionProductComboBox = new QComboBox(tabCorrection);
        correctionProductComboBox->setObjectName(QStringLiteral("correctionProductComboBox"));

        formLayout_7->setWidget(1, QFormLayout::FieldRole, correctionProductComboBox);

        label_38 = new QLabel(tabCorrection);
        label_38->setObjectName(QStringLiteral("label_38"));

        formLayout_7->setWidget(2, QFormLayout::LabelRole, label_38);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        correctionPrice = new QSpinBox(tabCorrection);
        correctionPrice->setObjectName(QStringLiteral("correctionPrice"));
        correctionPrice->setMinimum(1);
        correctionPrice->setMaximum(99999999);

        horizontalLayout_5->addWidget(correctionPrice);

        label_39 = new QLabel(tabCorrection);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setMinimumSize(QSize(21, 18));
        label_39->setMaximumSize(QSize(21, 18));

        horizontalLayout_5->addWidget(label_39);


        formLayout_7->setLayout(2, QFormLayout::FieldRole, horizontalLayout_5);

        label_40 = new QLabel(tabCorrection);
        label_40->setObjectName(QStringLiteral("label_40"));

        formLayout_7->setWidget(3, QFormLayout::LabelRole, label_40);

        correctionProductsCount = new QSpinBox(tabCorrection);
        correctionProductsCount->setObjectName(QStringLiteral("correctionProductsCount"));
        correctionProductsCount->setMinimum(1);
        correctionProductsCount->setMaximum(999);

        formLayout_7->setWidget(3, QFormLayout::FieldRole, correctionProductsCount);

        label_41 = new QLabel(tabCorrection);
        label_41->setObjectName(QStringLiteral("label_41"));

        formLayout_7->setWidget(4, QFormLayout::LabelRole, label_41);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        correctionPercent = new QDoubleSpinBox(tabCorrection);
        correctionPercent->setObjectName(QStringLiteral("correctionPercent"));
        correctionPercent->setMaximum(100);

        horizontalLayout_6->addWidget(correctionPercent);

        label_42 = new QLabel(tabCorrection);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setMinimumSize(QSize(21, 18));
        label_42->setMaximumSize(QSize(21, 18));

        horizontalLayout_6->addWidget(label_42);


        formLayout_7->setLayout(4, QFormLayout::FieldRole, horizontalLayout_6);

        label_43 = new QLabel(tabCorrection);
        label_43->setObjectName(QStringLiteral("label_43"));

        formLayout_7->setWidget(5, QFormLayout::LabelRole, label_43);

        correctionDateOfSale = new QDateEdit(tabCorrection);
        correctionDateOfSale->setObjectName(QStringLiteral("correctionDateOfSale"));
        correctionDateOfSale->setEnabled(true);
        correctionDateOfSale->setWrapping(false);
        correctionDateOfSale->setFrame(true);
        correctionDateOfSale->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        correctionDateOfSale->setKeyboardTracking(true);
        correctionDateOfSale->setProperty("showGroupSeparator", QVariant(false));
        correctionDateOfSale->setMinimumDate(QDate(1900, 9, 14));
        correctionDateOfSale->setCalendarPopup(true);

        formLayout_7->setWidget(5, QFormLayout::FieldRole, correctionDateOfSale);


        verticalLayout_12->addLayout(formLayout_7);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        correctionDeleteOrRestoreButton = new QPushButton(tabCorrection);
        correctionDeleteOrRestoreButton->setObjectName(QStringLiteral("correctionDeleteOrRestoreButton"));

        horizontalLayout_32->addWidget(correctionDeleteOrRestoreButton);

        addCorrectionButton = new QPushButton(tabCorrection);
        addCorrectionButton->setObjectName(QStringLiteral("addCorrectionButton"));

        horizontalLayout_32->addWidget(addCorrectionButton);


        verticalLayout_12->addLayout(horizontalLayout_32);

        label_44 = new QLabel(tabCorrection);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_12->addWidget(label_44);

        correctionHistoryList = new QScrollArea(tabCorrection);
        correctionHistoryList->setObjectName(QStringLiteral("correctionHistoryList"));
        correctionHistoryList->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 98, 28));
        correctionHistoryList->setWidget(scrollAreaWidgetContents);

        verticalLayout_12->addWidget(correctionHistoryList);


        horizontalLayout_7->addLayout(verticalLayout_12);

        tabWidget->addTab(tabCorrection, QString());
        tabSales = new QWidget();
        tabSales->setObjectName(QStringLiteral("tabSales"));
        horizontalLayout_35 = new QHBoxLayout(tabSales);
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_46 = new QLabel(tabSales);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_14->addWidget(label_46);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        label_45 = new QLabel(tabSales);
        label_45->setObjectName(QStringLiteral("label_45"));

        horizontalLayout_34->addWidget(label_45);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(horizontalSpacer_7);

        verticalSpacer_6 = new QSpacerItem(10, 25, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_34->addItem(verticalSpacer_6);

        salesDateInput = new QDateEdit(tabSales);
        salesDateInput->setObjectName(QStringLiteral("salesDateInput"));
        salesDateInput->setEnabled(true);
        salesDateInput->setWrapping(false);
        salesDateInput->setFrame(true);
        salesDateInput->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        salesDateInput->setKeyboardTracking(true);
        salesDateInput->setProperty("showGroupSeparator", QVariant(false));
        salesDateInput->setMinimumDate(QDate(1900, 9, 14));
        salesDateInput->setCalendarPopup(true);

        horizontalLayout_34->addWidget(salesDateInput);


        verticalLayout_14->addLayout(horizontalLayout_34);

        managersSalesTable = new QTableView(tabSales);
        managersSalesTable->setObjectName(QStringLiteral("managersSalesTable"));

        verticalLayout_14->addWidget(managersSalesTable);


        horizontalLayout_35->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_48 = new QLabel(tabSales);
        label_48->setObjectName(QStringLiteral("label_48"));
        label_48->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_15->addWidget(label_48);

        label_47 = new QLabel(tabSales);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_15->addWidget(label_47);

        unconfirmedSalesTable = new QTableView(tabSales);
        unconfirmedSalesTable->setObjectName(QStringLiteral("unconfirmedSalesTable"));

        verticalLayout_15->addWidget(unconfirmedSalesTable);

        label_49 = new QLabel(tabSales);
        label_49->setObjectName(QStringLiteral("label_49"));
        label_49->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_15->addWidget(label_49);

        confirmedSalesTable = new QTableView(tabSales);
        confirmedSalesTable->setObjectName(QStringLiteral("confirmedSalesTable"));

        verticalLayout_15->addWidget(confirmedSalesTable);


        horizontalLayout_35->addLayout(verticalLayout_15);

        tabWidget->addTab(tabSales, QString());
        tabStatistic = new QWidget();
        tabStatistic->setObjectName(QStringLiteral("tabStatistic"));
        horizontalLayout_37 = new QHBoxLayout(tabStatistic);
        horizontalLayout_37->setSpacing(6);
        horizontalLayout_37->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_37->setObjectName(QStringLiteral("horizontalLayout_37"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        label_50 = new QLabel(tabStatistic);
        label_50->setObjectName(QStringLiteral("label_50"));
        label_50->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_16->addWidget(label_50);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setObjectName(QStringLiteral("horizontalLayout_36"));
        label_51 = new QLabel(tabStatistic);
        label_51->setObjectName(QStringLiteral("label_51"));

        horizontalLayout_36->addWidget(label_51);

        statisticStartPeriod = new QDateEdit(tabStatistic);
        statisticStartPeriod->setObjectName(QStringLiteral("statisticStartPeriod"));
        statisticStartPeriod->setEnabled(true);
        statisticStartPeriod->setWrapping(false);
        statisticStartPeriod->setFrame(true);
        statisticStartPeriod->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        statisticStartPeriod->setKeyboardTracking(true);
        statisticStartPeriod->setProperty("showGroupSeparator", QVariant(false));
        statisticStartPeriod->setMinimumDate(QDate(1900, 9, 14));
        statisticStartPeriod->setCalendarPopup(true);

        horizontalLayout_36->addWidget(statisticStartPeriod);

        verticalSpacer_5 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_36->addItem(verticalSpacer_5);

        label_52 = new QLabel(tabStatistic);
        label_52->setObjectName(QStringLiteral("label_52"));

        horizontalLayout_36->addWidget(label_52);

        statisticEndPeriod = new QDateEdit(tabStatistic);
        statisticEndPeriod->setObjectName(QStringLiteral("statisticEndPeriod"));
        statisticEndPeriod->setEnabled(true);
        statisticEndPeriod->setWrapping(false);
        statisticEndPeriod->setFrame(true);
        statisticEndPeriod->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        statisticEndPeriod->setKeyboardTracking(true);
        statisticEndPeriod->setProperty("showGroupSeparator", QVariant(false));
        statisticEndPeriod->setMinimumDate(QDate(1900, 9, 14));
        statisticEndPeriod->setCalendarPopup(true);

        horizontalLayout_36->addWidget(statisticEndPeriod);


        verticalLayout_16->addLayout(horizontalLayout_36);

        statisticTable = new QTableView(tabStatistic);
        statisticTable->setObjectName(QStringLiteral("statisticTable"));

        verticalLayout_16->addWidget(statisticTable);


        horizontalLayout_37->addLayout(verticalLayout_16);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_55 = new QLabel(tabStatistic);
        label_55->setObjectName(QStringLiteral("label_55"));
        label_55->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_17->addWidget(label_55);

        label_53 = new QLabel(tabStatistic);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_17->addWidget(label_53);

        statisticSalesTable = new QTableView(tabStatistic);
        statisticSalesTable->setObjectName(QStringLiteral("statisticSalesTable"));

        verticalLayout_17->addWidget(statisticSalesTable);

        label_54 = new QLabel(tabStatistic);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_17->addWidget(label_54);

        statisticCalendar = new QCalendarWidget(tabStatistic);
        statisticCalendar->setObjectName(QStringLiteral("statisticCalendar"));
        statisticCalendar->setLayoutDirection(Qt::LeftToRight);
        statisticCalendar->setAutoFillBackground(true);
        statisticCalendar->setGridVisible(true);
        statisticCalendar->setVerticalHeaderFormat(QCalendarWidget::ISOWeekNumbers);
        statisticCalendar->setNavigationBarVisible(true);
        statisticCalendar->setDateEditEnabled(true);

        verticalLayout_17->addWidget(statisticCalendar);


        horizontalLayout_37->addLayout(verticalLayout_17);

        tabWidget->addTab(tabStatistic, QString());
        tabSalary = new QWidget();
        tabSalary->setObjectName(QStringLiteral("tabSalary"));
        horizontalLayout_18 = new QHBoxLayout(tabSalary);
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        label_57 = new QLabel(tabSalary);
        label_57->setObjectName(QStringLiteral("label_57"));
        label_57->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_18->addWidget(label_57);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setSpacing(6);
        horizontalLayout_38->setObjectName(QStringLiteral("horizontalLayout_38"));
        label_56 = new QLabel(tabSalary);
        label_56->setObjectName(QStringLiteral("label_56"));

        horizontalLayout_38->addWidget(label_56);

        salaryAccountingPeriod = new QComboBox(tabSalary);
        salaryAccountingPeriod->setObjectName(QStringLiteral("salaryAccountingPeriod"));

        horizontalLayout_38->addWidget(salaryAccountingPeriod);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_38->addItem(horizontalSpacer_8);


        verticalLayout_18->addLayout(horizontalLayout_38);

        salaryTable = new QTableView(tabSalary);
        salaryTable->setObjectName(QStringLiteral("salaryTable"));
        salaryTable->setShowGrid(true);
        salaryTable->horizontalHeader()->setCascadingSectionResizes(false);

        verticalLayout_18->addWidget(salaryTable);

        salaryTotalTable = new QTableView(tabSalary);
        salaryTotalTable->setObjectName(QStringLiteral("salaryTotalTable"));
        salaryTotalTable->setMinimumSize(QSize(20, 20));
        salaryTotalTable->setBaseSize(QSize(20, 20));
        salaryTotalTable->setShowGrid(true);
        salaryTotalTable->horizontalHeader()->setCascadingSectionResizes(false);

        verticalLayout_18->addWidget(salaryTotalTable);

        closeAccountingPeriod = new QPushButton(tabSalary);
        closeAccountingPeriod->setObjectName(QStringLiteral("closeAccountingPeriod"));

        verticalLayout_18->addWidget(closeAccountingPeriod);


        horizontalLayout_18->addLayout(verticalLayout_18);

        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setSpacing(6);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        label_58 = new QLabel(tabSalary);
        label_58->setObjectName(QStringLiteral("label_58"));
        label_58->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_26->addWidget(label_58);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_65 = new QLabel(tabSalary);
        label_65->setObjectName(QStringLiteral("label_65"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_65->sizePolicy().hasHeightForWidth());
        label_65->setSizePolicy(sizePolicy2);
        label_65->setMinimumSize(QSize(102, 0));

        horizontalLayout_10->addWidget(label_65);

        managerFIOLabel = new QLabel(tabSalary);
        managerFIOLabel->setObjectName(QStringLiteral("managerFIOLabel"));

        horizontalLayout_10->addWidget(managerFIOLabel);


        verticalLayout_13->addLayout(horizontalLayout_10);

        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setSpacing(6);
        horizontalLayout_43->setObjectName(QStringLiteral("horizontalLayout_43"));
        label_62 = new QLabel(tabSalary);
        label_62->setObjectName(QStringLiteral("label_62"));
        sizePolicy2.setHeightForWidth(label_62->sizePolicy().hasHeightForWidth());
        label_62->setSizePolicy(sizePolicy2);
        label_62->setMinimumSize(QSize(100, 0));

        horizontalLayout_43->addWidget(label_62);

        salaryPasportSeries = new QSpinBox(tabSalary);
        salaryPasportSeries->setObjectName(QStringLiteral("salaryPasportSeries"));
        salaryPasportSeries->setEnabled(false);
        salaryPasportSeries->setMinimum(1000);
        salaryPasportSeries->setMaximum(9999);

        horizontalLayout_43->addWidget(salaryPasportSeries);

        label_63 = new QLabel(tabSalary);
        label_63->setObjectName(QStringLiteral("label_63"));

        horizontalLayout_43->addWidget(label_63);

        salaryPasportNumber = new QSpinBox(tabSalary);
        salaryPasportNumber->setObjectName(QStringLiteral("salaryPasportNumber"));
        salaryPasportNumber->setEnabled(false);
        salaryPasportNumber->setMinimum(100000);
        salaryPasportNumber->setMaximum(999999);

        horizontalLayout_43->addWidget(salaryPasportNumber);


        verticalLayout_13->addLayout(horizontalLayout_43);

        formLayout_10 = new QFormLayout();
        formLayout_10->setSpacing(6);
        formLayout_10->setObjectName(QStringLiteral("formLayout_10"));
        salaryPasportSourse = new QLineEdit(tabSalary);
        salaryPasportSourse->setObjectName(QStringLiteral("salaryPasportSourse"));
        salaryPasportSourse->setEnabled(false);

        formLayout_10->setWidget(0, QFormLayout::FieldRole, salaryPasportSourse);

        label_60 = new QLabel(tabSalary);
        label_60->setObjectName(QStringLiteral("label_60"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_60->sizePolicy().hasHeightForWidth());
        label_60->setSizePolicy(sizePolicy3);

        formLayout_10->setWidget(1, QFormLayout::LabelRole, label_60);

        salaryDateOfReceipt = new QDateEdit(tabSalary);
        salaryDateOfReceipt->setObjectName(QStringLiteral("salaryDateOfReceipt"));
        salaryDateOfReceipt->setEnabled(false);
        salaryDateOfReceipt->setWrapping(false);
        salaryDateOfReceipt->setFrame(true);
        salaryDateOfReceipt->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        salaryDateOfReceipt->setKeyboardTracking(true);
        salaryDateOfReceipt->setProperty("showGroupSeparator", QVariant(false));
        salaryDateOfReceipt->setMinimumDate(QDate(1900, 9, 14));
        salaryDateOfReceipt->setCalendarPopup(true);

        formLayout_10->setWidget(1, QFormLayout::FieldRole, salaryDateOfReceipt);

        label_61 = new QLabel(tabSalary);
        label_61->setObjectName(QStringLiteral("label_61"));
        label_61->setMinimumSize(QSize(100, 0));

        formLayout_10->setWidget(0, QFormLayout::LabelRole, label_61);


        verticalLayout_13->addLayout(formLayout_10);

        salarySexGroup = new QGroupBox(tabSalary);
        salarySexGroup->setObjectName(QStringLiteral("salarySexGroup"));
        salarySexGroup->setEnabled(false);
        salarySexGroup->setAutoFillBackground(false);
        salarySexGroup->setFlat(false);
        salarySexGroup->setCheckable(false);
        horizontalLayout_41 = new QHBoxLayout(salarySexGroup);
        horizontalLayout_41->setSpacing(6);
        horizontalLayout_41->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_41->setObjectName(QStringLiteral("horizontalLayout_41"));
        salaryMaleRButton = new QRadioButton(salarySexGroup);
        salaryMaleRButton->setObjectName(QStringLiteral("salaryMaleRButton"));

        horizontalLayout_41->addWidget(salaryMaleRButton);

        salaryFemaleRButton = new QRadioButton(salarySexGroup);
        salaryFemaleRButton->setObjectName(QStringLiteral("salaryFemaleRButton"));
        salaryFemaleRButton->setEnabled(false);

        horizontalLayout_41->addWidget(salaryFemaleRButton);


        verticalLayout_13->addWidget(salarySexGroup);

        formLayout_11 = new QFormLayout();
        formLayout_11->setSpacing(6);
        formLayout_11->setObjectName(QStringLiteral("formLayout_11"));
        salaryINN = new QLineEdit(tabSalary);
        salaryINN->setObjectName(QStringLiteral("salaryINN"));
        salaryINN->setEnabled(false);

        formLayout_11->setWidget(0, QFormLayout::FieldRole, salaryINN);

        label_59 = new QLabel(tabSalary);
        label_59->setObjectName(QStringLiteral("label_59"));
        label_59->setMinimumSize(QSize(100, 0));

        formLayout_11->setWidget(0, QFormLayout::LabelRole, label_59);


        verticalLayout_13->addLayout(formLayout_11);


        verticalLayout_26->addLayout(verticalLayout_13);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_26->addItem(verticalSpacer_7);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setSpacing(6);
        horizontalLayout_44->setObjectName(QStringLiteral("horizontalLayout_44"));
        salesButton = new QPushButton(tabSalary);
        salesButton->setObjectName(QStringLiteral("salesButton"));

        horizontalLayout_44->addWidget(salesButton);

        dataButton = new QPushButton(tabSalary);
        dataButton->setObjectName(QStringLiteral("dataButton"));

        horizontalLayout_44->addWidget(dataButton);


        verticalLayout_26->addLayout(horizontalLayout_44);


        horizontalLayout_18->addLayout(verticalLayout_26);

        tabWidget->addTab(tabSalary, QString());

        verticalLayout_5->addWidget(tabWidget);

        boss_manager_stackedWidget->addWidget(owner);
        manager = new QWidget();
        manager->setObjectName(QStringLiteral("manager"));
        horizontalLayout_24 = new QHBoxLayout(manager);
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_22 = new QLabel(manager);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_10->addWidget(label_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        label_24 = new QLabel(manager);
        label_24->setObjectName(QStringLiteral("label_24"));

        horizontalLayout_23->addWidget(label_24);

        verticalSpacer_9 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(verticalSpacer_9);

        currentSalary = new QLineEdit(manager);
        currentSalary->setObjectName(QStringLiteral("currentSalary"));
        currentSalary->setClearButtonEnabled(false);

        horizontalLayout_23->addWidget(currentSalary);

        label_64 = new QLabel(manager);
        label_64->setObjectName(QStringLiteral("label_64"));
        label_64->setMinimumSize(QSize(21, 18));
        label_64->setMaximumSize(QSize(21, 18));

        horizontalLayout_23->addWidget(label_64);


        verticalLayout_10->addLayout(horizontalLayout_23);

        label_25 = new QLabel(manager);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_10->addWidget(label_25);

        label_26 = new QLabel(manager);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_10->addWidget(label_26);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_27 = new QLabel(manager);
        label_27->setObjectName(QStringLiteral("label_27"));
        sizePolicy2.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy2);

        gridLayout_6->addWidget(label_27, 0, 0, 1, 1);

        productComboBox = new QComboBox(manager);
        productComboBox->setObjectName(QStringLiteral("productComboBox"));

        gridLayout_6->addWidget(productComboBox, 0, 1, 1, 1);

        label_28 = new QLabel(manager);
        label_28->setObjectName(QStringLiteral("label_28"));
        sizePolicy2.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy2);

        gridLayout_6->addWidget(label_28, 0, 2, 1, 1);

        priceInput = new QSpinBox(manager);
        priceInput->setObjectName(QStringLiteral("priceInput"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(priceInput->sizePolicy().hasHeightForWidth());
        priceInput->setSizePolicy(sizePolicy4);
        priceInput->setMinimumSize(QSize(100, 0));
        priceInput->setMinimum(1);
        priceInput->setMaximum(99999999);

        gridLayout_6->addWidget(priceInput, 0, 3, 1, 1);

        label_29 = new QLabel(manager);
        label_29->setObjectName(QStringLiteral("label_29"));
        sizePolicy2.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy2);

        gridLayout_6->addWidget(label_29, 0, 4, 1, 1);

        countInput = new QSpinBox(manager);
        countInput->setObjectName(QStringLiteral("countInput"));
        sizePolicy4.setHeightForWidth(countInput->sizePolicy().hasHeightForWidth());
        countInput->setSizePolicy(sizePolicy4);
        countInput->setMinimumSize(QSize(20, 0));
        countInput->setMinimum(1);
        countInput->setMaximum(999);

        gridLayout_6->addWidget(countInput, 0, 5, 1, 1);


        verticalLayout_10->addLayout(gridLayout_6);

        label_30 = new QLabel(manager);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_10->addWidget(label_30);

        confirmedSales = new QTableView(manager);
        confirmedSales->setObjectName(QStringLiteral("confirmedSales"));

        verticalLayout_10->addWidget(confirmedSales);

        label_31 = new QLabel(manager);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_10->addWidget(label_31);

        unconfirmedSales = new QTableView(manager);
        unconfirmedSales->setObjectName(QStringLiteral("unconfirmedSales"));

        verticalLayout_10->addWidget(unconfirmedSales);


        horizontalLayout_24->addLayout(verticalLayout_10);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_23 = new QLabel(manager);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setStyleSheet(QStringLiteral("QLabel { background-color: rgb(225, 225, 225) }"));

        verticalLayout_9->addWidget(label_23);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        productSearch_2 = new QLineEdit(manager);
        productSearch_2->setObjectName(QStringLiteral("productSearch_2"));
        productSearch_2->setClearButtonEnabled(false);

        horizontalLayout_22->addWidget(productSearch_2);

        managerProductSearchButton = new QPushButton(manager);
        managerProductSearchButton->setObjectName(QStringLiteral("managerProductSearchButton"));
        managerProductSearchButton->setIcon(icon);

        horizontalLayout_22->addWidget(managerProductSearchButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_5);


        verticalLayout_9->addLayout(horizontalLayout_22);

        managersProductTable = new QTableView(manager);
        managersProductTable->setObjectName(QStringLiteral("managersProductTable"));

        verticalLayout_9->addWidget(managersProductTable);


        horizontalLayout_24->addLayout(verticalLayout_9);

        boss_manager_stackedWidget->addWidget(manager);

        verticalLayout_6->addWidget(boss_manager_stackedWidget);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        quitButton = new QPushButton(main);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setStyleSheet(QStringLiteral("QPushButton { background-color: rgb(255, 0, 0); color: rgb(255, 255, 255); }"));

        horizontalLayout_13->addWidget(quitButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);


        verticalLayout_6->addLayout(horizontalLayout_13);

        auth_program_stackedWidget->addWidget(main);

        horizontalLayout_17->addWidget(auth_program_stackedWidget);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 814, 21));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        auth_program_stackedWidget->setCurrentIndex(1);
        boss_manager_stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);
        managersDataTab->setCurrentIndex(0);
        managersButtonsStackedWidget->setCurrentIndex(0);
        productButtonsStackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        label_19->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\220\321\203\321\202\320\265\320\275\321\204\320\270\320\272\320\260\321\206\320\270\321\217</span></p></body></html>", 0));
        label_20->setText(QApplication::translate("MainWindowClass", "\320\233\320\276\320\263\320\270\320\275", 0));
        label_21->setText(QApplication::translate("MainWindowClass", "\320\237\320\260\321\200\320\276\320\273\321\214", 0));
        errorLabel->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\">errorText</p></body></html>", 0));
        enterButton->setText(QApplication::translate("MainWindowClass", "\320\222\320\276\320\271\321\202\320\270", 0));
        label->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270</span></p></body></html>", 0));
        addManagerButton->setText(QApplication::translate("MainWindowClass", "\320\235\320\260\320\275\321\217\321\202\321\214 \320\274\320\265\320\275\320\265\320\264\320\266\320\265\321\200\320\260", 0));
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
        managersDataTab->setTabText(managersDataTab->indexOf(personalDataTab), QApplication::translate("MainWindowClass", "\320\233\320\270\321\207\320\275\321\213\320\265", 0));
        label_7->setText(QApplication::translate("MainWindowClass", "\320\233\320\276\320\263\320\270\320\275", 0));
        label_14->setText(QApplication::translate("MainWindowClass", "\320\237\320\260\321\200\320\276\320\273\321\214", 0));
        managersDataTab->setTabText(managersDataTab->indexOf(accountDataTab), QApplication::translate("MainWindowClass", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", 0));
        managerEditButton->setText(QApplication::translate("MainWindowClass", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        cancelManagerButton->setText(QApplication::translate("MainWindowClass", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        saveManagerButton->setText(QApplication::translate("MainWindowClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        managerCancelAddButton->setText(QApplication::translate("MainWindowClass", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0));
        managerSubmitAddButton->setText(QApplication::translate("MainWindowClass", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabManagers), QApplication::translate("MainWindowClass", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", 0));
        label_15->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\242\320\276\320\262\320\260\321\200\321\213</span></p></body></html>", 0));
        productSearch->setInputMask(QString());
        productSearch->setText(QString());
        productSearch->setPlaceholderText(QApplication::translate("MainWindowClass", "\320\277\320\276\320\270\321\201\320\272 \320\277\320\276 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\216", 0));
        searchButton->setText(QString());
        addProductButton->setText(QApplication::translate("MainWindowClass", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        label_16->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\224\320\260\320\275\320\275\321\213\320\265</span></p></body></html>", 0));
        label_17->setText(QApplication::translate("MainWindowClass", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        productName->setInputMask(QString());
        productName->setText(QString());
        label_18->setText(QApplication::translate("MainWindowClass", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202 \320\272\320\276\320\274\320\270\321\201\321\201\320\270\320\270", 0));
        deleteProductButton->setText(QApplication::translate("MainWindowClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        editProductButton->setText(QApplication::translate("MainWindowClass", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        cancelProductButton->setText(QApplication::translate("MainWindowClass", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        saveProductButton->setText(QApplication::translate("MainWindowClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        productCancelAddButton->setText(QApplication::translate("MainWindowClass", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0));
        productSubmitAddButton->setText(QApplication::translate("MainWindowClass", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabProducts), QApplication::translate("MainWindowClass", "\320\242\320\276\320\262\320\260\321\200\321\213", 0));
        label_32->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\224\320\260\320\275\320\275\321\213\320\265</span></p></body></html>", 0));
        label_33->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\321\221\320\275\320\275\321\213\320\265 \320\277\321\200\320\276\320\264\320\260\320\266\320\270</span></p></body></html>", 0));
        label_34->setText(QApplication::translate("MainWindowClass", "\320\240\320\260\321\201\321\207\320\265\321\202\320\275\321\213\320\271 \320\277\320\265\321\200\320\270\320\276\320\264:", 0));
        label_35->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\320\224\320\260\320\275\320\275\321\213\320\265 \320\276 \320\277\321\200\320\276\320\264\320\260\320\266\320\265</span></p></body></html>", 0));
        label_36->setText(QApplication::translate("MainWindowClass", "\320\237\321\200\320\276\320\264\320\260\320\262\320\265\321\206", 0));
        label_37->setText(QApplication::translate("MainWindowClass", "\320\242\320\276\320\262\320\260\321\200", 0));
        label_38->setText(QApplication::translate("MainWindowClass", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", 0));
        label_39->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p><span style=\" font-size:10pt;\">\342\202\275</span></p></body></html>", 0));
        label_40->setText(QApplication::translate("MainWindowClass", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", 0));
        label_41->setText(QApplication::translate("MainWindowClass", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202 \320\272\320\276\320\274\320\270\321\201\321\201\320\270\320\270", 0));
        label_42->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p><span style=\" font-size:10pt;\">%</span></p></body></html>", 0));
        label_43->setText(QApplication::translate("MainWindowClass", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\276\320\264\320\260\320\266\320\270", 0));
        correctionDeleteOrRestoreButton->setText(QApplication::translate("MainWindowClass", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        addCorrectionButton->setText(QApplication::translate("MainWindowClass", "\320\241\320\272\320\276\321\200\321\200\320\265\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
        label_44->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\272\320\276\321\200\321\200\320\265\320\272\321\202\320\270\321\200\320\276\320\262\320\276\320\272</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabCorrection), QApplication::translate("MainWindowClass", "\320\232\320\276\321\200\321\200\320\265\320\272\321\202\320\270\321\200\320\276\320\262\320\272\320\270", 0));
        label_46->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270</span></p></body></html>", 0));
        label_45->setText(QApplication::translate("MainWindowClass", "\320\224\320\260\321\202\320\260", 0));
        label_48->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\237\321\200\320\276\320\264\320\260\320\266\320\270</span></p></body></html>", 0));
        label_47->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\320\235\320\265\320\277\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\321\221\320\275\320\275\321\213\320\265</span></p></body></html>", 0));
        label_49->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\321\221\320\275\320\275\321\213\320\265</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabSales), QApplication::translate("MainWindowClass", "\320\237\321\200\320\276\320\264\320\260\320\266\320\270", 0));
        label_50->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \320\277\320\276 \320\277\321\200\320\276\320\264\320\260\320\266\320\260\320\274</span></p></body></html>", 0));
        label_51->setText(QApplication::translate("MainWindowClass", "\320\227\320\260 \320\277\320\265\321\200\320\270\320\276\320\264 \320\276\321\202:", 0));
        label_52->setText(QApplication::translate("MainWindowClass", "\320\237\320\276:", 0));
        label_55->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\224\320\260\320\275\320\275\321\213\320\265</span></p></body></html>", 0));
        label_53->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\320\237\321\200\320\276\320\264\320\260\320\266\320\270</span></p></body></html>", 0));
        label_54->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\320\232\320\260\320\273\320\265\320\275\320\264\320\260\321\200\321\214 \320\270\320\275\321\202\320\265\320\275\321\201\320\270\320\262\320\275\320\276\321\201\321\202\320\270 \320\277\321\200\320\276\320\264\320\260\320\266</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistic), QApplication::translate("MainWindowClass", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", 0));
        label_57->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\227\320\260\321\200\320\277\320\273\320\260\321\202\320\260</span></p></body></html>", 0));
        label_56->setText(QApplication::translate("MainWindowClass", "\320\240\320\260\321\201\321\207\320\265\321\202\320\275\321\213\320\271 \320\277\320\265\321\200\320\270\320\276\320\264:", 0));
        closeAccountingPeriod->setText(QApplication::translate("MainWindowClass", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \321\200\320\260\321\201\321\207\320\265\321\202\320\275\321\213\320\271 \320\277\320\265\321\200\320\270\320\276\320\264", 0));
        label_58->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\224\320\260\320\275\320\275\321\213\320\265</span></p></body></html>", 0));
        label_65->setText(QApplication::translate("MainWindowClass", "\320\237\320\276 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\321\203:", 0));
        managerFIOLabel->setText(QApplication::translate("MainWindowClass", "TextLabel", 0));
        label_62->setText(QApplication::translate("MainWindowClass", "\320\241\320\265\321\200\320\270\321\217 \320\277\320\260\321\201\320\277\320\276\321\200\321\202\320\260", 0));
        label_63->setText(QApplication::translate("MainWindowClass", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\260\321\201\320\277\320\276\321\200\321\202\320\260", 0));
        label_60->setText(QApplication::translate("MainWindowClass", "\320\224\320\260\321\202\320\260 \320\262\321\213\320\264\320\260\321\207\320\270", 0));
        label_61->setText(QApplication::translate("MainWindowClass", "\320\237\320\260\321\201\320\277\320\276\321\200\321\202 \320\262\321\213\320\264\320\260\320\275", 0));
        salarySexGroup->setTitle(QApplication::translate("MainWindowClass", "\320\237\320\276\320\273", 0));
        salaryMaleRButton->setText(QApplication::translate("MainWindowClass", "\320\274\321\203\320\266\321\201\320\272\320\276\320\271", 0));
        salaryFemaleRButton->setText(QApplication::translate("MainWindowClass", "\320\266\320\265\320\275\321\201\320\272\320\270\320\271", 0));
        label_59->setText(QApplication::translate("MainWindowClass", "\320\230\320\235\320\235", 0));
        salesButton->setText(QApplication::translate("MainWindowClass", "\320\237\321\200\320\276\320\264\320\260\320\266\320\270", 0));
        dataButton->setText(QApplication::translate("MainWindowClass", "\320\224\320\260\320\275\320\275\321\213\320\265", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabSalary), QApplication::translate("MainWindowClass", "\320\227\320\260\321\200\320\277\320\273\320\260\321\202\320\260", 0));
        label_22->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\227\320\260\321\200\320\260\320\261\320\276\321\202\320\275\320\260\321\217 \320\277\320\273\320\260\321\202\320\260</span></p></body></html>", 0));
        label_24->setText(QApplication::translate("MainWindowClass", "\320\227\320\260\321\200\320\277\320\273\320\260\321\202\320\260 \320\275\320\260 \321\202\320\265\320\272\321\203\321\211\320\270\320\271 \320\274\320\276\320\274\320\265\320\275\321\202:", 0));
        currentSalary->setInputMask(QString());
        currentSalary->setText(QString());
        label_64->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">\342\202\275</span></p></body></html>", 0));
        label_25->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\234\320\276\320\270 \320\277\321\200\320\276\320\264\320\260\320\266\320\270</span></p></body></html>", 0));
        label_26->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\277\321\200\320\276\320\264\320\260\320\266\321\203</span></p></body></html>", 0));
        label_27->setText(QApplication::translate("MainWindowClass", "\320\242\320\276\320\262\320\260\321\200", 0));
        label_28->setText(QApplication::translate("MainWindowClass", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", 0));
        label_29->setText(QApplication::translate("MainWindowClass", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", 0));
        label_30->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\321\221\320\275\320\275\321\213\320\265</span></p></body></html>", 0));
        label_31->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\"> \320\235\320\265\320\277\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\321\221\320\275\320\275\321\213\320\265</span></p></body></html>", 0));
        label_23->setText(QApplication::translate("MainWindowClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\320\242\320\276\320\262\320\260\321\200\321\213</span></p></body></html>", 0));
        productSearch_2->setInputMask(QString());
        productSearch_2->setText(QString());
        productSearch_2->setPlaceholderText(QApplication::translate("MainWindowClass", "\320\277\320\276\320\270\321\201\320\272 \320\277\320\276 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\216", 0));
        managerProductSearchButton->setText(QString());
        quitButton->setText(QApplication::translate("MainWindowClass", "\320\222\321\213\320\271\321\202\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
