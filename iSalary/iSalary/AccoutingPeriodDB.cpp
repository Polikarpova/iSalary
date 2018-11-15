#include "AccoutingPeriodDB.h"

AccoutingPeriodDB::AccoutingPeriodDB( QSqlDatabase* database) {
    this->db = database;
	this->init();
}

void AccoutingPeriodDB::init() {
    this->tableName = "accouting_period";
	this->idField = "id";
	this->dateFromField = "dateFrom";
	this->dateToField = "dateTo";
	this->statusField = "status";

	QSqlQuery query( *db );
	query.prepare( "CREATE TABLE  IF NOT EXISTS `" + this->tableName + "` ( `id` int(11) NOT NULL AUTO_INCREMENT, `dataFrom` date NOT NULL, `dataTo` date DEFAULT NULL, `status` int(11) NOT NULL, PRIMARY KEY (`id`) ) ENGINE=InnoDB DEFAULT CHARSET=latin1;" );
	this->execQuery( query);

	this->initFirstAccountingPeriod();
}

void AccoutingPeriodDB::initFirstAccountingPeriod() {

	QString sql = "select * from accouting_period";
	QSqlQuery query( *db );
	query.prepare( sql);
	this->execQuery( query);

	if ( !query.next()) {
	
		QString date = QDate(QDate::currentDate().year(), QDate::currentDate().month(), 1 ).toString(Qt::ISODate);
		sql = "INSERT INTO `accouting_period` (`dateFrom`, `status`) VALUES (\"" + date + QString("\", 1);");
		query.prepare( sql);
		
		try {
			this->execQuery( query);
		} catch ( ... ) {
			
			QMessageBox::information(0, "Текущий РП", "Невозможно создать текущий РП. Обратитесь к разработчикам.");
		}
	}
}

QList<AccoutingPeriodDTO> AccoutingPeriodDB::getAllPeriods() {

	QString sql = "select * from accouting_period";
	QSqlQuery query( *db );
	query.prepare( sql);
	this->execQuery( query);

	QList<AccoutingPeriodDTO> result;

	while ( query.next() ) {
	
		AccoutingPeriodDTO el;
		el.id = query.value("id").value<int>();
		el.dateFrom = QDate::fromString( query.value("dateFrom").value<QString>(), Qt::ISODate);
		el.dateTo = QDate::fromString( query.value("dateTo").value<QString>(), Qt::ISODate);
		el.status = query.value("status").value<int>();

		result.append( el);
	}

	return result;
}

void AccoutingPeriodDB::execQuery( QSqlQuery& query) const {
    bool isSuccess = query.exec();
    if( !isSuccess ){
        QString err = query.lastError().text();
        this->handleError( query.lastError());
    }
}

void AccoutingPeriodDB::handleError( const QSqlError& error) const {

    QSqlError * err = new QSqlError(error);
	QString text = err->text() + this->db->lastError().text();
    throw err;
}

void AccoutingPeriodDB::handleError( const QString& error) const {
    QString * err = new QString(error);
    throw err;
}