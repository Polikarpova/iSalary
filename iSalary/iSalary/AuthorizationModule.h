#pragma once

#include <qstring.h>

#include "User.h"
#include "SignResult.h"
#include "IUserRepository.h"




/** 
 *  ласс, отвечающий за авторизацию и регистрацию пользователей
 *
 */
class AuthorizationModule
{
public:
	AuthorizationModule(IUserRepository* userRepository);
	~AuthorizationModule(void);
	/**
	 * јвторизаци€ пользовател€
	 *
	 */
	SignInResult signIn( const QString& login, const QString& password);
	SignUpResult signUp( const QString& login, const QString& password);

private:
    IUserRepository* userRepository;
};
