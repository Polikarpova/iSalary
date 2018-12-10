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
#include <qstackedwidget.h>
#include <qgroupbox.h>

#include <qtableview.h>

#include <qheaderview.h>
#include <qmodelindex>
#include <qabstractitemview.h>

#include "PersonnalAccountingFacade.h"
#include "EmployeesTableModel.h"
#include "ErrorMessageHandler.h"

class EmployeesPage : public QObject {
Q_OBJECT
public:
    EmployeesPage(PersonnalAccountingFacade* pa);
    ~EmployeesPage(void);

    void setUI(
      QWidget* tabWidget,
      QTableView* managersTable,
      QLineEdit* loginInput,
      QLineEdit* passwordInput,
      QLineEdit* firstNameInput,
      QLineEdit* secondNameInput,
      QLineEdit* thirdNameInput,
      QDateTimeEdit* birthdayInput,
      QSpinBox* passportSerialInput,
      QSpinBox* passportNumberInput,
      QGroupBox* sexChecKGroup,
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

    void setErrorHandler( ErrorMessageHandler* errorHandler);

    void refreshList();

	void showDetailsById( int managerId);

protected slots:

    void showDetails( const QModelIndex& index);

    void startEdit();

    void startAdd();

    void saveEdit();

    void saveAdd();

    void cancel();
    

protected:    
    
    void enableInputs( bool isEnable);

    void clearInputs();

    int getSelectedManagerId();

    QDate getSelectedManagerDateOfEmployment();

    ManagerDTO readFromInputs();
    
    bool validateInputs();

    QHash<QWidget*, QString> widgetDefaultStyles;

    void fillInputDefaultStyles();

    void inputError( QWidget* edit);
    
    void clearError( QWidget* edit);

    void clearErrors();
    
    enum Btns_Page {
        PAGE_BTNS_SHOW,
        PAGE_BTNS_EDIT,
        PAGE_BTNS_ADD,
    };

    void startBlockForRequest();
    void endBlockForRequest();

private:
    PersonnalAccountingFacade* personnalAccouting;

    QHash<int, ManagerDTO> managers;

    ErrorMessageHandler* errorHandler;

    QWidget* tabWidget;

    QTableView* managersTable;

    QLineEdit* loginInput;
    QLineEdit* passwordInput;

    QLineEdit* firstNameInput;
    QLineEdit* secondNameInput;
    QLineEdit* thirdNameInput;

    QDateTimeEdit* birthdayInput;

    QSpinBox* passportSerialInput;
    QSpinBox* passportNumberInput;

    QGroupBox* sexCheckGroup;
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

