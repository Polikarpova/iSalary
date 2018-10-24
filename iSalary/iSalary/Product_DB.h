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

protected:
	QString TABLE_NAME;
private:
	QSqlDatabase _db;
};

