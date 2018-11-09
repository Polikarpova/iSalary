#include <QtWidgets/QApplication>

#include "mainwindow.h"
#include "AuthorizationFacade.h"
#include "UserDB.h"
#include "AuthPage.h"

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

    UserDB * userDB = new UserDB( &sqlDB);
    AuthorizationModule * authModule = new AuthorizationModule( userDB);
    AuthorizationFacade * authFacade = new AuthorizationFacade( authModule);
    AuthPage * authPage = new AuthPage( authFacade);

    MainWindow w( authPage);
	w.show();

	int exitCode = a.exec();

    delete authPage;
    delete authFacade;
    delete authModule;
    delete userDB;

    return exitCode;
}
