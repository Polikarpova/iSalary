#pragma once

#include "UserInfo.h"

/**
* ���������, ����������� ��������� ������� �����������
*
*/
struct SignInResult : UserInfo {
public:
    bool success;
};

struct SignUpResult: SignInResult {
public:
    QString failReason;
};