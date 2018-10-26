#pragma once

#include "UserInfo.h"

/**
* Структура, описывающая результат попытки авторизации
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