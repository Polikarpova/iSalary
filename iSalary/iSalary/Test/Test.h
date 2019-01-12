#include "test_product_db.h"
#include "test_user_db.h"

#include "test_product_gui.h"
#include "test_manager_gui.h"
#include "test_employees_gui.h"
#include "test_sales_gui.h"
#include "test_statistic_gui.h"
#include "test_salary_gui.h"
#include "test_auth_gui.h"

#include <iostream>
#include "stdio.h"
using namespace std;
class Test
{
public:
	Test( 
		QSqlDatabase *sql,
		AuthPage *authPage,
		EmployeesPage *employeesPage,
		ProductPage *productPage,
		SalesPage *salesPage,
		StatisticPage *statisticPage,
		SalaryPage *salaryPage,
		ManagerPage *managerPage
	);
	~Test(void);
	void startTesting();

private:
	QSqlDatabase  *db;
	AuthPage *authPage;
	EmployeesPage *employeesPage;
	ProductPage *productPage;
	SalesPage *salesPage;
	StatisticPage *statisticPage;
	SalaryPage *salaryPage;
	ManagerPage *managerPage;

	void test_DB();
	void test_GUI();
};

