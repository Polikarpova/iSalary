#include <QtWidgets/QApplication>

#include "mainwindow.h"
#include "AuthorizationFacade.h"
#include "UserDB.h"
#include "AuthPage.h"
#include "ProductPage.h"
#include "ManagerPage.h"
#include "PersonnalAccountingFacade.h"

#include "SalesFacade.h"

#include "UserDB.h"
#include "ManagerDB.h"

#include "Sale_DB.h"
#include "ManagerDB.h"

#include "AuthPage.h"
#include "EmployeesPage.h"
#include "SalesPage.h"

#include "Test.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

    QSqlDatabase sqlDB;
    
	sqlDB= QSqlDatabase::addDatabase( "QMYSQL");
	sqlDB.setHostName( "127.0.0.1");
    sqlDB.setPort( 3306);

	Test test = Test(sqlDB);
	test.startTesting();

	sqlDB.setDatabaseName( "mdkp");
    sqlDB.setUserName( "root");
    sqlDB.setPassword( "root");
    bool isOpen = sqlDB.open();

	Product_DB *product_DB = new Product_DB( sqlDB, "products" );
	ProductFacade *productFacade = new ProductFacade( product_DB );
	ProductPage *productPage = new ProductPage( productFacade );

	Sale_DB *sale_DB = new Sale_DB( sqlDB, "sales" );
	SaleFacade *saleFacade = new SaleFacade( sale_DB );
	ManagerPage *managerPage = new ManagerPage( productFacade, saleFacade );
    
	UserDB userDB( &sqlDB);
    UserValidator userValidator( &userDB);
    AuthorizationModule authModule( &userValidator, &userDB);
    AuthorizationFacade authFacade( &authModule);
    AuthPage authPage( &authFacade);

    ManagerDB managerDB( &sqlDB, &userDB);
    ManagerValidator managerValidator( &userDB, &managerDB);
    Employer employer( &authModule, &managerDB, &managerValidator);
    PersonnalAccountingFacade personnalAccountingFacade( &employer, &managerDB, &managerValidator);
    EmployeesPage employeesPage( &personnalAccountingFacade);

    Sale_DB * saleDB = new Sale_DB( sqlDB, QString("sales"));
	SalesFacade * salesFacade = new SalesFacade(&managerDB, saleDB);
    //SalesPage salesPage(salesFacade);

    MainWindow w( 
		&authPage, 
		&employeesPage, 
		NULL,//&salesPage, 
		productPage,
		managerPage
	);
	
	w.show();

	int exitCode = a.exec();

    return exitCode;
}
