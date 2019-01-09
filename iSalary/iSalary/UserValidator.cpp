#include "UserValidator.h"

UserValidator::UserValidator( IUserRepository *userRepository ) { this->userRepository = userRepository; }

UserValidator::~UserValidator( void ) {}

bool UserValidator::isUserValid( const User &user, QString *errorOutput, bool checkPassword ) {
    QString error( "" );
    QLinkedList<UserInfo> usersWithSameLogin = this->userRepository->findByLogin( user.getLogin() );
    bool isValid = true;

    if ( usersWithSameLogin.size() > 1 ) {
        error += QString::fromWCharArray( L"В системе уже зарегистрированно несколько пользователей с заданным логином\n" );
        isValid = false;
    } else if ( usersWithSameLogin.size() == 1 && usersWithSameLogin.first().user.getId() != user.getId() ) {
        error += QString::fromWCharArray( L"Заданный логин занят - выберите другой\n" );
        isValid = false;
    } else {
        if ( checkPassword ) {
            if ( user.getPassword().size() < 3 ) {
                error += QString::fromWCharArray( L"Слишком короткий пароль\n" );
                isValid = false;
            }
        }
    }

    QRegExp onlyLatin( "[a-z\_]+" );

    if ( checkPassword ) {
        bool isPasswordValid = ( onlyLatin.indexIn( user.getPassword() ) == 0 && onlyLatin.matchedLength() == user.getPassword().size() );

        if ( !isPasswordValid ) {
            error += QString::fromWCharArray( L"Пароль должен состоять из символов латинского алфавита\n" );
            isValid = false;
        }
    }

    bool isLoginValid = user.getLogin().size() > 0;

    if ( !isLoginValid ) {
        error += QString::fromWCharArray( L"Слишком короткий логин\n" );
        isValid = false;
    }
    isLoginValid = onlyLatin.indexIn( user.getLogin() ) == 0 && onlyLatin.matchedLength() == user.getLogin().size();

    if ( !isLoginValid ) {
        error += QString::fromWCharArray( L"Логин должен состоять из символов латинского алфавита\n" );
        isValid = false;
    }

    *errorOutput = error;

    return isValid;
}

bool UserValidator::isLoginExist( const QString &login ) {
    QLinkedList<UserInfo> usersWithSameLogin = this->userRepository->findByLogin( login );
    return usersWithSameLogin.size() > 0;
}