#include "Employer.h"


Employer::Employer( AuthorizationModule* authorizationModule, IManagerRepository* managers, ManagerValidator* managereValidator){
    this->authorizationModule = authorizationModule;
    this->managerRepository = managers;
    this->managerValidator = managereValidator;
}


Manager& Employer::employ( Manager& manager){
    QString error;

    if( this->managerValidator->isManagerValid(manager, &error)) {
        SignUpResult signUpRes = this->authorizationModule->signUp( manager.getLogin(), manager.getPassword(), MANAGER);
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