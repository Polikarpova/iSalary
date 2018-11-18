#include "ManagerDB.h"


ManagerDB:: ManagerDB( QSqlDatabase* database, UserDB* userDB) {
    this->db = database;
    this->userDB = userDB;
    init();
}

void ManagerDB::init() {
    this->tableName = "users";
    this->firstNameField = "firstName";
    this->secondNameField = "secondName";
    this->thirdNameField = "thirdName";
    this->sexField = "sex";
    this->passportSerialField = "passportSerial";
    this->passportNumberField = "passportNumber";
    this->passportIssueDateField = "passportIssueDate";
    this->passportSourceField = "passportSource";
    this->addressField = "address";
    this->INNField = "INN";
    this->emailField = "email";
    this->mobileNumberField = "mobileNumber";
    this->dateOfEmploymentField = "dateOfEmployment";
    this->dateOfBitrthField = "dateOfBirth";
}

Manager ManagerDB::getById( int id) {
    UserInfo user;
    try {
        user = userDB->getById( id);
    } catch ( QString except ) {
        throw except;
    }

    if( user.type != MANAGER) {
        throw new QString("Запись не найдена");
    }
    QString sql = "SELECT `%1`, `%2`, `%3`, `%4`, `%5`, `%6`, `%7`, `%8`, `%9`, `%10`, `%11`, `%12`, `%13`, `%14`,`%15`,`%21` FROM %0 WHERE `%21` = :%21";
    sql = sql.arg(
        this->tableName,
        this->firstNameField,
        this->secondNameField,
        this->thirdNameField,
        this->sexField,
        this->passportSerialField,
        this->passportNumberField
    );
    sql = sql.arg(
        this->passportIssueDateField,
        this->addressField,
        this->INNField,
        this->emailField,
        this->mobileNumberField,
        this->dateOfEmploymentField
    );
    sql = sql.arg(
        this->addressField,
        this->passportSourceField,
        this->dateOfBitrthField
    );
    sql = sql.arg(
        UserDB::idField
    );

    QSqlQuery query( *this->db);
    query.prepare( sql);

    query.bindValue( ":" + UserDB::idField, id);

    this->execQuery( query);

    Manager manager;

    if( query.next()) {
        manager = this->readOneRecord(query);
        manager.setLogin( user.user.getLogin());
        manager.setPassword( user.user.getPassword());
    } else { 
        handleError(QString::fromWCharArray(L"Запись не найдена"));
    }

    return manager;
}

ManagerDTO ManagerDB::getManagerInfoById( int id) {

	QString sql = "SELECT `%1`, `%2`, `%3`, `%4`, `%5`, `%6`, `%7`, `%8`, `%9`, `%10`, `%11`, `%12`, `%13`, `%14`,`%15`, `passportSource`,`id` FROM %0 WHERE `id` = :id";
    sql = sql.arg(
        this->tableName,
        this->firstNameField,
        this->secondNameField,
        this->thirdNameField,
        this->sexField,
        this->passportSerialField,
        this->passportNumberField
    );
    sql = sql.arg(
        this->passportIssueDateField,
        this->addressField,
        this->INNField,
        this->emailField,
        this->mobileNumberField,
        this->dateOfEmploymentField
    );
    sql = sql.arg(
        this->addressField,
        this->passportSourceField,
        this->dateOfBitrthField
    );

    QSqlQuery query( *this->db);
    query.prepare( sql);

    query.bindValue( ":id", id);

    this->execQuery( query);

    ManagerDTO manager;

    if( query.next()) {
		manager = this->readRecordToDTO( query);
    } else { 
        handleError(QString::fromWCharArray(L"Запись не найдена"));
    }

    return manager;
}

