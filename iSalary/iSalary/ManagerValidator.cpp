#include "ManagerValidator.h"


ManagerValidator::ManagerValidator( IUserRepository* userRep, IManagerRepository* managerRep) : UserValidator( userRep) {
    this->managerRepository = managerRep;
}

bool ManagerValidator::isManagerValid( const Manager& manager, QString* errorOutput) {
    QString error;
    bool isValid = this->isUserValid( manager, &error);

    if( this->managerRepository->findByINN( manager.getINN(), NULL) ){
        error += "�������� � ����� ��� ��� ����������\n";
        isValid = false;
    }
    
    if( this->managerRepository->findByPassport( manager.getPassportSerial(), manager.getPassportNumber(), NULL)) {
        error += "�������� � ������ ����������� ������� (������ � �������) ��� ����������\n";
        isValid = false;
    }

    *errorOutput = error;
    return isValid;
}


ManagerValidator::~ManagerValidator(void) {
}
