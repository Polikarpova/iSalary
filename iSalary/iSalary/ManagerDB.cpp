#include "ManagerDB.h"


ManagerDB:: ManagerDB( QSqlDatabase* database, UserDB* userDB) {
    this->db = db;
    this->userDB = userDB;
    init();
}

void ManagerDB::init(){
    this->tableName = "users";
    this->firstNameField = "firstName";
    this->secondNameField = "secondName";
    this->thirdNameField = "thirdName";
    this->sexField = "sex";
    this->passportSerialField = "passportSerial";
    this->passportNumberField = "passportNumber";
    this->passportIssueDateField = "passportIssueDate";
    this->addressField = "address";
    this->INNField = "INN";
    this->emailField = "email";
    this->mobileNumberField = "mobileNumber";
    this->dateOfEmploymentField = "dateOfEmployment";
}

Manager ManagerDB::getById( int id){
    UserInfo user;
    try {
        UserInfo user = userDB->getById( id);
    } catch ( QString except ) {
        throw except;
    }

    if( user.type != MANAGER) {
        throw "Запись не найдена";
    }
    QString sql = "SELECT `%1`, `%2`, `%3`, `%4`, `%5`, `%6`, `%7`, `%8`, `%9, `%10`, `%11`, `%12` FROM %0 WHERE %15 = :%15";
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
        UserDB::idField
    );

    QSqlQuery query( *this->db);
    query.prepare( sql);

    query.bindValue( ":" + UserDB::idField, id);

    this->execQuery( query);

    Manager manager;

    if( query.next()) {
        manager = this->readOneRecord(query);
    } else { 
        handleError("Запись не найдена");
    }

    return manager;
}

QList<Manager> ManagerDB::getAll(){
    QString sql = "SELECT `%15`,`%1`, `%2`, `%3`, `%4`, `%5`, `%6`, `%7`, `%8`, `%9, `%10`, `%11`, `%12` FROM %0" ;
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
        UserDB::idField
    );

    QSqlQuery query( *db);
    query.prepare(sql);
    this->execQuery( query);
    
    QList<int> userIds;
    QList<Manager> managers;

    while( query.next()){
        userIds.append( query.value( ":" + this->idField).value<int>());
        managers.append( readOneRecord(query));
    }

    QList<UserInfo> users = this->getByIds( userIds);
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
                  `%8` = :%8, `%9` = :%9, `%10` = :%10, `%11` = :%11 , `%12` = :%12 \
                  `%13` = :%13 \
                  WHERE `%15` = :`%15` ";

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
    query.bindValue( ":" + this->addressField, manager.getAddress());
    query.bindValue( ":" + this->INNField, manager.getINN());
    query.bindValue( ":" + this->emailField, manager.getEmail());
    query.bindValue( ":" + this->mobileNumberField, manager.getMobileNumber());
    query.bindValue( ":" + this->dateOfEmploymentField, manager.getDateOfEmployment());

    query.bindValue( ":" + UserDB::userTypeField, MANAGER);

    this->execQuery( query);
}

bool ManagerDB::findByINN( const QString& INN, Manager* manager){

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
    this->execQuery( query);
    bool found = query.next();
    if( found) {
        if ( manager != NULL) {
            int id = query.value( ":" + UserDB::idField).value<int>();
            *manager = getById( id);
        }
    }

    return found;
}

bool ManagerDB::findByPassport( const QString& passportSerial, const QString passportNumber, Manager* manager) {

    QString sql = "SELECT `%15` FROM %0 WHERE `%1` = :%1 AND `%2` = %2" ;
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
    this->execQuery( query);
    bool found = query.next();
    if( found) {
        if ( manager != NULL) {
            int id = query.value( ":" + UserDB::idField).value<int>();
            *manager = getById( id);
        }
    }

    return found;
}


Manager ManagerDB::readOneRecord( const QSqlQuery& query){
    int id = query.value( ":" + this->idField).value<int>();
    Manager manager( id);
    manager.setAddress( query.value( ":" + this->addressField).value<QString>() );
    manager.setDateOfEmployment( query.value( ":" + this->dateOfEmploymentField).value<QDate>());
    manager.setEmail( query.value( ":" + this->emailField).value<QString>());
    manager.setFirstName( query.value( ":" + this->firstNameField).value<QString>());
    manager.setSecondName( query.value( ":" + this->secondNameField).value<QString>());
    manager.setThirdName( query.value( ":" + this->thirdNameField).value<QString>());
    manager.setINN( query.value( ":" + this->INNField).value<QString>());
    manager.setMobileNumber( query.value( ":" + this->mobileNumberField).value<QString>());
    manager.setPassportDateIssue( query.value( ":" + this->passportIssueDateField).value<QDate>());
    manager.setPassportNumber( query.value( ":" + this->passportNumberField).value<QString>());
    manager.setPassportSerial( query.value( ":" + this->passportSerialField).value<QString>());
    Sex sex = static_cast<Sex>( query.value( ":" + this->sexField).value<int>());
    manager.setSex( sex);

    return manager;
}

ManagerDB::~ManagerDB(void){
}
