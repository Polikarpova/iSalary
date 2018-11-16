#include "Employer.h"


Employer::Employer( AuthorizationModule* authorizationModule, IManagerRepository* managers, ManagerValidator* managereValidator){
    this->authorizationModule = authorizationModule;
    this->managerRepository = managers;
    this->managerValidator = managereValidator;
}


Manager& Employer::employ( Manager& manager){
    QString error;
    QString login = translite(
      manager.getSecondName() 
      + ( manager.getSecondName().size() > 0 ? QString(1, manager.getFirstName()[0]) : "")
    );
    while( this->managerValidator->isLoginExist( login)){
       login += generateRandomString(1);
    }
    manager.setLogin( login);
    if( this->managerValidator->isManagerValid(manager, &error)) {
        SignUpResult signUpRes = this->authorizationModule->signUp( manager.getLogin(), MANAGER);
        if( signUpRes.success){
            manager.setUserInfo( signUpRes.user);
            manager.setDateOfEmployment( QDate::currentDate());
            this->managerRepository->update( manager);
        } else {
            throw new QString( signUpRes.failReason);
        }
    } else {
        throw new QString( error); 
    }

    return manager;
}