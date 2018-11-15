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
    virtual QLinkedList<Manager> findByINN( const QString& INN) = 0;

    /**
    * Найти менеджера по ИНН
    * @param passportSerial - серия паспорта Менеджера
    * @param passportNumber - номер паспорта Менеджера
    * @param[out] manager - Указатель, по которому будет записан переданный менеджер, если будет найден ( можно передать NULL)
    * @return удалось ли найти менеджера с таким ИНН
    */
    virtual QLinkedList<Manager> findByPassport( const QString& passportSerial, const QString passportNumber) = 0;
    
    /**
    * Обновить запись о менеджере в БД, необходимо наличие хотя бы Пользователь с таким же id 
    * @param manager - обновляемый менеджер
    */
    virtual void update( const Manager& manager) = 0;

};

