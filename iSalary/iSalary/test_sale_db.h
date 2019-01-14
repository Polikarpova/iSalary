#ifndef TEST_SALE_DB_H
#define TEST_SALE_DB_H

#include "ManagerDB.h"
#include "Product_DB.h"
#include "QTextCodec"
#include "Sale_DB.h"
#include "UserDB.h"
#include <QObject>
#include <QSqlDatabase>
#include <qtest.h>

class Test_Sale_DB : public QObject {
    Q_OBJECT

  public:
    Test_Sale_DB( QSqlDatabase *sql );
    ~Test_Sale_DB();

  private:
    QSqlDatabase *sql;
    UserDB *user_DB;
    ManagerDB *manager_DB;
    Product_DB *product_DB;
    Sale_DB *sale_DB;
    QTextCodec *c;

    void removeManager( int id );
    Product createProduct( QString productName, double productCommission );
    void removeProduct( QString productName );
    void compareSales( ActiveSale first_sale, ActiveSale second_sale );
    void compareSales( QVector<ActiveSale> first_sales, QVector<ActiveSale> second_sales );
    void compareManagers( Manager first_manager, Manager second_manager );
    ActiveSale createSale( Product product, QDate saleDate, int manager_id );
    ActiveSale createConfirmedSale( Product product, QDate saleDate, int manager_id );

  private slots:
    void create();
    void getActiveManagerSales();
    void remove();
    void getActiveAllInPeriod();
    void confirmSale();
    void unconfirmSale();
    void cleanup();
};

#endif // TEST_SALE_DB_H
