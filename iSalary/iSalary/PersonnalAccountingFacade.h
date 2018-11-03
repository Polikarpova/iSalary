#pragma once

#include <qlist.h>

#include "Employer.h"
#include "ManagerDTO.h"
#include "ManagerDB.h"

class PersonnalAccountingFacade {
public:
    QList<ManagerDTO> getAllManagers();
    bool hireManager( const ManagerDTO& manager);
    void updateManager( const ManagerDTO& manager);

    PersonnalAccountingFacade(Employer* employer, ManagerDB* managerDB);
    ~PersonnalAccountingFacade(void);

protected:
    Manager fromDTO( const ManagerDTO& manager);
    ManagerDTO toDTO( const Manager& manager);

private:
    Employer* employer;
    ManagerDB* managerDB;
};

