#include "mainwindow.h"
#include <qlabel.h>
#include <qtextcodec.h>


MainWindow::MainWindow( QWidget *parent ) : QMainWindow(parent) {
	ui.setupUi(this);
	c = QTextCodec::codecForLocale();
	createHorizontalTabs();


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

	initProductWindow();

	connect( ui.productTable->selectionModel(), SIGNAL( currentChanged ( const QModelIndex &, const QModelIndex & ) ), this, SLOT( showProduct() ) );

	connect( ui.addProductButton, SIGNAL( clicked() ), this, SLOT( directAddProduct() ) );
	connect( ui.productCancelAddButton, SIGNAL( clicked() ), this, SLOT( directAddProduct() ) );
	connect( ui.productSubmitAddButton, SIGNAL( clicked() ), this, SLOT( addProduct() ) );

	connect( ui.editProductButton, SIGNAL( clicked() ), this, SLOT( directUpdateProduct() ) );
	connect( ui.cancelProductButton, SIGNAL( clicked() ), this, SLOT( directUpdateProduct() ) );
	connect( ui.saveProductButton, SIGNAL( clicked() ), this, SLOT( updateProduct() ) );

	connect( ui.deleteProductButton, SIGNAL( clicked() ), this, SLOT( removeProduct() ) );

	connect( ui.searchButton, SIGNAL( clicked() ), this, SLOT( searchProduct() ) );


	initManagerWindow();

	connect( ui.managerProductSearchButton, SIGNAL( clicked() ), this, SLOT( searchManagersProductTable() ) );
}

MainWindow::~MainWindow() {

}

void MainWindow::createHorizontalTabs() {

	QStringList tabs_text;
	tabs_text << c->toUnicode( "Сотрудники" ) << c->toUnicode( "Товары" ) << c->toUnicode( "Корректировки" ) 
		<< c->toUnicode( "Продажи" ) << c->toUnicode( "Статистика" ) << c->toUnicode( "Зарплата");
	QTabWidget *tabw = ui.tabWidget;
	
	for ( int i = 0; i < 6; i++ ) {
		tabw->setTabText( i, "" );
	}
	
	QTabBar *tabbar = tabw->tabBar();

	for( int i = 0; i < 6; i++) {
		QLabel *lbl = new QLabel();
		lbl->setText(tabs_text[i]);
		tabbar->setTabButton(i, QTabBar::LeftSide, lbl);
	}
}

void MainWindow::initManagerWindow() {
	productsTableModel = new QStandardItemModel;
	fillManagetsProductTable();
}

void MainWindow::clearManagersProductsTable() {
	productsTableModel->clear();
	QStringList horizontalHeader;
    horizontalHeader.append( c->toUnicode( "Название товара" ) );
    horizontalHeader.append( c->toUnicode( "Процент комиссии" ) );
	productsTableModel->setHorizontalHeaderLabels( horizontalHeader );
	ui.managersProductTable->setModel( productsTableModel );
    ui.managersProductTable->resizeColumnsToContents();
}

void MainWindow::fillManagetsProductTable() {
    clearManagersProductsTable();
	
	auto _products = product_db -> getAll();

    for ( int idx = 0; idx < _products.size(); idx++) {
		Product product = _products[idx];
		products[ product.getId() ] = product;
		QStandardItem *item;
		item = new QStandardItem( product.getName() );
		productsTableModel->setItem( idx, 0, item );
		item = new QStandardItem( QString::number( product.getCommission() ) + "%" );
		productsTableModel->setItem( idx, 1, item );
	}

	ui.addSaleButton->setEnabled( !products.empty() );
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
		fillManagetsProductTable();
	}
}





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
    horizontalHeader.append( c->toUnicode( "Название товара" ) );
    horizontalHeader.append( c->toUnicode( "Процент комиссии" ) );
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