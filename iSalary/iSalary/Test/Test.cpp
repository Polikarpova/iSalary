#include "Test.h"


Test::Test( QSqlDatabase * sqlDB, EmployeesPage *employeesPage, ProductPage *productPage, ManagerPage *managerPage )
{
	freopen("testing.log", "w", stdout);
	db = sqlDB;
	this->productPage = productPage;
	this->managerPage = managerPage;
	this->employeesPage = employeesPage;
	/*db->setDatabaseName( "test");
    db->setUserName( "root");
    db->setPassword( "root");
	db->open();*/
}


Test::~Test(void)
{
}

void Test::startTesting() {
	test_DB();
	test_GUI();
}

void Test::test_DB() {
	
	Test_Product_DB test_product_DB( db );
	QTest::qExec( &test_product_DB );
	Test_User_DB test_user_DB( db );
	QTest::qExec( &test_user_DB );
}

void Test::test_GUI() {
	
	Test_Employees_GUI test_employees_GUI( db, employeesPage );
	QTest::qExec( &test_employees_GUI );
	Test_Product_GUI test_product_GUI( db, productPage );
	QTest::qExec( &test_product_GUI );
	Test_Manager_GUI test_manager_GUI( db, managerPage );
	QTest::qExec( &test_manager_GUI );
}
