#ifndef TEST_PRODUCT_DB_H
#define TEST_PRODUCT_DB_H

#include <QObject>
#include <qtest.h>
#include <QSqlDatabase>
#include "Product_DB.h"
#include "QTextCodec"
class Test_Product_DB : public QObject
{
	Q_OBJECT

public:
	Test_Product_DB( QSqlDatabase *sql );
	~Test_Product_DB();

private:
	QSqlDatabase *sql;
	Product_DB * product_DB;
	QTextCodec * c;

	void removeProduct( int id );

private slots:
	void create();
	void update();
	void remove();
	void getAll();
};

#endif // TEST_PRODUCT_DB_H
