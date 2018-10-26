#pragma once

#include "User.h"

/**
* ����������� ����� ������������� � ����������
*/
enum UserType {
    MANAGER,      /**< �������� */
    BOSS,         /**< ������������ */
    NOT_SPECIFIED /**< �� ����� */
};

/**
* ���������� � ������������, ���������� ������ ������������ � ��� ���
*/
struct UserInfo {

public:
    User user;     /**< ����������� */
    UserType type; /**< ��� ������������ */
};
