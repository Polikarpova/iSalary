#pragma once

#include <qstring.h>

#include "User.h"
#include "SignResult.h"
#include "IUserRepository.h"
#include "UserValidator.h"



/** 
 * �����, ���������� �� ����������� � ����������� �������������
 *
 */
class AuthorizationModule
{
public:
	AuthorizationModule(UserValidator* userValidator, IUserRepository* userRepository);
	~AuthorizationModule(void);
	/**
	 * ����������� ������������
     * @param login - ����� ������������
     * @param password - ������ ������������
     * @return SignInResult - ���������, ���������� ��������� �� ���������� ����������� � ��������������� ������������
	 */
	SignInResult signIn( const QString& login, const QString& password);

    
    /**
	* ����������� ������ ������������
    * @param login - ����� ������������
    * @param password - ������ ������������
    * @param userType - ��� ������������
    * @return SignUpResult - ���������, ���������� ��������� �� ���������� ������� ����������� � ������ ������������������� ������������
	*/
	SignUpResult signUp( const QString& login, const QString& password, UserType userType);

private:
    IUserRepository* userRepository;
    UserValidator* userValidator;
};


