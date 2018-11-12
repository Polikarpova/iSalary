#include "SalaryPage.h"

SalaryPage::SalaryPage( SalesFacade * salesFacade, PersonnalAccountingFacade* personnalAccountingFacade){
    this->salesFacade = salesFacade;
	this->personnalAccountingFacade = personnalAccountingFacade;
}

SalaryPage::~SalaryPage( void) {

}

void SalaryPage::refreshPage() {

	//обновление таблиц
	//очищение виджетов(?)
}

void SalaryPage::setErrorHandler( ErrorMessageHandler* errorHandler) {
    this->errorHandler = errorHandler;
}

 void SalaryPage::setUI( QComboBox* salaryAccountingPeriod, QTableView* salaryTable, QTableView* salaryTotalTable, QLabel* managerFIOLabel, QSpinBox* salaryPasportSeries,
				QSpinBox* salaryPasportNumber, QLineEdit* salaryPasportSourse, QDateEdit* salaryDateOfReceipt, QRadioButton* salaryMaleRButton, QRadioButton* salaryFemaleRButton,
				QLineEdit* salaryINN, QPushButton* closeAccountingPeriod, QPushButton* salesButton, QPushButton* dataButton) {
 
	this->salaryAccountingPeriod = salaryAccountingPeriod; 
	//инициализировать комбобокс

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
	//инифиализировать форму

	this->closeAccountingPeriod = closeAccountingPeriod;
	//инициализировать кнопку

	//инициализируем таблички
	this->initSalaryTable( salaryTable); 
	this->initSalaryTotalTable( salaryTotalTable); 
 }

 void SalaryPage::initSalaryTable (QTableView* salaryTable) {
	
	////настройки таблиц
	//this->managersSalesTable = managersSalesTable;
	//auto model = new ManagersSalesTableModel();
	//this->managersSalesTable->setModel( model);

	//this->managersSalesTable->horizontalHeader()->setStretchLastSection(true);
	//this->managersSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	//this->managersSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);

	////скрытие поля с id
	//this->managersSalesTable->setColumnHidden( ManagersSalesTableModel::COLUMN_ID, true);

	//connect( this->managersSalesTable, &QTableView::clicked, this, &SalesPage::showManagersSales);
}

 void SalaryPage::initSalaryTotalTable (QTableView* salaryTotalTable) {
	
	////настройки таблиц
	//this->managersSalesTable = managersSalesTable;
	//auto model = new ManagersSalesTableModel();
	//this->managersSalesTable->setModel( model);

	//this->managersSalesTable->horizontalHeader()->setStretchLastSection(true);
	//this->managersSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	//this->managersSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);

	////скрытие поля с id
	//this->managersSalesTable->setColumnHidden( ManagersSalesTableModel::COLUMN_ID, true);

	//connect( this->managersSalesTable, &QTableView::clicked, this, &SalesPage::showManagersSales);
}