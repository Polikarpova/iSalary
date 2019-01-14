#include "test_salary_gui.h"

Test_Salary_GUI::Test_Salary_GUI( QSqlDatabase *sql, SalaryPage *salaryPage, EmployeesPage *employeesPage, SalesPage *salesPage ) {

    this->salaryPage = salaryPage;
    this->employeesPage = employeesPage;
    this->salesPage = salesPage;
    this->sql = sql;
    user_DB = new UserDB( sql );
    manager_DB = new ManagerDB( sql, user_DB );
    product_DB = new Product_DB( sql, "products" );
    product_DB->init();
    sale_DB = new Sale_DB( sql, "sales" );
    sale_DB->init();
    c = QTextCodec::codecForLocale();
}

Test_Salary_GUI::~Test_Salary_GUI() {}

void Test_Salary_GUI::removeEmployee( int id ) {
    QSqlQuery query( "DELETE FROM users WHERE id = " + QString::number( id ), *sql );
    bool isOk = query.exec();
}

void Test_Salary_GUI::removeProduct( QString productName ) {
    Product product = product_DB->findByName( productName );
    QSqlQuery query( "DELETE FROM products WHERE id = " + QString::number( product.getId() ), *sql );
    bool isOk = query.exec();
}

Product Test_Salary_GUI::createProduct( QString productName, double productCommission ) {
    Product product;
    product.setName( productName );
    product.setCommission( productCommission );
    product_DB->create( product );
    product = product_DB->getAll().last();
    return product;
}

QString Test_Salary_GUI::findElemInSalaryTable( int row, int col ) {
    return salaryPage->salaryTable->model()->data( salaryPage->salaryTable->model()->index( row, col ) ).toString();
}

QString Test_Salary_GUI::findElemInSalaryTotalTable( int col ) {
    return salaryPage->salaryTotalTable->model()->data( salaryPage->salaryTotalTable->model()->index( 0, col ) ).toString();
}

QString Test_Salary_GUI::findElemInUnconfirmedTable( int row, int col ) {
    return salesPage->unconfirmedSalesTable->model()->data( salesPage->unconfirmedSalesTable->model()->index( row, col ) ).toString();
}

QString Test_Salary_GUI::findElemInConfirmedTable( int row, int col ) {
    return salesPage->confirmedSalesTable->model()->data( salesPage->confirmedSalesTable->model()->index( row, col ) ).toString();
}

