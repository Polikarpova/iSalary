#include "Product_DB.h"


Product_DB::Product_DB( QSqlDatabase &db, QString table_name ) {
	_db = db;
	TABLE_NAME = table_name;
	this->init();
}


Product_DB::~Product_DB(void) {

}

void Product_DB::init() {
}

void Product_DB::createTable() {
    QSqlQuery query( _db );
    query.prepare( "CREATE TABLE  IF NOT EXISTS `" + TABLE_NAME + "` (`id` int NOT NULL PRIMARY KEY AUTO_INCREMENT, `name` NVARCHAR(45) NOT NULL,`commission` DOUBLE NOT NULL)" );
    try {
		bool isSuccess = query.exec();
		if ( !isSuccess ) {
			QString s = _db.lastError().text();
			int stop = 2;
		}
	} catch ( ... ) {}
}

bool Product_DB::create( Product product ) {

    QSqlQuery query( _db );
	query.prepare( QString( "INSERT INTO " + TABLE_NAME + " (`name`, `commission`) VALUES(:name, :commission)" ) );
    query.bindValue( ":name", product.getName() );
	query.bindValue( ":commission",  product.getCommission() );

    try {
		bool isSuccess = query.exec();
		if ( !isSuccess ) {
			QString s = _db.lastError().text();
			int stop = 2;
		}
		return isSuccess;
	} catch ( ... ) {}
	
}

bool Product_DB::update( Product product ) {

    QSqlQuery query( _db );
	query.prepare(QString( "UPDATE " + TABLE_NAME + " SET `name` = :name, `commission` = :commission WHERE id = ") + QString::number( product.getId() ) );
    query.bindValue( ":name", product.getName() );
	query.bindValue( ":commission",  product.getCommission() );

    try {
		bool isSuccess = query.exec();
		if ( !isSuccess ) {
			QString s = _db.lastError().text();
			int stop = 2;
		}
		return isSuccess;
	} catch ( ... ) {}
}

bool Product_DB::remove( int id ) {
	QSqlQuery query("DELETE FROM " + TABLE_NAME + " WHERE id = " + QString::number(id), _db);
	try {
		bool isSuccess = query.exec();
		if ( !isSuccess ) {
			QString s = _db.lastError().text();
			int stop = 2;
		}
		return isSuccess;
	} catch ( ... ) {}
}

Product Product_DB::read( const QSqlQuery * sqlQuery ){
    Product product;
    fillProduct( product, sqlQuery );
    return product;
}

void Product_DB::fillProduct( Product & product, const QSqlQuery * sqlQuery ) {
	product.setId( sqlQuery->value( "id" ).value<int>() );
	product.setName( sqlQuery->value( "name" ).value<QString>() );
	product.setCommission( sqlQuery->value( "commission" ).value<double>() );
}

QVector<Product> Product_DB::getAll() {
    QSqlQuery query( QString( "SELECT * FROM " ) + TABLE_NAME, _db );
    QVector<Product> products;
    while ( query.next() ) {
        Product product = read( &query );
        products.append( product );
    }
    return products;
}

Product Product_DB::findByName( QString productName ) {
	productName.insert( 0, "'");
	productName += "'";
	QSqlQuery query( "SELECT * FROM products WHERE name = " + productName, _db );
	bool isOk = query.next();
	QString s = query.lastError().text();
	Product product = read( &query );
	return product;
}

Product Product_DB::findById( int id ) {
	QSqlQuery query("SELECT * FROM " + TABLE_NAME + " WHERE id = " + QString::number(id), _db);
    bool isSuccess = query.next();
	Product product = read( &query );
	return product;
}