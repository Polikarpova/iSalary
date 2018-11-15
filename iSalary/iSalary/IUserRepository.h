#pragma once

#include "UserInfo.h"
#include <qlinkedlist.h>
/**
* Интерфейс, описывающий методы хранилища пользователей, необходимые модулю авторизации
* @author Курносов
* @see AuthorizationModule
*/
class IUserRepository {
public:
    
    /**
    * Получение записи о пользователе из БД по его логину и паролю
    * @param login - логин пользвателя
    * @param password - пароль пользователя
    * @throws "Запись не найдена"
    * @return Структура, хранящая запись о пользователе и его тип
    */
    virtual UserInfo findByLoginPassword( const QString& login, const QString& password) = 0;
    
    /**
    * Получение записи о пользователе из БД по его логину
    * @param login - логин пользвателя    
    * @throws "Запись не найдена"
    * @return Структура, хранящая запись о пользователе и его тип
    */
    virtual QLinkedList<UserInfo> findByLogin( const QString& login) = 0;
    
    /**
    * Сохраняет запись о пользователе в БД
    * @param user - объект пользователя, который надо сохранить
    * @param login - тип сохраняемого пользователя ( Менеджер / Начальник)
    * @throws "Данный логин уже занят"
    * @return Структура, хранящая запись о пользователе и его тип
    */
    virtual User insert( const User& user, UserType type) = 0;

};