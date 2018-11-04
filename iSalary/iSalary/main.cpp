#include <QtWidgets/QApplication>

#include "mainwindow.h"

#include "AuthorizationFacade.h"
#include "PersonnalAccountingFacade.h"

#include "UserDB.h"
#include "ManagerDB.h"

#include "AuthPage.h"
#include "EmployeesPage.h"

#include "test_userdb.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

    QSqlDatabase sqlDB;
    
	sqlDB= QSqlDatabase::addDatabase( "QMYSQL");
	sqlDB.setHostName( "127.0.0.1");
    sqlDB.setPort( 3306);
    sqlDB.setDatabaseName( "test");
    sqlDB.setUserName( "root");
    sqlDB.setPassword( "root");
    bool isOpen = sqlDB.open();

	freopen("testing.log", "w", stdout);
	Test_UserDB test_userDB( &sqlDB );
	QTest::qExec( &test_userDB );
    
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

    MainWindow w( &authPage, &employeesPage);
	w.show();
    
    int stop = 2;
    
    int exitCode =-1;
    exitCode = a.exec();
    return exitCode;
    
}
