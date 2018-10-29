#include "Employer.h"


Employer::Employer( IUserRepository* users, IManagerRepository* managers){
    this->userRepository = users;
    this->managerRepository = managers;
}


bool Employer::Employ( const Manager& manager){
    bool isINNUniq = !this->managerRepository->findByINN( manager.getINN(), NULL);
    bool isPassporUniq = !this->managerRepository->findByPassport( manager.getPassportSerial(), manager.getPassportNumber(), NULL);
    
    bool isSuccess = isINNUniq && isPassporUniq;

    if( isSuccess){
        this->userRepository->insert( manager, MANAGER);
        this->managerRepository->update( manager);
    }

    return isSuccess;
}