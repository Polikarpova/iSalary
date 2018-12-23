#include "TabNavigator.h"
#include "EmployeesPage.h"
#include "ProductPage.h"
#include "SalesPage.h"
#include "SalaryPage.h"

TabNavigator::TabNavigator(QTabWidget* tabs) {

	this->tabs = tabs;
}


TabNavigator::~TabNavigator(void)
{
}

void TabNavigator::setEmployeesPage(EmployeesPage* employeesPage) {

	this->employeesPage = employeesPage;
}

void TabNavigator::setProductPage(ProductPage* productPage) {

	this->productPage = productPage;
}

void TabNavigator::setSalesPage(SalesPage* salesPage) {

	this->salesPage = salesPage;
}

void TabNavigator::setSalaryPage(SalaryPage* salaryPage) {

	this->salaryPage = salaryPage;
	this->salaryPage->setTabNavigator(this);
}

void TabNavigator::openEmployeesPage( int employId) {
		tabs->setCurrentIndex( PAGE_EMPLOYEES);
		this->employeesPage->showDetailsById( employId);
}

void TabNavigator::openSalesPage( int id) {
		tabs->setCurrentIndex( PAGE_SALES);
		this->salesPage->showManagerSales( id);
}