#ifndef TEST_SALARY_GUI_H
#define TEST_SALARY_GUI_H

#include "EmployeesPage.h"
#include "Product_DB.h"
#include "QTextCodec"
#include <qlayout.h>
#include "SalaryPage.h"
#include "SalesPage.h"
#include <QObject>
#include <QSqlDatabase>
#include <qtest.h>

class Test_Salary_GUI : public QObject {
    Q_OBJECT
    friend class SalaryPage;
    friend class EmployeesPage;
    friend class SalesPage;

  public:
    Test_Salary_GUI( QSqlDatabase *sql, SalaryPage *salaryPage, EmployeesPage *employeesPage, SalesPage *salesPage );
    ~Test_Salary_GUI();

  private:
    SalaryPage *salaryPage;
    EmployeesPage *employeesPage;
    SalesPage *salesPage;
    Product_DB *product_DB;
    UserDB *user_DB;
    ManagerDB *manager_DB;
    Sale_DB *sale_DB;
    QSqlDatabase *sql;
    QTextCodec *c;

    void removeProduct( QString productName );
    Product createProduct( QString productName, double productCommission );
    QString findElemInSalaryTable( int row, int col );
    QString findElemInSalaryTotalTable( int col );
    QString findElemInUnconfirmedTable( int row, int col );
    QString findElemInConfirmedTable( int row, int col );
    ActiveSale createSale( Product product, QDate saleDate, int manaher_id );
	ActiveSale createConfirmedSale( Product product, QDate saleDate, int manager_id );
    void removeEmployee( int id );
    void compareRowInSalaryTable( Manager manager, QDate date, int row );
    // void compareRowInSalaryTotalTable( ActiveSale sale, int row );
    // void rowInStatisticSalesTableIsEmpty( int row );
    void salaryTotalIsEmpty();
    void compareRowInSalaryTotalTable();
    void compareRowInUnconfirmedTable( ActiveSale sale, int row );
    void compareRowInConfirmedTable( ActiveSale sale, int row );
    void unconfirmedTableIsEmpty();
    void confirmedTableIsEmpty();
    void compareManagerInfo( Manager manager );
    void compareManagerInfoInEmployeesPage( Manager manager );
    void compareManagerSales( Manager manager );
    void compareManagerSalesInSalesPage( Manager manager );

  private slots:
    void showManagersSalary();
    void showManagersSalaryInPreviousMonths();
    void showManagerSales();
    void showManagerInfo();
    void directManagerSales();
    void directManagerInfo();
    void cleanup();
};

#endif // TEST_SALARY_GUI_H
