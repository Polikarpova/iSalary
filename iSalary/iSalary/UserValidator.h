#pragma once

#include <qregexp.h>
#include "Codec.h"

#include "IUserRepository.h"

class UserValidator {
public:
    UserValidator(IUserRepository* userRepository);
    ~UserValidator(void);

    bool isUserValid( const User& user, QString* errorOutput, bool checkPassword = false);
    
    bool isLoginExist( const QString& login);

protected:
    IUserRepository* userRepository;
};

