#pragma once

#include <qstring.h>

#include "User.h"
#include "SignResult.h"
#include "IUserRepository.h"
#include "UserValidator.h"



/** 
 *  ласс, отвечающий за авторизацию и регистрацию пользователей
 *
 */
class AuthorizationModule
{
public:
	AuthorizationModule(UserValidator* userValidator, IUserRepository* userRepository);
	~AuthorizationModule(void);
	/**
	 * јвторизаци€ пользовател€
     * @param login - логин пользовател€
     * @param password - пароль пользовател€
     * @return SignInResult - структура, содержаща€ информацю об успешности авторизации и автроизованного пользовател€
	 */
	SignInResult signIn( const QString& login, const QString& password);

    
    /**
	* –егистраци€ нового пользовател€
    * @param login - логин пользовател€
    * @param password - пароль пользовател€
    * @param userType - тип пользовател€
    * @return SignUpResult - структура, содержаща€ информацю об успешности попытки регистрации и объект зарегистрированного пользовател€
	*/
	SignUpResult signUp( const QString& login, const QString& password, UserType userType);

private:
    IUserRepository* userRepository;
    UserValidator* userValidator;
};


