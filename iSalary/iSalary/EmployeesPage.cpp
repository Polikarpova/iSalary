#include "EmployeesPage.h"

EmployeesPage::EmployeesPage( PersonnalAccountingFacade* pa) {
    this->personnalAccouting = pa;
}


EmployeesPage::~EmployeesPage(void) {
}

void EmployeesPage::setUI(
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
  QPushButton* cancelAddBtn,
  QLabel* dataHeader
) {
    this->managersTable = managersTable;
    auto model = new EmployeesTableModel();
    this->managersTable->setModel( model);

    this->managersTable->setColumnHidden( EmployeesTableModel::COLUMN_ID, true);
    //Расстягивать столбцы
    this->managersTable->horizontalHeader()->setStretchLastSection(true);
    this->managersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
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
    this->sexCheckGroup = sexChecKGroup;
    this->maleInput = maleInput;
    this->femaleInput = femaleInput;
    this->passportSourceInput = passportSourceInput;
    this->passportIssueDate = passportIssueDate;
    this->addressInput = addressInput;
    this->INNInput = INNInput;

    this->buttonStackedWidget = buttonStackedWidget;
    this->buttonStackedWidget->setCurrentIndex( PAGE_BTNS_SHOW);

    this->dataHeader = dataHeader;
    this->dataHeaderStyle = this->dataHeader->styleSheet();


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

    this->tabWidget = tabWidget;


}

void EmployeesPage::setErrorHandler( ErrorMessageHandler* errorHandler) {
    this->errorHandler = errorHandler;
}

void EmployeesPage::refreshList() {
    this->startBlockForRequest();
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
            this->showDetailsById( currentManagerId);
        }
        
        this->buttonStackedWidget->setEnabled( true);
    } else {
        this->buttonStackedWidget->setEnabled( false);
    }

    this->endBlockForRequest();
}
void EmployeesPage::showDetailsById( int managerId) {
    if( managerId < 0) {
        this->buttonStackedWidget->setEnabled( false);
    } else {

        if( this->getSelectedManagerId() != managerId){
            auto index = static_cast<EmployeesTableModel*>( this->managersTable->model())->getIndexByRecordId( managerId);
            this->managersTable->setCurrentIndex( index);
        }
        this->startBlockForRequest();

        this->enableInputs( false);
        this->buttonStackedWidget->setCurrentIndex( PAGE_BTNS_SHOW);
        this->clearErrors();

        const ManagerDTO& manager = this->managers[ managerId];

        this->firstNameInput->setText( manager.firstName);
        this->secondNameInput->setText( manager.secondName);
        this->thirdNameInput->setText( manager.thirdName);
        this->birthdayInput->setDate( manager.dateOfBirth);
        if( manager.sex == MALE) {
            this->maleInput->setChecked( true);
        } else if( manager.sex == FEMALE) {
            this->femaleInput->setChecked( true);
        }

        this->passportIssueDate->setDate( manager.passportIssueDate);
        this->passportNumberInput->setValue( manager.passportNumber.toInt());
        this->passportSerialInput->setValue( manager.passportSerial.toInt());
        this->passportSourceInput->setText( manager.passportSource);
        this->addressInput->setText( manager.address);

        this->INNInput->setText( manager.INN);

        this->loginInput->setText( manager.login);
        this->passwordInput->setText( manager.passwword);

        this->endBlockForRequest();
        this->buttonStackedWidget->setEnabled( true);
        this->dataHeader->setText("");
    }
}

void EmployeesPage::showDetails( const QModelIndex& index) {
	this->showDetailsById( this->getSelectedManagerId());
}


void EmployeesPage::startEdit() {
    this->buttonStackedWidget->setCurrentIndex( PAGE_BTNS_EDIT);
    this->enableInputs(true);
    this->buttonStackedWidget->setEnabled(true);
    this->dataHeader->setText( QString::fromWCharArray( L"Изменение данных о менеджере"));
    this->dataHeader->setStyleSheet( this->dataHeaderStyle);
}

