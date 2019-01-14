#include "Test.h"


Test::Test( 
	QSqlDatabase * sqlDB,
	AuthPage *authPage,
	EmployeesPage *employeesPage, 
	ProductPage *productPage,
	SalesPage *salesPage,
	StatisticPage *statisticPage,
	SalaryPage *salaryPage,
	ManagerPage *managerPage )
{
	
	freopen("testing.log", "w", stdout);
	db = sqlDB;
	this->authPage = authPage;
	this->employeesPage = employeesPage;
	this->productPage = productPage;
	this->salesPage = salesPage;
	this->statisticPage = statisticPage;
	this->salaryPage = salaryPage;
	this->managerPage = managerPage;
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
	cout<<"Testing DB"<<endl;
	
	Test_Product_DB test_product_DB( db );
	QTest::qExec( &test_product_DB );
	
	cout<<endl;
	
	Test_User_DB test_user_DB( db );
	QTest::qExec( &test_user_DB );
	
	cout<<endl;

	Test_Manager_DB test_manager_DB( db );
	QTest::qExec( &test_manager_DB );

	cout<<endl;

	Test_Sale_DB test_sale_DB( db );
	QTest::qExec( &test_sale_DB );

	cout<<endl;
}

void Test::test_GUI() {
	
	cout<<"Testing GUI"<<endl;

	Test_Employees_GUI test_employees_GUI( db, employeesPage );
	QTest::qExec( &test_employees_GUI );

	cout<<endl;

	Test_Product_GUI test_product_GUI( db, productPage );
	QTest::qExec( &test_product_GUI );

	cout<<endl;

	Test_Manager_GUI test_manager_GUI( db, managerPage );
	QTest::qExec( &test_manager_GUI );

	cout<<endl;

	Test_Sales_GUI test_sales_GUI( db, salesPage );
	QTest::qExec( &test_sales_GUI );

	cout<<endl;

	Test_Statistic_GUI test_statistic_GUI( db, statisticPage );
	QTest::qExec( &test_statistic_GUI );

	cout<<endl;

	Test_Salary_GUI test_salary_GUI( db, salaryPage, employeesPage, salesPage );
	QTest::qExec( &test_salary_GUI );

	cout<<endl;

	Test_Auth_GUI test_auth_GUI( db, authPage, managerPage );
	QTest::qExec( &test_auth_GUI );

	cout<<endl;
}
