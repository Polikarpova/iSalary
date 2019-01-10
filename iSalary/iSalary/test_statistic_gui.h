#ifndef TEST_STATISTIC_GUI_H
#define TEST_STATISTIC_GUI_H

#include "Product_DB.h"
#include "QTextCodec"
#include "StatisticPage.h"
#include <QObject>
#include <QSqlDatabase>
#include <qtest.h>

class Test_Statistic_GUI : public QObject {
    Q_OBJECT
    friend class StatisticPage;

  public:
    Test_Statistic_GUI( QSqlDatabase *sql, StatisticPage *statisticPage );
    ~Test_Statistic_GUI();

  private:
    StatisticPage *statisticPage;
    Product_DB *product_DB;
    UserDB *user_DB;
    ManagerDB *manager_DB;
    Sale_DB *sale_DB;
    QSqlDatabase *sql;
    QTextCodec *c;

    void removeProduct( QString productName );
    Product createProduct( QString productName, double productCommission );
    QString findElemInStatisticTable( int row, int col );
    QString findElemInStatisticSalesTable( int row, int col );
    ActiveSale createSale( Product product, QDate saleDate, int manaher_id );
    void removeEmployee( int id );
    void compareRowInStatisticTable( Manager manager, int row );
    void compareRowInStatisticSalesTable( ActiveSale sale, int row );
    void rowInStatisticSalesTableIsEmpty( int row );
    void managerStatisticIsEmpty( Manager manager, int row );

  private slots:
    void showCountManagerSales();
    void showSales();
    void showCalendar();
    void showSalesInPreviousMonths();
    void showAllManagersSales();
	//void init();
	void cleanup();
};

#endif // TEST_STATISTIC_GUI_H
