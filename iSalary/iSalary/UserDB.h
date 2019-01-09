#pragma once

#include <qlist.h>
#include <qsqldatabase.h>
#include <qsqlerror.h>
#include <qsqlquery.h>
#include <qvariant.h>

#include "ASqlTable.h"
#include "IUserRepository.h"
#include "User.h"
#include "UserInfo.h"

/**
 * ����� ������� � �� ��� �������� User
 *
 */
class UserDB : public IUserRepository, public ASqlTable {

  public:
    /**
     * �����������.
     * @param database - ��������� ��� ����������� QSqlDatabase
     */
    UserDB( QSqlDatabase *database );

    void createTable() override;

    /**
     * ���������� ������ � ������������ � ��
     * @throws TODO: SQLException
     * @throws ������ �� �������
     * @param user -����������� ��������
     * @return -������, ������� ���� �������� � �� ( � ������������� id)
     * @see IUserRepository::insert
     */
    User insert( const User &user, UserType type ) override;

    /**
     * ���������� ������ � ������������ � ��
     * @throws TODO: SQLException
     * @param user -����������� ��������
     */
    void update( const User &user );

    /**
     * ��������� ������ � ������������ �� �� �� ��� ID
     * @throws TODO: SQLException
     * @throws ������ �� �������
     * @return ���������, �������� ������ � ������������ � ��� ���
     */
    UserInfo getById( int userId );

    /**
     * ��������� ������ ������� � ������������ �� �� �� ������ ID
     * @throws TODO: SQLException
     * @throws ������ �� �������
     * @return ������ ��������, �������� ������ � ������������ � ��� ���
     */
    QList<UserInfo> getByIds( QList<int> userIds );

    /**
     * @see IUserRepository::findByLoginPassword
     */
    UserInfo findByLoginPassword( const QString &login, const QString &password ) override;

    /**
     * @see IUserRepository::findByLogin
     */
    QLinkedList<UserInfo> findByLogin( const QString &login ) override;

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
    UserInfo readOneRecord( const QSqlQuery &query ) const;

    QSqlDatabase *db;      /**< ��������� �� � ������� ����� ����������� ������� */
    QString loginField;    /**< �������� ���� � ������� � �� */
    QString passwordField; /**< �������� ���� � ������� � �� */
    QString idField;       /**< �������� ���� � id � �� */
    QString userTypeField; /**< �������� ���� � ����� ������������ � �� */
    QString tableName;     /**< �������� ������� � �� */
};
