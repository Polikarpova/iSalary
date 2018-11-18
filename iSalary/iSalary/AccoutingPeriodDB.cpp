#include "AccoutingPeriodDB.h"

AccoutingPeriodDB::AccoutingPeriodDB( QSqlDatabase* database) {
    this->db = database;
	this->init();
}

void AccoutingPeriodDB::createTable() {
    QSqlQuery query( *db );
	query.prepare( "CREATE TABLE  IF NOT EXISTS `" + this->tableName + "` ( `id` int(11) NOT NULL AUTO_INCREMENT, `dataFrom` date NOT NULL, `dataTo` date DEFAULT NULL, `status` int(11) NOT NULL, PRIMARY KEY (`id`) ) ENGINE=InnoDB DEFAULT CHARSET=latin1;" );
	this->execQuery( query);

	this->initAccountingPeriod();
}

void AccoutingPeriodDB::init() {
    this->tableName = "accouting_period";
	this->idField = "id";
	this->dateFromField = "dateFrom";
	this->dateToField = "dateTo";
	this->statusField = "status";
}

void AccoutingPeriodDB::initAccountingPeriod() {

	QString sql = "select * from accouting_period";
	QSqlQuery query( *db );
	query.prepare( sql);
	this->execQuery( query);

	if ( !query.next()) {
	
		this->openAccountingPeriod();
	}
}

void AccoutingPeriodDB::openAccountingPeriod() {

	QString date = QDate(QDate::currentDate().year(), QDate::currentDate().month(), 1 ).toString(Qt::ISODate);
	QString sql = "INSERT INTO `accouting_period` (`dateFrom`, `status`) VALUES (\"" + date + QString("\", 1);");
	QSqlQuery query( *db);
	query.prepare( sql);
		
	try {
		this->execQuery( query);
	} catch ( ... ) {
			
		//QMessageBox::information(0, "������� ��", "���������� ������� ������� ��. ���������� � �������������.");
	}
}

QList<AccoutingPeriodDTO> AccoutingPeriodDB::getAllPeriods() {

	this->checkCurrentPeriod();

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

AccoutingPeriodDTO AccoutingPeriodDB::getCurrentPeriod() {

	this->checkCurrentPeriod();

	QString sql = "select * from accouting_period order by id desc limit 1";
	QSqlQuery query( *db );
	query.prepare( sql);
	this->execQuery( query);

	AccoutingPeriodDTO result;

	while ( query.next() ) {

		int id = query.value("id").value<int>();
		QDate dateFrom = QDate::fromString( query.value("dateFrom").value<QString>(), Qt::ISODate);
		
		result.id = id;
		result.dateFrom = dateFrom;
	}

	return result;
}

void AccoutingPeriodDB::closePeriod( int id, QDate dateFrom) {

	QString sql = "UPDATE `accouting_period` SET `dateTo` = :date, `status` = 0 WHERE `id` = :id;";
	QSqlQuery query( *db );
	query.prepare( sql);

	QDate date(dateFrom.year(), dateFrom.month(), dateFrom.daysInMonth());
	query.bindValue(":date", date);
	query.bindValue(":id", id);
	this->execQuery( query);
}

void AccoutingPeriodDB::checkCurrentPeriod() {

	//����� ��������� ��
	QString sql = "select * from accouting_period order by id desc limit 1";
	QSqlQuery query( *db );
	query.prepare( sql);
	this->execQuery( query);

	while( query.next() ) {

		QDate nowDate = QDate::currentDate();

		QDate dateFrom = QDate::fromString(query.value("dateFrom").value<QString>(), Qt::ISODate);
		QDate closeDate(dateFrom.year(), dateFrom.month(), dateFrom.daysInMonth());
		QDate newPeriodDateFrom = closeDate.addDays(1);
	
		//���� ������� ���� ����� ��� ����� �� ���� ������ ������ �������
		if ( nowDate >= newPeriodDateFrom ) {

			//��������� ������� ������ � �������� �����
			int id = query.value("id").value<int>();
			this->closePeriod(id, dateFrom);
			this->openAccountingPeriod();
		}
	}
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