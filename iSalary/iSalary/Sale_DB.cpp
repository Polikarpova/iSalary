#include "Sale_DB.h"
#include "ActiveSale.h"
#include "Manager.h"

Sale_DB::Sale_DB( QSqlDatabase* db, QString table_name ) {
	this->db = db;
	TABLE_NAME = table_name;
	this->init();
}


Sale_DB::~Sale_DB(void) {

}

void Sale_DB::init() {
}

void Sale_DB::createTable() {
    
    QSqlQuery query( *db );
    query.prepare( "CREATE TABLE  IF NOT EXISTS `" + TABLE_NAME + 
		"` (`id` int NOT NULL PRIMARY KEY AUTO_INCREMENT, `manager_id` int NOT NULL, `product_id` int NOT NULL, `productName` varchar(45) CHARACTER SET utf8 NOT NULL, `productCommission` double NOT NULL, `price` DOUBLE NOT NULL, `count` int NOT NULL, `isActive` INT(1) NOT NULL, `isConfirmed` INT(1) NOT NULL, `saleDate` date NOT NULL DEFAULT \"1000-01-01\", `confirmDate` DATE NOT NULL DEFAULT \"1000-01-01\" ) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;" );
	this->execQuery(query);
}

void Sale_DB::create( ActiveSale sale ) {

    QSqlQuery query( *db );
	QString sql = "INSERT INTO " + TABLE_NAME + 
		" (`manager_id`, `product_id`, `productName`, `productCommission`, `price`, `count`, `isActive`, `isConfirmed`) VALUES(:manager_id, :product_id, :name, :productCommission, :price, :count, :isActive, :isConfirmed)";
	query.prepare( sql );
	query.bindValue( ":manager_id", sale.getSaler().getId() );
	query.bindValue( ":product_id",  sale.getProduct().getId() );
	query.bindValue( ":name",  sale.getProduct().getName() );
	query.bindValue( ":productCommission",  sale.getProduct().getCommission() );
	query.bindValue( ":price", sale.getCost() );
	query.bindValue( ":count",  sale.getCount() );
	query.bindValue( ":isActive", 1 );
	query.bindValue( ":isConfirmed",  0 );

    this->execQuery( query);

}

void Sale_DB::remove( int id ) {
	QSqlQuery query(*db);
    query.prepare( "DELETE FROM " + TABLE_NAME + " WHERE id = " + QString::number(id));

    this->execQuery( query);
}

ActiveSale Sale_DB::read( const QSqlQuery * sqlQuery ){
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
	sale.setConfirmDate( QDate::fromString( sqlQuery->value("confirmDate").value<QString>(), Qt::ISODate) );
}

