#include "Product_DB.h"


Product_DB::Product_DB( QSqlDatabase* db, QString table_name ) {
	this->db = db;
	TABLE_NAME = table_name;
	this->init();
}


Product_DB::~Product_DB(void) {

}

void Product_DB::init() {
}

void Product_DB::createTable() {
    QSqlQuery query( *db );
    query.prepare( "CREATE TABLE  IF NOT EXISTS `" + TABLE_NAME + "` (`id` int NOT NULL PRIMARY KEY AUTO_INCREMENT, `name` NVARCHAR(45) NOT NULL,`commission` DOUBLE NOT NULL)" );
    
    this->execQuery( query);
}

void Product_DB::create( Product product ) {

    QSqlQuery query( *db );
	query.prepare( QString( "INSERT INTO " + TABLE_NAME + " (`name`, `commission`) VALUES(:name, :commission)" ) );
    query.bindValue( ":name", product.getName() );
	query.bindValue( ":commission",  product.getCommission() );

    this->execQuery( query);
}

void Product_DB::update( Product product ) {

    QSqlQuery query( *db );
	query.prepare(QString( "UPDATE " + TABLE_NAME + " SET `name` = :name, `commission` = :commission WHERE id = ") + QString::number( product.getId() ) );
    query.bindValue( ":name", product.getName() );
	query.bindValue( ":commission",  product.getCommission() );

    this->execQuery( query);
}

void Product_DB::remove( int id ) {
	QSqlQuery query( *db);
    query.prepare( "DELETE FROM " + TABLE_NAME + " WHERE id = " + QString::number(id));
    this->execQuery( query);
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
    QSqlQuery query( *db );
    query.prepare(  QString( "SELECT * FROM " ) + TABLE_NAME);
    this->execQuery( query);
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
	QSqlQuery query( *db );
    query.prepare(  "SELECT * FROM products WHERE name = " + productName);
    this->execQuery( query);

	bool isOk = query.next();
	QString s = query.lastError().text();
	Product product = read( &query );
	return product;
}

Product Product_DB::findById( int id ) {
	QSqlQuery query(*db);
    query.prepare( "SELECT * FROM " + TABLE_NAME + " WHERE id = " + QString::number(id));
    this->execQuery( query);
	Product product = read( &query );
	return product;
}