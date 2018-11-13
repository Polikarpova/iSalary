#include "mainwindow.h"
MainWindow::MainWindow( AuthPage* authPage, EmployeesPage* employeesPage, SalesPage* salesPage, SalaryPage* salaryPage, QWidget *parent ) : QMainWindow(parent) {
	ui.setupUi(this);
	
	//блокировка вкладки корректировки
	ui.tabWidget->setTabEnabled(2, false);
	ui.tabWidget->setTabEnabled(4, false);
	ui.tabWidget->setTabToolTip(2, "Реализация отменена");
	ui.tabWidget->setTabToolTip(4, "Заблокировано до лучших времен");

    ui.auth_program_stackedWidget->setCurrentIndex( AUTH_WIDGET);

	createHorizontalTabs();

    this->errorHandler = new ErrorMessageHandler( this);

    this->authPage = authPage;
    this->authPage->setUI( ui.loginInput, ui.passwordInput, ui.enterButton, ui.errorLabel);

    this->employeesPage = employeesPage;
    this->employeesPage->setUI(
        ui.managersTable,
        ui.login,
        ui.password,
        ui.firstName,
        ui.secondName,
        ui.thirdName,
        ui.dateOfBirth,
        ui.pasportSeries,
        ui.pasportNumber,
        ui.sexGroup,
        ui.maleRButton,
        ui.femaleRButton,
        ui.pasportSourse,
        ui.dateOfReceipt,
        ui.registration,
        ui.INN,
        ui.managersButtonsStackedWidget,
        ui.managerEditButton,
        ui.addManagerButton,
        ui.saveManagerButton,
        ui.cancelManagerButton,
        ui.managerSubmitAddButton,
        ui.managerCancelAddButton
    );
    this->employeesPage->setErrorHandler( errorHandler);
    connect( ui.tabWidget, &QTabWidget::currentChanged, this, &MainWindow::refreshBossPage);
    //this->employeesPage->refreshList();

	this->salesPage = salesPage;
	this->salesPage->setUI(ui.salesDateInput, ui.managersSalesTable, ui.unconfirmedSalesTable, ui.confirmedSalesTable);
	this->salesPage->setErrorHandler( errorHandler);

	this->salaryPage = salaryPage;
	this->salaryPage->setUI(
		ui.salaryAccountingPeriod, 
		ui.salaryTable, 
		ui.salaryTotalTable, 
		ui.managerFIOLabel, 
		ui.salaryPasportSeries, 
		ui.salaryPasportNumber, 
		ui.salaryPasportSourse, 
		ui.salaryDateOfReceipt, 
		ui.salaryMaleRButton, 
		ui.salaryFemaleRButton, 
		ui.salaryINN, 
		ui.closeAccountingPeriod, 
		ui.salesButton, 
		ui.dataButton	
	);
	this->salaryPage->setErrorHandler( errorHandler);

    connect(this->authPage, &AuthPage::userLoggedIn, this, &MainWindow::enterProgram);

	connect( ui.quitButton, &QPushButton::clicked, this, &MainWindow::exit);

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
    
    if( _db.lastError().type() != QSqlError::NoError){
        QMessageBox::critical( 0, "Nu epta", _db.lastError().text());
    }

	QString s = _db.lastError().text();
	product_db = new Product_DB( _db, "products" );
    product_db->init();

	initProductWindow();

	ui.productTable->setEditTriggers(0);
	ui.productTable->horizontalHeader()->setStretchLastSection(true);
	connect( ui.productTable->selectionModel(), SIGNAL( currentChanged ( const QModelIndex &, const QModelIndex & ) ), this, SLOT( showProduct() ) );

	connect( ui.addProductButton, SIGNAL( clicked() ), this, SLOT( directAddProduct() ) );
	connect( ui.productCancelAddButton, SIGNAL( clicked() ), this, SLOT( directAddProduct() ) );
	connect( ui.productSubmitAddButton, SIGNAL( clicked() ), this, SLOT( addProduct() ) );

	connect( ui.editProductButton, SIGNAL( clicked() ), this, SLOT( directUpdateProduct() ) );
	connect( ui.cancelProductButton, SIGNAL( clicked() ), this, SLOT( directUpdateProduct() ) );
	connect( ui.saveProductButton, SIGNAL( clicked() ), this, SLOT( updateProduct() ) );

	connect( ui.deleteProductButton, SIGNAL( clicked() ), this, SLOT( removeProduct() ) );

	connect( ui.searchButton, SIGNAL( clicked() ), this, SLOT( searchProduct() ) );

	this->current_user_id = -1;
	sale_db = new Sale_DB( _db, "sales" );

	initManagerWindow();

	ui.managersProductTable->setEditTriggers(0);
	ui.confirmedSales->setEditTriggers(0);
	ui.unconfirmedSales->setEditTriggers(0);
	ui.managersProductTable->horizontalHeader()->setStretchLastSection(true);
	ui.confirmedSales->horizontalHeader()->setStretchLastSection(true);
	ui.unconfirmedSales->horizontalHeader()->setStretchLastSection(true);

	connect( ui.managerProductSearchButton, SIGNAL( clicked() ), this, SLOT( searchManagersProductTable() ) );
	connect( ui.addSaleButton, SIGNAL( clicked() ), this, SLOT( addSale() ) );

}