ActiveSale Test_Salary_GUI::createSale( Product product, QDate saleDate, int manager_id ) {
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

ActiveSale Test_Salary_GUI::createConfirmedSale( Product product, QDate saleDate, int manager_id ) {

    ActiveSale sale = createSale( product, saleDate, manager_id );
    sale_DB->confirmSale( sale.getId() );
    return sale;
}

void Test_Salary_GUI::compareRowInUnconfirmedTable( ActiveSale sale, int row ) {

    Manager manager = manager_DB->getById( sale.getSalerId() );

    QString exp_FIO = manager.getSecondName() + " " + manager.getFirstName() + " " + manager.getThirdName();

    QString FIO = findElemInUnconfirmedTable( row, 2 );
    QString saleDate = findElemInUnconfirmedTable( row, 3 );
    QString productName = findElemInUnconfirmedTable( row, 4 );
    int countSale = findElemInUnconfirmedTable( row, 5 ).toInt();
    double costSale = findElemInUnconfirmedTable( row, 6 ).toDouble();
    double productPercent = findElemInUnconfirmedTable( row, 7 ).toDouble();

    QCOMPARE( FIO, exp_FIO );
    QCOMPARE( saleDate, sale.getSaleDate().toString( Qt::DateFormat::ISODate ) );
    QCOMPARE( productName, sale.getProductName() );
    QCOMPARE( countSale, sale.getCount() );
    QCOMPARE( costSale, sale.getCost() * sale.getCount() );
    QCOMPARE( productPercent, sale.getProductCommission() );
}

void Test_Salary_GUI::compareRowInConfirmedTable( ActiveSale sale, int row ) {

    Manager manager = manager_DB->getById( sale.getSalerId() );

    QString exp_FIO = manager.getSecondName() + " " + manager.getFirstName() + " " + manager.getThirdName();

    QString FIO = findElemInConfirmedTable( row, 2 );
    QString confirmDate = findElemInConfirmedTable( row, 3 );
    QString saleDate = findElemInConfirmedTable( row, 4 );
    QString productName = findElemInConfirmedTable( row, 5 );
    int countSale = findElemInConfirmedTable( row, 6 ).toInt();
    double costSale = findElemInConfirmedTable( row, 7 ).toDouble();
    double productPercent = findElemInConfirmedTable( row, 8 ).toDouble();

    QCOMPARE( FIO, exp_FIO );
    QCOMPARE( confirmDate, sale.getConfirmDate().toString( Qt::DateFormat::ISODate ) );
    QCOMPARE( saleDate, sale.getSaleDate().toString( Qt::DateFormat::ISODate ) );
    QCOMPARE( productName, sale.getProductName() );
    QCOMPARE( countSale, sale.getCount() );
    QCOMPARE( costSale, sale.getCost() * sale.getCount() );
    QCOMPARE( productPercent, sale.getProductCommission() );
}

void Test_Salary_GUI::unconfirmedTableIsEmpty() {

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

void Test_Salary_GUI::confirmedTableIsEmpty() {

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

void Test_Salary_GUI::compareRowInSalaryTable( Manager manager, QDate date, int row ) {

    QString exp_FIO = manager.getSecondName() + " " + manager.getFirstName() + " " + manager.getThirdName();

    double exp_salary = 0;
    double exp_allCost = 0;

    QVector<ActiveSale> sales = sale_DB->getActiveAll( manager.getId() );
    for ( int i = 0; i < sales.size(); i++ ) {

        if ( sales[i].getSaleDate() >= date ) {

            int cost = sales[i].getCount() * sales[i].getCost();
            exp_allCost += cost;
            exp_salary += cost * sales[i].getProductCommission() / 100;
        }
    }

    QString FIO = findElemInSalaryTable( row, 1 );
    double allCost = findElemInSalaryTable( row, 2 ).toDouble();
    double salary = findElemInSalaryTable( row, 3 ).toDouble();

    QCOMPARE( FIO, exp_FIO );
    QCOMPARE( allCost, exp_allCost );
    QCOMPARE( salary, exp_salary );
}

void Test_Salary_GUI::compareManagerInfo( Manager manager ) {

    QString exp_FIO = manager.getSecondName() + " " + manager.getFirstName() + " " + manager.getThirdName();
    bool isMale = manager.getSex() == Sex::MALE;
    QCOMPARE( salaryPage->managerFIOLabel->text(), exp_FIO );
    QCOMPARE( salaryPage->salaryPasportSeries->text(), manager.getPassportSerial() );
    QCOMPARE( salaryPage->salaryPasportNumber->text(), manager.getPassportNumber() );
    QCOMPARE( salaryPage->salaryPasportSourse->text(), manager.getPassportSource() );
    QCOMPARE( salaryPage->salaryDateOfReceipt->date(), manager.getPassportDateIssue() );
    QCOMPARE( salaryPage->salaryMaleRButton->isChecked(), isMale );
    QCOMPARE( salaryPage->salaryFemaleRButton->isChecked(), !isMale );
    QCOMPARE( salaryPage->salaryINN->text(), manager.getINN() );
}

void Test_Salary_GUI::compareManagerInfoInEmployeesPage( Manager manager ) {

    bool isMale = manager.getSex() == Sex::MALE;
    QCOMPARE( employeesPage->firstNameInput->text(), manager.getFirstName() );
    QCOMPARE( employeesPage->secondNameInput->text(), manager.getSecondName() );
    QCOMPARE( employeesPage->thirdNameInput->text(), manager.getThirdName() );
    QCOMPARE( employeesPage->birthdayInput->date(), manager.getDateOfBirth() );
    QCOMPARE( employeesPage->maleInput->isChecked(), isMale );
    QCOMPARE( employeesPage->femaleInput->isChecked(), !isMale );
    QCOMPARE( employeesPage->passportSerialInput->value(), manager.getPassportSerial().toInt() );
    QCOMPARE( employeesPage->passportNumberInput->value(), manager.getPassportNumber().toInt() );
    QCOMPARE( employeesPage->passportSourceInput->text(), manager.getPassportSource() );
    QCOMPARE( employeesPage->passportIssueDate->date(), manager.getPassportDateIssue() );
    QCOMPARE( employeesPage->addressInput->text(), manager.getAddress() );
    QCOMPARE( employeesPage->INNInput->text(), manager.getINN() );
}

void Test_Salary_GUI::compareManagerSales( Manager manager ) {

    QScrollArea *scroll = salaryPage->salesWindows[manager.getId()].first;
    int id = salaryPage->salesWindows.begin().key();
    bool windowIsOpen = scroll->isVisible();
    QCOMPARE( windowIsOpen, true );

    /*QWidget *w = scroll->widget();
    QDialog *dialog = qobject_cast<QDialog *>( w );
    QLayout *layout = dialog->layout();
    QVBoxLayout *VBlayout = qobject_cast<QVBoxLayout *>( layout );
    w = VBlayout->widget();
    QLabel *label = qobject_cast<QLabel *>( w );*/
    /*QLabel *label = scroll->widget()->layout()->widget()->findChild<QLabel*>("lbl");
    QString text = label->text();*/

    QString message = salaryPage->salesWindows[manager.getId()].second->text();
    QString exp_message = "";

    QVector<ActiveSale> sales = sale_DB->getActiveAll( manager.getId() );
    int cntConfirmedSales = 0;
    for ( int sales_num = 0; sales_num < sales.size(); sales_num++ ) {

        ActiveSale sale = sales[sales_num];
        if ( sale.isConfirmed() == true ) {

            QString str = QString::fromWCharArray( L"Товар: " ) + toUnicode( sale.getProductName() ) + "\n        " +
                          QString::fromWCharArray( L"Дата продажи: " ) + sale.getSaleDate().toString( "dd.MM.yyyy" ) + "\n        " +
                          QString::fromWCharArray( L"Дата подтверждения: " ) + sale.getConfirmDate().toString( "dd.MM.yyyy" ) + "\n        " +
                          QString::fromWCharArray( L"Количество: " ) + QString::number( sale.getCount() ) + "\n        " +
                          QString::fromWCharArray( L"Цена: " ) + QString::number( sale.getCost() ) + "\n        " + QString::fromWCharArray( L"Комиссия: " ) +
                          QString::number( sale.getProductCommission() ) + "\n\n";
            exp_message += str;
            cntConfirmedSales++;
        }
    }
    QCOMPARE( message, exp_message );
    scroll->close();
}

void Test_Salary_GUI::compareManagerSalesInSalesPage( Manager manager ) {

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

void Test_Salary_GUI::showManagersSalary() {

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

    sale_DB->confirmSale( first_sale.getId() );
    sale_DB->confirmSale( second_sale.getId() );

    salaryPage->refreshPage();

    compareRowInSalaryTable( manager, QDate( QDate::currentDate().year(), QDate::currentDate().month(), 01 ), 0 );
}

void Test_Salary_GUI::showManagersSalaryInPreviousMonths() {}

void Test_Salary_GUI::showManagerSales() {

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
    ActiveSale first_sale = createConfirmedSale( first_product, QDate::currentDate(), manager_id );
    ActiveSale second_sale = createSale( second_product, QDate::currentDate(), manager_id );

    salaryPage->refreshPage();

    QWidget *w = salaryPage->salaryTable->indexWidget( salaryPage->salaryTable->model()->index( 0, 4 ) );

    QPushButton *btn = qobject_cast<QPushButton *>( w );
    btn->click();

    compareManagerSales( manager );
}

void Test_Salary_GUI::showManagerInfo() {

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
    manager.setSex( Sex::MALE );
    manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
    manager.setPassportSerial( "1000" );
    manager.setPassportNumber( "100000" );
    manager.setPassportSource( "ABC" );
    manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
    manager.setAddress( "ABC" );
    manager.setINN( "012345678901" );

    manager_DB->update( manager );

    salaryPage->refreshPage();

    salaryPage->salaryTable->setFocus();
    QModelIndex newIndex = salaryPage->salaryTable->model()->index( 0, 1 );
    salaryPage->salaryTable->setCurrentIndex( newIndex );
    salaryPage->salaryTable->clicked( newIndex );

    compareManagerInfo( manager );
}

void Test_Salary_GUI::directManagerSales() {

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
    manager.setSex( Sex::MALE );
    manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
    manager.setPassportSerial( "1000" );
    manager.setPassportNumber( "100000" );
    manager.setPassportSource( "ABC" );
    manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
    manager.setAddress( "ABC" );
    manager.setINN( "012345678901" );

    manager_DB->update( manager );

    salaryPage->refreshPage();

    salaryPage->salaryTable->setFocus();
    QModelIndex newIndex = salaryPage->salaryTable->model()->index( 0, 1 );
    salaryPage->salaryTable->setCurrentIndex( newIndex );
    salaryPage->salaryTable->clicked( newIndex );

    salaryPage->salesButton->click();

    compareManagerSalesInSalesPage( manager );
}

void Test_Salary_GUI::directManagerInfo() {

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
    manager.setSex( Sex::MALE );
    manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
    manager.setPassportSerial( "1000" );
    manager.setPassportNumber( "100000" );
    manager.setPassportSource( "ABC" );
    manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
    manager.setAddress( "ABC" );
    manager.setINN( "012345678901" );

    manager_DB->update( manager );

    salaryPage->refreshPage();

    salaryPage->salaryTable->setFocus();
    QModelIndex newIndex = salaryPage->salaryTable->model()->index( 0, 1 );
    salaryPage->salaryTable->setCurrentIndex( newIndex );
    salaryPage->salaryTable->clicked( newIndex );

    salaryPage->dataButton->click();

    compareManagerInfoInEmployeesPage( manager );
}

void Test_Salary_GUI::cleanup() {

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

    salaryPage->refreshPage();
}
