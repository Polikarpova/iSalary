#pragma once

#include <qobject.h>
#include <qstring.h>
#include <qhash.h>
#include <qlist.h>

#include <qlineedit.h>
#include <qdatetimeedit.h>
#include <qspinbox.h>
#include <qradiobutton.h>
#include <qpushbutton.h>
#include <qtableview.h>
#include <qstackedwidget.h>

#include <qheaderview.h>
#include <qmodelindex>
#include <qabstractitemview.h>

#include "PersonnalAccountingFacade.h"
#include "EmployeesTableModel.h"

class EmployeesPage : public QObject {
Q_OBJECT
public:
    EmployeesPage(PersonnalAccountingFacade* pa);
    ~EmployeesPage(void);

    void setUI(
      QTableView* managersTable,
      QLineEdit* loginInput,
      QLineEdit* passwordInput,
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
      QStackedWidget* buttonStackedWidget,
      QPushButton* editBtn,
      QPushButton* addBtn,
      QPushButton* confirmUpdateBtn,
      QPushButton* cancelUpdateBtn,
      QPushButton* confirmAddBtn,
      QPushButton* cancelAddBtn
    );

    void refreshList();

protected slots:

    void showDetails( const QModelIndex& index);

    void startEdit();

    void startAdd();

    void saveEdit();

    void saveAdd();

    void cancel();
    

protected:    
    void showDetailsById( int managerId);

    void enableInputs( bool isEnable);

    void clearInputs();

    int getSelectedManagerId();

    ManagerDTO readFromInputs();
    
    enum Btns_Page {
        PAGE_BTNS_SHOW,
        PAGE_BTNS_EDIT,
        PAGE_BTNS_ADD,
    };

private:
    PersonnalAccountingFacade* personnalAccouting;

    QHash<int, ManagerDTO> managers;

    QTableView* managersTable;

    QLineEdit* loginInput;
    QLineEdit* passwordInput;

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

    QStackedWidget* buttonStackedWidget;
    QPushButton* editBtn;
    QPushButton* addBtn;
    QPushButton* confirmUpdateBtn;
    QPushButton* cancelUpdateBtn;
    QPushButton* confirmAddBtn;
    QPushButton* cancelAddBtn;
};

