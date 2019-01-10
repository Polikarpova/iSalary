#pragma once

#include "AuthorizationModule.h"
#include "SignResultDTO.h"

/**
 * Класс, предоставляющий доступ к функциям приложения, связанным с Авторизацией и Регистрацией
 * @author Курносов
 */
class AuthorizationFacade {
  public:
    /**
     * Конструктор
     * @param authModule - модуль авторизации, к которому будет обращаться фасад
     */
    AuthorizationFacade( AuthorizationModule *authModule );

    /**
     * Авторизация пользователя
     * @param login - логин пользователя
     * @param password - пароль пользователя
     * @return SignInResultDTO - структура, содержащая информацю об успешности авторизации и объект автроизованного пользователя
     */
    SignInResultDTO signIn( const QString &login, const QString &password );

    /**
     * Регистрация нового пользователя
     * @param login - логин пользователя
     * @param password - пароль пользователя
     * @param userType - тип пользователя
     * @return SignUpResultDTO - структура, содержащая информацю об успешности попытки регистрации и объект зарегистрированного пользователя
     */
    SignUpResultDTO signUp( const QString &login, const QString &password, UserType userType );

    ~AuthorizationFacade( void );

  private:
    AuthorizationModule *authModule;
};
