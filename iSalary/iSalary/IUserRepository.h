#pragma once

#include "UserInfo.h"
/**
*
*
*/
class IUserRepository {
public:
    
    /**
    * ��������� ������ � ������������ �� �� �� ��� ������ � ������
    * @param login - ����� �����������
    * @param password - ������ �����������
    * @throws "������ �� �������"
    * @return ���������, �������� ������ � ������������ � ��� ���
    */
    virtual UserInfo findByLoginPassword( const QString& login, const QString& password) = 0;
    
    /**
    * ��������� ������ � ������������ �� �� �� ��� ������
    * @param login - ����� �����������    
    * @throws "������ �� �������"
    * @return ���������, �������� ������ � ������������ � ��� ���
    */
    virtual UserInfo findByLogin( const QString& login) = 0;
    
    /**
    * ��������� ������ � ������������ � ��
    * @param user - ������ ������������, ������� ���� ���������
    * @param login - ��� ������������ ������������ ( �������� / ���������)
    * @throws "������ ����� ��� �����"
    * @return ���������, �������� ������ � ������������ � ��� ���
    */
    virtual User insert( const User& user, UserType type) = 0;

};