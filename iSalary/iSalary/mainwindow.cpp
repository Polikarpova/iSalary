#include "mainwindow.h"
#include <qlabel.h>
#include <qtextcodec.h>

QTextCodec* c = QTextCodec::codecForName("UTF-8");
 
MainWindow::MainWindow( 
	AuthPage* authPage, 
	EmployeesPage* employeesPage, 
	SalesPage* salesPage, 
	ProductPage *productPage, 
	ManagerPage *managerPage,
	QWidget *parent 
) : QMainWindow(parent) {
	
	ui.setupUi(this);
	
	//блокировка вкладки корректировки
	ui.tabWidget->setTabEnabled(2, false);

    ui.auth_program_stackedWidget->setCurrentIndex( AUTH_WIDGET);

	//MANAGER_WIDGET BOSS_WIDGET
	ui.boss_manager_stackedWidget->setCurrentIndex( MANAGER_WIDGET);

	createHorizontalTabs();

    this->authPage = authPage;
    this->authPage->setUI( ui.loginInput, ui.passwordInput, ui.enterButton, ui.errorLabel);
    
    connect(this->authPage, &AuthPage::userLoggedIn, this, &MainWindow::enterProgram);

	this->productPage = productPage;
	this->productPage->setUI(
		ui.productSearch, 
		ui.searchButton,
		ui.productTable,
		ui.productName,
		ui.productPercent,
		ui.productButtonsStackedWidget,
		ui.addProductButton,
		ui.deleteProductButton,
		ui.editProductButton,
		ui.cancelProductButton,
		ui.saveProductButton,
		ui.productCancelAddButton,
		ui.productSubmitAddButton
	);

	this->managerPage = managerPage;
	this->managerPage->setUI(
		ui.currentSalary,
		ui.productComboBox,
		ui.priceSale,
		ui.countSaleProducts,
		ui.addSaleButton,
		ui.managerProductSearch,
		ui.managerProductSearchButton,
		ui.managerProductTable,
		ui.managerConfirmedSalesTable,
		ui.managerUnconfirmedSalesTable
	);

	auto drivers =  QSqlDatabase::drivers();
	QString mes = "";

    for ( auto it = drivers.begin(); it != drivers.end(); it++ )
        mes += *it + "\n";

	this->salesPage = salesPage;
	this->salesPage->setUI(ui.salesDateInput, ui.managersSalesTable, ui.unconfirmedSalesTable, ui.confirmedSalesTable);
	this->salesPage->setErrorHandler( errorHandler);
}

void MainWindow::enterProgram( const UserDTO& user, UserType userType){
    if( userType == MANAGER) {
        ui.boss_manager_stackedWidget->setCurrentIndex( MANAGER_WIDGET);
    } else if ( userType == BOSS ){
        ui.boss_manager_stackedWidget->setCurrentIndex( BOSS_WIDGET);
    }
    ui.auth_program_stackedWidget->setCurrentIndex( PROGRAM_WIDGET);
}

void MainWindow::createHorizontalTabs() {

	QStringList tabs_text;
    tabs_text.push_back( toUnicode("Сотрудники"));
    tabs_text.push_back( toUnicode("Товары"));
    tabs_text.push_back( toUnicode("Корректировки"));
    tabs_text.push_back( toUnicode("Продажи"));
    tabs_text.push_back( toUnicode("Статистика"));
    tabs_text.push_back( toUnicode("Зарплата"));
	QTabWidget *tabw = ui.tabWidget;
	
    for( int i = 0; i < tabs_text.size(); i++) {
		tabw->setTabText(i, "");
	}
	
	QTabBar *tabbar = tabw->tabBar();

    for( int i = 0; i < tabs_text.size(); i++) {
		QLabel *lbl = new QLabel();
        QString labelText = tabs_text[i]; 
        lbl->setText(labelText);
		tabbar->setTabButton(i, QTabBar::LeftSide, lbl);
	}
}

MainWindow::~MainWindow() {

    switch( page ){
        case PAGE_EMPLOYEES: this->employeesPage->refreshList(); break;
		case PAGE_SALES: this->salesPage->refreshPage(); break;
        default:;
    }
}

MainWindow::~MainWindow() {
    delete this->errorHandler;
}
