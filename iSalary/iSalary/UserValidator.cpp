#include "UserValidator.h"


UserValidator::UserValidator( IUserRepository* userRepository){
    this->userRepository = userRepository;
}


UserValidator::~UserValidator(void){
}

bool UserValidator::isUserValid( const User& user, QString* errorOutput) {
    bool isValid = false;
    QString error("");
    try {
        this->userRepository->findByLogin( user.getLogin());
    } catch( QString* findError) {
        isValid = true;
    }

    if( !isValid) {
        if( errorOutput) {
            error += "������������ � �������� ������� ��� ����������\n";
        }
    } else {
        if( user.getLogin().size() < 3) {
            error += "������� �������� �����\n";
            isValid = false;
        }
        if( user.getPassword().size() < 3) { 
            error += "������� �������� ������\n";
            isValid = false;
        }
    }

    *errorOutput = error;
    
    return isValid;
}
