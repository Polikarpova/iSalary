#pragma once
#include "IManagerRepository.h"
#include "IUserRepository.h"

/**
* ������������ ��������� ����������� ������� �����
*/
enum EmployResult {
    EMPLOY_RES_OK,     /**< ���� ������ ������� */
    EMPLOY_RES_INN,    /**< ���� �� ������, �.�. ���� ������ �������� � ����� ��� */
    EMPLOY_RES_PASSPORT/**< ���� �� ������, �.�. ���� ������ �������� � ������ ������ � ������� �������� */
};

/**
* �����, "����������" ���������� 
*/
class Employer{
public:

    /**
    * ����������
    * @param IUserRepository - ��������� �������������
    * @param IManagerRepository - ��������� ����������
    */
    Employer( IUserRepository*, IManagerRepository*);

    /**
    * ������ ���������
    * @return - ��������� ������� �����
    */
    bool employ( const Manager& manager);

private:
    IManagerRepository* managerRepository; /**< ��������� ���������� */
    IUserRepository* userRepository; /**< ��������� ������������� */
};

