#pragma once

#include "Manager.h"

/**
* Интерфейс класса, предоставляющий доступ к менеджерам по ИНН и номеру паспорта
* Нужен для проверки на наличие пользователя перед его наймом
* @author курносов
*/
class IManagerRepository
{
public:
    
    /**
    * Найти менеджера по ИНН
    * @param INN - ИНН менеджера
    * @param[out] manager - Указатель, по которому будет записан переданный менеджер, если будет найден ( можно передать NULL)
    * @return удалось ли найти менеджера с таким ИНН
    */
    virtual bool findByINN( const QString& INN, Manager* manager) = 0;

    /**
    * Найти менеджера по ИНН
    * @param passportSerial - серия паспорта Менеджера
    * @param passportNumber - номер паспорта Менеджера
    * @param[out] manager - Указатель, по которому будет записан переданный менеджер, если будет найден ( можно передать NULL)
    * @return удалось ли найти менеджера с таким ИНН
    */
    virtual bool findByPassport( const QString& passportSerial, const QString passportNumber, Manager* manager) = 0;

    virtual ~IManagerRepository(void);
};

