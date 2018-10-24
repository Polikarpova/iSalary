#include "Product_DB.h"


Product_DB::Product_DB( QSqlDatabase &db, QString table_name ) {
	_db = db;
	TABLE_NAME = table_name;
}


Product_DB::~Product_DB(void) {

}
