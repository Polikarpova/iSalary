#include "test_manager_gui.h"

Test_Manager_GUI::Test_Manager_GUI( QSqlDatabase *sql, ManagerPage *managerPage ) {
	this->managerPage = managerPage;
	this->sql = sql;
	product_DB = new Product_DB( sql, "products" );
	product_DB->init();
	sale_DB = new Sale_DB( sql, "sales");
	sale_DB->init();
	user_DB = new UserDB( sql );
	User user;
	user = user_DB->insert( user, UserType::MANAGER );
	manager_id = user.getId();
	managerPage->setCurrentManagerId( manager_id );
	c = QTextCodec::codecForLocale();
}

Test_Manager_GUI::~Test_Manager_GUI() {

}

void Test_Manager_GUI::removeProduct( QString productName ) {
	Product product = product_DB->findByName( productName );
	QSqlQuery query("DELETE FROM products WHERE id = " + QString::number( product.getId() ), *sql);
	bool isOk = query.exec();
}

Product Test_Manager_GUI::createProduct( QString productName, double productCommission ) {
	Product product;
	product.setName( productName );
	product.setCommission( productCommission );
	product_DB->create( product );
	return product;
} 

QString Test_Manager_GUI::findElemInProductTable( int row, int col ){
	return managerPage->productsTableModel->data( managerPage->productsTableModel->index( row, col ) ).toString();
}

QString Test_Manager_GUI::findElemInUnconfirmedTable( int row, int col ){
	return managerPage->unconfirmedSalesTableModel->data( managerPage->unconfirmedSalesTableModel->index( row, col ) ).toString();
}

QString Test_Manager_GUI::findElemInConfirmedTable( int row, int col ){
	return managerPage->confirmedSalesTableModel->data( managerPage->confirmedSalesTableModel->index( row, col ) ).toString();
}

ActiveSale Test_Manager_GUI::createSale( Product product) {
	ActiveSale sale;
	sale.setConfirmDate( QDate::currentDate() );
	sale.setSaleDate( QDate( 2018, 12, 31) );
	sale.setCost( 100 );
	sale.setCount( 3 );
	sale.setProduct( product );
	Manager saler;
	saler.setId( manager_id );
	sale.setSaler( saler );
	sale_DB->create( sale );
	return sale;
}



void Test_Manager_GUI::showProduct() {

	QString exp_product_name = "AAA";
	double product_commission = 1.9;
	QString exp_product_commission = QString::number( product_commission ) + "%";
	createProduct( exp_product_name, product_commission );
	managerPage->refreshPage();

	QCOMPARE( managerPage->currentSalaryOutput->isEnabled(), false );
	QCOMPARE( managerPage->possibleSalaryOutput->isEnabled(), false );
	QCOMPARE( managerPage->productNameOutput->isEnabled(), false );
	QCOMPARE( managerPage->priceSaleInput->isEnabled(), true );
	QCOMPARE( managerPage->dateSaleInput->isEnabled(), true );
	QCOMPARE( managerPage->countSaleProductsInput->isEnabled(), true );
	QCOMPARE( managerPage->addSaleButton->isEnabled(), false );
	QCOMPARE( managerPage->productSearchInput->isEnabled(), true );
	QCOMPARE( managerPage->productTable->isEnabled(), true );
	QCOMPARE( managerPage->confirmedSalesTable->isEnabled(), true );
	QCOMPARE( managerPage->unconfirmedSalesTable->isEnabled(), true );

	managerPage->productTable->setFocus();
	QModelIndex newIndex = managerPage->productTable->model()->index(0, 0);
	managerPage->productTable->setCurrentIndex(newIndex);

	QCOMPARE( managerPage->addSaleButton->isEnabled(), true );

	QString productName = findElemInProductTable( 0, 0 );
	QString productPercent = findElemInProductTable( 0, 1 );

	QCOMPARE( productName, exp_product_name );
	QCOMPARE( productPercent, exp_product_commission );
	QCOMPARE( productName, managerPage->productNameOutput->text() );
	removeProduct( productName );
}

