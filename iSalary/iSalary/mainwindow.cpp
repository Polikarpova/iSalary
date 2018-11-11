#include "mainwindow.h"
#include <qlabel.h>
#include <qtextcodec.h>

QTextCodec* c = QTextCodec::codecForName("UTF-8");

MainWindow::MainWindow( AuthPage* authPage, ProductPage *productPage, QWidget *parent ) : QMainWindow(parent) {
	ui.setupUi(this);
	
//    ui.auth_program_stackedWidget->setCurrentIndex( AUTH_WIDGET);
    ui.auth_program_stackedWidget->setCurrentIndex( PROGRAM_WIDGET);

	//MANAGER_WIDGET BOSS_WIDGET
	ui.boss_manager_stackedWidget->setCurrentIndex( BOSS_WIDGET);

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

	auto drivers =  QSqlDatabase::drivers();
	QString mes = "";

    for ( auto it = drivers.begin(); it != drivers.end(); it++ )
        mes += *it + "\n";

	_db = QSqlDatabase::addDatabase( "QMYSQL" );
	_db.setHostName( "127.0.0.1" );
    _db.setPort( 3306 );
    _db.setDatabaseName( "mdkp" );
    _db.setUserName( "root" );
    _db.setPassword( "root" );
	bool ok = _db.open();
	QString s = _db.lastError().text();
	product_db = new Product_DB( _db, "products" );
    product_db->init();


	current_user_id = 1;
	sale_db = new Sale_DB( _db, "sales" );
    sale_db->init();

	initManagerWindow();

	connect( ui.managerProductSearchButton, SIGNAL( clicked() ), this, SLOT( searchManagersProductTable() ) );
	connect( ui.addSaleButton, SIGNAL( clicked() ), this, SLOT( addSale() ) );

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

//
void MainWindow::initManagerWindow() {
	unconfirmedSalesTableModel = new QStandardItemModel;
	confirmedSalesTableModel = new QStandardItemModel;
	managerProductsTableModel = new QStandardItemModel;
	fillManagersProductTable();
	fillManagersConfirmedSalesTable();
	fillManagersUnconfirmedSalesTable();
}

void MainWindow::clearManagersConfirmedSalesTable() {
	confirmedSalesTableModel->clear();
	QStringList horizontalHeader;
    horizontalHeader.append( c->toUnicode( "Название" ) );
    horizontalHeader.append( c->toUnicode( "Количество" ) );
	horizontalHeader.append( c->toUnicode( "Стоимость" ) );
	horizontalHeader.append( c->toUnicode( "Процент комиссии" ) );
	confirmedSalesTableModel->setHorizontalHeaderLabels( horizontalHeader );
	ui.confirmedSales->setModel( confirmedSalesTableModel );
    ui.confirmedSales->resizeColumnsToContents();
}

void MainWindow::fillManagersConfirmedSalesTable() {
    clearManagersConfirmedSalesTable();
	
	auto _sales = sale_db -> getActiveAll( current_user_id );
	int allCount = 0, lastRow = 0;
	double allCost = 0, salary = 0;
    for ( int idx = 0; idx < _sales.size(); idx++) {
		if ( _sales[idx].isConfirmed() == true) {
			ActiveSale sale = _sales[idx];
			sale.setProduct(products[sale.getProductId()]);
			sales[ sale.getId() ] = sale;
			QStandardItem *item;
			item = new QStandardItem( sale.getProductName() );
			confirmedSalesTableModel->setItem( lastRow, 0, item );
			item = new QStandardItem( QString::number( sale.getCount() ) );
			confirmedSalesTableModel->setItem( lastRow, 1, item );
			item = new QStandardItem( QString::number( sale.getCost() ) );
			confirmedSalesTableModel->setItem( lastRow, 2, item );
			item = new QStandardItem( QString::number( sale.getProductCommission() ) + "%" );
			confirmedSalesTableModel->setItem( lastRow, 3, item );

			allCount += sale.getCount();
			allCost += sale.getCost();
			salary += sale.getCost() / 100 * sale.getProductCommission();
			lastRow++;
		}
	}
	QStandardItem *item;
	item = new QStandardItem(  c->toUnicode( "Итого:" ) );
	confirmedSalesTableModel->setItem( lastRow, 0, item );
	item = new QStandardItem( QString::number( allCount ) );
	confirmedSalesTableModel->setItem( lastRow, 1, item );
	item = new QStandardItem( QString::number( allCost ) );
	confirmedSalesTableModel->setItem( lastRow, 2, item );
	item = new QStandardItem( QString::number( salary ) );
	confirmedSalesTableModel->setItem( lastRow, 3, item );

	ui.currentSalary->setText( QString::number( salary ) );
}

void MainWindow::clearManagersUnconfirmedSalesTable() {
	unconfirmedSalesTableModel->clear();
	QStringList horizontalHeader;
    horizontalHeader.append( c->toUnicode( "Название" ) );
    horizontalHeader.append( c->toUnicode( "Количество" ) );
	horizontalHeader.append( c->toUnicode( "Стоимость" ) );
	horizontalHeader.append( c->toUnicode( "Процент комиссии" ) );
	unconfirmedSalesTableModel->setHorizontalHeaderLabels( horizontalHeader );
	ui.unconfirmedSales->setModel( unconfirmedSalesTableModel );
    ui.unconfirmedSales->resizeColumnsToContents();
}

void MainWindow::fillManagersUnconfirmedSalesTable() {
    clearManagersUnconfirmedSalesTable();
	
	auto _sales = sale_db -> getActiveAll( current_user_id );
	int allCount = 0, lastRow = 0;
	double allCost = 0, salary = 0;
    for ( int idx = 0; idx < _sales.size(); idx++) {
		if ( _sales[idx].isConfirmed() == false ) {
			
			ActiveSale sale = _sales[idx];
			sale.setProduct(products[sale.getProductId()]);
			sales[ sale.getId() ] = sale;
			QStandardItem *item;
			item = new QStandardItem( sale.getProductName() );
			unconfirmedSalesTableModel->setItem( lastRow, 0, item );
			item = new QStandardItem( QString::number( sale.getCount() ) );
			unconfirmedSalesTableModel->setItem( lastRow, 1, item );
			item = new QStandardItem( QString::number( sale.getCost() ) );
			unconfirmedSalesTableModel->setItem( lastRow, 2, item );
			item = new QStandardItem( QString::number( sale.getProductCommission() ) + "%" );
			unconfirmedSalesTableModel->setItem( lastRow, 3, item );

			allCount += sale.getCount();
			allCost += sale.getCost();
			salary += sale.getCost() / 100 * sale.getProductCommission();
			lastRow++;
		}
	}
	QStandardItem *item;
	item = new QStandardItem(  c->toUnicode( "Итого:" ) );
	unconfirmedSalesTableModel->setItem( lastRow, 0, item );
	item = new QStandardItem( QString::number( allCount ) );
	unconfirmedSalesTableModel->setItem( lastRow, 1, item );
	item = new QStandardItem( QString::number( allCost ) );
	unconfirmedSalesTableModel->setItem( lastRow, 2, item );
	item = new QStandardItem( QString::number( salary ) );
	unconfirmedSalesTableModel->setItem( lastRow, 3, item );
}

void MainWindow::addSale() {
	ActiveSale sale;
	fillSale( sale );
	sale_db->create( sale );
	fillManagersUnconfirmedSalesTable();
}

void MainWindow::fillSale( ActiveSale & sale ) {
	Manager saler;
	saler.setFirstName( "Dima" );
	saler.setId( current_user_id );
	sale.setSaler( saler );
	QString nameProduct = ui.productComboBox->currentText();
	for ( auto it = products.begin(); it != products.end(); it++ ) {
		if ( ( *it ).getName() == nameProduct ) {
			sale.setProduct( *it );
		}
	}
	sale.setCost( ui.priceSale->value() );
	sale.setCount( ui.countSaleProducts->value() );
}


void MainWindow::clearManagersProductsTable() {
	managerProductsTableModel->clear();
	QStringList horizontalHeader;
    horizontalHeader.append( c->toUnicode( "Название" ) );
    horizontalHeader.append( c->toUnicode( "Комиссия" ) );
	managerProductsTableModel->setHorizontalHeaderLabels( horizontalHeader );
	ui.managersProductTable->setModel( managerProductsTableModel );
    ui.managersProductTable->resizeColumnsToContents();
}

void MainWindow::fillManagersProductTable() {
    clearManagersProductsTable();
	
	auto _products = product_db -> getAll();

    for ( int idx = 0; idx < _products.size(); idx++) {
		Product product = _products[idx];
		products[ product.getId() ] = product;
		QStandardItem *item;
		item = new QStandardItem( product.getName() );
		managerProductsTableModel->setItem( idx, 0, item );
		item = new QStandardItem( QString::number( product.getCommission() ) + "%" );
		managerProductsTableModel->setItem( idx, 1, item );
		ui.productComboBox->addItem( product.getName() );
	}

	ui.deleteProductButton->setEnabled( !products.empty() );
	ui.productComboBox->setEnabled( !products.empty() );
}

void MainWindow::searchManagersProductTable() {
	QString nameProduct = ui.managerProductSearch->text();
	if ( nameProduct != "" ) {
		clearManagersProductsTable();
		for ( auto it = products.begin(); it != products.end(); it++ ) {
			if ( ( *it ).getName() == nameProduct) {
				Product product = ( *it );
				QStandardItem *item;
				item = new QStandardItem( product.getName() );
				managerProductsTableModel->setItem( 0, 0, item );
				item = new QStandardItem( QString::number( product.getCommission() ) + "%" );
				managerProductsTableModel->setItem( 0, 1, item );
			}
		}
	} else {
		fillManagersProductTable();
	}
}
