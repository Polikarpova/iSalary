#include "test_statistic_gui.h"

Test_Statistic_GUI::Test_Statistic_GUI( QSqlDatabase *sql, StatisticPage *statisticPage ) {

	this->statisticPage = statisticPage;
	this->sql = sql;
	user_DB = new UserDB( sql );
	manager_DB = new ManagerDB( sql, user_DB );
	product_DB = new Product_DB( sql, "products" );
	product_DB->init();
	sale_DB = new Sale_DB( sql, "sales");
	sale_DB->init();
	c = QTextCodec::codecForLocale();
}

Test_Statistic_GUI::~Test_Statistic_GUI()
{

}

void Test_Statistic_GUI::removeEmployee( int id ) {
	QSqlQuery query("DELETE FROM users WHERE id = " + QString::number( id ), *sql);
	bool isOk = query.exec();
}

void Test_Statistic_GUI::removeProduct( QString productName ) {
	Product product = product_DB->findByName( productName );
	QSqlQuery query("DELETE FROM products WHERE id = " + QString::number( product.getId() ), *sql);
	bool isOk = query.exec();
}

Product Test_Statistic_GUI::createProduct( QString productName, double productCommission ) {
	Product product;
	product.setName( productName );
	product.setCommission( productCommission );
	product_DB->create( product );
	return product;
} 

QString Test_Statistic_GUI::findElemInStatisticTable( int row, int col ){
	return statisticPage->statisticTable->model()->data( statisticPage->statisticTable->model()->index( row, col ) ).toString();
}

QString Test_Statistic_GUI::findElemInStatisticSalesTable( int row, int col ){
	return statisticPage->statisticSalesTable->model()->data( statisticPage->statisticSalesTable->model()->index( row, col ) ).toString();
}

ActiveSale Test_Statistic_GUI::createSale( Product product, QDate saleDate, int manager_id ) {
	ActiveSale sale;
	sale.setConfirmDate( QDate::currentDate() );
	sale.setSaleDate( saleDate );
	sale.setCost( 100 );
	sale.setCount( 3 );
	sale.setProduct( product );
	Manager saler;
	saler.setId( manager_id );
	sale.setSaler( saler );
	sale_DB->create( sale );
	sale = sale_DB->getActiveAll( manager_id ).last();
	return sale;
}

void Test_Statistic_GUI::compareRowInStatisticTable( Manager manager, int row ) {
	
	QString exp_FIO = manager.getSecondName() + " " +  manager.getFirstName() + " " + manager.getThirdName();

	QVector<ActiveSale>sales = sale_DB->getActiveAll( manager.getId() );

	double currentSalary = 0;
	double allSalary = 0;
	double previousSalary = 0;
	double exp_allCost = 0;
	int exp_countSales = 0;
	for ( int i = 0; i < sales.size(); i++ ) {
		int salary = sales[i].getCount() * sales[i].getCost() * sales[i].getProductCommission() / 100;
		if ( sales[i].getSaleDate() >= statisticPage->statisticMonth->date() ) {
			currentSalary += salary;
			exp_countSales++;
		}
		else if ( sales[i].getSaleDate() >= statisticPage->statisticMonth->date().addMonths(-1) ) {
			previousSalary += salary;
		}
		exp_allCost += sales[i].getCount() * sales[i].getCost();
		allSalary += salary;
	}

	double exp_LET = 0, exp_OET = 0;
	if ( previousSalary > 0 ) {
		exp_LET = currentSalary / previousSalary;
	}
	if ( allSalary > 0 ) {
		exp_OET = currentSalary / allSalary;
	}

	QString FIO = findElemInStatisticTable( row, 1 );
	int countSales = findElemInStatisticTable( row, 2 ).toInt();
	double allCost = findElemInStatisticTable( row, 3 ).toDouble();
	double LET = findElemInStatisticTable( row, 4 ).toDouble();
	double OET = findElemInStatisticTable( row, 5 ).toDouble();

	QCOMPARE( FIO, exp_FIO );
	QCOMPARE( countSales, exp_countSales );
	QCOMPARE( allCost, exp_allCost );
	QCOMPARE( LET, exp_LET );
	QCOMPARE( OET, exp_OET );
}

