#pragma once

#include <qhash.h>
#include <qlist.h>
#include <qobject.h>
#include <qstring.h>

#include <qdatetimeedit.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qspinbox.h>
#include <qstackedwidget.h>

#include <qtableview.h>

#include <qstyle.h>s

#include <qabstractitemview.h>
#include <qheaderview.h>
#include <qmodelindex>

#include "EmployeesTableModel.h"
#include "ErrorMessageHandler.h"
#include "PersonnalAccountingFacade.h"

#include "test_employees_gui.h"
#include "test_salary_gui.h"
class EmployeesPage : public QObject {
    Q_OBJECT
    friend class Test_Employees_GUI;
	friend class Test_Salary_GUI;
  public:
    EmployeesPage( PersonnalAccountingFacade *pa );
    ~EmployeesPage( void );

    void setUI( QWidget *tabWidget, QTableView *managersTable, QLineEdit *loginInput, QLineEdit *passwordInput, QLineEdit *firstNameInput,
                QLineEdit *secondNameInput, QLineEdit *thirdNameInput, QDateTimeEdit *birthdayInput, QSpinBox *passportSerialInput,
                QSpinBox *passportNumberInput, QGroupBox *sexChecKGroup, QRadioButton *maleInput, QRadioButton *femaleInput, QLineEdit *passportSourceInput,
                QDateTimeEdit *passportIssueDate, QLineEdit *addressInput, QLineEdit *INNInput, QStackedWidget *buttonStackedWidget, QPushButton *editBtn,
                QPushButton *addBtn, QPushButton *confirmUpdateBtn, QPushButton *cancelUpdateBtn, QPushButton *confirmAddBtn, QPushButton *cancelAddBtn,
                QLabel *dataHeader );

    void setErrorHandler( ErrorMessageHandler *errorHandler );

    void refreshList();

    void showDetailsById( int managerId );

  protected slots:

    void showDetails( const QModelIndex &index );

    void startEdit();

    void startAdd();

    void saveEdit();

    void saveAdd();

    void cancel();

  protected:
    void enableInputs( bool isEnable );

    void clearInputs();

    int getSelectedManagerId();

    QDate getSelectedManagerDateOfEmployment();

    ManagerDTO readFromInputs();

    bool validateInputs();

    QHash<QWidget *, QString> widgetDefaultStyles;

    void fillInputDefaultStyles();

    void inputError( QWidget *edit );

    void clearError( QWidget *edit );

    void clearErrors();

    enum Btns_Page {
        PAGE_BTNS_SHOW,
        PAGE_BTNS_EDIT,
        PAGE_BTNS_ADD,
    };

    void startBlockForRequest();
    void endBlockForRequest();

    QString dataHeaderStyle;

  private:
    PersonnalAccountingFacade *personnalAccouting;

    QHash<int, ManagerDTO> managers;

    ErrorMessageHandler *errorHandler;

    QWidget *tabWidget;

    QTableView *managersTable;

    QLineEdit *loginInput;
    QLineEdit *passwordInput;

    QLineEdit *firstNameInput;
    QLineEdit *secondNameInput;
    QLineEdit *thirdNameInput;

    QDateTimeEdit *birthdayInput;

    QSpinBox *passportSerialInput;
    QSpinBox *passportNumberInput;

    QGroupBox *sexCheckGroup;
    QRadioButton *maleInput;
    QRadioButton *femaleInput;

    QLineEdit *passportSourceInput;

    QDateTimeEdit *passportIssueDate;

    QLineEdit *addressInput;
    QLineEdit *INNInput;

    QStackedWidget *buttonStackedWidget;
    QPushButton *editBtn;
    QPushButton *addBtn;
    QPushButton *confirmUpdateBtn;
    QPushButton *cancelUpdateBtn;
    QPushButton *confirmAddBtn;
    QPushButton *cancelAddBtn;

    QLabel *dataHeader;
};
