#include "SalaryPage.h"

SalaryPage::SalaryPage( SalesFacade * salesFacade, PersonnalAccountingFacade* personnalAccountingFacade){
    this->salesFacade = salesFacade;
	this->personnalAccountingFacade = personnalAccountingFacade;
}

SalaryPage::~SalaryPage( void) {
}

void SalaryPage::refreshPage() {

	//обновление таблиц
	this->updatePeriods();

	//очищение виджетов(?)
}

void SalaryPage::setErrorHandler( ErrorMessageHandler* errorHandler) {
    this->errorHandler = errorHandler;
}

void SalaryPage::setTabNavigator(TabNavigator* tabNavigator) {
	this->tabNav = tabNavigator;
}

void SalaryPage::setUI( QTabWidget* tabWidget, QComboBox* salaryAccountingPeriod, QTableView* salaryTable, QTableView* salaryTotalTable, QLabel* managerFIOLabel, QSpinBox* salaryPasportSeries,
				QSpinBox* salaryPasportNumber, QLineEdit* salaryPasportSourse, QDateEdit* salaryDateOfReceipt, QRadioButton* salaryMaleRButton, QRadioButton* salaryFemaleRButton,
				QLineEdit* salaryINN, QPushButton* closeAccountingPeriod, QPushButton* salesButton, QPushButton* dataButton) {
 
	this->tabWidget = tabWidget;
	this->salaryAccountingPeriod = salaryAccountingPeriod; 

	this->managerFIOLabel = managerFIOLabel; 
	this->salaryPasportSeries = salaryPasportSeries; 
	this->salaryPasportNumber = salaryPasportNumber;
	this->salaryPasportSourse = salaryPasportSourse;
	this->salaryDateOfReceipt = salaryDateOfReceipt;
	this->salaryMaleRButton = salaryMaleRButton;
	this->salaryFemaleRButton = salaryFemaleRButton;
	this->salaryINN = salaryINN;
	this->salesButton = salesButton;
	this->dataButton = dataButton;
	this->initManagerForm();

	this->closeAccountingPeriod = closeAccountingPeriod;
	this->closeAccountingPeriod->hide();

	//инициализируем таблички
	this->initSalaryTable( salaryTable); 
	this->initSalaryTotalTable( salaryTotalTable); 

	//инициализируем выпадающий список
	this->initComboBox();
 }

void SalaryPage::initComboBox() {
	
	connect(this->salaryAccountingPeriod, SIGNAL(currentIndexChanged(int)), this, SLOT(showSelectedPeriod()));

	this->updatePeriods();
}

void SalaryPage::initManagerForm() {

	this->managerFIOLabel->setText("");
	this->dataButton->setEnabled(false);
	this->salesButton->setEnabled(false);

	connect(this->dataButton, SIGNAL(clicked(bool)), this, SLOT(showManagerInformation()));
	connect(this->salesButton, SIGNAL(clicked(bool)), this, SLOT(showManagerSales()));
}

void SalaryPage::initSalaryTable (QTableView* salaryTable) {
	
	//настройки таблиц
	this->salaryTable = salaryTable;
	auto model = new SalaryTableModel();
	this->salaryTable->setModel( model);

	this->salaryTable->horizontalHeader()->setStretchLastSection(true);
	this->salaryTable->horizontalHeader()->setSectionResizeMode( SalaryTableModel::COLUMN_FIO, QHeaderView::ResizeToContents);
	this->salaryTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->salaryTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//скрытие поля с id
	this->salaryTable->setColumnHidden( SalaryTableModel::COLUMN_ID, true);

	connect( this->salaryTable, &QTableView::clicked, this, &SalaryPage::showManager);
}

void SalaryPage::initSalaryTotalTable (QTableView* salaryTotalTable) {
	
	//настройки таблиц
	this->salaryTotalTable = salaryTotalTable;
	auto model = new SalaryTotalTableModel();
	this->salaryTotalTable->setModel( model);

	this->salaryTotalTable->horizontalHeader()->setStretchLastSection(true);
	this->salaryTotalTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->salaryTotalTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//скрытие поля с id
	this->salaryTotalTable->setColumnHidden( SalaryTotalTableModel::COLUMN_ID, true);
}

