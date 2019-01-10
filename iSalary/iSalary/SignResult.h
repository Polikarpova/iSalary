#pragma once

#include "UserInfo.h"

/**
 * Структура, описывающая результат попытки авторизации
 * @author Курносов
 */
struct SignInResult : public UserInfo {
  public:
    bool success; /**< Успешность попытки */
};

/**
 * Структура, описывающая результат попытки регистрации
 * @author Курносов
 */
struct SignUpResult : public SignInResult {
  public:
    QString failReason; /**< Причина неудачи попытки */
};