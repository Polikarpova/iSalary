#pragma once

#include <qlist.h>

#include "Employer.h"
#include "ManagerDTO.h"
#include "ManagerDB.h"

class PersonnalAccountingFacade {
public:
    QList<ManagerDTO> getAllManagers();
    ManagerDTO hireManager( const ManagerDTO& manager);
    void updateManager( const ManagerDTO& manager);

    PersonnalAccountingFacade(Employer* employer, ManagerDB* managerDB, ManagerValidator* managerValidator);
    ~PersonnalAccountingFacade(void);

protected:
    Manager fromDTO( const ManagerDTO& manager);
    ManagerDTO toDTO( const Manager& manager);

private:
    Employer* employer;
    ManagerDB* managerDB;
    ManagerValidator* managerValidator; //TODO: найти этому лучшее место
};

