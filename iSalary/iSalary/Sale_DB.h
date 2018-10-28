#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVariant>
#include <QSqlResult>
#include "Sale.h"
#include <QVector>
#include <QSqlError>

class Sale_DB
{
public:
	Sale_DB( QSqlDatabase &db, QString table_name );
	~Sale_DB(void);
	void init();
	void create(Sale sale);
	void update(Sale sale);
	void remove(int id);
	void fillSale( Sale & sale, const QSqlQuery * sqlQuery );
	QVector<Sale> getAll(int manager_id);

protected:
	QString TABLE_NAME;
	Sale read(const QSqlQuery * sqlQuery);

private:
	QSqlDatabase _db;
};