int SalaryPage::getSelectedManagerId() {

	auto model = static_cast<SalaryTableModel*>( this->salaryTable->model());
	return model->getRecordId( this->salaryTable->currentIndex().row());
}

void SalaryPage::updatePeriods() {

	this->salaryAccountingPeriod->clear();
	this->comboBoxMap.clear();

	QList<AccoutingPeriodDTO> list = this->salesFacade->getAllAccoutingPeriods();

	QMutableListIterator<AccoutingPeriodDTO> i(list);
	i.toBack();
	int k = 0;
	while (i.hasPrevious()) {
		i.previous();
		QString str = "C " + i.value().dateFrom.toString(Qt::ISODate) + QString::fromWCharArray( L" по ");

		if ( i.value().dateTo.isNull() ) {
		
			str += QDate::currentDate().toString(Qt::ISODate) + QString::fromWCharArray( L" {текущий}");
		} else {
		
			str += i.value().dateTo.toString(Qt::ISODate);
		}

		this->salaryAccountingPeriod->addItem(str);
		this->comboBoxMap.insert(k, i.value());
		k++;
	}

	this->salaryAccountingPeriod->setCurrentIndex(0);

	this->showSelectedPeriod();
}

void SalaryPage::setEnable(bool flag){

	this->tabWidget->setEnabled(flag);
}

//====SLOTS====//
void SalaryPage::showManager() {

	this->setEnable(false);

	ManagerDTO m;

	try {
	
		int id = this->getSelectedManagerId();
		m = this->salesFacade->getManagerInfo( id);
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}

	this->managerFIOLabel->setText( m.secondName + " " + m.firstName + " " + m.thirdName );
	this->salaryPasportSeries->setValue( m.passportSerial.toInt());
	this->salaryPasportNumber->setValue( m.passportNumber.toInt());
	this->salaryPasportSourse->setText( m.passportSource);
	this->salaryDateOfReceipt->setDate( m.passportIssueDate);
	if( m.sex == MALE) {
        this->salaryMaleRButton->setChecked( true);
    } else if( m.sex == FEMALE) {
		this->salaryFemaleRButton->setChecked( true);
    }
	this->salaryINN->setText( m.INN);

	this->dataButton->setEnabled(true);
	this->salesButton->setEnabled(true);
	this->dataButton->setProperty("id", m.id);
	this->salesButton->setProperty("id", m.id);

	this->setEnable(true);
}

void SalaryPage::showSelectedPeriod() {
	
	this->setEnable(false);

	//получаем нужную инфу из фасада(бд)
	QList<ManagerSalaryDTO> list;

	int currentPeriod = this->salaryAccountingPeriod->currentIndex();
	QDate from = this->comboBoxMap[currentPeriod].dateFrom;
	QDate to = this->comboBoxMap[currentPeriod].dateTo;

	try {
	
		list = this->salesFacade->getManagersSalary( from, to);
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}

	//чистим Qhash
	this->salary.clear();
	//заполняем его новыми данными из бд
	for ( auto i = list.begin(); i != list.end(); i++) {
	
		this->salary.insert( i->managerId, *i);
	}

	//инициализируем и заполняем модели
	SalaryTableModel* model = static_cast<SalaryTableModel*>( this->salaryTable->model());
	model->refreshData( list);

	SalaryTotalTableModel* modelTotal = static_cast<SalaryTotalTableModel*>( this->salaryTotalTable->model());
	modelTotal->refreshData( list);

	this->setEnable(true);
}

void SalaryPage::showManagerInformation() {

	this->setEnable(false);

	int id = this->dataButton->property("id").toInt();
	this->tabNav->openEmployeesPage( id);

	this->setEnable(true);
}

void SalaryPage::showManagerSales() {

	this->setEnable(false);

	int id = this->salesButton->property("id").toInt();
	this->tabNav->openSalesPage( id);

	this->setEnable(true);
}