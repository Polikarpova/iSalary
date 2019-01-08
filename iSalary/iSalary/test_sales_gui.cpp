#include "test_sales_gui.h"

Test_Sales_GUI::Test_Sales_GUI( QSqlDatabase *sql, SalesPage *salesPage ) {
	
	this->salesPage = salesPage;
	this->sql = sql;
	user_DB = new UserDB( sql );
	manager_DB = new ManagerDB( sql, user_DB );
	product_DB = new Product_DB( sql, "products" );
	product_DB->init();
	sale_DB = new Sale_DB( sql, "sales");
	sale_DB->init();
	c = QTextCodec::codecForLocale();
}

Test_Sales_GUI::~Test_Sales_GUI() {

}

void Test_Sales_GUI::removeEmployee( int id ) {
	QSqlQuery query("DELETE FROM users WHERE id = " + QString::number( id ), *sql);
	bool isOk = query.exec();
}

void Test_Sales_GUI::removeProduct( QString productName ) {
	Product product = product_DB->findByName( productName );
	QSqlQuery query("DELETE FROM products WHERE id = " + QString::number( product.getId() ), *sql);
	bool isOk = query.exec();
}

Product Test_Sales_GUI::createProduct( QString productName, double productCommission ) {
	Product product;
	product.setName( productName );
	product.setCommission( productCommission );
	product_DB->create( product );
	return product;
} 

QString Test_Sales_GUI::findElemInManagersTable( int row, int col ){
	return salesPage->managersSalesTable->model()->data( salesPage->managersSalesTable->model()->index( row, col ) ).toString();
}

QString Test_Sales_GUI::findElemInUnconfirmedTable( int row, int col ){
	return salesPage->unconfirmedSalesTable->model()->data( salesPage->unconfirmedSalesTable->model()->index( row, col ) ).toString();
}

QString Test_Sales_GUI::findElemInConfirmedTable( int row, int col ){
	return salesPage->confirmedSalesTable->model()->data( salesPage->confirmedSalesTable->model()->index( row, col ) ).toString();
}

ActiveSale Test_Sales_GUI::createSale( Product product, int manager_id ) {
	ActiveSale sale;
	sale.setConfirmDate( QDate::currentDate() );
	sale.setSaleDate( QDate::currentDate() );
	sale.setCost( 100 );
	sale.setCount( 3 );
	sale.setProduct( product );
	Manager saler;
	saler.setId( manager_id );
	sale.setSaler( saler );
	sale_DB->create( sale );
	return sale;
}

void Test_Sales_GUI::compareRowInUnconfirmedTable( QString exp_FIO, ActiveSale sale, int row ) {
	
	QString FIO = findElemInUnconfirmedTable( row, 2 );
	QString saleDate = findElemInUnconfirmedTable( row, 3 );
	QString productName = findElemInUnconfirmedTable( row, 4 );
	int countSale = findElemInUnconfirmedTable( row, 5 ).toInt();
	double costSale = findElemInUnconfirmedTable( row, 6 ).toDouble();
	double productPercent = findElemInUnconfirmedTable( row, 7 ).toDouble();

	QCOMPARE( exp_FIO, FIO );
	QCOMPARE( saleDate, sale.getSaleDate().toString( Qt::DateFormat::ISODate ) );
	QCOMPARE( productName, sale.getProductName() );
	QCOMPARE( countSale, sale.getCount() );
	QCOMPARE( costSale, sale.getCost() * sale.getCount() );
	QCOMPARE( productPercent, sale.getProductCommission() );
}

void Test_Sales_GUI::compareRowInConfirmedTable( QString exp_FIO, ActiveSale sale, int row ) {
	
	QString FIO = findElemInConfirmedTable( row, 2 );
	QString confirmDate = findElemInConfirmedTable( row, 3 );
	QString saleDate = findElemInConfirmedTable( row, 4 );
	QString productName = findElemInConfirmedTable( row, 5 );
	int countSale = findElemInConfirmedTable( row, 6 ).toInt();
	double costSale = findElemInConfirmedTable( row, 7 ).toDouble();
	double productPercent = findElemInConfirmedTable( row, 8 ).toDouble();

	QCOMPARE( exp_FIO, FIO );
	QCOMPARE( confirmDate, sale.getConfirmDate().toString( Qt::DateFormat::ISODate ) );
	QCOMPARE( saleDate, sale.getSaleDate().toString( Qt::DateFormat::ISODate ) );
	QCOMPARE( productName, sale.getProductName() );
	QCOMPARE( countSale, sale.getCount() );
	QCOMPARE( costSale, sale.getCost() * sale.getCount() );
	QCOMPARE( productPercent, sale.getProductCommission() );
}

