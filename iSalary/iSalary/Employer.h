#pragma once
#include "IManagerRepository.h"
#include "IUserRepository.h"

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
class Employer{
public:

    /**
    * Контруктор
    * @param IUserRepository - хранилище пользователей
    * @param IManagerRepository - хранилище менеджеров
    */
    Employer( IUserRepository*, IManagerRepository*);

    /**
    * Нанять менеджера
    * @return - результат попытки найма
    */
    bool employ( const Manager& manager);

private:
    IManagerRepository* managerRepository; /**< хранилище менеджеров */
    IUserRepository* userRepository; /**< хранилище пользователей */
};

