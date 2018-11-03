#pragma once

#include <qobject.h>
#include <qhash.h>
#include <qlist.h>

#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qspinbox.h>
#include <qradiobutton.h>
#include <qtableview.h>
#include <qpushbutton.h>

#include "PersonnalAccountingFacade.h"
#include "EmployeesTableModel.h"

class EmployeesPage : public QObject {
Q_OBJECT
public:
    EmployeesPage(PersonnalAccountingFacade* pa);
    ~EmployeesPage(void);

    void setUI(
      QTableView* managersTable,
      QLineEdit* firstNameInput,
      QLineEdit* secondNameInput,
      QLineEdit* thirdNameInput,
      QDateTimeEdit* birthdayInput,
      QSpinBox* passportSerialInput,
      QSpinBox* passportNumberInput,
      QRadioButton* maleInput,
      QRadioButton* femaleInput,
      QLineEdit* passportSourceInput,
      QDateTimeEdit* passportIssueDate,
      QLineEdit* addressInput,
      QLineEdit* INNInput,
      QPushButton* editBtn,
      QPushButton* addBtn,
      QPushButton* cancelBtn,
      QPushButton* saveBtn
    );

    void refreshList();

protected slots:

    void showDetails(int managerId);

    void hireManager();

    void startEdit();

    void startAdd();

    void save();

    void cancel();
private:
    PersonnalAccountingFacade* personnalAccouting;

    QHash<int, ManagerDTO> managers;

    QTableView* managersTable;

    QLineEdit* firstNameInput;
    QLineEdit* secondNameInput;
    QLineEdit* thirdNameInput;

    QDateTimeEdit* birthdayInput;

    QSpinBox* passportSerialInput;
    QSpinBox* passportNumberInput;

    QRadioButton* maleInput;
    QRadioButton* femaleInput;

    QLineEdit* passportSourceInput;

    QDateTimeEdit* passportIssueDate;

    QLineEdit* addressInput;
    QLineEdit* INNInput;

    QPushButton* editBtn;
    QPushButton* addBtn;
    QPushButton* cancelBtn;
    QPushButton* saveBtn;
};

