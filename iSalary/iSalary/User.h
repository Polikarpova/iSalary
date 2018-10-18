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
    User( int id, QString login, QString password);

    /**
    * Получить id
    * @return id пользователя
    */
    int getId();

    /**
    * Получить Логин
    * @return логин пользователя
    */
    QString getLogin();

    /**
    * Установить Логин
    */
    void setLogin( QString login);

    /**
    * Получить пароль
    * @return пароль пользователя
    */
    QString getPassword();

    /**
    * Установить новый пароль
    */
    void setPassword( QString password);

	~User(void);

private:
    int id;             /**< id пользователя*/
    QString login;		/**< Логин пользователя*/
    QString password;	/**< Пароль пользователя*/
};

