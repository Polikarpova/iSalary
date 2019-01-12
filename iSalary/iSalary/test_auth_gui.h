#ifndef TEST_AUTH_GUI_H
#define TEST_AUTH_GUI_H

#include "AuthPage.h"
#include "ManagerPage.h"
#include "ManagerDB.h"
#include "Product_DB.h"
#include "QTextCodec"
#include "Sale_DB.h"
#include "UserDB.h"
#include <QObject>
#include <QSqlDatabase>
#include <qtest.h>

class Test_Auth_GUI : public QObject {
    Q_OBJECT
    friend class AuthPage;
	friend class ManagerPage;
  public:
    Test_Auth_GUI( QSqlDatabase *sql, AuthPage *authPage, ManagerPage *managerPage );
    ~Test_Auth_GUI();

  private:
    AuthPage *authPage;
	ManagerPage *managerPage;
    Product_DB *product_DB;
    UserDB *user_DB;
    ManagerDB *manager_DB;
    Sale_DB *sale_DB;
    QSqlDatabase *sql;
    QTextCodec *c;

	void removeProduct( QString productName );
	Product createProduct( QString productName, double productCommission );
	QString findElemInUnconfirmedTable( int row, int col );
    QString findElemInConfirmedTable( int row, int col );
	void unconfirmedTableIsEmpty();
    void confirmedTableIsEmpty();
	ActiveSale createSale( Product product, QDate saleDate, int manaher_id );
    ActiveSale createConfirmedSale( Product product, QDate saleDate, int manager_id );
	void removeEmployee( int id );
	void compareManagerSales( Manager manager );
	void compareRowInUnconfirmedTable( ActiveSale sale, int row );
	void compareRowInConfirmedTable( ActiveSale sale, int row );

  private slots:
    void managerAuth();
    void bossAuth();
    void cleanup();
};

#endif // TEST_AUTH_GUI_H
