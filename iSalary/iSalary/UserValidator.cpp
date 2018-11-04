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
            error += "Пользователь с заданным логином уже существует\n";
        }
    } else {
        if( user.getLogin().size() < 3) {
            error += "Слишком короткий логин\n";
            isValid = false;
        }
        if( user.getPassword().size() < 3) { 
            error += "Слишком короткий пароль\n";
            isValid = false;
        }
    }

    *errorOutput = error;
    
    return isValid;
}
