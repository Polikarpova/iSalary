#include "mainwindow.h"
#include "TabNavigator.h"

MainWindow::MainWindow( AuthPage *authPage, EmployeesPage *employeesPage, SalesPage *salesPage, SalaryPage *salaryPage, ProductPage *productPage,
                        ManagerPage *managerPage, StatisticPage *statisticPage, QWidget *parent )
    : QMainWindow( parent ) {
    ui.setupUi( this );

    ui.auth_program_stackedWidget->setCurrentIndex( AUTH_WIDGET );

    createHorizontalTabs();

    this->errorHandler = new ErrorMessageHandler( this );

    this->authPage = authPage;
    this->authPage->setUI( ui.loginInput, ui.passwordInput, ui.enterButton, ui.errorLabel, ui.auth_program_stackedWidget, ui.boss_manager_stackedWidget );
    connect( this->authPage, &AuthPage::userLoggedIn, this, &MainWindow::enterProgram );
    connect( ui.quitButton, &QPushButton::clicked, this, &MainWindow::exit );

    this->employeesPage = employeesPage;
    this->employeesPage->setUI( ui.tabManagers, ui.managersTable, ui.login, ui.password, ui.firstName, ui.secondName, ui.thirdName, ui.dateOfBirth,
                                ui.pasportSeries, ui.pasportNumber, ui.sexGroup, ui.maleRButton, ui.femaleRButton, ui.pasportSourse, ui.dateOfReceipt,
                                ui.registration, ui.INN, ui.managersButtonsStackedWidget, ui.managerEditButton, ui.addManagerButton, ui.saveManagerButton,
                                ui.cancelManagerButton, ui.managerSubmitAddButton, ui.managerCancelAddButton, ui.employDataHeaderLabel );
    this->employeesPage->setErrorHandler( errorHandler );
    connect( ui.tabWidget, &QTabWidget::currentChanged, this, &MainWindow::refreshBossPage );

    this->salesPage = salesPage;
    this->salesPage->setUI( ui.tabWidget, ui.salesForAllButton, ui.managersSalesTable, ui.unconfirmedSalesTable, ui.confirmedSalesTable );
    this->salesPage->setErrorHandler( errorHandler );

    this->salaryPage = salaryPage;
    this->salaryPage->setUI( ui.tabWidget, ui.salaryAccountingPeriod, ui.salaryTable, ui.salaryTotalTable, ui.managerFIOLabel, ui.salaryPasportSeries,
                             ui.salaryPasportNumber, ui.salaryPasportSourse, ui.salaryDateOfReceipt, ui.salaryMaleRButton, ui.salaryFemaleRButton, ui.salaryINN,
                             ui.closeAccountingPeriod, ui.salesButton, ui.dataButton );
    this->salaryPage->setErrorHandler( errorHandler );

    this->productPage = productPage;
    this->productPage->setWindow( this );
    this->productPage->setUI( ui.tabWidget, ui.productSearch, ui.productTable, ui.productName, ui.productPercent, ui.productButtonsStackedWidget,
                              ui.addProductButton, ui.deleteProductButton, ui.editProductButton, ui.cancelProductButton, ui.saveProductButton,
                              ui.productCancelAddButton, ui.productSubmitAddButton );
    this->productPage->setErrorHandler( errorHandler );

    this->managerPage = managerPage;
    this->managerPage->setUI( ui.boss_manager_stackedWidget, ui.currentSalary, ui.possibleSalary, ui.nameProductOutput, ui.dateSale, ui.priceSale,
                              ui.countSaleProducts, ui.addSaleButton, ui.managerProductSearch, ui.managerProductTable, ui.managerConfirmedSalesTable,
                              ui.managerUnconfirmedSalesTable );
    this->managerPage->setErrorHandler( errorHandler );

    this->statisticPage = statisticPage;
    this->statisticPage->setUI( ui.tabWidget, ui.statisticForAllButton, ui.statisticMonth, ui.statisticTable, ui.statisticSalesTable, ui.statisticCalendar );

    TabNavigator *tabNavigator = new TabNavigator( ui.tabWidget );
    tabNavigator->setEmployeesPage( this->employeesPage );
    tabNavigator->setProductPage( this->productPage );
    tabNavigator->setSalesPage( this->salesPage );
    tabNavigator->setSalaryPage( this->salaryPage );

    auto drivers = QSqlDatabase::drivers();
    QString mes = "";

    for ( auto it = drivers.begin(); it != drivers.end(); it++ )
        mes += *it + "\n";
}

void MainWindow::enterProgram( const UserDTO &user, UserType userType ) {
    if ( userType == MANAGER ) {
        ui.boss_manager_stackedWidget->setCurrentIndex( MANAGER_WIDGET );
        this->managerPage->setCurrentManagerId( this->authPage->currentUserId() );
        this->managerPage->refreshPage();
    } else if ( userType == BOSS ) {
        ui.boss_manager_stackedWidget->setCurrentIndex( BOSS_WIDGET );
        ui.tabWidget->setCurrentIndex( PAGE_EMPLOYEES );
        this->refreshBossPage( PAGE_EMPLOYEES );
    }
    ui.auth_program_stackedWidget->setCurrentIndex( PROGRAM_WIDGET );
}

void MainWindow::createHorizontalTabs() {

    QStringList tabs_text;
    tabs_text.push_back( toUnicode( "Сотрудники" ) );
    tabs_text.push_back( toUnicode( "Товары" ) );
    tabs_text.push_back( toUnicode( "Продажи" ) );
    tabs_text.push_back( toUnicode( "Статистика" ) );
    tabs_text.push_back( toUnicode( "Зарплата" ) );
    QTabWidget *tabw = ui.tabWidget;

    for ( int i = 0; i < tabs_text.size(); i++ ) {
        tabw->setTabText( i, "" );
    }

    QTabBar *tabbar = tabw->tabBar();

    for ( int i = 0; i < tabs_text.size(); i++ ) {
        QLabel *lbl = new QLabel();
        QString labelText = tabs_text[i];
        lbl->setText( labelText );
        tabbar->setTabButton( i, QTabBar::LeftSide, lbl );
    }
}

void MainWindow::refreshBossPage( int page ) {

    switch ( page ) {
    case PAGE_EMPLOYEES:
        this->employeesPage->refreshList();
        break;
    case PAGE_PRODUCTS:
        this->productPage->refreshPage();
        break;
    case PAGE_SALES:
        this->salesPage->refreshPage();
        break;
    case PAGE_STATISTIC:
        this->statisticPage->refreshPage();
        break;
    case PAGE_SALARY:
        this->salaryPage->refreshPage();
        break;
    default:;
    }
}

void MainWindow::exit() {
    if ( QMessageBox::Yes == QMessageBox::question( this, "Выход", "Вы уверены, что хотите выйти?", QMessageBox::Yes | QMessageBox::No ) ) {

        ui.auth_program_stackedWidget->setCurrentIndex( AUTH_WIDGET );
    }
}

MainWindow::~MainWindow() { delete this->errorHandler; }
