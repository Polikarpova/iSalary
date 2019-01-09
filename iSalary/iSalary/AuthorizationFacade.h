#pragma once

#include "AuthorizationModule.h"
#include "SignResultDTO.h"

/**
 * �����, ��������������� ������ � �������� ����������, ��������� � ������������ � ������������
 * @author ��������
 */
class AuthorizationFacade {
  public:
    /**
     * �����������
     * @param authModule - ������ �����������, � �������� ����� ���������� �����
     */
    AuthorizationFacade( AuthorizationModule *authModule );

    /**
     * ����������� ������������
     * @param login - ����� ������������
     * @param password - ������ ������������
     * @return SignInResultDTO - ���������, ���������� ��������� �� ���������� ����������� � ������ ��������������� ������������
     */
    SignInResultDTO signIn( const QString &login, const QString &password );

    /**
     * ����������� ������ ������������
     * @param login - ����� ������������
     * @param password - ������ ������������
     * @param userType - ��� ������������
     * @return SignUpResultDTO - ���������, ���������� ��������� �� ���������� ������� ����������� � ������ ������������������� ������������
     */
    SignUpResultDTO signUp( const QString &login, const QString &password, UserType userType );

    ~AuthorizationFacade( void );

  private:
    AuthorizationModule *authModule;
};
