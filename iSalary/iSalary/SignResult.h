#pragma once

#include "UserInfo.h"

/**
 * ���������, ����������� ��������� ������� �����������
 * @author ��������
 */
struct SignInResult : public UserInfo {
  public:
    bool success; /**< ���������� ������� */
};

/**
 * ���������, ����������� ��������� ������� �����������
 * @author ��������
 */
struct SignUpResult : public SignInResult {
  public:
    QString failReason; /**< ������� ������� ������� */
};