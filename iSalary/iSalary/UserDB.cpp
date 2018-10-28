#include "UserDB.h"


UserDB::UserDB( QSqlDatabase* database){
    this->init();
    this->db = database;
}

void UserDB::init(){
    this->loginField = "login";
    this->passwordField = "password";
    this->tableName = "users";
    this->idField = "id";
    this->userTypeField ="type";

	QSqlQuery query( *db );
	query.prepare( "CREATE TABLE  IF NOT EXISTS `" + this->tableName + "` (`id` int NOT NULL PRIMARY KEY AUTO_INCREMENT, `name` NVARCHAR(45) NOT NULL,`commission` DOUBLE NOT NULL)" );
    query.exec();
}

User UserDB::insert( const User& user, UserType type) {
    QSqlQuery query( *db);
    QString sql = "INSERT INTO %0 (`%1`, `%2`, `%3`) VALUES(:%1, :%2, :%3)";
    sql = sql.arg(
      this->tableName, 
      this->loginField, 
      this->passwordField,
      this->userTypeField
    );
    query.prepare(sql);
    
    query.bindValue(":" + this->loginField, user.getLogin());
    query.bindValue(":" + this->passwordField, user.getPassword());
    query.bindValue(":" + this->userTypeField, type);

    this->execQuery( query);
    User newUser( query.lastInsertId().value<int>(), user.getLogin(), user.getPassword());
    return newUser;
}

void UserDB::update( const User& user) {
    QSqlQuery query( *db);

    UserInfo existUser = this->getById( user.getId());

    QString sql = "UPDATE %0 SET `%1` = :%1, `%2` = :%2 WHERE `%3` = :`%3`";
    sql = sql.arg(
      this->tableName, 
      this->loginField,
      this->passwordField,
      this->idField
    );
    query.prepare(sql);
    
    query.bindValue(":" + this->loginField, user.getLogin());
    query.bindValue(":" + this->passwordField, user.getPassword());
    query.bindValue(":" + this->idField, user.getId());

    this->execQuery( query);

}

UserInfo UserDB::getById( int id) {
    QSqlQuery query( *db);

    QString sql = "SELECT `%1`,`%2`,`%3`,`%4` FROM %0 WHERE `%1` = :%1";
    sql = sql.arg(
        this->tableName,
        this->idField,
        this->loginField,
        this->passwordField,
        this->userTypeField
    );

    query.prepare(sql);
    query.bindValue(":" + this->idField, id);

    this->execQuery( query);
    UserInfo userInfo;
    if( query.next()) {
        userInfo = this->readOneRecord(query);
    } else { 
        handleError("Запись не найдена");
    }
    return userInfo;
}


UserInfo UserDB::findByLoginPassword( const QString& login, const QString& password) {
    QSqlQuery query( *db);

    QString sql = "SELECT `%1`,`%2`,`%3`,`%4` FROM %0 WHERE `%2` = :%2 AND `%3` = :%3 ";
    sql = sql.arg(
        this->tableName,
        this->idField,
        this->loginField,
        this->passwordField,
        this->userTypeField
    );

    query.prepare(sql);
    
    query.bindValue(":" + this->loginField, login);
    query.bindValue(":" + this->passwordField, password);

    auto h = query.boundValues();

    this->execQuery( query);
    UserInfo userInfo;
    if( query.next()) {
        userInfo = this->readOneRecord(query);
    } else { 
        handleError( "Запись не найдена");
    }
    return userInfo;
}


UserInfo UserDB::findByLogin( const QString& login) {
    QSqlQuery query( *db);

    QString sql = "SELECT `%1`,`%2`,`%3`,`%4` FROM %0 WHERE `%2` = :%2 ";
    sql = sql.arg(
        this->tableName,
        this->idField,
        this->loginField,
        this->passwordField,
        this->userTypeField
    );

    query.prepare(sql);
    query.bindValue(":" + this->loginField, login);

    this->execQuery( query);
    UserInfo userInfo;
    if( query.next()) {
        userInfo = this->readOneRecord(query);
    } else { 
        handleError("Запись не найдена");
    }
    return userInfo;
}


void UserDB::handleError( const QSqlError& error) const {
    QSqlError err = error;
    throw err;
}

void UserDB::handleError( const QString& error) const {
    QString err = error;
    throw err;
}

void UserDB::execQuery( QSqlQuery& query) const {
    bool isSuccess = query.exec();
    if( !isSuccess ){
        this->handleError( query.lastError());
    }
}

UserInfo UserDB::readOneRecord( const QSqlQuery& query) const {
    UserInfo userInfo;

    int utype = query.value( this->userTypeField).value<int>();
    userInfo.type = static_cast<UserType>( utype);
    QString login = query.value( this->loginField).value<QString>();
    QString password = query.value( this->passwordField).value<QString>();
    int id = query.value( this->idField).value<int>();
    User user(id, login, password);
   
    userInfo.user = user;

    return userInfo;
}
