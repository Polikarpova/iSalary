#pragma once
#include "UserDTO.h"
#include "AuthorizationModule.h"

/**
* Структура, описывающая результат попытки авторизации. Предназначена для передачи слою отображения
* @author Курносов
*/
struct SignInResultDTO {
public:
    UserDTO user; /** Пользователь */
    UserType userType; /**< Тип пользователя */
    bool success; /**< Успешность попытки */
};

/**
* Структура, описывающая результат попытки регистрации. Предназначена для передачи слою отображения
* @author Курносов
*/
struct SignUpResultDTO : public SignInResultDTO {
public:
    QString failReason; /**< Причина неудачи попытки */

};