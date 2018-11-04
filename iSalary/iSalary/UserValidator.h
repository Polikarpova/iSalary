#pragma once

#include "IUserRepository.h"

class UserValidator {
public:
    UserValidator(IUserRepository* userRepository);
    ~UserValidator(void);

    bool isUserValid( const User& user, QString* errorOutput);

protected:
    IUserRepository* userRepository;
};