void Test_Statistic_GUI::compareRowInStatisticSalesTable( ActiveSale sale, int row ) {
	
	Manager manager = manager_DB->getById( sale.getSalerId() );

	QString exp_FIO = manager.getSecondName() + " " +  manager.getFirstName() + " " + manager.getThirdName();

	QString FIO = findElemInStatisticSalesTable( row, 1 );
	QString saleDate = findElemInStatisticSalesTable( row, 2 );
	int countSale = findElemInStatisticSalesTable( row, 3 ).toInt();
	QString productName = findElemInStatisticSalesTable( row, 4 );
	double costSale = findElemInStatisticSalesTable( row, 5 ).toDouble();
	double productPercent = findElemInStatisticSalesTable( row, 6 ).toDouble();

	QCOMPARE( exp_FIO, FIO );
	QCOMPARE( saleDate, sale.getSaleDate().toString( Qt::DateFormat::ISODate ) );
	QCOMPARE( productName, sale.getProductName() );
	QCOMPARE( countSale, sale.getCount() );
	QCOMPARE( costSale, sale.getCost() * sale.getCount() );
	QCOMPARE( productPercent, sale.getProductCommission() );
}

void Test_Statistic_GUI::statisticSalesTableIsEmpty() {
	
	QString FIO = findElemInStatisticSalesTable( 0, 1 );
	QString saleDate = findElemInStatisticSalesTable( 0, 2 );
	int countSale = findElemInStatisticSalesTable( 0, 3 ).toInt();
	QString productName = findElemInStatisticSalesTable( 0, 4 );
	double costSale = findElemInStatisticSalesTable( 0, 5 ).toDouble();
	QString productPercent = findElemInStatisticSalesTable( 0, 6 );
	
	QCOMPARE( FIO, QString( "" ) );
	QCOMPARE( saleDate, QString( "" ) );
	QCOMPARE( productName, QString( "" ) );
	QCOMPARE( countSale, 0 );
	QCOMPARE( costSale, 0.0 );
	QCOMPARE( productPercent, QString( "" ) );
}

void Test_Statistic_GUI::managerStatisticIsEmpty( Manager manager, int row) {
	
	QString exp_FIO = manager.getSecondName() + " " +  manager.getFirstName() + " " + manager.getThirdName();
	
	QString FIO = findElemInStatisticTable( row, 1 );
	int countSales = findElemInStatisticTable( row, 2 ).toInt();
	double costSale = findElemInStatisticTable( row, 3 ).toDouble();
	double LET = findElemInStatisticTable( row, 4 ).toDouble();
	double OET = findElemInStatisticTable( row, 5 ).toDouble();
	
	QCOMPARE( FIO, exp_FIO );
	QCOMPARE( countSales, 0 );
	QCOMPARE( costSale, 0.0 );
	QCOMPARE( LET, 0.0 );
	QCOMPARE( LET, 0.0 );
}



void Test_Statistic_GUI::showCountManagerSales() {

	statisticPage->statisticMonth->setDate( QDate( 2019, 01, 01 ) );

	User user;
	user = user_DB->insert( user, UserType::MANAGER );
	int manager_id = user.getId();

	QString firstName = "Ivan";
	QString secondName = "Ivanov";
	QString thirdName = "Ivanovich";

	Manager manager;
	manager.setId( manager_id );
	manager.setFirstName( firstName );
	manager.setSecondName( secondName );
	manager.setThirdName( thirdName );

	manager_DB->update( manager );

	Product first_product = createProduct( "ABC", 15.3 );
	Product second_product = createProduct( "AAA", 35 );
	ActiveSale first_sale = createSale( first_product, QDate( 2019, 01, 01 ), manager_id );
	ActiveSale second_sale = createSale( second_product, QDate( 2018, 12, 01 ), manager_id );

	statisticPage->refreshPage();

	managerStatisticIsEmpty( manager, 0);
	statisticSalesTableIsEmpty();

	sale_DB->confirmSale( first_sale.getId() );
	sale_DB->confirmSale( second_sale.getId() );

	statisticPage->refreshPage();

	compareRowInStatisticTable( manager, 0);
	compareRowInStatisticSalesTable( first_sale, 0 );
	compareRowInStatisticSalesTable( second_sale, 1 );

	QVector<ActiveSale> sales = sale_DB->getActiveAll( manager_id );

	sale_DB->remove( sales[0].getId() );
	sale_DB->remove( sales[1].getId() );
	removeProduct( first_product.getName() );
	removeProduct( second_product.getName() );
	removeEmployee( manager_id );

	statisticPage->refreshPage();
}

void Test_Statistic_GUI::showSales() {

}

void Test_Statistic_GUI::showCalendar() {

}

void Test_Statistic_GUI::showSalesInPreviousMonths() {

}

void Test_Statistic_GUI::showAllManagersSales() {

}