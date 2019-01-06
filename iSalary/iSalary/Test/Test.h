#include "test_product_db.h"
#include "test_user_db.h"

#include "test_product_gui.h"

class Test
{
public:
	Test( 
		QSqlDatabase *sql,
		//AuthPage *authPage,
		//EmployeesPage *employeesPage,
		//SalesPage *salesPage,
		//SalaryPage *salaryPage,
		ProductPage *productPage
		//ManagerPage *managerPage,
		//StatisticPage *statisticPage
	);
	~Test(void);
	void startTesting();

private:
	QSqlDatabase  *db;
	//AuthPage *authPage,
	//EmployeesPage *employeesPage,
	//SalesPage *salesPage,
	//SalaryPage *salaryPage,
	ProductPage *productPage;
	//ManagerPage *managerPage,
	//StatisticPage *statisticPage

	void test_DB();
	void test_GUI();
};