void EmployeesPage::startAdd() {
    this->buttonStackedWidget->setCurrentIndex( PAGE_BTNS_ADD);
    this->clearInputs();
    this->enableInputs(true);
    this->loginInput->setEnabled(false);
    this->passwordInput->setEnabled(false);
    this->buttonStackedWidget->setEnabled(true);
    this->dataHeader->setText( QString::fromWCharArray(L"Добавление нового менеджера"));
    this->dataHeader->setStyleSheet( this->dataHeaderStyle);
}

void EmployeesPage::saveEdit() {
    this->startBlockForRequest();

    try {
        if( /*validateInputs()*/ true){
            ManagerDTO manager = this->readFromInputs();
            manager.id = this->getSelectedManagerId();
            manager.dateOfEmplyment = this->getSelectedManagerDateOfEmployment();
    
            this->personnalAccouting->updateManager( manager);
    
            this->refreshList();
        }
    } catch( QString* error) {
        this->errorHandler->handleError( error);
    }
    this->endBlockForRequest();
    
    this->dataHeader->setText(QString::fromWCharArray(L""));
    this->dataHeader->setStyleSheet( this->dataHeaderStyle);
}

void EmployeesPage::saveAdd() {
    this->startBlockForRequest();

    try {
        if( /*validateInputs()*/ true) {
            ManagerDTO manager = this->readFromInputs();
    
            manager = this->personnalAccouting->hireManager( manager);
    
            this->refreshList();
            showDetailsById( manager.id);
        }
    } catch( QString* error) {
        this->errorHandler->handleError( error);
    }

    this->endBlockForRequest();
    this->dataHeader->setText(QString::fromWCharArray(L""));
    this->dataHeader->setStyleSheet( this->dataHeaderStyle);
}

void EmployeesPage::cancel() {
    this->showDetails( this->managersTable->currentIndex());
    this->buttonStackedWidget->setCurrentIndex( Btns_Page::PAGE_BTNS_SHOW);
    this->dataHeader->setText(QString::fromWCharArray(L""));
    this->dataHeader->setStyleSheet( this->dataHeaderStyle);
    this->enableInputs( false);
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
    this->sexCheckGroup->setEnabled( isEnable);
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


QDate EmployeesPage::getSelectedManagerDateOfEmployment() {
    auto model = static_cast<EmployeesTableModel*>( this->managersTable->model());
    return model->getRecordDateOfEmployment( this->managersTable->currentIndex().row()); 
}


ManagerDTO EmployeesPage::readFromInputs() {
    ManagerDTO manager;

    manager.firstName = this->firstNameInput->text();
    manager.secondName = this->secondNameInput->text();
    manager.thirdName = this->thirdNameInput->text();

    manager.dateOfBirth = this->birthdayInput->date();

    manager.login = this->loginInput->text();
    manager.passwword = this->passwordInput->text();

    manager.passportIssueDate = this->passportIssueDate->date();
    manager.passportNumber = QString::number( this->passportNumberInput->value());
    int passportNumberSize = 6;
    if( manager.passportNumber.size() < passportNumberSize) {
        manager.passportNumber = QString( passportNumberSize - manager.passportNumber.size(), '0')
          + manager.passportNumber;
    }

    manager.passportSerial = QString::number( this->passportSerialInput->value());
    int passportSerialSize = 4;
    if( manager.passportSerial.size() < passportSerialSize) {
        manager.passportSerial = QString( passportSerialSize - manager.passportSerial.size(), '0')
          + manager.passportSerial;
    }
    manager.passportSource = this->passportSourceInput->text();
    manager.address = this->addressInput->text();

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

    
    if( manager.passportSource.size() == 0 ){
        inputError( this->passportSourceInput);
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


void EmployeesPage::startBlockForRequest(){
    this->tabWidget->setEnabled( false);
}

void EmployeesPage::endBlockForRequest(){
    this->tabWidget->setEnabled(true);
}