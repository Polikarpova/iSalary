#include "SalaryPage.h"

SalaryPage::SalaryPage( SalesFacade * salesFacade, PersonnalAccountingFacade* personnalAccountingFacade){
    this->salesFacade = salesFacade;
	this->personnalAccountingFacade = personnalAccountingFacade;
}

SalaryPage::~SalaryPage( void) {
}

void SalaryPage::refreshPage() {

	//���������� ������
	//�������� ��������(?)
	this->showSelectedPeriod();
}

void SalaryPage::setErrorHandler( ErrorMessageHandler* errorHandler) {
    this->errorHandler = errorHandler;
}

void SalaryPage::setUI( QComboBox* salaryAccountingPeriod, QTableView* salaryTable, QTableView* salaryTotalTable, QLabel* managerFIOLabel, QSpinBox* salaryPasportSeries,
				QSpinBox* salaryPasportNumber, QLineEdit* salaryPasportSourse, QDateEdit* salaryDateOfReceipt, QRadioButton* salaryMaleRButton, QRadioButton* salaryFemaleRButton,
				QLineEdit* salaryINN, QPushButton* closeAccountingPeriod, QPushButton* salesButton, QPushButton* dataButton) {
 
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

	//�������������� ��������
	this->initSalaryTable( salaryTable); 
	this->initSalaryTotalTable( salaryTotalTable); 

	//�������������� ���������� ������
	this->initComboBox();
 }

void SalaryPage::initComboBox() {

	QList<AccoutingPeriodDTO> list = this->salesFacade->getAllAccoutingPeriods();

	QMutableListIterator<AccoutingPeriodDTO> i(list);
	i.toBack();
	int k = 0;
	while (i.hasPrevious()) {
		i.previous();
		QString str = "C " + i.value().dateFrom.toString(Qt::ISODate) + QString::fromWCharArray( L" �� ");

		if ( i.value().dateTo.isNull() ) {
		
			str += QDate::currentDate().toString(Qt::ISODate) + QString::fromWCharArray( L" {�������}");
		} else {
		
			str += i.value().dateTo.toString(Qt::ISODate);
		}

		this->salaryAccountingPeriod->addItem(str);
		this->comboBoxMap.insert(k, i.value());
		k++;
	}

	connect(this->salaryAccountingPeriod, SIGNAL(currentIndexChanged(int)), this, SLOT(showSelectedPeriod()));

	this->salaryAccountingPeriod->setCurrentIndex(0);

	this->showSelectedPeriod();
}

void SalaryPage::initManagerForm() {

	this->managerFIOLabel->setText("");

	//��������� ������ �� 1�� �����
	this->salesButton->hide();
	this->dataButton->hide();
}

void SalaryPage::initSalaryTable (QTableView* salaryTable) {
	
	//��������� ������
	this->salaryTable = salaryTable;
	auto model = new SalaryTableModel();
	this->salaryTable->setModel( model);

	this->salaryTable->horizontalHeader()->setStretchLastSection(true);
	this->salaryTable->horizontalHeader()->setSectionResizeMode( SalaryTableModel::COLUMN_FIO, QHeaderView::ResizeToContents);
	this->salaryTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->salaryTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//������� ���� � id
	this->salaryTable->setColumnHidden( SalaryTableModel::COLUMN_ID, true);

	connect( this->salaryTable, &QTableView::clicked, this, &SalaryPage::showManager);
}

void SalaryPage::initSalaryTotalTable (QTableView* salaryTotalTable) {
	
	//��������� ������
	this->salaryTotalTable = salaryTotalTable;
	auto model = new SalaryTotalTableModel();
	this->salaryTotalTable->setModel( model);

	this->salaryTotalTable->horizontalHeader()->setStretchLastSection(true);
	this->salaryTotalTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->salaryTotalTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//������� ���� � id
	this->salaryTotalTable->setColumnHidden( SalaryTotalTableModel::COLUMN_ID, true);
}

int SalaryPage::getSelectedManagerId() {

	auto model = static_cast<SalaryTableModel*>( this->salaryTable->model());
	return model->getRecordId( this->salaryTable->currentIndex().row());
}

//====SLOTS====//
void SalaryPage::showManager() {

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

	//��������� ��������� property, ���� ��������������, �� �� 1�� ����� �� �� �� ������
}

void SalaryPage::showSelectedPeriod() {
	
	//�������� ������ ���� �� ������(��)
	QList<ManagerSalaryDTO> list;

	int currentPeriod = this->salaryAccountingPeriod->currentIndex();
	QDate from = this->comboBoxMap[currentPeriod].dateFrom;
	QDate to = this->comboBoxMap[currentPeriod].dateTo;

	try {
	
		list = this->salesFacade->getManagersSalary( from, to);
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}

	//������ Qhash
	this->salary.clear();
	//��������� ��� ������ ������� �� ��
	for ( auto i = list.begin(); i != list.end(); i++) {
	
		this->salary.insert( i->managerId, *i);
	}

	//�������������� � ��������� ������
	SalaryTableModel* model = static_cast<SalaryTableModel*>( this->salaryTable->model());
	model->refreshData( list);

	SalaryTotalTableModel* modelTotal = static_cast<SalaryTotalTableModel*>( this->salaryTotalTable->model());
	modelTotal->refreshData( list);
}