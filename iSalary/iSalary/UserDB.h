#pragma once

#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qvariant.h>
#include <qsqlerror.h>
#include <qlist.h>

#include "User.h"
#include "UserInfo.h"
#include "IUserRepository.h"

/**
* Класс доступа к БД для сущности User
*
*/
class UserDB : public IUserRepository {

public:

    /**
    * Конструктор.
    * @param database - экземпляр уже настроенной QSqlDatabase
    */
    UserDB( QSqlDatabase* database);

    /**
    * Добавление записи о пользователе в БД
    * @throws TODO: SQLException
    * @throws Запись не найдена
    * @param user -добавляемая сущность
    * @return -запись, которая была записана в БД ( с проставленным id)
    * @see IUserRepository::insert
    */
    User insert( const User& user, UserType type) override;

    /**
    * Обновление записи о пользователе в БД
    * @throws TODO: SQLException
    * @param user -обновляемая сущность
    */
    void update( const User& user);
    
    /**
    * Получение записи о пользователе из БД по его ID
    * @throws TODO: SQLException
    * @throws Запись не найдена
    * @return Структура, хранящая запись о пользователе и его тип
    */ 
    UserInfo getById( int userId);

    /**
    * Получение списка записей о пользователе из БД по списку ID
    * @throws TODO: SQLException
    * @throws Запись не найдена
    * @return список Структур, хранящих запись о пользователе и его тип
    */ 
    QList<UserInfo> getByIds( QList<int> userIds);
  
    /**
    * @see IUserRepository::findByLoginPassword
    */
    UserInfo findByLoginPassword( const QString& login, const QString& password) override;
    
    /**
    * @see IUserRepository::findByLogin
    */
    QLinkedList<UserInfo> findByLogin( const QString& login) override;


protected:
    
    /**
    * Контруктор по-умолчанию
    */
    UserDB();

    /*
    * Инициализация полей
    */
    void init();
    
    /*
    * Чтение одной записи из Запроса (QSqlQuery)
    */
    UserInfo readOneRecord( const QSqlQuery& query) const;  

    /*
    * Выполнение Запроса (QSqlQuery) с обработкой ошибки
    */    
    void execQuery( QSqlQuery& query) const;
    
    /*
    * Обработка ошибки - выкидывает исключение с переданной ошибкой
    */
    void handleError( QSqlError error) const;
    
    /*
    * Обработка ошибки - выкидывает исключение с переданным текстом
    */
    void handleError( const QString& error) const;
    

    QSqlDatabase* db;       /**< экземпляр БД к которой будут применяться запросы */
    QString loginField;    /**< Название поля с логином в БД */
    QString passwordField; /**< Название поля с паролем в БД */
    QString idField;       /**< Название поля с id в БД */
    QString userTypeField; /**< Название поля с типом пользователя в БД */
    QString tableName;     /**< Название таблицы в БД */
};

