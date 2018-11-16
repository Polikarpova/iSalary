#pragma once

#include "uservalidator.h"
#include "IManagerRepository.h"


class ManagerValidator : protected UserValidator {
public:

    ManagerValidator( IUserRepository*, IManagerRepository*);
    ~ManagerValidator(void);

    bool isManagerValid( const Manager& manager, QString* errorOutput);

    bool isLoginExist( const QString& login);

protected:
    IManagerRepository* managerRepository;
};

