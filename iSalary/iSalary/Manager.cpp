#include "Manager.h"


Manager::Manager(void){
    this->dateOfEmplyment = QDate::currentDate();
}

Manager::Manager( int id){
    this->id = id;
}

Manager::Manager( const User& user){
    this->id = user.getId();
    this->login = user.getLogin();
    this->password = user.getPassword();
}


void Manager::setUserInfo( const User& user){
    this->id = user.getId();
    this->login = user.getLogin();
    this->password = user.getPassword();
}

void Manager::setId( int _id){
    this->id = _id;
}

QString Manager::getFirstName() const{
    return this->firstName;
};
  
void Manager::setFirstName( const QString& firstname){
    this->firstName = firstname;
};
  
QString Manager::getSecondName() const{
     return this->secondName;
};
  
void Manager::setSecondName( const QString& secondname){
    this->secondName = secondname;
};
  
QString Manager::getThirdName() const{
    return this->thirdName;
};
  
void Manager::setThirdName( const QString& thirdname){
    this->thirdName = thirdname;
};

QDate Manager::getDateOfBirth() const{
    return this->dateOfBirth;
};
  
void Manager::setDateOfBirth( const QDate& dateOfBirth){
    this->dateOfBirth = dateOfBirth;
};

Sex Manager::getSex() const{
    return this->sex;
};
  
void Manager::setSex( Sex sex){
    this->sex = sex;
};

QString Manager::getPassportSerial() const{
    return this->passportSerial;
};
  
void Manager::setPassportSerial( const QString& passportSerial){
    if( passportSerial.size() == 4){
        this->passportSerial = passportSerial;
    }
};
  
QString Manager::getPassportNumber() const{
    return this->passportNumber;
}
  
void Manager::setPassportNumber( const QString& passportNumber){
    if( passportNumber.size() == 6){
        this->passportNumber = passportNumber;
    }
};
  
QDate Manager::getPassportDateIssue() const{
    return this->passportIssueDate;
};
  
void Manager::setPassportDateIssue( const QDate& date){
    this->passportIssueDate = date;
};

QString Manager::getPassportSource() const{
    return this->passportSource;
}
  
void Manager::setPassportSource( const QString& passportSource){
    this->passportSource = passportSource;
};
  
QString Manager::getAddress() const{
    return this->address;
};
    
void Manager::setAddress( const QString& address){
    this->address = address;
};
    
QString Manager::getINN() const{
    return this->INN;
}
  
void Manager::setINN( const QString& INN){
    this->INN = INN;
};
  
QString Manager::getEmail() const{
    return this->email;
}
  
void Manager::setEmail( const QString& email){
    this->email = email;
}
  
QString Manager::getMobileNumber() const{
    return this->mobileNumber;
}
  
void Manager::setMobileNumber( const QString& mobileNumber){
    this->mobileNumber = mobileNumber;
};
    
QDate Manager::getDateOfEmployment() const{
    return this->dateOfEmplyment;
}
  
void Manager::setDateOfEmployment(const QDate& date){
    this->dateOfEmplyment = date;
};

Manager::~Manager(void){
}