void Test_Manager_GUI::searchProduct() {
	
	Product firstProduct, secondProduct;
	firstProduct.setName( "AAA" );
	firstProduct.setCommission( 1.9 );
	secondProduct.setName( "ABC" );
	secondProduct.setCommission( 33.5 );

	createProduct( firstProduct.getName(), firstProduct.getCommission() );
	createProduct( secondProduct.getName(), secondProduct.getCommission() );

	managerPage->refreshPage();
	managerPage->productSearchInput->setText( "A" );

	QString firstProductName = findElemInProductTable( 0, 0 );
	QString firstProductPercent = findElemInProductTable( 0, 1 );
	QString secondProductName = findElemInProductTable( 1, 0 );
	QString secondProductPercent = findElemInProductTable( 1, 1 );

	QCOMPARE( firstProductName, firstProduct.getName() );
	QCOMPARE( firstProductPercent, QString::number( firstProduct.getCommission() ) + "%" );
	QCOMPARE( secondProductName, secondProduct.getName() );
	QCOMPARE( secondProductPercent, QString::number( secondProduct.getCommission() ) + "%" );

	managerPage->productSearchInput->setText( "AA" );

	firstProductName = findElemInProductTable( 0, 0 );
	firstProductPercent = findElemInProductTable( 0, 1 );
	secondProductName = findElemInProductTable( 1, 0 );
	secondProductPercent = findElemInProductTable( 1, 1 );

	QCOMPARE( firstProductName, firstProduct.getName() );
	QCOMPARE( firstProductPercent, QString::number( firstProduct.getCommission() ) + "%" );
	QCOMPARE( secondProductName, QString( "" ) );
	QCOMPARE( secondProductPercent, QString( "" ) );

	managerPage->productSearchInput->clear();
	removeProduct( firstProduct.getName() );
	removeProduct( secondProduct.getName() );
	managerPage->refreshPage();
}

void Test_Manager_GUI::addUnconfirmedSale() {

	createProduct( "AAA", 3.5 );
	Product product = product_DB->findByName( "AAA" );
	ActiveSale sale = createSale( product );
	managerPage->refreshPage();

	QString productName = findElemInUnconfirmedTable( 0, 0 );
	QString saleDate = findElemInUnconfirmedTable( 0, 1 );
	QString saleCount = findElemInUnconfirmedTable( 0, 2 );
	QString salePrice = findElemInUnconfirmedTable( 0, 3 );
	QString saleCost = findElemInUnconfirmedTable( 0, 4 );
	QString saleSalary = findElemInUnconfirmedTable( 0, 5 );

	QCOMPARE( productName, sale.getProductName() );
	QCOMPARE( saleDate, sale.getSaleDate().toString(Qt::DateFormat::LocalDate) );
	QCOMPARE( saleCount, QString::number( sale.getCount() ) );
	QCOMPARE( salePrice, QString::number( sale.getCost() ) );
	QCOMPARE( saleCost, QString::number( sale.getCost() * sale.getCount() ) );
	QCOMPARE( saleSalary, QString::number( sale.getCost() * sale.getCount() * sale.getProductCommission() / 100 ) );
	
	sale_DB->remove( sale_DB->getActiveAll( manager_id )[0].getId() );
	removeProduct( product.getName() );
	managerPage->refreshPage();
}

void Test_Manager_GUI::removeUnconfirmedSale() {

	createProduct( "AAA", 3.5 );
	Product product = product_DB->findByName( "AAA" );
	ActiveSale sale = createSale( product );
	managerPage->refreshPage();

	QWidget * w = managerPage->unconfirmedSalesTable->indexWidget( managerPage->unconfirmedSalesTableModel->index( 0, 6 ) );
	
	QPushButton * btn = qobject_cast<QPushButton*>( w );
	btn->click();

	QString productName = findElemInUnconfirmedTable( 0, 0 );
	QString saleDate = findElemInUnconfirmedTable( 0, 1 );
	QString saleCount = findElemInUnconfirmedTable( 0, 2 );
	QString salePrice = findElemInUnconfirmedTable( 0, 3 );
	QString saleCost = findElemInUnconfirmedTable( 0, 4 );
	QString saleSalary = findElemInUnconfirmedTable( 0, 5 );
	
	QCOMPARE( productName, c->toUnicode( "Итого:" ) );
	QCOMPARE( saleDate, QString( "" ) );
	QCOMPARE( saleCount, QString( "0" ) );
	QCOMPARE( salePrice, QString( "" ) );
	QCOMPARE( saleCost, QString( "0" ) );
	QCOMPARE( saleSalary, QString( "0" ) );

	removeProduct( product.getName() );
	managerPage->refreshPage();
}

