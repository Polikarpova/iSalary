#include <QtWidgets/QApplication>

#include "mainwindow.h"

#include "AuthorizationFacade.h"
#include "PersonnalAccountingFacade.h"

#include "SalesFacade.h"

#include "AccoutingPeriodDB.h"
#include "ManagerDB.h"
#include "Sale_DB.h"
#include "UserDB.h"

#include "AuthPage.h"
#include "EmployeesPage.h"
#include "ManagerPage.h"
#include "ProductPage.h"
#include "SalaryPage.h"
#include "SalesPage.h"
#include "StatisticPage.h"

#include "Settings.h"
#include "Test\Test.h"
#include "dbHelpers.h"
#include <qdir.h>
#include <qfile.h>
#include <qfileinfo.h>

Settings getSettings() {

    QString settingsFilePath( "./Settings/settings.json" );
    QFileInfo settingsFileInfo( settingsFilePath );
    QString fullPath = settingsFileInfo.absoluteFilePath();
    QFile settingsFile( fullPath );
    Settings settings;
    if ( settingsFileInfo.exists() ) {
        if ( settingsFileInfo.isFile() && settingsFileInfo.isReadable() ) {
            settings = Settings::read( &settingsFile );
        }
    } else {
        bool isCreate = QDir::current().mkdir( settingsFileInfo.dir().path() );
        Settings::writeDefault( &settingsFile );
    }
    return settings;
}

int main( int argc, char *argv[] ) {
    QApplication a( argc, argv );

    QSqlDatabase sqlDB;

    Settings settings = getSettings();

    sqlDB = QSqlDatabase::addDatabase( "QMYSQL" );
    sqlDB.setHostName( settings.databaseIP );
    sqlDB.setPort( settings.databasePort.toInt() );

    sqlDB.setUserName( settings.databaseUser );
    sqlDB.setPassword( settings.databasePassword );

    bool isOpen = sqlDB.open();

    UserDB userDB( &sqlDB );
    ManagerDB managerDB( &sqlDB, &userDB );
    Sale_DB saleDB( &sqlDB, QString( "sales" ) );
    AccoutingPeriodDB periodDB( &sqlDB );
    Product_DB product_DB( &sqlDB, "products" );

    QList<ASqlTable *> tabels;
    tabels << &userDB << &managerDB << &product_DB << &saleDB << &periodDB;

    sqlDB.setDatabaseName( settings.databaseName );

    createDbAndTables( &sqlDB, settings.databaseName, ( tabels ) );

    if ( sqlDB.lastError().type() != QSqlError::NoError ) {
        QMessageBox::critical( 0, QString::fromWCharArray( L"Ошибка подключения к БД" ), sqlDB.lastError().text() );
        return 0;
    }

    SqlErrorHandler sqlErrorHandler;
    for ( auto itable = tabels.begin(); itable != tabels.end(); itable++ ) {
        ( *itable )->setErrorHandler( &sqlErrorHandler );
    }

    UserValidator userValidator( &userDB );
    AuthorizationModule authModule( &userValidator, &userDB );
    AuthorizationFacade authFacade( &authModule );
    AuthPage authPage( &authFacade );

    ManagerValidator managerValidator( &userDB, &managerDB );
    Employer employer( &authModule, &managerDB, &managerValidator );
    PersonnalAccountingFacade personnalAccountingFacade( &employer, &managerDB, &managerValidator );
    EmployeesPage employeesPage( &personnalAccountingFacade );

    ProductFacade productFacade( &product_DB );
    ProductPage productPage( &productFacade );

    SalesFacade salesFacade( &managerDB, &saleDB, &periodDB );
    SalesPage salesPage( &salesFacade );

    SalaryPage salaryPage( &salesFacade, &personnalAccountingFacade );

    ManagerPage managerPage( &productFacade, &salesFacade );

    StatisticPage statisticPage( &salesFacade );

    MainWindow w( &authPage, &employeesPage, &salesPage, &salaryPage, &productPage, &managerPage, &statisticPage );
	
	if ( settings.databaseName == "test" ) {
		
		Test test = Test( &sqlDB, &authPage, &employeesPage, &productPage, &salesPage, &statisticPage, &salaryPage, &managerPage );
		test.startTesting();
	}

    try {
        w.showMaximized();
    } catch ( ... ) {
        QMessageBox::critical( 0, "Что-то пошло", "не так" );
    }
    int stop = 2;

    int exitCode = -1;
    exitCode = a.exec();
    sqlDB.close();
    return exitCode;
}
