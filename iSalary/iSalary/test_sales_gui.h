#ifndef TEST_SALES_GUI_H
#define TEST_SALES_GUI_H

#include "EmployeesPage.h"
#include "Product_DB.h"
#include "QTextCodec"
#include "SalesPage.h"
#include <QObject>
#include <QSqlDatabase>
#include <qtest.h>

class Test_Sales_GUI : public QObject {
    Q_OBJECT
    friend class SalesPage;

  public:
    Test_Sales_GUI( QSqlDatabase *sql, SalesPage *salesPage );
    ~Test_Sales_GUI();

  private:
    SalesPage *salesPage;
    Product_DB *product_DB;
    UserDB *user_DB;
    ManagerDB *manager_DB;
    Sale_DB *sale_DB;
    QSqlDatabase *sql;
    QTextCodec *c;

    void removeProduct( QString productName );
    Product createProduct( QString productName, double productCommission );
    QString findElemInManagersTable( int row, int col );
    QString findElemInUnconfirmedTable( int row, int col );
    QString findElemInConfirmedTable( int row, int col );
    ActiveSale createSale( Product product, int manaher_id );
    void removeEmployee( int id );
    void compareRowInUnconfirmedTable( QString FIO, ActiveSale sale, int row );
    void compareRowInConfirmedTable( QString FIO, ActiveSale sale, int row );
    void unconfirmedTableIsEmpty();
    void confirmedTableIsEmpty();

  private slots:
    void initTestCase();
    void showCountManagerSales();
    void showManagerUnconfirmedSales();
    void showManagerConfirmedSales();
    void confirmSale();
    void unconfirmSale();
    void showAllManagersSales();
    // void cleanupTestCase();
};

#endif // TEST_SALES_GUI_H
