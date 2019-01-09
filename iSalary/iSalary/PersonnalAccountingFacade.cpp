#include "PersonnalAccountingFacade.h"

PersonnalAccountingFacade::PersonnalAccountingFacade( Employer *employer, ManagerDB *managerDB, ManagerValidator *managerValidator ) {
    this->employer = employer;
    this->managerDB = managerDB;
    this->managerValidator = managerValidator;
}

PersonnalAccountingFacade::~PersonnalAccountingFacade( void ) {}

QList<ManagerDTO> PersonnalAccountingFacade::getAllManagers() {
    QList<ManagerDTO> managerDTOs;

    QList<Manager> managers = this->managerDB->getAll();

    for ( auto iManager = managers.begin(); iManager != managers.end(); iManager++ ) {
        managerDTOs.append( this->toDTO( *iManager ) );
    }

    return managerDTOs;
}

ManagerDTO PersonnalAccountingFacade::hireManager( const ManagerDTO &manager ) {
    Manager m = this->fromDTO( manager );
    m = this->employer->employ( m );
    return this->toDTO( m );
}

void PersonnalAccountingFacade::updateManager( const ManagerDTO &manager ) {
    Manager m = this->fromDTO( manager );
    QString error;
    if ( this->managerValidator->isManagerValid( m, &error, true ) ) {
        this->managerDB->update( m );
    } else {
        throw new QString( error );
    }
}

Manager PersonnalAccountingFacade::fromDTO( const ManagerDTO &manager ) {
    Manager obj( manager.id );
    obj.setAddress( manager.address );
    obj.setDateOfEmployment( manager.dateOfEmplyment );
    obj.setDateOfBirth( manager.dateOfBirth );
    obj.setEmail( manager.email );
    obj.setFirstName( manager.firstName );
    obj.setINN( manager.INN );
    obj.setLogin( manager.login );
    obj.setMobileNumber( manager.mobileNumber );
    obj.setPassportDateIssue( manager.passportIssueDate );
    obj.setPassportNumber( manager.passportNumber );
    obj.setPassportSerial( manager.passportSerial );
    obj.setPassportSource( manager.passportSource );
    obj.setPassword( manager.passwword );
    obj.setSecondName( manager.secondName );
    obj.setSex( manager.sex );
    obj.setThirdName( manager.thirdName );

    return obj;
}

ManagerDTO PersonnalAccountingFacade::toDTO( const Manager &manager ) {
    ManagerDTO dto;
    dto.address = manager.getAddress();
    dto.dateOfEmplyment = manager.getDateOfEmployment();
    dto.dateOfBirth = manager.getDateOfBirth();
    dto.email = manager.getEmail();
    dto.firstName = manager.getFirstName();
    dto.id = manager.getId();
    dto.INN = manager.getINN();
    dto.login = manager.getLogin();
    dto.mobileNumber = manager.getMobileNumber();
    dto.passportIssueDate = manager.getPassportDateIssue();
    dto.passportSerial = manager.getPassportSerial();
    dto.passportNumber = manager.getPassportNumber();
    dto.passportSource = manager.getPassportSource();
    dto.passwword = manager.getPassword();
    dto.secondName = manager.getSecondName();
    dto.sex = manager.getSex();
    dto.thirdName = manager.getThirdName();

    return dto;
}