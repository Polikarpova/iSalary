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
            error += toUnicode("������������ � �������� ������� ��� ����������\n");
        }
    } else {
        if( user.getLogin().size() < 3) {
            error += toUnicode("������� �������� �����\n");
            isValid = false;
        }
        if( user.getPassword().size() < 3) { 
            error += toUnicode("������� �������� ������\n");
            isValid = false;
        }
    }

    
    QRegExp onlyLatin("[a-z]+");
    bool isPasswordValid = ( onlyLatin.indexIn( user.getPassword()) == 0 
      && onlyLatin.matchedLength() == user.getPassword().size()); 
        
    if( !isPasswordValid) {
        error += toUnicode("������ ������ �������� �� �������� ���������� ��������\n");
        isValid = false;
    }

    bool isLoginValid = onlyLatin.indexIn( user.getLogin()) == 0 
      && onlyLatin.matchedLength() == user.getLogin().size(); 
        
    if( !isLoginValid) { 
        error += toUnicode("����� ������ �������� �� �������� ���������� ��������\n");
        isValid = false;
    }

    *errorOutput = error;
    
    return isValid;
}
