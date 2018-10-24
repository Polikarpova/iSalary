#include "Product_DB.h"


Product_DB::Product_DB( QSqlDatabase &db, QString table_name ) {
	_db = db;
	TABLE_NAME = table_name;
}


Product_DB::~Product_DB(void) {

}

void Product_DB::init() {
    QSqlQuery query(_db);
    query.prepare("CREATE TABLE  IF NOT EXISTS `products` (`id` int NOT NULL PRIMARY KEY AUTO_INCREMENT, `name` NVARCHAR(45) NOT NULL,`commission` DOUBLE NOT NULL)");
    query.exec();
}

void Product_DB::create( Product product ) {

    QSqlQuery query( _db );
	query.prepare( QString( "INSERT INTO products (`name`, `commission`) VALUES(:name, :commission)" ) );
    query.bindValue( ":name", product.getName() );
	query.bindValue( ":commission",  product.getCommission() );

    bool isOk = query.exec();
    if ( !isOk ) {
		QString s = _db.lastError().text();
        int stop = 2;
    }
}