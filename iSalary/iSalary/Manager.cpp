#include "Manager.h"


Manager::Manager(void){
    this->dateOfEmplyment = QDate::currentDate();
}

Manager::Manager( int id){
    this->id = id;
}

Manager::~Manager(void){
}

QString Manager::getFirstName(){
    return this->firstName;
};
  
void Manager::setFirstName( const QString& firstname){
    this->firstName = firstname;
};
  
QString Manager::getSecondName(){
     return this->secondName;
};
  
void Manager::setSecondName( const QString& secondname){
    this->secondName = secondname;
};
  
QString Manager::getThirdName(){
    return this->thirdName;
};
  
void Manager::setThirdName( const QString& thirdname){
    this->thirdName = thirdname;
};
    
Sex Manager::getSex(){
    return this->sex;
};
  
void Manager::setSex( Sex sex){
    this->sex = sex;
};

QString Manager::getPassportSerial(){
    return this->passportSerial;
};
  
void Manager::setPassportSerial( const QString& passportSerial){
    if( passportSerial.size() == 4){
        this->passportSerial = passportSerial;
    }
};
  
QString Manager::getPassportNumber(){
    return this->passportNumber;
}
  
void Manager::setPassportNumber( const QString& passportNumber){
    if( passportNumber.size() == 6){
        this->mobileNumber = passportNumber;
    }
};
  
QDate Manager::getPassportDateIssue(){
    return this->passportIssueDate;
};
  
void Manager::setPassportDateIssue( const QDate& date){
    this->passportIssueDate = date;
};
  
QString Manager::getAddress(){
    return this->address;
};
    
void Manager::setAddress( const QString& address){
    this->address = address;
};
    
QString Manager::getINN(){
    return this->INN;
}
  
void Manager::setINN( const QString& INN){
    this->INN = INN;
};
  
QString Manager::getEmail(){
    return this->email;
}
  
void Manager::setEmail( const QString& email){
    this->email = email;
}
  
QString Manager::getMobileNumber(){
    return this->mobileNumber;
}
  
void Manager::setMobileNumber( const QString& mobileNumber){
    this->mobileNumber = mobileNumber;
};
    
QDate Manager::getDateOfEmployment(){
    return this->dateOfEmplyment;
}
  
void Manager::setDateOfEmployment(const QDate& date){
    this->dateOfEmplyment = date;
};