void Test_Sales_GUI::unconfirmedTableIsEmpty() {
	
	QString FIO = findElemInUnconfirmedTable( 0, 2 );
	QString saleDate = findElemInUnconfirmedTable( 0, 3 );
	QString productName = findElemInUnconfirmedTable( 0, 4 );
	int countSale = findElemInUnconfirmedTable( 0, 5 ).toInt();
	double costSale = findElemInUnconfirmedTable( 0, 6 ).toDouble();
	QString productPercent = findElemInUnconfirmedTable( 0, 7 );
	
	QCOMPARE( FIO, QString( "" ) );
	QCOMPARE( saleDate, QString( "" ) );
	QCOMPARE( productName, QString( "" ) );
	QCOMPARE( countSale, 0 );
	QCOMPARE( costSale, 0.0 );
	QCOMPARE( productPercent, QString( "" ) );
}

void Test_Sales_GUI::confirmedTableIsEmpty() {
	
	QString FIO = findElemInConfirmedTable( 0, 2 );
	QString confirmDate = findElemInConfirmedTable( 0, 3 );
	QString saleDate = findElemInConfirmedTable( 0, 4 );
	QString productName = findElemInConfirmedTable( 0, 5 );
	int countSale = findElemInConfirmedTable( 0, 6 ).toInt();
	double costSale = findElemInConfirmedTable( 0, 7 ).toDouble();
	QString productPercent = findElemInConfirmedTable( 0, 8 );
	
	QCOMPARE( FIO, QString( "" ) );
	QCOMPARE( confirmDate, QString( "" ) );
	QCOMPARE( saleDate, QString( "" ) );
	QCOMPARE( productName, QString( "" ) );
	QCOMPARE( countSale, 0 );
	QCOMPARE( costSale, 0.0 );
	QCOMPARE( productPercent, QString( "" ) );
}



void Test_Sales_GUI::initTestCase() {

}

void Test_Sales_GUI::showCountManagerSales() {

	User user;
	user = user_DB->insert( user, UserType::MANAGER );
	int manager_id = user.getId();

	QString firstName = "Ivan";
	QString secondName = "Ivanov";
	QString thirdName = "Ivanovich";
	QString exp_FIO = secondName + " " + firstName + " " + thirdName;

	Manager manager;
	manager.setId( manager_id );
	manager.setFirstName( firstName );
	manager.setSecondName( secondName );
	manager.setThirdName( thirdName );
	manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
	manager.setPassportSerial( "1000" );
	manager.setPassportNumber( "100000" );
	manager.setPassportSource( "ABC" );
	manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
	manager.setAddress( "ABC" );
	manager.setINN( "012345678901" );

	manager_DB->update( manager );

	Product product = createProduct( "ABC", 13.5 );

	createSale( product, manager_id ); 
	createSale( product, manager_id ); 

	salesPage->refreshPage();

	QString FIO = findElemInManagersTable( 0, 1 );
	int countConfirmSales = findElemInManagersTable( 0, 2 ).toInt();
	int countUnconfirmSales = findElemInManagersTable( 0, 3 ).toInt();

	QCOMPARE( exp_FIO, FIO );
	QCOMPARE( countConfirmSales, 0 );
	QCOMPARE( countUnconfirmSales, 2 );

	sale_DB->confirmSale( sale_DB->getActiveAll( manager_id )[0].getId() );

	salesPage->refreshPage();

	FIO = findElemInManagersTable( 0, 1 );
	countConfirmSales = findElemInManagersTable( 0, 2 ).toInt();
	countUnconfirmSales = findElemInManagersTable( 0, 3 ).toInt();

	QCOMPARE( exp_FIO, FIO );
	QCOMPARE( countConfirmSales, 1 );
	QCOMPARE( countUnconfirmSales, 1 );

	QVector<ActiveSale> sales = sale_DB->getActiveAll( manager_id );
	sale_DB->remove( sales[0].getId() );
	sale_DB->remove( sales[1].getId() );
	removeProduct( product.getName() );
	removeEmployee( manager_id );

	salesPage->refreshPage();
}

void Test_Sales_GUI::showManagerUnconfirmedSales() {

	User user;
	user = user_DB->insert( user, UserType::MANAGER );
	int manager_id = user.getId();

	QString firstName = "Ivan";
	QString secondName = "Ivanov";
	QString thirdName = "Ivanovich";
	QString exp_FIO = secondName + " " + firstName + " " + thirdName;

	Manager manager;
	manager.setId( manager_id );
	manager.setFirstName( firstName );
	manager.setSecondName( secondName );
	manager.setThirdName( thirdName );

	manager_DB->update( manager );

	Product first_product = createProduct( "ABC", 13.5 );
	ActiveSale first_sale = createSale( first_product, manager_id );

	Product second_product = createProduct( "AAA", 55 );
	ActiveSale second_sale = first_sale;
	second_sale.setProduct( second_product );
	second_sale.setCount( 5 );
	second_sale.setCost( 777 );
	sale_DB->create( second_sale );

	salesPage->refreshPage();

	compareRowInUnconfirmedTable( exp_FIO, first_sale, 0);
	compareRowInUnconfirmedTable( exp_FIO, second_sale, 1);

	QVector<ActiveSale> sales = sale_DB->getActiveAll( manager_id );
	sale_DB->remove( sales[0].getId() );
	sale_DB->remove( sales[1].getId() );
	removeProduct( first_product.getName() );
	removeProduct( second_product.getName() );
	removeEmployee( manager_id );

	salesPage->refreshPage();
}

