#include "Sale_DB.h"


Sale_DB::Sale_DB( QSqlDatabase &db, QString table_name ) {
	_db = db;
	TABLE_NAME = table_name;
}


Sale_DB::~Sale_DB(void) {

}

void Sale_DB::init() {
    QSqlQuery query( _db );
    query.prepare( "CREATE TABLE  IF NOT EXISTS `" + TABLE_NAME + 
		"` (`id` int NOT NULL PRIMARY KEY AUTO_INCREMENT, `manager_id` int NOT NULL,`product_id` int NOT NULL, `price` DOUBLE NOT NULL, `count` int NOT NULL)" );
    query.exec();
}

void Sale_DB::create( Sale sale ) {

    QSqlQuery query( _db );
	query.prepare( QString( "INSERT INTO " + TABLE_NAME + 
		" (`manager_id`, `product_id`, `price`, `count`) VALUES(:manager_id, :product_id, :price, :count)" ) );
	query.bindValue( ":manager_id", sale.getSaler().getId() );
	query.bindValue( ":product_id",  sale.getProduct().getId() );
	query.bindValue( ":price", sale.getCost() );
	query.bindValue( ":count",  sale.getCount() );

    bool isOk = query.exec();
    if ( !isOk ) {
		QString s = _db.lastError().text();
        int stop = 2;
    }
}

Sale Sale_DB::read( const QSqlQuery * sqlQuery ){
    Sale sale;
    fillSale( sale, sqlQuery );
    return sale;
}

void Sale_DB::fillSale( Sale & sale, const QSqlQuery * sqlQuery ) {
	sale.setId( sqlQuery->value( "id" ).value<int>() );
	sale.setSalerId( sqlQuery->value( "manager_id" ).value<int>() );
	sale.setProductId( sqlQuery->value( "product_id" ).value<int>() );
	sale.setCost( sqlQuery->value( "price" ).value<double>() );
	sale.setCount( sqlQuery->value( "count" ).value<int>() );
}

QVector<Sale> Sale_DB::getAll( int manager_id ) {
    QSqlQuery query( QString( "SELECT * FROM " ) + TABLE_NAME, _db );
    QVector<Sale> sales;
    while ( query.next() ) {
        Sale sale = read( &query );
		if ( sale.getSalerId() == manager_id ) {
			sales.append( sale );
		}
    }
    return sales;
}