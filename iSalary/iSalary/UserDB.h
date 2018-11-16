#pragma once

#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qvariant.h>
#include <qsqlerror.h>
#include <qlist.h>

#include "User.h"
#include "UserInfo.h"
#include "IUserRepository.h"

/**
* ����� ������� � �� ��� �������� User
*
*/
class UserDB : public IUserRepository {

public:

    /**
    * �����������.
    * @param database - ��������� ��� ����������� QSqlDatabase
    */
    UserDB( QSqlDatabase* database);

    /**
    * ���������� ������ � ������������ � ��
    * @throws TODO: SQLException
    * @throws ������ �� �������
    * @param user -����������� ��������
    * @return -������, ������� ���� �������� � �� ( � ������������� id)
    * @see IUserRepository::insert
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
    * @return ���������, �������� ������ � ������������ � ��� ���
    */ 
    UserInfo getById( int userId);

    /**
    * ��������� ������ ������� � ������������ �� �� �� ������ ID
    * @throws TODO: SQLException
    * @throws ������ �� �������
    * @return ������ ��������, �������� ������ � ������������ � ��� ���
    */ 
    QList<UserInfo> getByIds( QList<int> userIds);
  
    /**
    * @see IUserRepository::findByLoginPassword
    */
    UserInfo findByLoginPassword( const QString& login, const QString& password) override;
    
    /**
    * @see IUserRepository::findByLogin
    */
    QLinkedList<UserInfo> findByLogin( const QString& login) override;


protected:
    
    /**
    * ���������� ��-���������
    */
    UserDB();

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
    void handleError( QSqlError error) const;
    
    /*
    * ��������� ������ - ���������� ���������� � ���������� �������
    */
    void handleError( const QString& error) const;
    

    QSqlDatabase* db;       /**< ��������� �� � ������� ����� ����������� ������� */
    QString loginField;    /**< �������� ���� � ������� � �� */
    QString passwordField; /**< �������� ���� � ������� � �� */
    QString idField;       /**< �������� ���� � id � �� */
    QString userTypeField; /**< �������� ���� � ����� ������������ � �� */
    QString tableName;     /**< �������� ������� � �� */
};

