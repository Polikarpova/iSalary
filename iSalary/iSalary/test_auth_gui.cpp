#include "test_auth_gui.h"

Test_Auth_GUI::Test_Auth_GUI( QSqlDatabase *sql, AuthPage *authPage, ManagerPage *managerPage ) {

    this->authPage = authPage;
    this->managerPage = managerPage;
    this->sql = sql;
    user_DB = new UserDB( sql );
    manager_DB = new ManagerDB( sql, user_DB );
    product_DB = new Product_DB( sql, "products" );
    product_DB->init();
    sale_DB = new Sale_DB( sql, "sales" );
    sale_DB->init();
    c = QTextCodec::codecForLocale();
}

Test_Auth_GUI::~Test_Auth_GUI() {}

void Test_Auth_GUI::removeEmployee( int id ) {
    QSqlQuery query( "DELETE FROM users WHERE id = " + QString::number( id ), *sql );
    bool isOk = query.exec();
}

void Test_Auth_GUI::removeProduct( QString productName ) {
    Product product = product_DB->findByName( productName );
    QSqlQuery query( "DELETE FROM products WHERE id = " + QString::number( product.getId() ), *sql );
    bool isOk = query.exec();
}

Product Test_Auth_GUI::createProduct( QString productName, double productCommission ) {
    Product product;
    product.setName( productName );
    product.setCommission( productCommission );
    product_DB->create( product );
    product = product_DB->getAll().last();
    return product;
}

