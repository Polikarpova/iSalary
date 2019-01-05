#include "test_product_db.h"

Test_Product_DB::Test_Product_DB( QSqlDatabase *_sql ) {
	sql = _sql;
	product_DB = new Product_DB( _sql, "products" );
	product_DB->init();
	c = QTextCodec::codecForName("CP1251");
}

Test_Product_DB::~Test_Product_DB() {

}

void Test_Product_DB::removeProduct( int id ) {
	QSqlQuery query("DELETE FROM products WHERE id = " + QString::number( id ), *sql);
	bool isOk = query.exec();
}

void Test_Product_DB::create() {
	
	Product product;
	QString productName = c->toUnicode( "Товар" );
	product.setName( productName );
	product.setCommission( 15.33 );
	product_DB->create( product );
	Product res_product = product_DB->findByName( productName );
	removeProduct( res_product.getId() );
	QCOMPARE( res_product.getName(), product.getName() );
	QCOMPARE( res_product.getCommission(), product.getCommission() );
}

void Test_Product_DB::update() {
	
	Product product;
	QString productName = c->toUnicode( "Товар" );
	product.setName( productName );
	product.setCommission( 15.33 );
	product_DB->create( product );
	product = product_DB->findByName( productName );
	QString newProductName = c->toUnicode( "Другой Товар" );
	product.setName( newProductName );
	product_DB->update( product );
	Product res_product = product_DB->findByName( newProductName );
	removeProduct( res_product.getId() );
	QCOMPARE( res_product.getName(), product.getName() );
	QCOMPARE( res_product.getCommission(), product.getCommission() );
}

void Test_Product_DB::remove() {
	
	Product product;
	QString productName = c->toUnicode( "Товар" );
	product.setName( productName );
	product.setCommission( 15.33 );
	product_DB->create( product );
	Product res_product = product_DB->findByName( productName );
	product_DB->remove( res_product.getId() );
	res_product = product_DB->findByName( productName );
	removeProduct( res_product.getId() );
	QCOMPARE( res_product.getIsDeleted(), true );
}

void Test_Product_DB::getAll() {
	
	QVector<Product> products;
	QString productName = "";
	for (int i = 0; i < 3; i++) {
		Product product;
		productName += 'A' + i;
		product.setName( productName );
		product.setCommission( i );
		product_DB->create( product );
		products.append( product );
	}
	QVector<Product> res_products = product_DB->getAll();
	QCOMPARE( res_products.size(), products.size() );
	for (int i = 0; i < res_products.size(); i++) {
		QCOMPARE( res_products[i].getName(), products[i].getName() );
		QCOMPARE( res_products[i].getCommission(), products[i].getCommission() );
		removeProduct( res_products[i].getId() );
	}
}

