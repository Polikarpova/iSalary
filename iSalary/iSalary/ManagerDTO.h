#pragma once
#include "Manager.h"
#include "UserDTO.h"
#include "qdatetime.h"

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