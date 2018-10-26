#include "AuthorizationModule.h"

AuthorizationModule::AuthorizationModule(IUserRepository* userRepository){
    this->userRepository = userRepository;
}


AuthorizationModule::~AuthorizationModule(void) {
    
}


SignInResult AuthorizationModule::signIn( const QString& login, const QString& password) {
    UserInfo user;
    bool isExist = true;
    try {
        user = userRepository->findByLoginPassword(login, password);
    } catch (char* ex) {
        isExist = false;
    }

    SignInResult result;
    result.success = isExist;
    if (isExist ){
        result.success = true;
        result.type = user.type;
        result.user = user.user;
    } else {
        result.success = false;
    }
    
    return result;
}

SignUpResult AuthorizationModule::signUp( const QString& login, const QString& password) {
    UserInfo user;
    bool isExist = true;
    try {
        user = userRepository->findByLogin(login);
    } catch (char* ex) {
        isExist = false;
    }

    SignUpResult result;
    if( !isExist){
        result.success = true;
        User newUser;
        newUser.setLogin(login);
        newUser.setPassword(password);

        result.user = userRepository->insert(newUser);
        result.type = MANAGER;
    } else {
        result.success = false;
        result.failReason = "Данный логин уже занят";
    }

    return result;
}