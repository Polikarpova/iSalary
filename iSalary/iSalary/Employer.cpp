#include "Employer.h"


Employer::Employer( AuthorizationModule* authorizationModule, IManagerRepository* managers){
    this->authorizationModule = authorizationModule;
    this->managerRepository = managers;
}


Manager& Employer::employ( Manager& manager){
    bool isINNUniq = !this->managerRepository->findByINN( manager.getINN(), NULL);
    bool isPassporUniq = !this->managerRepository->findByPassport( manager.getPassportSerial(), manager.getPassportNumber(), NULL);
    
    if( !isINNUniq) {
        throw new QString( "Работник с таким ИНН уже существует");
    } else if ( !isPassporUniq) {
        throw new QString( "Работник с такими паспортными данными (логинов и паролем) уже существует");
    }
    else {
        SignUpResult signUpRes = this->authorizationModule->signUp( manager.getLogin(), manager.getPassword(), MANAGER);
        if( signUpRes.success){
            manager.setUserInfo( signUpRes.user);
            this->managerRepository->update( manager);
        } else {
            QString* err = new QString( signUpRes.failReason);
            throw err;
        }
    }

    return manager;
}