void Test_Sales_GUI::showManagerConfirmedSales() {

	User user;
	user = user_DB->insert( user, UserType::MANAGER );
	int manager_id = user.getId();

	QString firstName = "Ivan";
	QString secondName = "Ivanov";
	QString thirdName = "Ivanovich";
	QString exp_FIO = secondName + " " + firstName + " " + thirdName;

	Manager manager;
	manager.setId( manager_id );
	manager.setFirstName( firstName );
	manager.setSecondName( secondName );
	manager.setThirdName( thirdName );
	manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
	manager.setPassportSerial( "1000" );
	manager.setPassportNumber( "100000" );
	manager.setPassportSource( "ABC" );
	manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
	manager.setAddress( "ABC" );
	manager.setINN( "012345678901" );

	manager_DB->update( manager );

	Product first_product = createProduct( "ABC", 13.5 );
	ActiveSale first_sale = createSale( first_product, manager_id );

	Product second_product = createProduct( "AAA", 55 );
	ActiveSale second_sale = first_sale;
	second_sale.setProduct( second_product );
	second_sale.setCount( 5 );
	second_sale.setCost( 777 );
	sale_DB->create( second_sale );

	sale_DB->confirmSale( sale_DB->getActiveAll( manager_id )[0].getId() );
	sale_DB->confirmSale( sale_DB->getActiveAll( manager_id )[1].getId() );

	salesPage->refreshPage();

	QVector<ActiveSale> sales = sale_DB->getActiveAll( manager_id );
	first_sale = sales[0];
	second_sale = sales[1];

	compareRowInConfirmedTable( exp_FIO, first_sale, 0);
	compareRowInConfirmedTable( exp_FIO, second_sale, 1);

	sale_DB->remove( sales[0].getId() );
	sale_DB->remove( sales[1].getId() );
	removeProduct( first_product.getName() );
	removeProduct( second_product.getName() );
	removeEmployee( manager_id );

	salesPage->refreshPage();
}

void Test_Sales_GUI::confirmSale() {

	User user;
	user = user_DB->insert( user, UserType::MANAGER );
	int manager_id = user.getId();

	QString firstName = "Ivan";
	QString secondName = "Ivanov";
	QString thirdName = "Ivanovich";
	QString exp_FIO = secondName + " " + firstName + " " + thirdName;
	QDate date = QDate::currentDate();
	QString str_date = date.toString(Qt::DateFormat::LocalDate);

	Manager manager;
	manager.setId( manager_id );
	manager.setFirstName( firstName );
	manager.setSecondName( secondName );
	manager.setThirdName( thirdName );
	manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
	manager.setPassportSerial( "1000" );
	manager.setPassportNumber( "100000" );
	manager.setPassportSource( "ABC" );
	manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
	manager.setAddress( "ABC" );
	manager.setINN( "012345678901" );

	manager_DB->update( manager );

	Product first_product = createProduct( "ABC", 13.5 );
	ActiveSale first_sale = createSale( first_product, manager_id );
	salesPage->refreshPage();

	QWidget * w = salesPage->unconfirmedSalesTable->indexWidget( salesPage->unconfirmedSalesTable->model()->index( 0, 1 ) );
	
	QPushButton * btn = qobject_cast<QPushButton*>( w );
	btn->click();

	compareRowInConfirmedTable( exp_FIO, first_sale, 0);
	unconfirmedTableIsEmpty();

	QVector<ActiveSale> sales = sale_DB->getActiveAll( manager_id );
	sale_DB->remove( sales[0].getId() );
	removeProduct( first_product.getName() );
	removeEmployee( manager_id );

	salesPage->refreshPage();
}

