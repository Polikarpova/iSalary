#include "mainwindow.h"
#include <qlabel.h>
#include <qtextcodec.h>


MainWindow::MainWindow( QWidget *parent ) : QMainWindow(parent) {
	ui.setupUi(this);
	c = QTextCodec::codecForLocale();
	createHorizontalTabs();


	auto drivers =  QSqlDatabase::drivers();
	QString mes = "";

    for ( auto it = drivers.begin(); it != drivers.end(); it++)
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
	fillProducts();
}

MainWindow::~MainWindow() {

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

void MainWindow::initProductWindow() {
	productsTableModel = new QStandardItemModel;
	QStringList horizontalHeader;
    horizontalHeader.append( c->toUnicode( "Название товара" ) );
    horizontalHeader.append( c->toUnicode( "Процент комиссии" ) );
	productsTableModel->setHorizontalHeaderLabels( horizontalHeader );
	ui.productTable->setModel( productsTableModel );
    ui.productTable->resizeColumnsToContents();
}

void MainWindow::fillProducts() {
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
}