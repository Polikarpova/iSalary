#pragma once

#include <qstring.h>
#include <qdatetime.h>

#include "User.h"

/**
* Пол
*/
enum Sex {
    MALE = 1,
    FEMALE = 2
};

/**
* Класс Менеджера
* Содержит всю информацию по менеджеру
*/
class Manager : public User
{
public:
    Manager( void);
    Manager( int id);
    Manager( const User& user);

    void setId(int _id);

    /**
    * Получить Имя менеджера
    * @return -Имя менеджера
    */
    QString getFirstName() const;
    
    /**
    * Изменить Имя менеджера
    * @param firstname -новое Имя менеджера
    */
    void setFirstName( const QString& firstname);
    
    /**
    * Получить Фамилию менеджера
    * @return -Фамилия менеджера
    */
    QString getSecondName() const;
    
    /**
    * Изменить Фамилию менеджера
    * @param secondname -новую Фамилию менеджера
    */
    void setSecondName( const QString& secondname);
    
    /**
    * Получить Отчество менеджера
    * @return -Отчество менеджера
    */
    QString getThirdName() const;
    
    /**
    * Изменить Отчество менеджера
    * @param thirdname -новое Отчество менеджера
    */
    void setThirdName( const QString& thirdname);
    
    /**
    * Получить дату рождения менеджера
    * @return - дата рождения менеджера
    */
    QDate getDateOfBirth() const;
    
    /**
    * Изменить дату рождения менеджера
    * @param dateOfBirth -новая дата рождения менеджера длиной в 4 символа
    */
    void setDateOfBirth( const QDate& dateOfBirth);
    
    /**
    * Получить пол менеджера
    * @return - пол менеджера
    */
    Sex getSex() const;
    
    /**
    * Изменить Пол менеджера
    * @param sex -новый пол менеджера
    */
    void setSex( Sex sex);

    /**
    * Получить серийный номер паспорта менеджера
    * @return -серийный номер паспорта менеджера
    */
    QString getPassportSerial() const;
    
    /**
    * Изменить Серию паспорта менеджера
    * @param passportSerial -новая серия паспорта менеджера длиной в 4 символа
    */
    void setPassportSerial( const QString& passportSerial);
    
    /**
    * Получить номер паспорта менеджера
    * @return -номер паспорта менеджера
    */
    QString getPassportNumber() const;
    
    /**
    * Изменить Номер паспорта менеджера
    * @param passportNumber -новый Номер паспорта менеджера длиной в 6 символов
    */
    void setPassportNumber( const QString& passportNumber);
    
    /**
    * Получить дату выдачи паспорта менеджера
    * @return -дата выдачи паспорта менеджера
    */
    QDate getPassportDateIssue() const;
    
    /**
    * Изменить Дату выдачи паспорта менеджера
    * @param date -новая Дата выдачи паспорта менеджера
    */
    void setPassportDateIssue( const QDate& date);
    
    
    /**
    * Получить "кем выдан" паспорт
    * @return - "кем выдан" паспорт менеджера
    */
    QString getPassportSource() const;
    
    /**
    * Уставновить "кем выдан" паспорт
    * @param passportSource - "кем выдан" паспорт менеджера
    */
    void setPassportSource( const QString& passportSource);
    
    /**
    * Получить адрес прописки менеджера
    * @return -адрес прописки менеджера
    */
    QString getAddress() const;
    
    /**
    * Изменить Адрес прописки менеджера
    * @param passportNumber -новый Адрес прописки менеджера
    */
    void setAddress( const QString& passportNumber);
    
    
    /**
    * Получить ИНН менеджера
    * @return -ИНН менеджера
    */
    QString getINN() const;
    
    /**
    * Изменить ИНН менеджера
    * @param INN -новый ИНН менеджера
    * @todo: проверка корректности
    */
    void setINN( const QString& INN);
    
    /**
    * Получить E-mail менеджера
    * @return -E-mail менеджера
    */
    QString getEmail() const;
    
    /**
    * Изменить E-Mail менеджера
    * @param email -новый E-mail менеджера
    * @todo: проверка корректности
    */
    void setEmail( const QString& email);
    
    /**
    * Получить сотовый номер менеджера
    * @return -сотовый номер менеджера
    */
    QString getMobileNumber() const;
    
    /**
    * Изменить Сотовый номер менеджера
    * @param mobileNumber -Сотовый номер менеджера
    */
    void setMobileNumber( const QString& mobileNumber);
    
    /**
    * Получить дата найма менеджера
    * @return -дата найма менеджера
    */
    QDate getDateOfEmployment() const;
    
    /**
    * Изменить Дату найма менеджера
    * @param date -новая Дата найма менеджера
    */
    void setDateOfEmployment(const QDate& date);

    void setUserInfo( const User& user);
    ~Manager( void);

private:

    QString firstName;
    QString secondName;
    QDate dateOfBirth;
    QString thirdName;
    Sex sex;
    QString passportSerial;
    QString passportNumber;
    QDate passportIssueDate;
    QString passportSource;
    QString address;
    QString INN;
    QString email;
    QString mobileNumber;
    QDate dateOfEmplyment;

};

