#pragma once

#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qvariant.h>
#include <qsqlerror.h>

#include "User.h"
#include "UserInfo.h"
#include "IUserRepository.h"

/**
* ����� ������� � �� ��� �������� User
*
*/
class UserDB : IUserRepository {

public:

    /**
    * �����������.
    * @param database - ��������� ��� ����������� QSqlDatabase
    */
    UserDB( QSqlDatabase database);

    /**
    * ���������� ������ � ������������ � ��
    * @throws TODO: SQLException
    * @throws ������ �� �������
    * @param user -����������� ��������
    * @return -������, ������� ���� �������� � �� ( � ������������� id)
    */
    User insert( const User& user, UserType type) override;

    /**
    * ���������� ������ � ������������ � ��
    * @throws TODO: SQLException
    * @param user -����������� ��������
    */
    void update( const User& user);
    
    /**
    * ��������� ������ � ������������ �� �� �� ��� ID
    * @throws TODO: SQLException
    * @throws ������ �� �������
    * @return ���������, �������� ������ � ������������ � ��� ��� ��� null, ���� ������ �� ������� 
    */ 
    UserInfo getById( int userId);
  
    UserInfo findByLoginPassword( const QString& login, const QString& password) override;

    UserInfo findByLogin( const QString& login) override;


protected:
    /*
    * ������������� �����
    */
    void init();
    
    /*
    * ������ ����� ������ �� ������� (QSqlQuery)
    */
    UserInfo readOneRecord( const QSqlQuery& query) const;  

    /*
    * ���������� ������� (QSqlQuery) � ���������� ������
    */    
    void execQuery( QSqlQuery& query) const;
    
    /*
    * ��������� ������ - ���������� ���������� � ���������� �������
    */
    void handleError( const QString& error) const;
    
    QSqlDatabase db;       /**< ��������� �� � ������� ����� ����������� ������� */
    QString loginField;    /**< �������� ���� � ������� � �� */
    QString passwordField; /**< �������� ���� � ������� � �� */
    QString idField;       /**< �������� ���� � id � �� */
    QString userTypeField; /**< �������� ���� � ����� ������������ � �� */
    QString tableName;     /**< �������� ������� � �� */
};