ActiveSale Test_Auth_GUI::createSale( Product product, QDate saleDate, int manager_id ) {
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

ActiveSale Test_Auth_GUI::createConfirmedSale( Product product, QDate saleDate, int manager_id ) {

    ActiveSale sale = createSale( product, saleDate, manager_id );
    sale_DB->confirmSale( sale.getId() );
    return sale;
}

QString Test_Auth_GUI::findElemInUnconfirmedTable( int row, int col ) {
    return managerPage->unconfirmedSalesTableModel->data( managerPage->unconfirmedSalesTableModel->index( row, col ) ).toString();
}

QString Test_Auth_GUI::findElemInConfirmedTable( int row, int col ) {
    return managerPage->confirmedSalesTableModel->data( managerPage->confirmedSalesTableModel->index( row, col ) ).toString();
}

void Test_Auth_GUI::compareRowInUnconfirmedTable( ActiveSale sale, int row ) {

    QString productName = findElemInUnconfirmedTable( row, 0 );
    QString saleDate = findElemInUnconfirmedTable( row, 1 );
    int saleCount = findElemInUnconfirmedTable( row, 2 ).toInt();
    double salePrice = findElemInUnconfirmedTable( row, 3 ).toDouble();
    double saleCost = findElemInUnconfirmedTable( row, 4 ).toDouble();
    double saleSalary = findElemInUnconfirmedTable( row, 5 ).toDouble();

    QCOMPARE( productName, sale.getProductName() );
    QCOMPARE( saleDate, sale.getSaleDate().toString( Qt::DateFormat::LocalDate ) );
    QCOMPARE( saleCount, sale.getCount() );
    QCOMPARE( salePrice, sale.getCost() );
    QCOMPARE( saleCost, sale.getCost() * sale.getCount() );
    QCOMPARE( saleSalary, sale.getCost() * sale.getCount() * sale.getProductCommission() / 100 );
}

void Test_Auth_GUI::compareRowInConfirmedTable( ActiveSale sale, int row ) {

    QString productName = findElemInConfirmedTable( row, 0 );
    QString saleDate = findElemInConfirmedTable( row, 1 );
    int saleCount = findElemInConfirmedTable( row, 2 ).toInt();
    double salePrice = findElemInConfirmedTable( row, 3 ).toDouble();
    double saleCost = findElemInConfirmedTable( row, 4 ).toDouble();
    double saleSalary = findElemInConfirmedTable( row, 5 ).toDouble();

    QCOMPARE( productName, sale.getProductName() );
    QCOMPARE( saleDate, sale.getSaleDate().toString( Qt::DateFormat::LocalDate ) );
    QCOMPARE( saleCount, sale.getCount() );
    QCOMPARE( salePrice, sale.getCost() );
    QCOMPARE( saleCost, sale.getCost() * sale.getCount() );
    QCOMPARE( saleSalary, sale.getCost() * sale.getCount() * sale.getProductCommission() / 100 );
}

void Test_Auth_GUI::unconfirmedTableIsEmpty() {

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
}

void Test_Auth_GUI::confirmedTableIsEmpty() {

    QString productName = findElemInConfirmedTable( 0, 0 );
    QString saleDate = findElemInConfirmedTable( 0, 1 );
    QString saleCount = findElemInConfirmedTable( 0, 2 );
    QString salePrice = findElemInConfirmedTable( 0, 3 );
    QString saleCost = findElemInConfirmedTable( 0, 4 );
    QString saleSalary = findElemInConfirmedTable( 0, 5 );

    QCOMPARE( productName, c->toUnicode( "Итого:" ) );
    QCOMPARE( saleDate, QString( "" ) );
    QCOMPARE( saleCount, QString( "0" ) );
    QCOMPARE( salePrice, QString( "" ) );
    QCOMPARE( saleCost, QString( "0" ) );
    QCOMPARE( saleSalary, QString( "0" ) );
}

void Test_Auth_GUI::compareManagerSales( Manager manager ) {

    QVector<ActiveSale> sales = sale_DB->getActiveAll( manager.getId() );
    int cntUnconfirmedSales = 0;
    int cntConfirmedSales = 0;
    for ( int sales_num = 0; sales_num < sales.size(); sales_num++ ) {

        if ( sales[sales_num].isConfirmed() == true ) {

            compareRowInConfirmedTable( sales[sales_num], cntConfirmedSales );
            cntConfirmedSales++;
        } else {

            compareRowInUnconfirmedTable( sales[sales_num], cntUnconfirmedSales );
            cntUnconfirmedSales++;
        }
    }
}

void Test_Auth_GUI::bossAuth() {

    authPage->loginInput->setText( "boss" );
    authPage->passwordInput->setText( "boss" );
    authPage->signInBtn->click();

    QCOMPARE( authPage->auth_program_stackedWidget->currentIndex(), 1 );
    QCOMPARE( authPage->boss_manager_stackedWidget->currentIndex(), 0 );
}

void Test_Auth_GUI::managerAuth() {

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
    manager.setLogin( "ivan" );
    manager.setPassword( "ivan" );
    manager_DB->update( manager );

    Product product = createProduct( "ABC", 13.5 );

    createSale( product, QDate( 2019, 01, 01 ), manager_id );
    createConfirmedSale( product, QDate( 2019, 01, 02 ), manager_id );

    authPage->loginInput->setText( manager.getLogin() );
    authPage->passwordInput->setText( manager.getPassword() );
    authPage->signInBtn->click();

    QCOMPARE( authPage->auth_program_stackedWidget->currentIndex(), 1 );
    QCOMPARE( authPage->boss_manager_stackedWidget->currentIndex(), 1 );

    managerPage->refreshPage();

    compareManagerSales( manager );
}

void Test_Auth_GUI::cleanup() {

    QList<Manager> managers = manager_DB->getAll();
    for ( int manager_num = 0; manager_num < managers.size(); manager_num++ ) {

        int manager_id = managers[manager_num].getId();
        QVector<ActiveSale> sales = sale_DB->getActiveAll( manager_id );
        for ( int sale_num = 0; sale_num < sales.size(); sale_num++ ) {

            sale_DB->remove( sales[sale_num].getId() );
        }
        removeEmployee( manager_id );
    }

    QVector<Product> products = product_DB->getAll();
    for ( int product_num = 0; product_num < products.size(); product_num++ ) {

        removeProduct( products[product_num].getName() );
    }

    authPage->auth_program_stackedWidget->setCurrentIndex( 0 );
}