void MainWindow::enterProgram( const UserDTO& user, UserType userType){
    if( userType == MANAGER) {
        ui.boss_manager_stackedWidget->setCurrentIndex( MANAGER_WIDGET);
    } else if ( userType == BOSS ){
        ui.boss_manager_stackedWidget->setCurrentIndex( BOSS_WIDGET);
        this->refreshBossPage(0);
    }
    ui.auth_program_stackedWidget->setCurrentIndex( PROGRAM_WIDGET);

	this->current_user_id = this->authPage->currentUserId();
	this->updateManagerWindow();
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

void MainWindow::refreshBossPage( int page){

    switch( page){
        case PAGE_EMPLOYEES: this->employeesPage->refreshList(); break;
		case PAGE_SALES: this->salesPage->refreshPage(); break;
		case PAGE_SALARY: this->salaryPage->refreshPage(); break;
        default:;
    }
}

//
void MainWindow::initManagerWindow() {
	unconfirmedSalesTableModel = new QStandardItemModel;
	confirmedSalesTableModel = new QStandardItemModel;
}

void MainWindow::updateManagerWindow() {

	fillManagersProductTable();
	fillManagersConfirmedSalesTable();
	fillManagersUnconfirmedSalesTable();
}

void MainWindow::clearManagersConfirmedSalesTable() {
	confirmedSalesTableModel->clear();
	QStringList horizontalHeader;
    horizontalHeader.append( toUnicode( "Название" ) );
    horizontalHeader.append( toUnicode( "Количество" ) );
	horizontalHeader.append( toUnicode( "Стоимость" ) );
	horizontalHeader.append( toUnicode( "Процент комиссии" ) );
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
	item = new QStandardItem(  toUnicode( "Итого:" ) );
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
    horizontalHeader.append( toUnicode( "Название" ) );
    horizontalHeader.append( toUnicode( "Количество" ) );
	horizontalHeader.append( toUnicode( "Стоимость" ) );
	horizontalHeader.append( toUnicode( "Процент комиссии" ) );
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
	item = new QStandardItem(  toUnicode( "Итого:" ) );
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
	productsTableModel->clear();
	QStringList horizontalHeader;
    horizontalHeader.append( toUnicode( "Название" ) );
    horizontalHeader.append( toUnicode( "Комиссия" ) );
	productsTableModel->setHorizontalHeaderLabels( horizontalHeader );
	ui.managersProductTable->setModel( productsTableModel );
    ui.managersProductTable->resizeColumnsToContents();
}

void MainWindow::fillManagersProductTable() {
    clearManagersProductsTable();
	ui.productComboBox->clear();

	auto _products = product_db -> getAll();

    for ( int idx = 0; idx < _products.size(); idx++) {
		Product product = _products[idx];
		products[ product.getId() ] = product;
		QStandardItem *item;
		item = new QStandardItem( product.getName() );
		productsTableModel->setItem( idx, 0, item );
		item = new QStandardItem( QString::number( product.getCommission() ) + "%" );
		productsTableModel->setItem( idx, 1, item );
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
				productsTableModel->setItem( 0, 0, item );
				item = new QStandardItem( QString::number( product.getCommission() ) + "%" );
				productsTableModel->setItem( 0, 1, item );
			}
		}
	} else {
		fillManagersProductTable();
	}
}

//
void MainWindow::initProductWindow() {
	productsTableModel = new QStandardItemModel;
	fillProducts();
	status = DEFAULT;
}

void MainWindow::setInputsEnabledPageProducts( bool isEnabled ) {
	ui.productName->setEnabled( isEnabled );
	ui.productPercent->setEnabled( isEnabled );
}

void MainWindow::clearInputsPageProducts() {
	ui.productName->clear();
	ui.productPercent->clear();
}

