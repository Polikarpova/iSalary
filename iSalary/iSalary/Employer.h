#pragma once
#include "IManagerRepository.h"
#include "IUserRepository.h"
#include "AuthorizationModule.h"
#include "ManagerValidator.h"

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
class Employer {
public:

    /**
    * ����������
    * @param AuthorizationModule - ������ ����������� � �����������
    * @param IManagerRepository - ��������� ����������
    */
    Employer( AuthorizationModule*, IManagerRepository*, ManagerValidator*);

    /**
    * ������ ���������
    * @return - ��������� ������� �����
    */
    Manager& employ( Manager& manager);

private:
    IManagerRepository* managerRepository; /**< ��������� ���������� */
    AuthorizationModule* authorizationModule; /**< ��������� ������������� */
    ManagerValidator* managerValidator;
};

