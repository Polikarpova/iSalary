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
#include "ProductPage.h"
#include "ManagerPage.h"

#include "Test\Test.h"
#include "Settings.h"
#include <qfile.h>
#include <qfileinfo.h>
#include <qdir.h>
#include "dbHelpers.h"

Settings getSettings(){

    QString settingsFilePath( "./Settings/settings.json");
    QFileInfo settingsFileInfo( settingsFilePath);   
    QString fullPath = settingsFileInfo.absoluteFilePath();
    QFile settingsFile( fullPath);
    Settings settings; 
    if ( settingsFileInfo.exists()) {
        if ( settingsFileInfo.isFile() && settingsFileInfo.isReadable()) {
            settings = Settings::read( &settingsFile);
        } 
    } else {
        bool isCreate = QDir::current().mkdir(settingsFileInfo.dir().path());
        Settings::writeDefault( &settingsFile);
    }
    return settings;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    
    QSqlDatabase sqlDB;
    
    Settings settings = getSettings();

	sqlDB = QSqlDatabase::addDatabase( "QMYSQL");
    sqlDB.setHostName( settings.databaseIP);
    sqlDB.setPort( settings.databasePort.toInt());
    
    sqlDB.setUserName( settings.databaseUser);
    sqlDB.setPassword( settings.databasePassword);
    
    bool isOpen = sqlDB.open();

    UserDB userDB( &sqlDB);
    ManagerDB managerDB( &sqlDB, &userDB);
    Sale_DB saleDB( sqlDB, QString("sales"));
	AccoutingPeriodDB periodDB( &sqlDB);
	Product_DB product_DB( sqlDB, "products" );
	
    QList<ISqlTable*> tabels;
    tabels << &userDB << &managerDB <<  &product_DB << &saleDB << &periodDB;
    
    sqlDB.setDatabaseName( settings.databaseName);
    
    createDbAndTables(&sqlDB, settings.databaseName, tabels);

	//Test test = Test(sqlDB);
	//test.startTesting();


    if( sqlDB.lastError().type() != QSqlError::NoError){
        QMessageBox::critical( 0, QString::fromWCharArray(L"Ошибка подключения к БД"), sqlDB.lastError().text());
        return 0;
    }

	/*freopen("testing.log", "w", stdout);
	Test_UserDB test_userDB( &sqlDB );
	QTest::qExec( &test_userDB );*/
    
	
    UserValidator userValidator( &userDB);
    AuthorizationModule authModule( &userValidator, &userDB);
    AuthorizationFacade authFacade( &authModule);
    AuthPage authPage( &authFacade);

    ManagerValidator managerValidator( &userDB, &managerDB);
    Employer employer( &authModule, &managerDB, &managerValidator);
    PersonnalAccountingFacade personnalAccountingFacade( &employer, &managerDB, &managerValidator);
    EmployeesPage employeesPage( &personnalAccountingFacade);

    SalesFacade salesFacade(&managerDB, &saleDB, &periodDB);
    SalesPage salesPage(&salesFacade);

	SalaryPage salaryPage(&salesFacade, &personnalAccountingFacade);

	ProductFacade productFacade( &product_DB );
	ProductPage productPage( &productFacade );

	//SaleFacade saleFacade( &saleDB );
	ManagerPage managerPage( &productFacade, &salesFacade );

    MainWindow w( 
		&authPage,
		&employeesPage,
		&salesPage,
		&salaryPage,
		&productPage,
		&managerPage
	);
	
	w.show();
    
    int stop = 2;
    
    int exitCode =-1;
    exitCode = a.exec();
    sqlDB.close();
    return exitCode;
    
}
