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

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
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

    QSqlDatabase sqlDB;
    
	sqlDB= QSqlDatabase::addDatabase( "QMYSQL");
    sqlDB.setHostName( settings.databaseIP);
    sqlDB.setPort( settings.databasePort.toInt());
    sqlDB.setDatabaseName( settings.databaseName);
    sqlDB.setUserName( settings.databaseUser);
    sqlDB.setPassword( settings.databasePassword);

	Test test = Test(sqlDB);
	test.startTesting();

    sqlDB.setDatabaseName( "mdkp");
    sqlDB.setUserName( "root");
    sqlDB.setPassword( "root");
    bool isOpen = sqlDB.open();

    if( sqlDB.lastError().type() != QSqlError::NoError){
        QMessageBox::critical( 0, QString::fromWCharArray(L"������ ��� ����������� � ��"), sqlDB.lastError().text());
        return 0;
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

	Product_DB product_DB( sqlDB, "products" );
	ProductFacade productFacade( &product_DB );
	ProductPage productPage( &productFacade );

	SaleFacade saleFacade( &saleDB );
	ManagerPage managerPage( &productFacade, &saleFacade );

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
    return exitCode;
    
}
