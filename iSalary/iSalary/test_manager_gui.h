#ifndef TEST_MANAGER_GUI_H
#define TEST_MANAGER_GUI_H

#include <QObject>
#include <qtest.h>
#include "QTextCodec"
#include "ManagerPage.h"
#include <QSqlDatabase>
#include "UserDB.h"
class Test_Manager_GUI : public QObject
{
	Q_OBJECT
	friend class ManagerPage;

public:
	Test_Manager_GUI( QSqlDatabase *sql, ManagerPage *managerPage );
	~Test_Manager_GUI();

private:
	ManagerPage *managerPage;
	Product_DB *product_DB;
	Sale_DB *sale_DB;
	UserDB *user_DB;
	QSqlDatabase *sql;
	QTextCodec * c;
	int manager_id;

	void removeProduct( QString productName );
	Product createProduct( QString productName, double productCommission );
	QString findElemInProductTable( int row, int col );
	QString findElemInUnconfirmedTable( int row, int col );
	QString findElemInConfirmedTable( int row, int col );
	ActiveSale createSale( Product product);

private slots:
	void showProduct();

	void addUnconfirmedSale();
	void removeUnconfirmedSale();

	void showConfirmedSale();

	void calcUnconfirmedSalary();

	void calcConfirmedSalary();

	void cleanupTestCase();
};

#endif // TEST_MANAGER_GUI_H
