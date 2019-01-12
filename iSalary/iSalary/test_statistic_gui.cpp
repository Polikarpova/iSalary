#include "test_statistic_gui.h"

Test_Statistic_GUI::Test_Statistic_GUI( QSqlDatabase *sql, StatisticPage *statisticPage ) {

    this->statisticPage = statisticPage;
    this->sql = sql;
    user_DB = new UserDB( sql );
    manager_DB = new ManagerDB( sql, user_DB );
    product_DB = new Product_DB( sql, "products" );
    product_DB->init();
    sale_DB = new Sale_DB( sql, "sales" );
    sale_DB->init();
    c = QTextCodec::codecForLocale();
}

Test_Statistic_GUI::~Test_Statistic_GUI() {}

void Test_Statistic_GUI::removeEmployee( int id ) {
    QSqlQuery query( "DELETE FROM users WHERE id = " + QString::number( id ), *sql );
    bool isOk = query.exec();
}

void Test_Statistic_GUI::removeProduct( QString productName ) {
    Product product = product_DB->findByName( productName );
    QSqlQuery query( "DELETE FROM products WHERE id = " + QString::number( product.getId() ), *sql );
    bool isOk = query.exec();
}

Product Test_Statistic_GUI::createProduct( QString productName, double productCommission ) {
    Product product;
    product.setName( productName );
    product.setCommission( productCommission );
    product_DB->create( product );
    return product;
}

QString Test_Statistic_GUI::findElemInStatisticTable( int row, int col ) {
    return statisticPage->statisticTable->model()->data( statisticPage->statisticTable->model()->index( row, col ) ).toString();
}

