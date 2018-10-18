#include "User.h"


User::User(void){
    this->id = -1;
    this->login ="";
    this->password ="";
}

User::User( int id, QString login, QString password){
    this->id = id;
    this->login = login;
    this->password = password;
}

int User::getId(){
    return this->id;
}

QString User::getLogin(){
    return this->login;
}

void User::setLogin( QString login){
    this->login = login;
}

QString User::getPassword(){
    return this->password;
}

void User::setPassword( QString password){
    this->password = password;
}

User::~User(void){
}
