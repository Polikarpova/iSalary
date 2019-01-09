#include "AccoutingPeriodDB.h"

AccoutingPeriodDB::AccoutingPeriodDB( QSqlDatabase *database ) {
    this->db = database;
    this->init();
}

void AccoutingPeriodDB::createTable() {
    QSqlQuery query( *db );
    query.prepare( "CREATE TABLE  IF NOT EXISTS `" + this->tableName +
                   "` ( `id` int(11) NOT NULL AUTO_INCREMENT, `dateFrom` date NOT NULL, `dateTo` date DEFAULT NULL, `status` int(11) NOT NULL, PRIMARY KEY "
                   "(`id`) ) ENGINE=InnoDB DEFAULT CHARSET=latin1;" );
    this->execQuery( query );

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
    query.prepare( sql );
    this->execQuery( query );

    if ( !query.next() ) {

        this->openAccountingPeriod();
    }
}

void AccoutingPeriodDB::openAccountingPeriod() {

    QString date = QDate( QDate::currentDate().year(), QDate::currentDate().month(), 1 ).toString( Qt::ISODate );
    QString sql = "INSERT INTO `accouting_period` (`dateFrom`, `status`) VALUES (\"" + date + QString( "\", 1);" );
    QSqlQuery query( *db );
    query.prepare( sql );

    this->execQuery( query );
}

QList<AccoutingPeriodDTO> AccoutingPeriodDB::getAllPeriods() {

    this->checkCurrentPeriod();

    QString sql = "select * from accouting_period";
    QSqlQuery query( *db );
    query.prepare( sql );
    this->execQuery( query );

    QList<AccoutingPeriodDTO> result;

    while ( query.next() ) {

        AccoutingPeriodDTO el;
        el.id = query.value( "id" ).value<int>();
        el.dateFrom = QDate::fromString( query.value( "dateFrom" ).value<QString>(), Qt::ISODate );
        el.dateTo = QDate::fromString( query.value( "dateTo" ).value<QString>(), Qt::ISODate );
        el.status = query.value( "status" ).value<int>();

        result.append( el );
    }

    return result;
}

AccoutingPeriodDTO AccoutingPeriodDB::getCurrentPeriod() {

    this->checkCurrentPeriod();

    QString sql = "select * from accouting_period order by id desc limit 1";
    QSqlQuery query( *db );
    query.prepare( sql );
    this->execQuery( query );

    AccoutingPeriodDTO result;

    while ( query.next() ) {

        int id = query.value( "id" ).value<int>();
        QDate dateFrom = QDate::fromString( query.value( "dateFrom" ).value<QString>(), Qt::ISODate );

        result.id = id;
        result.dateFrom = dateFrom;
    }

    return result;
}

void AccoutingPeriodDB::closePeriod( int id, QDate dateFrom ) {

    QString sql = "UPDATE `accouting_period` SET `dateTo` = :date, `status` = 0 WHERE `id` = :id;";
    QSqlQuery query( *db );
    query.prepare( sql );

    QDate date( dateFrom.year(), dateFrom.month(), dateFrom.daysInMonth() );
    query.bindValue( ":date", date );
    query.bindValue( ":id", id );
    this->execQuery( query );

    //все активные и подтвержденные в этом периоде продажи сделать неактивными
    //все продажи подтвержденные включая до date поменять isActive = 0
    sql = "UPDATE `sales` SET `isActive` = 0 WHERE `confirmDate` <= :date AND `isActive` = 1;";
    query.prepare( sql );
    query.bindValue( ":date", date );
    this->execQuery( query );
}

void AccoutingPeriodDB::checkCurrentPeriod() {

    //берем последний РП
    QString sql = "select * from accouting_period order by id desc limit 1";
    QSqlQuery query( *db );
    query.prepare( sql );
    this->execQuery( query );

    while ( query.next() ) {

        QDate nowDate = QDate::currentDate();

        QDate dateFrom = QDate::fromString( query.value( "dateFrom" ).value<QString>(), Qt::ISODate );
        QDate closeDate( dateFrom.year(), dateFrom.month(), dateFrom.daysInMonth() );
        QDate newPeriodDateFrom = closeDate.addDays( 1 );

        //если текущая дата равна или зашла за дату начала нового периода
        if ( nowDate >= newPeriodDateFrom ) {

            //закрываем текущий период и начинаем новый
            int id = query.value( "id" ).value<int>();
            this->closePeriod( id, dateFrom );
            this->openAccountingPeriod();
        }
    }
}
