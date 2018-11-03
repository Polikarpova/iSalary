#include "EmployeesPage.h"


EmployeesPage::EmployeesPage(PersonnalAccountingFacade* pa) {
    this->personnalAccouting = pa;
}


EmployeesPage::~EmployeesPage(void) {
}

void EmployeesPage::setUI(
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
) {
    this->managersTable = managersTable;
    this->managersTable->setSelectionBehavior( QAbstractItemView::SelectRows);
    auto model = new EmployeesTableModel();
    this->managersTable->setModel( model);

    this->firstNameInput = firstNameInput;
    this->secondNameInput = secondNameInput;
    this->thirdNameInput = thirdNameInput;
    this->birthdayInput = birthdayInput;
    this->passportSerialInput = passportSerialInput;
    this->passportNumberInput = passportNumberInput;
    this->maleInput = maleInput;
    this->femaleInput = femaleInput;
    this->passportSourceInput = passportSourceInput;
    this->passportIssueDate = passportIssueDate;
    this->addressInput = addressInput;
    this->INNInput = INNInput;
    this->editBtn = editBtn;
    this->addBtn = addBtn;
    this->cancelBtn = cancelBtn;
    this->saveBtn = saveBtn;
}

void EmployeesPage::refreshList() {
    this->managers.clear();
    QList<ManagerDTO> managersList = this->personnalAccouting->getAllManagers();
    for ( auto iManager = managersList.begin(); iManager != managersList.end(); iManager++){
        managers.insert( iManager->id, *iManager);
    }
    
    EmployeesTableModel* model = static_cast<EmployeesTableModel*>( this->managersTable->model());
    model->refreshData( managersList);
}

void EmployeesPage::showDetails(int managerId) {
}


void EmployeesPage::hireManager() {
}

void EmployeesPage::startEdit() {
}

void EmployeesPage::startAdd() {
}

void EmployeesPage::save() {
}

void EmployeesPage::cancel() {
}

