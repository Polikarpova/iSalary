#include "UserDB.h"

UserDB::UserDB() {
    this->init();
}

UserDB::UserDB( QSqlDatabase* database){
    this->init();
    this->db = database;

	QSqlQuery query( *(this->db) );
    query.prepare( "CREATE TABLE IF NOT EXISTS `users` (`id` int(11) NOT NULL AUTO_INCREMENT,`login` varchar(50) CHARACTER SET utf8 NOT NULL,`password` varchar(50) CHARACTER SET utf8 NOT NULL,`type` int(11) NOT NULL,`firstName` varchar(100) CHARACTER SET utf8 DEFAULT NULL,`secondName` varchar(100) CHARACTER SET utf8 DEFAULT NULL,`thirdName` varchar(100) CHARACTER SET utf8 DEFAULT NULL,`sex` int(11) DEFAULT NULL,`passportSerial` varchar(6) CHARACTER SET utf8 DEFAULT NULL,`passportNumber` varchar(8) CHARACTER SET utf8 DEFAULT NULL,`passportIssueDate` date DEFAULT NULL,`address` varchar(100) CHARACTER SET utf8 DEFAULT NULL,`INN` varchar(40) CHARACTER SET utf8 DEFAULT NULL,`email` varchar(100) CHARACTER SET utf8 DEFAULT NULL,`mobileNumber` varchar(100) CHARACTER SET utf8 DEFAULT NULL,`dateOfEmployment` date DEFAULT NULL,PRIMARY KEY (`id`))" );
    query.exec();
}

void UserDB::init(){
    this->loginField = "login";
    this->passwordField = "password";
    this->tableName = "users";
    this->idField = "id";
    this->userTypeField ="type";
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
        handleError("������ �� �������");
    }
    return userInfo;
}

QList<UserInfo> UserDB::getByIds( QList<int> ids) {
    QList<UserInfo> users;
    if( ids.size() > 0) { 
        QSqlQuery query( *this->db);

        QString sql = "SELECT `%1`,`%2`,`%3`,`%4` FROM %0 WHERE `%1` IN (%10)";
        sql = sql.arg(
            this->tableName,
            this->idField,
            this->loginField,
            this->passwordField,
            this->userTypeField
        );

        QString idsStr = "";
        for( int iId = 0; iId < ids.size()-1; iId++){
            idsStr += QString::number( ids[iId]) + ",";
        }
        idsStr += QString::number( ids.last());
        sql = sql.arg( idsStr);
        query.prepare(sql);
        
        this->execQuery( query);
        UserInfo userInfo;
        while( query.next()){
            userInfo = readOneRecord( query);
            users.push_back(userInfo);
        }
    }
    return users;
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
        handleError( "������ �� �������");
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
        handleError("������ �� �������");
    }
    return userInfo;
}


void UserDB::handleError( const QSqlError& error) const {

    QSqlError * err = new QSqlError(error);
    QString text = err->text() + db->lastError().text();
    throw err;
}

void UserDB::handleError( const QString& error) const {
    QString err = error;
    throw new QString(err);
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
