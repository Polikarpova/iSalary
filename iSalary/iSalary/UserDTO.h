#pragma once

#include <qstring.h>

/** 
* ���������, ����������� ������������, ������������� ��� �������� ���� �����������.
* @author ��������
*/
struct UserDTO {
public:
    int id;             /**< id ������������ */
    QString login;      /**< ����� ������������ */
    QString passwword;  /**< ������ ������������ */
};