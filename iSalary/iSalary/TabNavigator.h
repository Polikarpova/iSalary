#pragma once
#include "enums.h"
#include <qtabwidget.h>

class EmployeesPage;
class ProductPage;
class SalesPage;
class SalaryPage;

class TabNavigator

{

  public:
    TabNavigator( QTabWidget *tabs );
    ~TabNavigator( void );

    QTabWidget *tabs;
    EmployeesPage *employeesPage;
    ProductPage *productPage;
    SalesPage *salesPage;
    SalaryPage *salaryPage;

    void setEmployeesPage( EmployeesPage *employeesPage );
    void setProductPage( ProductPage *productPage );
    void setSalesPage( SalesPage *salesPage );
    void setSalaryPage( SalaryPage *salaryPage );
    // setEmployeesPage(EmployeesPage* employeesPage);

    void openEmployeesPage( int employId );
    void openSalesPage( int id );
};
