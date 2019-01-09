#pragma once

#include "IManagerRepository.h"
#include "uservalidator.h"

class ManagerValidator : protected UserValidator {
  public:
    ManagerValidator( IUserRepository *, IManagerRepository * );
    ~ManagerValidator( void );

    bool isManagerValid( const Manager &manager, QString *errorOutput, bool checkPassword = false );

    bool isLoginExist( const QString &login );

  protected:
    IManagerRepository *managerRepository;
};
