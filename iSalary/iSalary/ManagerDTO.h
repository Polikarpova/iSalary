#pragma once
#include "UserDTO.h"
#include "qdatetime.h"
#include "Manager.h"

struct ManagerDTO : public UserDTO {
public:
    QString firstName;
    QString secondName;
    QString thirdName;
    Sex sex;
    QString passportSerial;
    QString passportNumber;
    QDate passportIssueDate;
    QString address;
    QString INN;
    QString email;
    QString mobileNumber;
    QDate dateOfEmplyment;
};