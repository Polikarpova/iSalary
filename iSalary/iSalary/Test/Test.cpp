#include "Test.h"


Test::Test( QSqlDatabase * sqlDB, ProductPage *productPage )
{
	freopen("testing.log", "w", stdout);
	db = sqlDB;
	this->productPage = productPage;
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
	
	Test_Product_GUI test_product_GUI( db, productPage );
	QTest::qExec( &test_product_GUI );
}