QList<Manager> ManagerDB::getAll() {
    QString sql = "SELECT `%15`,`%1`, `%2`, `%3`, `%4`, `%5`, `%6`, `%7`, `%8`, `%9`, `%10`, `%11`, `%12`, `%13`, `%14`, `%15`, `%16` FROM %0 " ;
    sql = sql.arg(
        this->tableName,
        this->firstNameField,
        this->secondNameField,
        this->thirdNameField,
        this->sexField,
        this->passportSerialField,
        this->passportNumberField
    );
    sql = sql.arg(
        this->passportIssueDateField,
        this->addressField,
        this->INNField,
        this->emailField,
        this->mobileNumberField,
        this->dateOfEmploymentField
    );
    sql = sql.arg(
        this->addressField,
        this->passportSourceField,
        this->dateOfBitrthField
    );
    sql = sql.arg(
        UserDB::idField
    );

    sql += " WHERE " + this->userTypeField + " = " + QString::number( MANAGER) + " ";

    QSqlQuery query( *this->db);
    query.prepare(sql);
    this->execQuery( query);
    
    QList<int> userIds;
    QList<Manager> managers;

    while( query.next()){
        userIds.append( query.value( UserDB::idField).value<int>());
        managers.append( readOneRecord(query));
    }

    QList<UserInfo> users = this->userDB->getByIds( userIds);
    QHash<int, UserInfo> usersById;

    for( auto iUser = users.begin(); iUser != users.end(); iUser++) {
        usersById[ iUser->user.getId()] = *iUser;
    }

    for( auto iManager = managers.begin(); iManager != managers.end(); iManager++) {
        UserInfo user = usersById[ iManager->getId()];
        iManager->setLogin( user.user.getLogin());
        iManager->setPassword( user.user.getPassword());
    }

    return managers;
}

void ManagerDB::update( const Manager& manager) {
    this->userDB->update( manager);
    
    QString sql = "UPDATE %0 SET `%1` = :%1, `%2` = :%2, `%3` = :%3, \
                  `%4` = :%4, `%5` = :%5, `%6` = :%6, `%7` = :%7, \
                  `%8` = :%8, `%9` = :%9, `%10` = :%10, `%11` = :%11 , `%12` = :%12, \
                  `%13` = :%13, `%14` = :%14, `%15` = :%15, \
                  `%20` = :%20 \
                  WHERE `%21` = :%21 ";

    sql = sql.arg(
        this->tableName,
        this->firstNameField,
        this->secondNameField,
        this->thirdNameField,
        this->sexField,
        this->passportSerialField,
        this->passportNumberField
    );
    sql = sql.arg(
        this->passportIssueDateField,
        this->addressField,
        this->INNField,
        this->emailField,
        this->mobileNumberField,
        this->dateOfEmploymentField
    );
    sql = sql.arg(
        this->addressField,
        this->passportSourceField,
        this->dateOfBitrthField
    );
    sql = sql.arg( UserDB::userTypeField); 
    sql = sql.arg( UserDB::idField);
    
    QSqlQuery query( *db);
    query.prepare( sql);

    query.bindValue( ":" + UserDB::idField, manager.getId());
    query.bindValue( ":" + this->firstNameField, manager.getFirstName());
    query.bindValue( ":" + this->secondNameField, manager.getSecondName());
    query.bindValue( ":" + this->thirdNameField, manager.getThirdName());
    query.bindValue( ":" + this->sexField, manager.getSex());
    query.bindValue( ":" + this->passportSerialField, manager.getPassportSerial());
    query.bindValue( ":" + this->passportNumberField, manager.getPassportNumber());
    query.bindValue( ":" + this->passportIssueDateField, manager.getPassportDateIssue());
    query.bindValue( ":" + this->passportSourceField, manager.getPassportSource());
    query.bindValue( ":" + this->addressField, manager.getAddress());
    query.bindValue( ":" + this->INNField, manager.getINN());
    query.bindValue( ":" + this->emailField, manager.getEmail());
    query.bindValue( ":" + this->mobileNumberField, manager.getMobileNumber());
    query.bindValue( ":" + this->dateOfEmploymentField, manager.getDateOfEmployment());
    query.bindValue( ":" + this->dateOfBitrthField, manager.getDateOfBirth());

    query.bindValue( ":" + UserDB::userTypeField, MANAGER);

    this->execQuery( query);
}

QLinkedList<Manager> ManagerDB::findByINN( const QString& INN) {

    QString sql = "SELECT `%15` FROM %0 WHERE `%1` = :%1";
    sql = sql.arg(
        this->tableName,          //0
        this->INNField           //1
    );
    sql = sql.arg(
        UserDB::idField
    );

    QSqlQuery query( *this->db);
    query.prepare( sql);
    query.bindValue(":" + this->INNField, INN);
    this->execQuery( query);

    QLinkedList<Manager> managers;
    while( query.next()) {
            int id = query.value( UserDB::idField).value<int>();
            managers.append( this->getById( id));
    }

    return managers;
}

