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

    /**
    * �������� ��� ���������
    * @return -��� ���������
    */
    QString getFirstName();
    
    /**
    * �������� ��� ���������
    * @param firstname -����� ��� ���������
    */
    void setFirstName( const QString& firstname);
    
    /**
    * �������� ������� ���������
    * @return -������� ���������
    */
    QString getSecondName();
    
    /**
    * �������� ������� ���������
    * @param secondname -����� ������� ���������
    */
    void setSecondName( const QString& secondname);
    
    /**
    * �������� �������� ���������
    * @return -�������� ���������
    */
    QString getThirdName();
    
    /**
    * �������� �������� ���������
    * @param thirdname -����� �������� ���������
    */
    void setThirdName( const QString& thirdname);
    
    Sex getSex();
    
    /**
    * �������� ��� ���������
    * @param sex -����� ��� ���������
    */
    void setSex( Sex sex);

    /**
    * �������� �������� ����� �������� ���������
    * @return -�������� ����� �������� ���������
    */
    QString getPassportSerial();
    
    /**
    * �������� ����� �������� ���������
    * @param passportSerial -����� ����� �������� ��������� ������ � 4 �������
    */
    void setPassportSerial( const QString& passportSerial);
    
    /**
    * �������� ����� �������� ���������
    * @return -����� �������� ���������
    */
    QString getPassportNumber();
    
    /**
    * �������� ����� �������� ���������
    * @param passportNumber -����� ����� �������� ��������� ������ � 6 ��������
    */
    void setPassportNumber( const QString& passportNumber);
    
    /**
    * �������� ���� ������ �������� ���������
    * @return -���� ������ �������� ���������
    */
    QDate getPassportDateIssue();
    
    /**
    * �������� ���� ������ �������� ���������
    * @param date -����� ���� ������ �������� ���������
    */
    void setPassportDateIssue( const QDate& date);
    
    /**
    * �������� ����� �������� ���������
    * @return -����� �������� ���������
    */
    QString getAddress();
    
    /**
    * �������� ����� �������� ���������
    * @param passportNumber -����� ����� �������� ���������
    */
    void setAddress( const QString& passportNumber);
    
    
    /**
    * �������� ��� ���������
    * @return -��� ���������
    */
    QString getINN();
    
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
    QString getEmail();
    
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
    QString getMobileNumber();
    
    /**
    * �������� ������� ����� ���������
    * @param mobileNumber -������� ����� ���������
    */
    void setMobileNumber( const QString& mobileNumber);
    
    /**
    * �������� ���� ����� ���������
    * @return -���� ����� ���������
    */
    QDate getDateOfEmployment();
    
    /**
    * �������� ���� ����� ���������
    * @param date -����� ���� ����� ���������
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