QString Test_Statistic_GUI::findElemInStatisticSalesTable( int row, int col ) {
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

ActiveSale Test_Statistic_GUI::createConfirmedSale( Product product, QDate saleDate, int manager_id ) {
	
	ActiveSale sale = createSale( product, saleDate, manager_id );
	sale_DB->confirmSale( sale.getId() );
	return sale;
}

void Test_Statistic_GUI::compareRowInStatisticTable( Manager manager, int row ) {

    QString exp_FIO = manager.getSecondName() + " " + manager.getFirstName() + " " + manager.getThirdName();
    
	double currentSalary = 0;
    double allSalary = 0;
    double previousSalary = 0;
    double exp_allCost = 0;
    int exp_countSales = 0;

	QList<Manager> managers = manager_DB->getAll();

	for ( int manager_num = 0; manager_num < managers.size(); manager_num++ ) {

		QVector<ActiveSale> sales = sale_DB->getActiveAll( managers[ manager_num ].getId() );
		for ( int i = 0; i < sales.size(); i++ ) {
			
			int salary = sales[i].getCount() * sales[i].getCost();
			
			if ( sales[i].getSaleDate() >= statisticPage->statisticMonth->date() ) {
				
				if ( managers[ manager_num ].getId() == manager.getId() ) {
					
					currentSalary += salary;
					exp_countSales++;
					exp_allCost += sales[i].getCount() * sales[i].getCost();
				}
				allSalary += salary;
			} else if ( sales[i].getSaleDate() >= statisticPage->statisticMonth->date().addMonths( -1 ) && 
						managers[ manager_num ].getId() == manager.getId() ) {
				
				previousSalary += salary;
			}
		}
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
    double LET = findElemInStatisticTable( row, 4 ).toDouble() / 100;
    double OET = findElemInStatisticTable( row, 5 ).toDouble() / 100;

    QCOMPARE( FIO, exp_FIO );
    QCOMPARE( countSales, exp_countSales );
    QCOMPARE( allCost, exp_allCost );
    QCOMPARE( LET, exp_LET );
    QCOMPARE( OET, exp_OET );
}

void Test_Statistic_GUI::compareRowInStatisticSalesTable( ActiveSale sale, int row ) {

    if ( sale.getSaleDate() < statisticPage->statisticMonth->date() ) {

        rowInStatisticSalesTableIsEmpty( row );
    } else {

        Manager manager = manager_DB->getById( sale.getSalerId() );

        QString exp_FIO = manager.getSecondName() + " " + manager.getFirstName() + " " + manager.getThirdName();

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
}

void Test_Statistic_GUI::rowInStatisticSalesTableIsEmpty( int row ) {

    QString FIO = findElemInStatisticSalesTable( row, 1 );
    QString saleDate = findElemInStatisticSalesTable( row, 2 );
    int countSale = findElemInStatisticSalesTable( row, 3 ).toInt();
    QString productName = findElemInStatisticSalesTable( row, 4 );
    double costSale = findElemInStatisticSalesTable( row, 5 ).toDouble();
    QString productPercent = findElemInStatisticSalesTable( row, 6 );

    QCOMPARE( FIO, QString( "" ) );
    QCOMPARE( saleDate, QString( "" ) );
    QCOMPARE( productName, QString( "" ) );
    QCOMPARE( countSale, 0 );
    QCOMPARE( costSale, 0.0 );
    QCOMPARE( productPercent, QString( "" ) );
}

void Test_Statistic_GUI::managerStatisticIsEmpty( Manager manager, int row ) {

    QString exp_FIO = manager.getSecondName() + " " + manager.getFirstName() + " " + manager.getThirdName();

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

void Test_Statistic_GUI::checkCalendar( Manager manager ) { 
	
	QVector<ActiveSale>sales = sale_DB->getActiveAll( manager.getId() );
	QMap<int, double>costInDays;
	double allCost = 0;
	QDate dateInWidget = statisticPage->statisticMonth->date();

	for ( int sale_num = 0; sale_num < sales.size(); sale_num++ ) {
		
		if ( sales[ sale_num ].getSaleDate() >= dateInWidget ) {
			
			ActiveSale sale = sales[ sale_num ];
			double cost = sale.getCost() * sale.getCount();
			costInDays[ sale.getSaleDate().day() ] += cost;
			allCost += cost;
		}
	}

	for ( int day = 1; day <= dateInWidget.daysInMonth(); day++ ) {
		
		QDate date = QDate( dateInWidget.year(), dateInWidget.month(), day );
		QColor color = statisticPage->statisticCalendar->dateTextFormat( date ).background().color();
		QColor exp_color;
		int index = 255 - ( 255 * costInDays[ day ] / allCost);
		if ( index != 255 )
			exp_color = QColor( index, 255, index );
		else
			exp_color = QColor( 0, 0, 0 );

		int red = color.red();
		int green = color.green();
		int blue = color.blue();
		
		QCOMPARE( color.red(), exp_color.red() );
		QCOMPARE( color.green(), exp_color.green() );
		QCOMPARE( color.blue(), exp_color.blue() );
	}
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

    managerStatisticIsEmpty( manager, 0 );
    rowInStatisticSalesTableIsEmpty( 0 );

    sale_DB->confirmSale( first_sale.getId() );
    sale_DB->confirmSale( second_sale.getId() );

    statisticPage->refreshPage();

    compareRowInStatisticTable( manager, 0 );
    compareRowInStatisticSalesTable( first_sale, 0 );
    compareRowInStatisticSalesTable( second_sale, 1 );
}

void Test_Statistic_GUI::showSales() {

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

    sale_DB->confirmSale( first_sale.getId() );
    sale_DB->confirmSale( second_sale.getId() );

    statisticPage->refreshPage();

    compareRowInStatisticSalesTable( first_sale, 0 );
}

void Test_Statistic_GUI::showCalendar() {
	
	statisticPage->statisticMonth->setDate( QDate( 2019, 01, 01 ) );

	User user;
    user = user_DB->insert( user, UserType::MANAGER );
    int manager_id = user.getId();

    QString firstName = "Ivan";
    QString secondName = "Ivanov";
    QString thirdName = "Ivanovich";
    QString first_exp_FIO = secondName + " " + firstName + " " + thirdName;

    Manager manager;
    manager.setId( manager_id );
    manager.setFirstName( firstName );
    manager.setSecondName( secondName );
    manager.setThirdName( thirdName );

    manager_DB->update( manager );

    Product first_product = createProduct( "ABC", 15.3 );
    Product second_product = createProduct( "AAA", 35 );

    createConfirmedSale( first_product, QDate( 2019, 01, 01 ), manager_id );
	createConfirmedSale( second_product, QDate( 2019, 01, 05 ), manager_id );
	createConfirmedSale( second_product, QDate( 2019, 01, 01 ), manager_id );

	statisticPage->refreshPage();

	statisticPage->statisticTable->setFocus();
    QModelIndex newIndex = statisticPage->statisticTable->model()->index( 0, 1 );
    statisticPage->statisticTable->setCurrentIndex( newIndex );
    statisticPage->statisticTable->clicked( newIndex );

	checkCalendar( manager );
}

void Test_Statistic_GUI::showSalesInPreviousMonths() {

    statisticPage->statisticMonth->setDate( QDate( 2018, 12, 01 ) );

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

    sale_DB->confirmSale( first_sale.getId() );
    sale_DB->confirmSale( second_sale.getId() );

    statisticPage->refreshPage();

    compareRowInStatisticSalesTable( second_sale, 0 );
}

void Test_Statistic_GUI::showAllManagersSales() {
	
	statisticPage->statisticMonth->setDate( QDate( 2019, 01, 01 ) );

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
    ActiveSale first_sale = createSale( first_product, QDate( 2019, 01, 01 ), first_manager_id );
    sale_DB->confirmSale( first_sale.getId() );

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

    ActiveSale second_sale = createSale( second_product, QDate( 2019, 01, 01 ), second_manager_id );
	sale_DB->confirmSale( second_sale.getId() );

    statisticPage->refreshPage();

	statisticPage->statisticTable->setFocus();
    QModelIndex newIndex = statisticPage->statisticTable->model()->index( 0, 1 );
    statisticPage->statisticTable->setCurrentIndex( newIndex );
    statisticPage->statisticTable->clicked( newIndex );

	compareRowInStatisticSalesTable( first_sale, 0 );

	statisticPage->statisticTable->setFocus();
    newIndex = statisticPage->statisticTable->model()->index( 1, 1 );
    statisticPage->statisticTable->setCurrentIndex( newIndex );
    statisticPage->statisticTable->clicked( newIndex );

	compareRowInStatisticSalesTable( second_sale, 0 );
}

void Test_Statistic_GUI::cleanup() {
	
	QList<Manager> managers = manager_DB->getAll();
	for ( int manager_num = 0; manager_num < managers.size(); manager_num++ ) {
		
		int manager_id = managers[ manager_num ].getId();
		QVector<ActiveSale> sales = sale_DB->getActiveAll( manager_id );
		for ( int sale_num = 0; sale_num < sales.size(); sale_num++ ) {
			
			sale_DB->remove( sales[ sale_num ].getId() );
		}
		removeEmployee( manager_id );
	}
	
	QVector<Product> products = product_DB->getAll();
    for ( int product_num = 0; product_num < products.size(); product_num++ ) {
		
		removeProduct( products[ product_num ].getName() );
	}

    statisticPage->refreshPage();
}
