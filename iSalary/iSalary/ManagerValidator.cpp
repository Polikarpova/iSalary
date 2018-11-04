#include "ManagerValidator.h"


ManagerValidator::ManagerValidator( IUserRepository* userRep, IManagerRepository* managerRep) : UserValidator( userRep) {
    this->managerRepository = managerRep;
}

bool ManagerValidator::isManagerValid( const Manager& manager, QString* errorOutput) {
    QString error;
    bool isValid = this->isUserValid( manager, &error);

    if( this->managerRepository->findByINN( manager.getINN(), NULL) ){
        error += "Работник с таким ИНН уже существует\n";
        isValid = false;
    }
    
    if( this->managerRepository->findByPassport( manager.getPassportSerial(), manager.getPassportNumber(), NULL)) {
        error += "Работник с такими паспортными данными (серией и номером) уже существует\n";
        isValid = false;
    }

    if( manager.getFirstName().size() < 1){
        error += "Имя должно содержать хотя бы один символ\n";
        isValid = false;
    }
    
    if( manager.getSecondName().size() < 1){
        error += "Фамилия должна содержать хотя бы один символ\n";
        isValid = false;
    }

    if( manager.getDateOfBirth() > QDate::currentDate().addYears(-13)) {
        error += "Сотруднику должно быть хотя бы 14 лет \n";
        isValid = false;
    }

    if( manager.getDateOfBirth().addYears(14) > manager.getPassportDateIssue()) {
        error += "Сотрудник должен был получить паспорт только после испольнения 14 лет\n";
        isValid = false;
    }

    bool isNumber = false;
    manager.getPassportSerial().toInt( &isNumber);
    if( manager.getPassportSerial().size() != 4 || isNumber ) {
        error += "Серия паспорта должна состоять из 4 цифр\n";
        isValid = false;
    }

    manager.getPassportNumber().toInt( &isNumber);
    if( manager.getPassportNumber().size() != 6 || isNumber ) {
        error += "Номер паспорта должен состоять из 6 цифр\n";
        isValid = false;
    }

    if( manager.getPassportDateIssue() > QDate::currentDate()) {
        error += "Дата выдачи паспорта не может быть больше текущей\n";
        isValid = false;
    }
    
    if ( manager.getPassportSerial().size() == 0){
        error += "Не заполнено учреждение, которое выдало паспорт\n";
        isValid = false;
    }

    manager.getINN().toULongLong(&isNumber);
    if( manager.getINN().size() == 12 && isNumber) {
        error += "ИНН должен состоять из 12 цифр\n";
        isValid = false;
    }

    *errorOutput = error;
    return isValid;
}


ManagerValidator::~ManagerValidator(void) {
}
