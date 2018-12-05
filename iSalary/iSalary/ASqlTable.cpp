#include "ASqlTable.h"

void ASqlTable::execQuery( QSqlQuery& query) const {
    
	bool isSuccess = query.exec();
	if( !isSuccess ){
		QString err = query.lastError().text();
		this->handleError( query.lastError());
	}
}

void ASqlTable::handleError( QSqlError error) const {

    QSqlError * err = new QSqlError(error);
    QString text = err->text() + db->lastError().text();
    throw err;
}

void ASqlTable::handleError( const QString& error) const {
    QString * err = new QString(error);
    throw err;
}