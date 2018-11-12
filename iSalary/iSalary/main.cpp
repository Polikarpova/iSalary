#include <QtWidgets/QApplication>

#include "mainwindow.h"

#include "AuthorizationFacade.h"
#include "PersonnalAccountingFacade.h"

#include "SalesFacade.h"

#include "UserDB.h"
#include "ManagerDB.h"
#include "Sale_DB.h"
#include "AccoutingPeriodDB.h"

#include "AuthPage.h"
#include "EmployeesPage.h"
#include "SalesPage.h"
#include "SalaryPage.h"

#include "test_userdb.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

    QSqlDatabase sqlDB;
    
	sqlDB= QSqlDatabase::addDatabase( "QMYSQL");
	sqlDB.setHostName( "127.0.0.1");
    sqlDB.setPort( 3306);
    sqlDB.setDatabaseName( "mdkp");
    sqlDB.setUserName( "root");
    sqlDB.setPassword( "root");
    bool isOpen = sqlDB.open();

    if( sqlDB.lastError().type() != QSqlError::NoError){
        QMessageBox::critical( 0, "Nu epta", sqlDB.lastError().text());
    }

	/*freopen("testing.log", "w", stdout);
	Test_UserDB test_userDB( &sqlDB );
	QTest::qExec( &test_userDB );*/
    
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

    Sale_DB saleDB( sqlDB, QString("sales"));
	AccoutingPeriodDB periodDB( &sqlDB);
	SalesFacade salesFacade(&managerDB, &saleDB, &periodDB);
    SalesPage salesPage(&salesFacade);

	SalaryPage salaryPage(&salesFacade, &personnalAccountingFacade);

    MainWindow w( &authPage, &employeesPage, &salesPage, &salaryPage);
	
	w.show();
    
    int stop = 2;
    
    int exitCode =-1;
    exitCode = a.exec();
    return exitCode;
    
}