void MainWindow::directAddProduct() {
	if ( status == DEFAULT ) {
		ui.productButtonsStackedWidget->setCurrentIndex( 2 );
		ui.addProductButton->setEnabled( false );
		ui.productTable->setEnabled( false );
		setInputsEnabledPageProducts( true );
		clearInputsPageProducts();
		status = ADD_PRODUCT;
	} else {
		ui.productButtonsStackedWidget->setCurrentIndex( 0 );
		ui.addProductButton->setEnabled( true );
		ui.productTable->setEnabled( true );
		setInputsEnabledPageProducts( false );
		status = DEFAULT;
	}
}

void MainWindow::addProduct() {
	Product product;
	fillProduct( product );
	product_db->create( product );
	fillProducts();
	directAddProduct();
}

void MainWindow::directUpdateProduct() {
	bool isSelected = !ui.productTable->selectionModel()->selectedIndexes().empty();
	if ( status == DEFAULT && isSelected == true ) {
		ui.productButtonsStackedWidget->setCurrentIndex( 1 );
		ui.productTable->setEnabled( false );
		setInputsEnabledPageProducts( true );
		status = UPDATE_PRODUCT;
	} else {
		ui.productButtonsStackedWidget->setCurrentIndex( 0 );
		ui.productTable->setEnabled( true );
		setInputsEnabledPageProducts( false );
		status = DEFAULT;
	}
}

void MainWindow::updateProduct() {
	QString id = productsTableModel->data( productsTableModel->index( ui.productTable->currentIndex().row(), 2 ) ).toString();
	Product product = products[ id.toInt() ];
	fillProduct( product );
	product_db->update( product );
	fillProducts();
	directUpdateProduct();
}

void MainWindow::removeProduct() {
	bool isSelected = !ui.productTable->selectionModel()->selectedIndexes().empty();
	if ( isSelected ) {
		int row = ui.productTable->currentIndex().row();
		QString id = productsTableModel->data( productsTableModel->index( ui.productTable->currentIndex().row(), 2 ) ).toString();
		product_db->remove( id.toInt() );
		fillProducts();
		clearInputsPageProducts();
	}
}

void MainWindow::showProduct() {
	QString id = productsTableModel->data( productsTableModel->index( ui.productTable->currentIndex().row(), 2 ) ).toString();
	Product product = products[ id.toInt() ];
	ui.productName->setText( product.getName() );
	ui.productPercent->setValue( product.getCommission() );
}

void MainWindow::fillProduct( Product & product ) {
	int id;
	product.setName( ui.productName->text() );
	product.setCommission( ui.productPercent->value() );
}

void MainWindow::clearTable() {
	productsTableModel->clear();
	QStringList horizontalHeader;
    horizontalHeader.append( toUnicode( "Название" ) );
    horizontalHeader.append( toUnicode( "Комиссия" ) );
	productsTableModel->setHorizontalHeaderLabels( horizontalHeader );
	ui.productTable->setModel( productsTableModel );
    ui.productTable->resizeColumnsToContents();
}

void MainWindow::fillProducts() {
    clearTable();
	
	auto _products = product_db -> getAll();

    for ( int idx = 0; idx < _products.size(); idx++) {
		Product product = _products[idx];
		products[ product.getId() ] = product;
		QStandardItem *item;
		item = new QStandardItem( product.getName() );
		productsTableModel->setItem( idx, 0, item );
		item = new QStandardItem( QString::number( product.getCommission() ) + "%" );
		productsTableModel->setItem( idx, 1, item );
		item = new QStandardItem( QString::number( product.getId() ) );
		productsTableModel->setItem( idx, 2, item );
	}

	ui.deleteProductButton->setEnabled( !products.empty() );
}

void MainWindow::searchProduct() {
	QString nameProduct = ui.productSearch->text();
	if ( nameProduct != "" ) {
		clearTable();
		for ( auto it = products.begin(); it != products.end(); it++ ) {
			if ( ( *it ).getName() == nameProduct) {
				Product product = ( *it );
				QStandardItem *item;
				item = new QStandardItem( product.getName() );
				productsTableModel->setItem( 0, 0, item );
				item = new QStandardItem( QString::number( product.getCommission() ) + "%" );
				productsTableModel->setItem( 0, 1, item );
				item = new QStandardItem( QString::number( product.getId() ) );
				productsTableModel->setItem( 0, 2, item );
			}
		}
	} else {
		fillProducts();
	}
}

void MainWindow::exit(){
	QMessageBox::critical(this, "Прощай","Был пацан - нет пацана");
	ui.auth_program_stackedWidget->setCurrentIndex( AUTH_WIDGET);
}

MainWindow::~MainWindow() {
    delete this->errorHandler;
}