QVector<ActiveSale> Sale_DB::getActiveAll( int manager_id ) {
    QSqlQuery query( *db );
    QString sql = QString( "SELECT * FROM " ) + TABLE_NAME;
    query.prepare( sql);
    this->execQuery( query);
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

QVector<ActiveSale> Sale_DB::getActiveAllInPeriod( int manager_id, QDate dateFrom ) {
    
	QString sql = QString( "SELECT * FROM " ) + TABLE_NAME + QString(" WHERE confirmDate >= \"") + dateFrom.toString(Qt::ISODate) + QString("\"");
	QSqlQuery query( *db );
	query.prepare( sql);
	query.bindValue(":id", manager_id);

	this->execQuery( query);

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

	//получаем id
	QString sql = "select users.id, users.firstName, users.secondName, users.thirdName from users where	users.type = 0;";
	QSqlQuery query( *db);
	query.prepare(sql);

	this->execQuery( query);

	QList<ManagerActiveSalesStatisticDTO> result;

	while( query.next() ) {
	
		//получаем список всех
		QString sql2 = "select users.id, users.firstName, users.secondName, users.thirdName, sales.isConfirmed from users, sales where sales.manager_id = users.id AND sales.isActive = 1 AND users.id = :id";

		QSqlQuery query2( *this->db);
		query2.prepare(sql2);
		query2.bindValue(":id", query.value("id").value<int>());

		this->execQuery( query2);
		
		if	( query2.next()) {
			
			result.append( this->readToDTO(query2, query) );

			while ( query2.next() ) {
			
				int i = query2.value("isConfirmed").value<int>();

				if( i == 0) {

					result.last().unconfirmCount += 1;
				} else {
			
					result.last().confirmCount += 1;
				}
			}
		} else {
		
			result.append( this->readEmptyResultToDTO(query));
		}
	}

	return result;
}

QList<ActiveSaleDTO> Sale_DB::getActiveSales() {

	//создаем строку с sql-запросом
	QString sql = "select users.firstName, users.secondName, users.thirdName, sales.* from sales, users where sales.manager_id = users.id AND sales.isActive = 1";
	QSqlQuery query( *db);
	query.prepare(sql);

	this->execQuery( query);

	QList<ActiveSaleDTO> result;

	while( query.next() ) {
	
		result.append( this->readActiveSalesToDTO(query) );
	}

	return result;
}

QList<ActiveSaleDTO> Sale_DB::getActiveSalesForManager( int managerId) {

	//создаем строку с sql-запросом
	QString sql = "select users.firstName, users.secondName, users.thirdName, sales.* from sales, users where sales.manager_id = users.id AND sales.isActive = 1 AND users.id = :id";
	QSqlQuery query( *db);
	query.prepare(sql);
	query.bindValue(":id", managerId);

	this->execQuery( query);

	QList<ActiveSaleDTO> result;

	while( query.next() ) {
	
		result.append( this->readActiveSalesToDTO(query) );
	}

	return result;
}

ManagerActiveSalesStatisticDTO Sale_DB::readToDTO( const QSqlQuery& query, const QSqlQuery& queryWithManagerData) {

	struct ManagerActiveSalesStatisticDTO result;

	result.managerId = queryWithManagerData.value("id").value<int>();
	result.managerName = queryWithManagerData.value("secondName").value<QString>() + " " +
						 queryWithManagerData.value("firstName").value<QString>() + " " +
						 queryWithManagerData.value("thirdName").value<QString>();
	
	
	int i = query.value("isConfirmed").value<int>();
	if ( i == 0 ) {
	
		result.confirmCount = 0;
		result.unconfirmCount = 1;
	} else {
	
		result.confirmCount = 1;
		result.unconfirmCount = 0;
	}

	return result;
}

ManagerActiveSalesStatisticDTO Sale_DB::readEmptyResultToDTO( const QSqlQuery& query) {

	struct ManagerActiveSalesStatisticDTO result;

	result.managerId = query.value("id").value<int>();
	result.managerName = query.value("secondName").value<QString>() + " " +
						 query.value("firstName").value<QString>() + " " +
						 query.value("thirdName").value<QString>();
	result.confirmCount = 0;
	result.unconfirmCount = 0;

	return result;
}

ActiveSaleDTO Sale_DB::readActiveSalesToDTO( const QSqlQuery& query) {

	struct ActiveSaleDTO result;

	result.id = query.value("id").value<int>();
	result.managerName = query.value("secondName").value<QString>() + " " +
						 query.value("firstName").value<QString>() + " " +
						 query.value("thirdName").value<QString>();
	
	result.product.id = query.value("product_id").value<int>();
	result.product.name = query.value("productName").value<QString>();
	result.product.commission = query.value("productCommission").value<double>();

	result.price = query.value("price").value<double>();
	result.count = query.value("count").value<int>();
	result.isConfirm = query.value("isConfirmed").value<int>() ? true : false;
	result.confirmDate = QDate::fromString( query.value("confirmDate").value<QString>(), Qt::ISODate);
	result.saleDate = QDate::fromString( query.value("saleDate").value<QString>(), Qt::ISODate);

	return result;
}

QList<SaleInfoDTO> Sale_DB::getSalesConfimedFromPeriod( int id, QDate from, QDate to) {

	QList<SaleInfoDTO> result;

	QString sql = "select sales.price, sales.count, products.commission from sales, users, products where sales.manager_id = users.id AND sales.product_id = products.id AND sales.isConfirmed = 1 AND users.id = :id AND sales.confirmDate >= :dateFrom AND sales.confirmDate <= :dateTo;";
	//sql.arg(QString(id)), from.toString(Qt::ISODate), to.toString(Qt::ISODate));
	QSqlQuery query( *db);
	query.prepare(sql);
	query.bindValue(":id", id);
	query.bindValue(":dateFrom", from);
	query.bindValue(":dateTo", to);

	this->execQuery( query);

	while( query.next() ) {
		
		SaleInfoDTO el;
		el.commission = query.value("commission").value<double>();
		el.count = query.value("count").value<int>();
		el.price = query.value("price").value<double>();
		
		result.append(el);
	}

	return result;
}


void Sale_DB::confirmSale( int id) {

	QString sql = "update %0 set `%1` = 1, `%2` = :%2 where %4 = :id;";
	sql = sql.arg("sales", "isConfirmed", "confirmDate", "sales.id");

	QSqlQuery query( *db);
	query.prepare(sql);

	query.bindValue(":id", id);
	query.bindValue(":confirmDate", QDate::currentDate());
	
	this->execQuery( query);
}

void Sale_DB::unconfirmSale( int id) {

	QString sql = "update %0 set `%1` = 0 where %2 = :id;";
	sql = sql.arg("sales", "isConfirmed", "sales.id");

	QSqlQuery query( *db);
	query.prepare(sql);
	query.bindValue(":id", id);

	this->execQuery( query);
}
