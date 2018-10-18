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
    User( int id, QString login, QString password);

    /**
    * �������� id
    * @return id ������������
    */
    int getId();

    /**
    * �������� �����
    * @return ����� ������������
    */
    QString getLogin();

    /**
    * ���������� �����
    */
    void setLogin( QString login);

    /**
    * �������� ������
    * @return ������ ������������
    */
    QString getPassword();

    /**
    * ���������� ����� ������
    */
    void setPassword( QString password);

	~User(void);

private:
    int id;             /**< id ������������*/
    QString login;		/**< ����� ������������*/
    QString password;	/**< ������ ������������*/
};

