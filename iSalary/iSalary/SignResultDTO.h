#pragma once
#include "AuthorizationModule.h"
#include "UserDTO.h"

/**
 * ���������, ����������� ��������� ������� �����������. ������������� ��� �������� ���� �����������
 * @author ��������
 */
struct SignInResultDTO {
  public:
    UserDTO user;      /** ������������ */
    UserType userType; /**< ��� ������������ */
    bool success;      /**< ���������� ������� */
};

/**
 * ���������, ����������� ��������� ������� �����������. ������������� ��� �������� ���� �����������
 * @author ��������
 */
struct SignUpResultDTO : public SignInResultDTO {
  public:
    QString failReason; /**< ������� ������� ������� */
};