void Test_Manager_GUI::showConfirmedSale() {

	createProduct( "AAA", 3.5 );
	Product product = product_DB->findByName( "AAA" );
	ActiveSale sale = createSale( product );
	sale = sale_DB->getActiveAll( manager_id )[0];
	sale_DB->confirmSale( sale.getId() );
	managerPage->refreshPage();

	QString productName = findElemInConfirmedTable( 0, 0 );
	QString saleDate = findElemInConfirmedTable( 0, 1 );
	QString saleCount = findElemInConfirmedTable( 0, 2 );
	QString salePrice = findElemInConfirmedTable( 0, 3 );
	QString saleCost = findElemInConfirmedTable( 0, 4 );
	QString saleSalary = findElemInConfirmedTable( 0, 5 );
	
	QCOMPARE( productName, sale.getProductName() );
	QCOMPARE( saleDate, sale.getSaleDate().toString(Qt::DateFormat::LocalDate) );
	QCOMPARE( saleCount, QString::number( sale.getCount() ) );
	QCOMPARE( salePrice, QString::number( sale.getCost() ) );
	QCOMPARE( saleCost, QString::number( sale.getCost() * sale.getCount() ) );
	QCOMPARE( saleSalary, QString::number( sale.getCost() * sale.getCount() * sale.getProductCommission() / 100 ) );

	sale_DB->remove( sale.getId() );
	removeProduct( product.getName() );
	managerPage->refreshPage();
}

void Test_Manager_GUI::calcUnconfirmedSalary() {
	createProduct( "AAA", 3.5 );
	Product firstProduct = product_DB->findByName( "AAA" );
	ActiveSale firstSale = createSale( firstProduct );
	createProduct( "ABC", 19.5 );
	Product secondProduct = product_DB->findByName( "ABC" );
	ActiveSale secondSale = createSale( secondProduct );
	managerPage->refreshPage();

	double exp_salary = firstSale.getCount() * firstSale.getCost() * firstProduct.getCommission() / 100 +
		secondSale.getCount() * secondSale.getCost() * secondProduct.getCommission() / 100;

	QString salary = managerPage->possibleSalaryOutput->text();
	QCOMPARE( salary.toDouble(), exp_salary );
	
	QVector<ActiveSale> sales = sale_DB->getActiveAll( manager_id );
	sale_DB->remove( sales[0].getId() );
	sale_DB->remove( sales[1].getId() );
	removeProduct( firstProduct.getName() );
	removeProduct( secondProduct.getName() );
	managerPage->refreshPage();
}

void Test_Manager_GUI::calcConfirmedSalary() {

	createProduct( "AAA", 3.5 );
	Product firstProduct = product_DB->findByName( "AAA" );
	ActiveSale firstSale = createSale( firstProduct );
	createProduct( "ABC", 19.5 );
	Product secondProduct = product_DB->findByName( "ABC" );
	ActiveSale secondSale = createSale( secondProduct );
	firstSale = sale_DB->getActiveAll( manager_id )[0];
	sale_DB->confirmSale( firstSale.getId() );
	secondSale = sale_DB->getActiveAll( manager_id )[1];
	sale_DB->confirmSale( secondSale.getId() );
	managerPage->refreshPage();

	double exp_salary = firstSale.getCount() * firstSale.getCost() * firstProduct.getCommission() / 100 +
		secondSale.getCount() * secondSale.getCost() * secondProduct.getCommission() / 100;

	QString salary = managerPage->currentSalaryOutput->text();
	QCOMPARE( salary.toDouble(), exp_salary );
	
	QVector<ActiveSale> sales = sale_DB->getActiveAll( manager_id );
	sale_DB->remove( sales[0].getId() );
	sale_DB->remove( sales[1].getId() );
	removeProduct( firstProduct.getName() );
	removeProduct( secondProduct.getName() );
	managerPage->refreshPage();
}



void Test_Manager_GUI::cleanupTestCase() {
	QSqlQuery query("DELETE FROM users WHERE id = " + QString::number( manager_id ), *sql);
	bool isOk = query.exec();
}