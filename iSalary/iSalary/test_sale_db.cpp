#include "test_sale_db.h"

Test_Sale_DB::Test_Sale_DB( QSqlDatabase *sql ) {

    this->sql = sql;
    this->user_DB = new UserDB( sql );
    this->manager_DB = new ManagerDB( sql, user_DB );
    this->product_DB = new Product_DB( sql, "products" );
    this->sale_DB = new Sale_DB( sql, "sales" );
}

Test_Sale_DB::~Test_Sale_DB() {}

void Test_Sale_DB::removeManager( int id ) {

    QSqlQuery query( "DELETE FROM users WHERE id = " + QString::number( id ), *sql );
    bool isOk = query.exec();
}

Product Test_Sale_DB::createProduct( QString productName, double productCommission ) {
    Product product;
    product.setName( productName );
    product.setCommission( productCommission );
    product_DB->create( product );
    product = product_DB->getAll().last();
    return product;
}

void Test_Sale_DB::removeProduct( QString productName ) {

    Product product = product_DB->findByName( productName );
    QSqlQuery query( "DELETE FROM products WHERE id = " + QString::number( product.getId() ), *sql );
    bool isOk = query.exec();
}

void Test_Sale_DB::compareSales( QVector<ActiveSale> first_sales, QVector<ActiveSale> second_sales ) {

    QCOMPARE( first_sales.size(), second_sales.size() );
    for ( int i = 0; i < first_sales.size(); i++ ) {

        compareSales( first_sales[i], second_sales[i] );
    }
}

void Test_Sale_DB::compareSales( ActiveSale first_sale, ActiveSale second_sale ) {

    QCOMPARE( first_sale.getId(), second_sale.getId() );
    QCOMPARE( first_sale.getConfirmDate(), second_sale.getConfirmDate() );
    QCOMPARE( first_sale.getSaleDate(), second_sale.getSaleDate() );
    QCOMPARE( first_sale.getCost(), second_sale.getCost() );
    QCOMPARE( first_sale.getCount(), second_sale.getCount() );
    QCOMPARE( first_sale.getProductId(), second_sale.getProductId() );
    QCOMPARE( first_sale.getProductCommission(), second_sale.getProductCommission() );
    QCOMPARE( first_sale.getProductName(), second_sale.getProductName() );
    QCOMPARE( first_sale.isConfirmed(), second_sale.isConfirmed() );
    compareManagers( first_sale.getSaler(), second_sale.getSaler() );
}

void Test_Sale_DB::compareManagers( Manager first_manager, Manager second_manager ) {

    QCOMPARE( first_manager.getId(), second_manager.getId() );
    QCOMPARE( first_manager.getFirstName(), second_manager.getFirstName() );
    QCOMPARE( first_manager.getSecondName(), second_manager.getSecondName() );
    QCOMPARE( first_manager.getThirdName(), second_manager.getThirdName() );
    QCOMPARE( first_manager.getSex(), second_manager.getSex() );
    QCOMPARE( first_manager.getDateOfBirth(), second_manager.getDateOfBirth() );
    QCOMPARE( first_manager.getPassportSerial(), second_manager.getPassportSerial() );
    QCOMPARE( first_manager.getPassportNumber(), second_manager.getPassportNumber() );
    QCOMPARE( first_manager.getPassportSource(), second_manager.getPassportSource() );
    QCOMPARE( first_manager.getPassportDateIssue(), second_manager.getPassportDateIssue() );
    QCOMPARE( first_manager.getAddress(), second_manager.getAddress() );
    QCOMPARE( first_manager.getINN(), second_manager.getINN() );
}

ActiveSale Test_Sale_DB::createSale( Product product, QDate saleDate, int manager_id ) {
    ActiveSale sale;
    sale.setConfirmDate( saleDate );
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

ActiveSale Test_Sale_DB::createConfirmedSale( Product product, QDate saleDate, int manager_id ) {

    ActiveSale sale = createSale( product, saleDate, manager_id );
    sale_DB->confirmSale( sale.getId() );
    return sale;
}

void Test_Sale_DB::create() {

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

    Product product = createProduct( "ABC", 15.3 );

    ActiveSale sale = createSale( product, QDate::currentDate(), manager_id );

    ActiveSale res_sale = sale_DB->getActiveAll( manager_id )[0];

    compareSales( sale, res_sale );
}

void Test_Sale_DB::getActiveManagerSales() {

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
    ActiveSale first_sale = createSale( first_product, QDate::currentDate(), manager_id );
    ActiveSale second_sale = createSale( second_product, QDate::currentDate(), manager_id );

    QVector<ActiveSale> exp_sales;
    exp_sales.append( first_sale );
    exp_sales.append( second_sale );
    QVector<ActiveSale> sales = sale_DB->getActiveAll( manager_id );

    compareSales( exp_sales, sales );
}

void Test_Sale_DB::remove() {

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

    Product product = createProduct( "ABC", 15.3 );

    ActiveSale sale = createSale( product, QDate::currentDate(), manager_id );

    sale_DB->remove( sale.getId() );

    QCOMPARE( sale_DB->getActiveAll( manager_id ).size(), 0 );
}

void Test_Sale_DB::getActiveAllInPeriod() {

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

    Product product = createProduct( "ABC", 15.3 );

    ActiveSale sale = createSale( product, QDate::currentDate(), manager_id );
    QVector<ActiveSale> exp_sales;
    exp_sales.append( sale );
    sale = createSale( product, QDate::currentDate().addDays( -3 ), manager_id );

    QVector<ActiveSale> sales = sale_DB->getActiveAllInPeriod( manager_id, QDate::currentDate() );

    compareSales( exp_sales, sales );
}

void Test_Sale_DB::confirmSale() {

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

    Product product = createProduct( "ABC", 15.3 );

    ActiveSale sale = createSale( product, QDate::currentDate(), manager_id );
    sale_DB->confirmSale( sale.getId() );
    sale.confirm();

    ActiveSale res_sale = sale_DB->getActiveAll( manager_id ).last();

    compareSales( sale, res_sale );
}

void Test_Sale_DB::unconfirmSale() {

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

    Product product = createProduct( "ABC", 15.3 );

    ActiveSale sale = createConfirmedSale( product, QDate::currentDate(), manager_id );
    sale_DB->unconfirmSale( sale.getId() );
    sale.cancelConfirm();

    ActiveSale res_sale = sale_DB->getActiveAll( manager_id ).last();

    compareSales( sale, res_sale );
}

void Test_Sale_DB::cleanup() {

    QList<Manager> managers = manager_DB->getAll();
    for ( int manager_num = 0; manager_num < managers.size(); manager_num++ ) {

        int manager_id = managers[manager_num].getId();
        QVector<ActiveSale> sales = sale_DB->getActiveAll( manager_id );
        for ( int sale_num = 0; sale_num < sales.size(); sale_num++ ) {

            sale_DB->remove( sales[sale_num].getId() );
        }
        removeManager( manager_id );
    }

    QVector<Product> products = product_DB->getAll();
    for ( int product_num = 0; product_num < products.size(); product_num++ ) {

        removeProduct( products[product_num].getName() );
    }
}