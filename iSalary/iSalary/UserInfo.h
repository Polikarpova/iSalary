#pragma once

#include "User.h"

/**
 * ����������� ����� ������������� � ����������
 * @author ��������
 */
enum UserType {
    MANAGER,      /**< �������� */
    BOSS,         /**< ������������ */
    NOT_SPECIFIED /**< �� ����� */
};

/**
 * ���������� � ������������, ���������� ������ ������������ � ��� ���
 * @author ��������
 */
struct UserInfo {

  public:
    User user;     /**< ����������� */
    UserType type; /**< ��� ������������ */
};
