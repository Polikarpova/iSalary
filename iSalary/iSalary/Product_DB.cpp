#include "Product_DB.h"


Product_DB::Product_DB( QSqlDatabase &db, QString table_name ) {
	_db = db;
	TABLE_NAME = table_name;
}


Product_DB::~Product_DB(void) {

}

void Product_DB::init() {
    QSqlQuery query( _db );
    query.prepare( "CREATE TABLE  IF NOT EXISTS `products` (`id` int NOT NULL PRIMARY KEY AUTO_INCREMENT, `name` NVARCHAR(45) NOT NULL,`commission` DOUBLE NOT NULL)" );
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

void Product_DB::update( Product product ) {

    QSqlQuery query( _db );
	query.prepare(QString( "UPDATE products SET `name` = :name, `commission` = :commission WHERE id = ") + QString::number( product.getId() ) );
    query.bindValue( ":name", product.getName() );
	query.bindValue( ":commission",  product.getCommission() );

    bool isOk = query.exec();
    if ( !isOk ) {
		QString s = _db.lastError().text();
        int stop = 2;
    }
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