#pragma once

#include <qstring.h>

/** 
* Структура, описывающая пользователя, предназначена для передачи слою отображения.
* @author Курносов
*/
struct UserDTO {
public:
    int id;             /**< id Пользователя */
    QString login;      /**< Логин пользователя */
    QString passwword;  /**< Пароль пользователя */
};