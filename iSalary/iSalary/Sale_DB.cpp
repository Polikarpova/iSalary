#include "Sale_DB.h"
#include "ActiveSale.h"
#include "Manager.h"

Sale_DB::Sale_DB( QSqlDatabase &db, QString table_name ) {
	_db = db;
	TABLE_NAME = table_name;
	this->init();
}


Sale_DB::~Sale_DB(void) {

}

void Sale_DB::init() {
    QSqlQuery query( _db );
    query.prepare( "CREATE TABLE  IF NOT EXISTS `" + TABLE_NAME + 
		"` (`id` int NOT NULL PRIMARY KEY AUTO_INCREMENT, `manager_id` int NOT NULL, `product_id` int NOT NULL, `price` DOUBLE NOT NULL, `count` int NOT NULL, `isActive` INT(1) NOT NULL, `isConfirmed` INT(1) NOT NULL)" );
    query.exec();
}

bool Sale_DB::create( ActiveSale sale ) {

    QSqlQuery query( _db );
	query.prepare( QString( "INSERT INTO " + TABLE_NAME + 
		" (`manager_id`, `product_id`, `price`, `count`, `isActive`, `isConfirmed`) VALUES(:manager_id, :product_id, :price, :count, :isActive, :isConfirmed)" ) );
	query.bindValue( ":manager_id", sale.getSaler().getId() );
	query.bindValue( ":product_id",  sale.getProduct().getId() );
	query.bindValue( ":price", sale.getCost() );
	query.bindValue( ":count",  sale.getCount() );
	query.bindValue( ":isActive", 1 );
	query.bindValue( ":isConfirmed",  0 );

    bool isSuccess = query.exec();
    if ( !isSuccess ) {
		QString s = _db.lastError().text();
        int stop = 2;
    }
	return isSuccess;
}

bool Sale_DB::remove( int id ) {
	QSqlQuery query("DELETE FROM " + TABLE_NAME + " WHERE id = " + QString::number(id), _db);
    bool isSuccess = query.exec();
	return isSuccess;
}

ActiveSale Sale_DB::read( const QSqlQuery * sqlQuery ) {
    ActiveSale sale;
    fillSale( sale, sqlQuery );
    return sale;
}

void Sale_DB::fillSale( ActiveSale & sale, const QSqlQuery * sqlQuery ) {
	sale.setId( sqlQuery->value( "id" ).value<int>() );
	sale.setSalerId( sqlQuery->value( "manager_id" ).value<int>() );
	sale.setProductId( sqlQuery->value( "product_id" ).value<int>() );
	sale.setCost( sqlQuery->value( "price" ).value<double>() );
	sale.setCount( sqlQuery->value( "count" ).value<int>() );
	if ( sqlQuery->value( "isConfirmed" ).value<int>() == 1 ) {
		sale.confirm();
	} else {
		sale.cancelConfirm();
	}
}

QVector<ActiveSale> Sale_DB::getActiveAll( int manager_id ) {
    QSqlQuery query( QString( "SELECT * FROM " ) + TABLE_NAME, _db );
    QVector<ActiveSale> sales;
    while ( query.next() ) {
        if ( query.value( "isActive" ).value<int>() == 1 ) {
			ActiveSale sale = read( &query );
			if ( sale.getSalerId() == manager_id ) {
				sales.append( sale );
			}
		}	
    }
    return sales;
}

int Sale_DB::getById(int id) {

    QString sql = "SELECT * FROM %1 WHERE id = %2";

	sql.arg(TABLE_NAME, QString(id));

    return 0;
}

QList<ManagerActiveSalesStatisticDTO> Sale_DB::getManagerActiveSalesSatistic() {

	//������� ������ � sql-��������
	QString sql = "select users.id, users.firstName, users.secondName, users.thirdName,	( select count(sales.isConfirmed) from sales, users where sales.manager_id = users.id AND sales.isActive = 1 AND sales.isConfirmed = 1) as confrim, count(sales.isConfirmed) as unconfirm from users, sales where sales.manager_id = users.id AND sales.isActive = 1 AND sales.isConfirmed = 0;";

	QSqlQuery query( this->_db);
	query.prepare(sql);

	this->execQuery( query);

	QList<ManagerActiveSalesStatisticDTO> result;

	while( query.next() ) {
	
		result.append( this->readToDTO(query) );
	}

	return result;
}

QList<ActiveSaleDTO> Sale_DB::getActiveSales() {

	//������� ������ � sql-��������
	QString sql = "select users.firstName, users.secondName, users.thirdName, sales.*, products.name, products.commission from sales, users, products where sales.manager_id = users.id AND sales.product_id = products.id AND sales.isActive = 1";
	QSqlQuery query( this->_db);
	query.prepare(sql);

	this->execQuery( query);

	QList<ActiveSaleDTO> result;

	while( query.next() ) {
	
		result.append( this->readActiveSalesToDTO(query) );
	}

	return result;
}

ManagerActiveSalesStatisticDTO Sale_DB::readToDTO( const QSqlQuery& query) {

	struct ManagerActiveSalesStatisticDTO result;

	result.managerId = query.value("id").value<int>();
	result.managerName = query.value("secondName").value<QString>() + " " +
						 query.value("firstName").value<QString>() + " " +
						 query.value("thirdName").value<QString>();
	result.confirmCount = query.value("confirm").value<int>();
	result.unconfirmCount = query.value("unconfirm").value<int>();

	return result;
}

ActiveSaleDTO Sale_DB::readActiveSalesToDTO( const QSqlQuery& query) {

	struct ActiveSaleDTO result;

	result.id = query.value("id").value<int>();
	result.managerName = query.value("secondName").value<QString>() + " " +
						 query.value("firstName").value<QString>() + " " +
						 query.value("thirdName").value<QString>();
	
	result.product.id = query.value("product_id").value<int>();
	result.product.name = query.value("name").value<QString>();
	result.product.commission = query.value("commission").value<double>();

	result.price = query.value("price").value<double>();
	result.count = query.value("count").value<int>();
	result.isConfirm = query.value("isConfirmed").value<int>() ? true : false;

	return result;
}

void Sale_DB::execQuery( QSqlQuery& query) const {
    bool isSuccess = query.exec();
    if( !isSuccess ){
        QString err = query.lastError().text();
        this->handleError( query.lastError());
    }
}

void Sale_DB::handleError( const QSqlError& error) const {

    QSqlError * err = new QSqlError(error);
	QString text = err->text() + this->_db.lastError().text();
    throw err;
}

void Sale_DB::handleError( const QString& error) const {
    QString * err = new QString(error);
    throw err;
}


