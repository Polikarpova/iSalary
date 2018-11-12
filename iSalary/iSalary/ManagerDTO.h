#pragma once
#include "UserDTO.h"
#include "qdatetime.h"
#include "Manager.h"

struct ManagerDTO : public UserDTO {
public:
    QString firstName;
    QString secondName;
    QString thirdName;
    QDate dateOfBirth;
    Sex sex;
    QString passportSerial;
    QString passportNumber;
    QDate passportIssueDate;
    QString passportSource;
    QString address;
    QString INN;
    QString email;
    QString mobileNumber;
    QDate dateOfEmplyment;
};

