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
    */
    void setLogin( const QString& login);

    /**
    * �������� ������
    * @return ������ ������������
    */
    QString getPassword() const;

    /**
    * ���������� ����� ������
    */
    void setPassword( const QString& password);

	~User(void);

private:
    int id;             /**< id ������������*/
    QString login;		/**< ����� ������������*/
    QString password;	/**< ������ ������������*/
};

