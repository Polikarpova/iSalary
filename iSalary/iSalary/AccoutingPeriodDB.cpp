#include "AccoutingPeriodDB.h"

AccoutingPeriodDB::AccoutingPeriodDB( QSqlDatabase* database){
    this->db = database;
	this->init();
}

void AccoutingPeriodDB::init(){
    this->tableName = "accouting_period";
	this->idField = "id";
	this->dateFromField = "dateFrom";
	this->dateToField = "dateTo";
	this->statusField = "status";

	/*
	QSqlQuery query( *db );
	query.prepare( "CREATE TABLE  IF NOT EXISTS `" + this->tableName + "` ( `id` int(11) NOT NULL AUTO_INCREMENT, `dataFrom` date NOT NULL, `dataTo` date DEFAULT NULL, `status` int(11) NOT NULL, PRIMARY KEY (`id`) ) ENGINE=InnoDB DEFAULT CHARSET=latin1;" );
    query.exec();
	*/
}