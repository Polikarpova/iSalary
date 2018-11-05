#include "AuthorizationModule.h"

AuthorizationModule::AuthorizationModule(UserValidator* userValidator, IUserRepository* userRepository){
    this->userRepository = userRepository;
    this->userValidator = userValidator;
}


AuthorizationModule::~AuthorizationModule(void) {
    
}


SignInResult AuthorizationModule::signIn( const QString& login, const QString& password) {
    UserInfo user;
    bool isExist = true;
    try {
        user = userRepository->findByLoginPassword(login, password);
    } catch (QString* ex) {
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

SignUpResult AuthorizationModule::signUp( const QString& login, const QString& password, UserType userType) {
    UserInfo user;
    
    User newUser;
    newUser.setLogin(login);
    newUser.setPassword(password);
    SignUpResult result;
    if( this->userValidator->isUserValid(newUser, &result.failReason)) {
        result.success = true;

        result.user = userRepository->insert( newUser, userType);
        result.type = MANAGER;
    }

    return result;
}