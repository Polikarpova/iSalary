#include "Product_DB.h"


Product_DB::Product_DB( QSqlDatabase &db, QString table_name ) {
	_db = db;
	TABLE_NAME = table_name;
}


Product_DB::~Product_DB(void) {

}

void Product_DB::init(){
    QSqlQuery query(_db);
    query.prepare("CREATE TABLE  IF NOT EXISTS `products` (`id` int NOT NULL PRIMARY KEY AUTO_INCREMENT, `name` NVARCHAR(45) NOT NULL,`commission` DOUBLE NOT NULL)");
    query.exec();
}