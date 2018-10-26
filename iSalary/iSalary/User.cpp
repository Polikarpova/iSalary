#include "User.h"


User::User(void){
    this->id = -1;
    this->login ="";
    this->password ="";
}

User::User( int id, const QString& login, const QString& password){
    this->id = id;
    this->login = login;
    this->password = password;
}

int User::getId() const {
    return this->id;
}

QString User::getLogin() const {
    return this->login;
}

void User::setLogin( const QString& login){
    this->login = login;
}

QString User::getPassword() const {
    return this->password;
}

void User::setPassword( const QString& password){
    this->password = password;
}

User::~User(void){
}
 