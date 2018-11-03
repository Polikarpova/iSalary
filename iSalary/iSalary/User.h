#pragma once


#include <qstring.h>

/** 
* ����� ����������� ������������.
* �������� ������� ��� ���� ����� �������������( ��������� � ������������)
* @author ��������
*/
class User
{
public:
    /**
    * ����������� ��-���������
    */
	User(void);

    /**
    * ����������� � ��������� id, ������ � ������
    * @param id -id ������������
    * @param login -����� ������������
    * @param password -������ ������������
    * @TODO ���������, ��� ���������� ������ ��� ���������� �� ��
    */
    User( int id, const QString& login, const QString& password);

    /**
    * �������� id
    * @return id ������������
    */
    int getId() const;

    /**
    * �������� �����
    * @return ����� ������������
    */
    QString getLogin() const;

    /**
    * ���������� �����
    * @param login - ����� �����
    */
    void setLogin( const QString& login);

    /**
    * �������� ������
    * @return ������ ������������
    */
    QString getPassword() const;

    /**
    * ���������� ����� ������
    * @param login - ����� ������
    */
    void setPassword( const QString& password);

	~User(void);

protected:
    int id;             /**< id ������������*/
    QString login;		/**< ����� ������������*/
    QString password;	/**< ������ ������������*/
};

