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

    /**
    * Получить Имя менеджера
    * @return -Имя менеджера
    */
    QString getFirstName();
    
    /**
    * Изменить Имя менеджера
    * @param firstname -новое Имя менеджера
    */
    void setFirstName( const QString& firstname);
    
    /**
    * Получить Фамилию менеджера
    * @return -Фамилия менеджера
    */
    QString getSecondName();
    
    /**
    * Изменить Фамилию менеджера
    * @param secondname -новую Фамилию менеджера
    */
    void setSecondName( const QString& secondname);
    
    /**
    * Получить Отчество менеджера
    * @return -Отчество менеджера
    */
    QString getThirdName();
    
    /**
    * Изменить Отчество менеджера
    * @param thirdname -новое Отчество менеджера
    */
    void setThirdName( const QString& thirdname);
    
    Sex getSex();
    
    /**
    * Изменить Пол менеджера
    * @param sex -новый пол менеджера
    */
    void setSex( Sex sex);

    /**
    * Получить серийный номер паспорта менеджера
    * @return -серийный номер паспорта менеджера
    */
    QString getPassportSerial();
    
    /**
    * Изменить Серию паспорта менеджера
    * @param passportSerial -новая серия паспорта менеджера длиной в 4 символа
    */
    void setPassportSerial( const QString& passportSerial);
    
    /**
    * Получить номер паспорта менеджера
    * @return -номер паспорта менеджера
    */
    QString getPassportNumber();
    
    /**
    * Изменить Номер паспорта менеджера
    * @param passportNumber -новый Номер паспорта менеджера длиной в 6 символов
    */
    void setPassportNumber( const QString& passportNumber);
    
    /**
    * Получить дату выдачи паспорта менеджера
    * @return -дата выдачи паспорта менеджера
    */
    QDate getPassportDateIssue();
    
    /**
    * Изменить Дату выдачи паспорта менеджера
    * @param date -новая Дата выдачи паспорта менеджера
    */
    void setPassportDateIssue( const QDate& date);
    
    /**
    * Получить адрес прописки менеджера
    * @return -адрес прописки менеджера
    */
    QString getAddress();
    
    /**
    * Изменить Адрес прописки менеджера
    * @param passportNumber -новый Адрес прописки менеджера
    */
    void setAddress( const QString& passportNumber);
    
    
    /**
    * Получить ИНН менеджера
    * @return -ИНН менеджера
    */
    QString getINN();
    
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
    QString getEmail();
    
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
    QString getMobileNumber();
    
    /**
    * Изменить Сотовый номер менеджера
    * @param mobileNumber -Сотовый номер менеджера
    */
    void setMobileNumber( const QString& mobileNumber);
    
    /**
    * Получить дата найма менеджера
    * @return -дата найма менеджера
    */
    QDate getDateOfEmployment();
    
    /**
    * Изменить Дату найма менеджера
    * @param date -новая Дата найма менеджера
    */
    void setDateOfEmployment(const QDate& date);

    ~Manager( void);

private:
    int id;
    QString firstName;
    QString secondName;
    QString thirdName;
    Sex sex;
    QString passportSerial;
    QString passportNumber;
    QDate passportIssueDate;
    QString address;
    QString INN;
    QString email;
    QString mobileNumber;
    QDate dateOfEmplyment;
};