void Test_Sales_GUI::unconfirmSale() {

	User user;
	user = user_DB->insert( user, UserType::MANAGER );
	int manager_id = user.getId();

	QString firstName = "Ivan";
	QString secondName = "Ivanov";
	QString thirdName = "Ivanovich";
	QString exp_FIO = secondName + " " + firstName + " " + thirdName;
	QDate date = QDate::currentDate();
	QString str_date = date.toString(Qt::DateFormat::LocalDate);

	Manager manager;
	manager.setId( manager_id );
	manager.setFirstName( firstName );
	manager.setSecondName( secondName );
	manager.setThirdName( thirdName );
	manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
	manager.setPassportSerial( "1000" );
	manager.setPassportNumber( "100000" );
	manager.setPassportSource( "ABC" );
	manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
	manager.setAddress( "ABC" );
	manager.setINN( "012345678901" );

	manager_DB->update( manager );

	Product first_product = createProduct( "ABC", 13.5 );
	ActiveSale first_sale = createSale( first_product, manager_id );
	salesPage->refreshPage();

	QWidget * w = salesPage->unconfirmedSalesTable->indexWidget( salesPage->unconfirmedSalesTable->model()->index( 0, 1 ) );
	QPushButton * btn = qobject_cast<QPushButton*>( w );
	btn->click();

	w = salesPage->confirmedSalesTable->indexWidget( salesPage->confirmedSalesTable->model()->index( 0, 1 ) );
	btn = qobject_cast<QPushButton*>( w );
	btn->click();

	compareRowInUnconfirmedTable( exp_FIO, first_sale, 0);
	confirmedTableIsEmpty();

	QVector<ActiveSale> sales = sale_DB->getActiveAll( manager_id );
	sale_DB->remove( sales[0].getId() );
	removeProduct( first_product.getName() );
	removeEmployee( manager_id );

	salesPage->refreshPage();
}

void Test_Sales_GUI::showAllManagersSales() {

	User first_user;
	first_user = user_DB->insert( first_user, UserType::MANAGER );
	int first_manager_id = first_user.getId();

	QString firstName = "Ivan";
	QString secondName = "Ivanov";
	QString thirdName = "Ivanovich";
	QString first_exp_FIO = secondName + " " + firstName + " " + thirdName;

	Manager manager;
	manager.setId( first_manager_id );
	manager.setFirstName( firstName );
	manager.setSecondName( secondName );
	manager.setThirdName( thirdName );

	manager_DB->update( manager );

	Product first_product = createProduct( "ABC", 15.3 );
	Product second_product = createProduct( "AAA", 35 );
	ActiveSale first_sale = createSale( first_product, first_manager_id );
	ActiveSale second_sale = createSale( second_product, first_manager_id );

	sale_DB->confirmSale( sale_DB->getActiveAll( first_manager_id )[1].getId() );

	User second_user;
	second_user = user_DB->insert( second_user, UserType::MANAGER );
	int second_manager_id = second_user.getId();

	firstName = "Dima";
	secondName = "Sokolov";
	thirdName = "Ivanovich";
	QString second_exp_FIO = secondName + " " + firstName + " " + thirdName;

	manager.setId( second_manager_id );
	manager.setFirstName( firstName );
	manager.setSecondName( secondName );
	manager.setThirdName( thirdName );

	manager_DB->update( manager );

	ActiveSale third_sale = createSale( first_product, second_manager_id );
	ActiveSale fourth_sale = createSale( second_product, second_manager_id );

	salesPage->refreshPage();

	salesPage->managersSalesTable->setFocus();
	QModelIndex newIndex = salesPage->managersSalesTable->model()->index(0, 1);
	salesPage->managersSalesTable->setCurrentIndex( newIndex );
	salesPage->managersSalesTable->clicked( newIndex );

	compareRowInUnconfirmedTable( first_exp_FIO, first_sale, 0);
	compareRowInConfirmedTable( first_exp_FIO, second_sale, 0);

	salesPage->managersSalesTable->setFocus();
	newIndex = salesPage->managersSalesTable->model()->index(1, 1);
	salesPage->managersSalesTable->setCurrentIndex( newIndex );
	salesPage->managersSalesTable->clicked( newIndex );

	compareRowInUnconfirmedTable( second_exp_FIO, third_sale, 0);
	compareRowInUnconfirmedTable( second_exp_FIO, fourth_sale, 1);

	salesPage->salesForAllButton->click();

	compareRowInUnconfirmedTable( first_exp_FIO, first_sale, 0);
	compareRowInUnconfirmedTable( second_exp_FIO, third_sale, 1);
	compareRowInUnconfirmedTable( second_exp_FIO, fourth_sale, 2);
	compareRowInConfirmedTable( first_exp_FIO, second_sale, 0);

	QVector<ActiveSale> sales = sale_DB->getActiveAll( first_manager_id );
	sale_DB->remove( sales[0].getId() );
	sale_DB->remove( sales[1].getId() );
	sales = sale_DB->getActiveAll( second_manager_id );
	sale_DB->remove( sales[0].getId() );
	sale_DB->remove( sales[1].getId() );
	removeProduct( first_product.getName() );
	removeProduct( second_product.getName() );
	removeEmployee( first_manager_id );
	removeEmployee( second_manager_id );

	salesPage->refreshPage();
}