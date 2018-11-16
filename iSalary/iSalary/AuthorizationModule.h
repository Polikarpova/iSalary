#pragma once

#include <qstring.h>

#include "User.h"
#include "SignResult.h"
#include "IUserRepository.h"
#include "UserValidator.h"
#include "Helpers.h"


/** 
 * Класс, отвечающий за авторизацию и регистрацию пользователей
 *
 */
class AuthorizationModule
{
public:
	AuthorizationModule(UserValidator* userValidator, IUserRepository* userRepository);
	~AuthorizationModule(void);
	/**
	 * Авторизация пользователя
     * @param login - логин пользователя
     * @param password - пароль пользователя
     * @return SignInResult - структура, содержащая информацю об успешности авторизации и автроизованного пользователя
	 */
	SignInResult signIn( const QString& login, const QString& password);

    /**
	* Регистрация нового пользователя
    * @param login - логин пользователя
    * @param password - пароль пользователя
    * @param userType - тип пользователя
    * @return SignUpResult - структура, содержащая информацю об успешности попытки регистрации и объект зарегистрированного пользователя
	*/
	SignUpResult signUp( const QString& login, const QString& password, UserType userType);

    
    /**
	* Регистрация нового пользователя( пароль генерируется)
    * @param login - логин пользователя
    * @param userType - тип пользователя
    * @return SignUpResult - структура, содержащая информацю об успешности попытки регистрации и объект зарегистрированного пользователя
	*/
	SignUpResult signUp( const QString& login, UserType userType);

private:
    IUserRepository* userRepository;
    UserValidator* userValidator;
};
