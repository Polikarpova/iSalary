#pragma once

#include <qlist.h>
#include <qsqldatabase.h>
#include <qsqlerror.h>
#include <qsqlquery.h>
#include <qvariant.h>

#include "ASqlTable.h"
#include "IUserRepository.h"
#include "User.h"
#include "UserInfo.h"

/**
 * Класс доступа к БД для сущности User
 *
 */
class UserDB : public IUserRepository, public ASqlTable {

  public:
    /**
     * Конструктор.
     * @param database - экземпляр уже настроенной QSqlDatabase
     */
    UserDB( QSqlDatabase *database );

    void createTable() override;

    /**
     * Добавление записи о пользователе в БД
     * @throws TODO: SQLException
     * @throws Запись не найдена
     * @param user -добавляемая сущность
     * @return -запись, которая была записана в БД ( с проставленным id)
     * @see IUserRepository::insert
     */
    User insert( const User &user, UserType type ) override;

    /**
     * Обновление записи о пользователе в БД
     * @throws TODO: SQLException
     * @param user -обновляемая сущность
     */
    void update( const User &user );

    /**
     * Получение записи о пользователе из БД по его ID
     * @throws TODO: SQLException
     * @throws Запись не найдена
     * @return Структура, хранящая запись о пользователе и его тип
     */
    UserInfo getById( int userId );

    /**
     * Получение списка записей о пользователе из БД по списку ID
     * @throws TODO: SQLException
     * @throws Запись не найдена
     * @return список Структур, хранящих запись о пользователе и его тип
     */
    QList<UserInfo> getByIds( QList<int> userIds );

    /**
     * @see IUserRepository::findByLoginPassword
     */
    UserInfo findByLoginPassword( const QString &login, const QString &password ) override;

    /**
     * @see IUserRepository::findByLogin
     */
    QLinkedList<UserInfo> findByLogin( const QString &login ) override;

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
    UserInfo readOneRecord( const QSqlQuery &query ) const;

    QSqlDatabase *db;      /**< экземпляр БД к которой будут применяться запросы */
    QString loginField;    /**< Название поля с логином в БД */
    QString passwordField; /**< Название поля с паролем в БД */
    QString idField;       /**< Название поля с id в БД */
    QString userTypeField; /**< Название поля с типом пользователя в БД */
    QString tableName;     /**< Название таблицы в БД */
};
