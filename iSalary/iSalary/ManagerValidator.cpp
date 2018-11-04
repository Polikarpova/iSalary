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

    if( manager.getFirstName().size() < 1){
        error += "��� ������ ��������� ���� �� ���� ������\n";
        isValid = false;
    }
    
    if( manager.getSecondName().size() < 1){
        error += "������� ������ ��������� ���� �� ���� ������\n";
        isValid = false;
    }

    if( manager.getDateOfBirth() > QDate::currentDate().addYears(-13)) {
        error += "���������� ������ ���� ���� �� 14 ��� \n";
        isValid = false;
    }

    if( manager.getDateOfBirth().addYears(14) > manager.getPassportDateIssue()) {
        error += "��������� ������ ��� �������� ������� ������ ����� ����������� 14 ���\n";
        isValid = false;
    }

    bool isNumber = false;
    manager.getPassportSerial().toInt( &isNumber);
    if( manager.getPassportSerial().size() != 4 || isNumber ) {
        error += "����� �������� ������ �������� �� 4 ����\n";
        isValid = false;
    }

    manager.getPassportNumber().toInt( &isNumber);
    if( manager.getPassportNumber().size() != 6 || isNumber ) {
        error += "����� �������� ������ �������� �� 6 ����\n";
        isValid = false;
    }

    if( manager.getPassportDateIssue() > QDate::currentDate()) {
        error += "���� ������ �������� �� ����� ���� ������ �������\n";
        isValid = false;
    }
    
    if ( manager.getPassportSerial().size() == 0){
        error += "�� ��������� ����������, ������� ������ �������\n";
        isValid = false;
    }

    manager.getINN().toULongLong(&isNumber);
    if( manager.getINN().size() == 12 && isNumber) {
        error += "��� ������ �������� �� 12 ����\n";
        isValid = false;
    }

    *errorOutput = error;
    return isValid;
}


ManagerValidator::~ManagerValidator(void) {
}
