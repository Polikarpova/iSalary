#include "EmployeesPage.h"

EmployeesPage::EmployeesPage( PersonnalAccountingFacade* pa) {
    this->personnalAccouting = pa;
}


EmployeesPage::~EmployeesPage(void) {
}

void EmployeesPage::setUI(
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
) {
    this->managersTable = managersTable;
    auto model = new EmployeesTableModel();
    this->managersTable->setModel( model);

    this->managersTable->setColumnHidden( EmployeesTableModel::COLUMN_ID, true);
    //Расстягивать столбцы
    this->managersTable->horizontalHeader()->setStretchLastSection(true);
    //Выбирать только строки
    this->managersTable->setSelectionBehavior( QAbstractItemView::SelectRows);
    this->managersTable->setSelectionMode(QAbstractItemView::SingleSelection);
   
    connect( this->managersTable, &QTableView::clicked, this, &EmployeesPage::showDetails); 
    //connect( this->managersTable, SIGNAL( clicked( const QModelIndex&)), this, SLOT( showDetails( const QModelIndex& index)));

    this->loginInput = loginInput;
    this->passwordInput = passwordInput;

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

    this->buttonStackedWidget = buttonStackedWidget;
    this->buttonStackedWidget->setCurrentIndex( PAGE_BTNS_SHOW);

    this->editBtn = editBtn;
    connect( this->editBtn, &QPushButton::clicked, this, &EmployeesPage::startEdit);

    this->addBtn = addBtn;
    connect( this->addBtn, &QPushButton::clicked, this, &EmployeesPage::startAdd);

    this->confirmUpdateBtn = confirmUpdateBtn;
    connect( this->confirmUpdateBtn, &QPushButton::clicked, this, &EmployeesPage::saveEdit);
    
    this->cancelUpdateBtn = cancelUpdateBtn;
    connect( this->cancelUpdateBtn, &QPushButton::clicked, this, &EmployeesPage::cancel);

    this->confirmAddBtn = confirmAddBtn;
    connect( this->confirmAddBtn, &QPushButton::clicked, this, &EmployeesPage::saveAdd);

    this->cancelAddBtn = cancelAddBtn;
    connect( this->cancelAddBtn, &QPushButton::clicked, this, &EmployeesPage::cancel);

    this->fillInputDefaultStyles();
}

void EmployeesPage::setErrorHandler( ErrorMessageHandler* errorHandler) {
    this->errorHandler = errorHandler;
}

void EmployeesPage::refreshList() {
    QList<ManagerDTO> managersList;
    
    try {
        managersList = this->personnalAccouting->getAllManagers();
    } catch( QString* error) { 
        this->errorHandler->handleError( error);
    }
    
    int currentManagerId = this->getSelectedManagerId();
        
    this->managers.clear();
        for ( auto iManager = managersList.begin(); iManager != managersList.end(); iManager++){
            managers.insert( iManager->id, *iManager);
        }
    
    EmployeesTableModel* model = static_cast<EmployeesTableModel*>( this->managersTable->model());
    model->refreshData( managersList);

    if( currentManagerId != -1){
        QModelIndex index = model->getIndexByRecordId( currentManagerId);
        if( index.isValid()){
            this->managersTable->setCurrentIndex( index);
        }
    }
}

void EmployeesPage::showDetailsById( int managerId) {
    this->enableInputs( false);
    this->buttonStackedWidget->setCurrentIndex( PAGE_BTNS_SHOW);
    this->clearErrors();

    const ManagerDTO& manager = this->managers[ managerId];

    this->firstNameInput->setText( manager.firstName);
    this->secondNameInput->setText( manager.secondName);
    this->thirdNameInput->setText( manager.thirdName);
    //this->birthdayInput->setDate( manager.dateOfBirth);
    if( manager.sex == MALE) {
        this->maleInput->setChecked( true);
    } else if( manager.sex == FEMALE) {
        this->femaleInput->setChecked( true);
    }

    this->passportIssueDate->setDate( manager.passportIssueDate);
    this->passportNumberInput->setValue( manager.passportNumber.toInt());
    this->passportSerialInput->setValue( manager.passportSerial.toInt());

    this->INNInput->setText( manager.INN);

    this->loginInput->setText( manager.login);
    this->passwordInput->setText( manager.passwword);
}

void EmployeesPage::showDetails( const QModelIndex& index) {
    this->showDetailsById( this->getSelectedManagerId());
}


void EmployeesPage::startEdit() {
    this->buttonStackedWidget->setCurrentIndex( PAGE_BTNS_EDIT);
    this->enableInputs(true);
}

void EmployeesPage::startAdd() {
    this->buttonStackedWidget->setCurrentIndex( PAGE_BTNS_ADD);
    this->clearInputs();
    this->enableInputs(true);
}

void EmployeesPage::saveEdit() {
    try {
        if( validateInputs()){
            ManagerDTO manager = this->readFromInputs();
            manager.id = this->getSelectedManagerId();
    
            this->personnalAccouting->updateManager( manager);
    
            this->refreshList();
        }
    } catch( QString* error) {
        this->errorHandler->handleError( error);
    }
}

void EmployeesPage::saveAdd() {
    try {
        if( validateInputs()) {
            ManagerDTO manager = this->readFromInputs();
    
            this->personnalAccouting->hireManager( manager);
    
            this->refreshList();
        }
    } catch( QString* error) {
        this->errorHandler->handleError( error);
    }
}

void EmployeesPage::cancel() {
    this->showDetails( this->managersTable->currentIndex());
}

