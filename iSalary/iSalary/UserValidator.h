#pragma once

#include "Codec.h"
#include <qregexp.h>

#include "IUserRepository.h"

class UserValidator {
  public:
    UserValidator( IUserRepository *userRepository );
    ~UserValidator( void );

    bool isUserValid( const User &user, QString *errorOutput, bool checkPassword = false );

    bool isLoginExist( const QString &login );

  protected:
    IUserRepository *userRepository;
};
