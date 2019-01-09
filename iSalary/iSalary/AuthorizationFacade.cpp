#include "AuthorizationFacade.h"

AuthorizationFacade::AuthorizationFacade( AuthorizationModule *am ) { this->authModule = am; }

SignInResultDTO AuthorizationFacade::signIn( const QString &login, const QString &password ) {
    SignInResult signInRes = authModule->signIn( login, password );

    SignInResultDTO signInResDTO;

    signInResDTO.user.id = signInRes.user.getId();
    signInResDTO.user.login = signInRes.user.getLogin();
    signInResDTO.user.passwword = signInRes.user.getPassword();

    signInResDTO.success = signInRes.success;
    signInResDTO.userType = signInRes.type;

    return signInResDTO;
}

SignUpResultDTO AuthorizationFacade::signUp( const QString &login, const QString &password, UserType userType ) {
    SignUpResult signUpRes = authModule->signUp( login, password, userType );

    SignUpResultDTO signUpResDTO;

    signUpResDTO.user.id = signUpRes.user.getId();
    signUpResDTO.user.login = signUpRes.user.getLogin();
    signUpResDTO.user.passwword = signUpRes.user.getPassword();

    signUpResDTO.success = signUpRes.success;
    signUpResDTO.userType = signUpRes.type;
    signUpResDTO.failReason = signUpRes.failReason;

    return signUpResDTO;
}

AuthorizationFacade::~AuthorizationFacade( void ) {}