QLinkedList<Manager> ManagerDB::findByPassport( const QString& passportSerial, const QString passportNumber) {

    QString sql = "SELECT `%15` FROM %0 WHERE `%1` = :%1 AND `%2` = :%2" ;
    sql = sql.arg(
        this->tableName,          //0
        this->passportSerialField,//1
        this->passportNumberField //2
    );
    sql = sql.arg(
        UserDB::idField
    );

    QSqlQuery query( *this->db);
    query.prepare( sql);
    query.bindValue(":" + this->passportSerialField, passportSerial);
    query.bindValue(":" + this->passportNumberField, passportNumber);
    this->execQuery( query);

    QLinkedList<Manager> managers;
    while( query.next()) {
            int id = query.value( UserDB::idField).value<int>();
            managers.append( this->getById( id));
    }

    return managers;
}

QList<QPair<int, QString> > ManagerDB::getAllIdAndName() {

	QList<QPair<int, QString> > result;

	QString sql = "select users.id, users.firstName, users.secondName, users.thirdName from users where users.type = 0;";

	QSqlQuery query( *this->db);
	query.prepare( sql);

	this->execQuery( query);

	while( query.next() ) {
	
		int id = query.value("id").value<int>();
		QString managerName = query.value("secondName").value<QString>() + " " +
						 query.value("firstName").value<QString>() + " " +
						 query.value("thirdName").value<QString>();
		result.append( qMakePair( id, managerName));
	}

	return result;
}


Manager ManagerDB::readOneRecord( const QSqlQuery& query) {
    int id = query.value( this->idField).value<int>();
    Manager manager( id);
    manager.setAddress( query.value( this->addressField).value<QString>() );
    manager.setDateOfEmployment( query.value( this->dateOfEmploymentField).value<QDate>());
    manager.setEmail( query.value( this->emailField).value<QString>());
    manager.setFirstName( query.value( this->firstNameField).value<QString>());
    manager.setSecondName( query.value( this->secondNameField).value<QString>());
    manager.setThirdName( query.value( this->thirdNameField).value<QString>());
    manager.setINN( query.value( this->INNField).value<QString>());
    manager.setMobileNumber( query.value( this->mobileNumberField).value<QString>());
    manager.setPassportDateIssue( query.value( this->passportIssueDateField).value<QDate>());
    manager.setPassportNumber( query.value( this->passportNumberField).value<QString>());
    manager.setPassportSerial( query.value( this->passportSerialField).value<QString>());
    manager.setPassportSource( query.value( this->passportSourceField).value<QString>());
    manager.setDateOfBirth( query.value( this->dateOfBitrthField).value<QDate>());
    Sex sex = static_cast<Sex>( query.value( this->sexField).value<int>());
    manager.setSex( sex);

    return manager;
}

ManagerDTO ManagerDB::readRecordToDTO( const QSqlQuery& query) {

    ManagerDTO manager;
	manager.id = query.value( this->idField).value<int>();
	manager.firstName = query.value( this->firstNameField).value<QString>();
	manager.secondName = query.value( this->secondNameField).value<QString>();
	manager.thirdName = query.value( this->thirdNameField).value<QString>();
	manager.dateOfBirth = QDate::fromString( query.value( this->dateOfBitrthField).value<QString>(), Qt::ISODate);
	manager.sex = static_cast<Sex>( query.value( this->sexField).value<int>());
	manager.passportSerial = query.value( this->passportSerialField).value<QString>();
	manager.passportNumber = query.value( this->passportNumberField).value<QString>();
	manager.passportIssueDate = QDate::fromString( query.value( this->passportIssueDateField).value<QString>(), Qt::ISODate);
	manager.address = query.value( this->addressField).value<QString>();
	manager.passportSource = query.value( this->passportSourceField).value<QString>();
	manager.INN = query.value( this->INNField).value<QString>();
	manager.email = query.value( this->emailField).value<QString>();
	manager.dateOfEmplyment = QDate::fromString( query.value( this->dateOfEmploymentField).value<QString>(), Qt::ISODate);

    return manager;
}

void ManagerDB::createTable(){
    // TODO: перенести сюда создание часть таблицы users, которая касаетеся менеджеров из UserDB
}

ManagerDB::~ManagerDB(void){
}