void EmployeesPage::enableInputs( bool isEnable) {

    this->loginInput->setEnabled( isEnable);
    this->passwordInput->setEnabled( isEnable);

    this->firstNameInput->setEnabled( isEnable);
    this->secondNameInput->setEnabled( isEnable);
    this->thirdNameInput->setEnabled( isEnable);
    this->birthdayInput->setEnabled( isEnable);
    this->passportSerialInput->setEnabled( isEnable);
    this->passportNumberInput->setEnabled( isEnable);
    this->maleInput->setEnabled( isEnable);
    this->femaleInput->setEnabled( isEnable);
    this->passportSourceInput->setEnabled( isEnable);
    this->passportIssueDate->setEnabled( isEnable);
    this->addressInput->setEnabled( isEnable);
    this->INNInput->setEnabled( isEnable);
}

void EmployeesPage::clearInputs() {

    this->loginInput->clear();
    this->passwordInput->clear();

    this->firstNameInput->clear();
    this->secondNameInput->clear();
    this->thirdNameInput->clear();
    this->birthdayInput->clear();
    this->passportSerialInput->clear();
    this->passportNumberInput->clear();

    this->maleInput->setChecked( true);
    
    this->passportSourceInput->clear();
    this->passportIssueDate->clear();
    this->addressInput->clear();
    this->INNInput->clear();
}


int EmployeesPage::getSelectedManagerId() {
    auto model = static_cast<EmployeesTableModel*>( this->managersTable->model());
    return model->getRecordId( this->managersTable->currentIndex().row()); 
}

ManagerDTO EmployeesPage::readFromInputs() {
    ManagerDTO manager;

    manager.firstName = this->firstNameInput->text();
    manager.secondName = this->secondNameInput->text();
    manager.thirdName = this->thirdNameInput->text();

    manager.login = this->loginInput->text();
    manager.passwword = this->passwordInput->text();

    manager.passportIssueDate = this->passportIssueDate->date();
    manager.passportNumber = this->passportNumberInput->value();
    manager.passportSerial = this->passportSerialInput->value();
    manager.address = this->passportSourceInput->text();

    manager.INN = this->INNInput->text();

    if( this->maleInput->isChecked()) {
        manager.sex = MALE;
    } else if ( this->femaleInput->isChecked()) {
        manager.sex = FEMALE;
    }

    return manager;
}


bool EmployeesPage::validateInputs() {

    ManagerDTO manager = this->readFromInputs();
    bool isOk = true;
    if( manager.firstName.size() == 0 ) {
        inputError( this->firstNameInput);
        isOk = false;
    }
    
    if( manager.secondName.size() == 0 ) {
        inputError( this->secondNameInput);
        isOk = false;
    }

    if( manager.thirdName.size() == 0 ) {
        inputError( this->thirdNameInput);
        isOk = false;
    }

    if( manager.passportSerial == 0 ) {
        inputError( this->passportSerialInput);
        isOk = false;
    }
    
    if( manager.passportNumber == 0 ) {
        inputError( this->passportNumberInput);
        isOk = false;
    }
    /*
    if( manager.address.size() ){
        inputError( this->addressInput);
        isOk = false;
    }
    */

    if( manager.INN.size() == 0 ) {
        inputError( this->INNInput);
        isOk = false;
    }

    if( manager.login.size() == 0 ) {
        inputError( this->loginInput);
        isOk = false;
    }

    if( manager.passwword.size() == 0 ) {
        inputError( this->passwordInput);
        isOk = false;
    }

    return isOk;
}


void EmployeesPage::fillInputDefaultStyles() {
    
    
    this->widgetDefaultStyles[ this->loginInput] = this->loginInput->styleSheet();
    this->widgetDefaultStyles[ this->passwordInput] = this->passwordInput->styleSheet();

    this->widgetDefaultStyles[ this->firstNameInput] = this->firstNameInput->styleSheet();
    this->widgetDefaultStyles[ this->secondNameInput] = this->secondNameInput->styleSheet();
    this->widgetDefaultStyles[ this->thirdNameInput] = this->thirdNameInput->styleSheet();
    this->widgetDefaultStyles[ this->birthdayInput] = this->birthdayInput->styleSheet();
    this->widgetDefaultStyles[ this->passportSerialInput] = this->passportSerialInput->styleSheet();
    this->widgetDefaultStyles[ this->passportNumberInput] = this->passportNumberInput->styleSheet();
    this->widgetDefaultStyles[ this->maleInput] = this->maleInput->styleSheet();
    this->widgetDefaultStyles[ this->femaleInput] = this->femaleInput->styleSheet();
    this->widgetDefaultStyles[ this->passportSourceInput] = this->passportSourceInput->styleSheet();
    this->widgetDefaultStyles[ this->passportIssueDate] = this->passportIssueDate->styleSheet();
    this->widgetDefaultStyles[ this->addressInput] = this->addressInput->styleSheet();
    this->widgetDefaultStyles[ this->INNInput] = this->INNInput->styleSheet();
}

void EmployeesPage::inputError( QWidget* edit) {
    edit->setStyleSheet("border: 1px solid red");
}

void EmployeesPage::clearError( QWidget* edit) {
    edit->setStyleSheet( this->widgetDefaultStyles[edit]);
}

void EmployeesPage::clearErrors() {
    for( auto iWidgetStyle = this->widgetDefaultStyles.begin(); iWidgetStyle != this->widgetDefaultStyles.end(); iWidgetStyle++){
        iWidgetStyle.key()->setStyleSheet( iWidgetStyle.value());
    }
}
