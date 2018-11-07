#include <QtWidgets/QApplication>

#include "mainwindow.h"
#include "AuthorizationFacade.h"
#include "SalesFacade.h"

#include "UserDB.h"
#include "Sale_DB.h"
#include "ManagerDB.h"

#include "AuthPage.h"
#include "SalesPage.h"

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

    UserDB * userDB = new UserDB( &sqlDB);
    AuthorizationModule * authModule = new AuthorizationModule( userDB);
    AuthorizationFacade * authFacade = new AuthorizationFacade( authModule);
    AuthPage * authPage = new AuthPage( authFacade);

	Sale_DB * saleDB = new Sale_DB( &sqlDB, QString("sales"));
	ManagerDB * managerDB = new ManagerDB(&sqlDB, userDB);
	SalesFacade * salesFacade = new SalesFacade(managerDB, saleDB);
	SalesPage * salesPage = new SalesPage(salesFacade);

    MainWindow w( authPage , salesPage);
	w.show();

	int exitCode = a.exec();

    delete authPage;
    delete authFacade;
    delete authModule;
    delete userDB;

    return exitCode;
}
