#include "mainwindow.h"
#include <qlabel.h>
#include <qtextcodec.h>

QTextCodec* c = QTextCodec::codecForName("UTF-8");

MainWindow::MainWindow( AuthPage* authPage, ProductPage *productPage, ManagerPage *managerPage, QWidget *parent ) : QMainWindow(parent) {
	ui.setupUi(this);
	
//    ui.auth_program_stackedWidget->setCurrentIndex( AUTH_WIDGET);
    ui.auth_program_stackedWidget->setCurrentIndex( PROGRAM_WIDGET);

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
	tabs_text << c->toUnicode("Сотрудники") << c->toUnicode("Товары") << c->toUnicode("Корректировки") << c->toUnicode("Продажи") <<
				  c->toUnicode("Статистика")<< c->toUnicode("Зарплата");
	QTabWidget *tabw = ui.tabWidget;
	
	for( int i = 0; i < 6; i++) {
		tabw->setTabText(i, "");
	}
	
	QTabBar *tabbar = tabw->tabBar();

	for( int i = 0; i < 6; i++) {
		QLabel *lbl = new QLabel();
		lbl->setText(tabs_text[i]);
		tabbar->setTabButton(i, QTabBar::LeftSide, lbl);
	}
}

MainWindow::~MainWindow() {

}

