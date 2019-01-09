#pragma once

#include "User.h"

/**
 * Пречисление типов пользователей в приложении
 * @author Курносов
 */
enum UserType {
    MANAGER,      /**< Менеджер */
    BOSS,         /**< Руководитель */
    NOT_SPECIFIED /**< Не задан */
};

/**
 * Информация о пользователе, содержащая объект пользователя и его тип
 * @author Курносов
 */
struct UserInfo {

  public:
    User user;     /**< Пользватель */
    UserType type; /**< Тип пользователя */
};
