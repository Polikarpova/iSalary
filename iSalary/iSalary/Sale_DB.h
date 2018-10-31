#pragma once
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVariant>
#include <QSqlResult>
#include "ActiveSale.h"
#include "ClosedSale.h"
#include "Manager.h"
#include <QVector>
#include <QSqlError>

class Sale_DB
{
public:
	Sale_DB( QSqlDatabase &db, QString table_name );
	~Sale_DB(void);
	void init();
	void create( ActiveSale sale );
	void fillSale( ActiveSale & sale, const QSqlQuery * sqlQuery );
	QVector<ActiveSale> getActiveAll( int manager_id );

protected:
	QString TABLE_NAME;
	ActiveSale read(const QSqlQuery * sqlQuery);

private:
	QSqlDatabase _db;
};
