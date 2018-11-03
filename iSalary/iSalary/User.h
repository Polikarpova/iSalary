#pragma once


#include <qstring.h>

/** 
* Класс описывающий пользователя.
* Является базовым для всех типов пользователей( менеджера и руководителя)
* @author Курносов
*/
class User
{
public:
    /**
    * Конструктор по-умолчанию
    */
	User(void);

    /**
    * Конструктор с указанием id, логина и пароля
    * @param id -id пользователя
    * @param login -логин пользователя
    * @param password -пароль пользователя
    * @TODO Придумать, как органичить только для заполнения из БД
    */
    User( int id, const QString& login, const QString& password);

    /**
    * Получить id
    * @return id пользователя
    */
    int getId() const;

    /**
    * Получить Логин
    * @return логин пользователя
    */
    QString getLogin() const;

    /**
    * Установить Логин
    * @param login - новый логин
    */
    void setLogin( const QString& login);

    /**
    * Получить пароль
    * @return пароль пользователя
    */
    QString getPassword() const;

    /**
    * Установить новый пароль
    * @param login - новый пароль
    */
    void setPassword( const QString& password);

	~User(void);

protected:
    int id;             /**< id пользователя*/
    QString login;		/**< Логин пользователя*/
    QString password;	/**< Пароль пользователя*/
};

