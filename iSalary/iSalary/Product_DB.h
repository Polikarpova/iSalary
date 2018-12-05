#pragma once
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVariant>
#include <QSqlResult>
#include "Product.h"
#include <QVector>
#include <QSqlError>

#include "ASqlTable.h"

class Product_DB : public ASqlTable
{
public:
	Product_DB( QSqlDatabase *db, QString table_name );
	~Product_DB(void);
	void init();
	void create(Product product);
	void update(Product product);
	void remove(int id);
	void fillProduct( Product & product, const QSqlQuery * sqlQuery );
	Product findByName( QString productName );
	Product findById( int id );
	QVector<Product> getAll();
    
    void createTable() override;

protected:
	QString TABLE_NAME;
	Product read(const QSqlQuery * sqlQuery);

private:
};

