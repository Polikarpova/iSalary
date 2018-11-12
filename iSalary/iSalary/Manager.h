#pragma once

#include <qstring.h>
#include <qdatetime.h>

#include "User.h"

/**
* ���
*/
enum Sex {
    MALE = 1,
    FEMALE = 2
};

/**
* ����� ���������
* �������� ��� ���������� �� ���������
*/
class Manager : public User
{
public:
    Manager( void);
    Manager( int id);
    Manager( const User& user);

    void setId(int _id);

    /**
    * �������� ��� ���������
    * @return -��� ���������
    */
    QString getFirstName() const;
    
    /**
    * �������� ��� ���������
    * @param firstname -����� ��� ���������
    */
    void setFirstName( const QString& firstname);
    
    /**
    * �������� ������� ���������
    * @return -������� ���������
    */
    QString getSecondName() const;
    
    /**
    * �������� ������� ���������
    * @param secondname -����� ������� ���������
    */
    void setSecondName( const QString& secondname);
    
    /**
    * �������� �������� ���������
    * @return -�������� ���������
    */
    QString getThirdName() const;
    
    /**
    * �������� �������� ���������
    * @param thirdname -����� �������� ���������
    */
    void setThirdName( const QString& thirdname);
    
    /**
    * �������� ���� �������� ���������
    * @return - ���� �������� ���������
    */
    QDate getDateOfBirth() const;
    
    /**
    * �������� ���� �������� ���������
    * @param dateOfBirth -����� ���� �������� ��������� ������ � 4 �������
    */
    void setDateOfBirth( const QDate& dateOfBirth);
    
    /**
    * �������� ��� ���������
    * @return - ��� ���������
    */
    Sex getSex() const;
    
    /**
    * �������� ��� ���������
    * @param sex -����� ��� ���������
    */
    void setSex( Sex sex);

    /**
    * �������� �������� ����� �������� ���������
    * @return -�������� ����� �������� ���������
    */
    QString getPassportSerial() const;
    
    /**
    * �������� ����� �������� ���������
    * @param passportSerial -����� ����� �������� ��������� ������ � 4 �������
    */
    void setPassportSerial( const QString& passportSerial);
    
    /**
    * �������� ����� �������� ���������
    * @return -����� �������� ���������
    */
    QString getPassportNumber() const;
    
    /**
    * �������� ����� �������� ���������
    * @param passportNumber -����� ����� �������� ��������� ������ � 6 ��������
    */
    void setPassportNumber( const QString& passportNumber);
    
    /**
    * �������� ���� ������ �������� ���������
    * @return -���� ������ �������� ���������
    */
    QDate getPassportDateIssue() const;
    
    /**
    * �������� ���� ������ �������� ���������
    * @param date -����� ���� ������ �������� ���������
    */
    void setPassportDateIssue( const QDate& date);
    
    
    /**
    * �������� "��� �����" �������
    * @return - "��� �����" ������� ���������
    */
    QString getPassportSource() const;
    
    /**
    * ����������� "��� �����" �������
    * @param passportSource - "��� �����" ������� ���������
    */
    void setPassportSource( const QString& passportSource);
    
    /**
    * �������� ����� �������� ���������
    * @return -����� �������� ���������
    */
    QString getAddress() const;
    
    /**
    * �������� ����� �������� ���������
    * @param passportNumber -����� ����� �������� ���������
    */
    void setAddress( const QString& passportNumber);
    
    
    /**
    * �������� ��� ���������
    * @return -��� ���������
    */
    QString getINN() const;
    
    /**
    * �������� ��� ���������
    * @param INN -����� ��� ���������
    * @todo: �������� ������������
    */
    void setINN( const QString& INN);
    
    /**
    * �������� E-mail ���������
    * @return -E-mail ���������
    */
    QString getEmail() const;
    
    /**
    * �������� E-Mail ���������
    * @param email -����� E-mail ���������
    * @todo: �������� ������������
    */
    void setEmail( const QString& email);
    
    /**
    * �������� ������� ����� ���������
    * @return -������� ����� ���������
    */
    QString getMobileNumber() const;
    
    /**
    * �������� ������� ����� ���������
    * @param mobileNumber -������� ����� ���������
    */
    void setMobileNumber( const QString& mobileNumber);
    
    /**
    * �������� ���� ����� ���������
    * @return -���� ����� ���������
    */
    QDate getDateOfEmployment() const;
    
    /**
    * �������� ���� ����� ���������
    * @param date -����� ���� ����� ���������
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

