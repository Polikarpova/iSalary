#pragma once
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVariant>
#include <QSqlResult>
#include "Product.h"
#include <QVector>
#include <QSqlError>
class Product_DB
{
public:
	Product_DB( QSqlDatabase &db, QString table_name );
	~Product_DB(void);
	void init();
	void create(Product product);
	void update(Product product);
	void remove(int id);
	void fillProduct( Product & product, const QSqlQuery * sqlQuery );
	Product findByName( QString productName );
	QVector<Product> getAll();

protected:
	QString TABLE_NAME;
	Product read( QSqlQuery * sqlQuery );

private:
	QSqlDatabase _db;
};

