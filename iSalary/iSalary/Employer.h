#pragma once
#include "IManagerRepository.h"
#include "IUserRepository.h"
#include "AuthorizationModule.h"
#include "ManagerValidator.h"

/**
* Перечисление вохможных результатов попытки найма
*/
enum EmployResult {
    EMPLOY_RES_OK,     /**< Найм прошёл успешно */
    EMPLOY_RES_INN,    /**< Найм не удался, т.к. есть другой работник с таким ИНН */
    EMPLOY_RES_PASSPORT/**< Найм не удался, т.к. есть другой работник с такими серией и номером паспорта */
};

/**
* Класс, "нанимающий" менеджеров 
*/
class Employer {
public:

    /**
    * Контруктор
    * @param AuthorizationModule - модуль авторизации и регистрации
    * @param IManagerRepository - хранилище менеджеров
    */
    Employer( AuthorizationModule*, IManagerRepository*, ManagerValidator*);

    /**
    * Нанять менеджера
    * @return - результат попытки найма
    */
    Manager& employ( Manager& manager);

private:
    IManagerRepository* managerRepository; /**< хранилище менеджеров */
    AuthorizationModule* authorizationModule; /**< хранилище пользователей */
    ManagerValidator* managerValidator;
};

