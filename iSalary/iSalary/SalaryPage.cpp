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
}

void SalaryPage::setErrorHandler( ErrorMessageHandler* errorHandler) {
    this->errorHandler = errorHandler;
}

void SalaryPage::setUI( QComboBox* salaryAccountingPeriod, QTableView* salaryTable, QTableView* salaryTotalTable, QLabel* managerFIOLabel, QSpinBox* salaryPasportSeries,
				QSpinBox* salaryPasportNumber, QLineEdit* salaryPasportSourse, QDateEdit* salaryDateOfReceipt, QRadioButton* salaryMaleRButton, QRadioButton* salaryFemaleRButton,
				QLineEdit* salaryINN, QPushButton* closeAccountingPeriod, QPushButton* salesButton, QPushButton* dataButton) {
 
	this->salaryAccountingPeriod = salaryAccountingPeriod; 
	this->initComboBox();

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
	//���������������� ����� (�������� �����������)

	this->closeAccountingPeriod = closeAccountingPeriod;
	this->closeAccountingPeriod->hide();

	//�������������� ��������
	this->initSalaryTable( salaryTable); 
	this->initSalaryTotalTable( salaryTotalTable); 
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
		
			str += QDate::currentDate().toString(Qt::ISODate);
		} else {
		
			str += i.value().dateTo.toString(Qt::ISODate);
		}

		this->salaryAccountingPeriod->addItem(str);
		this->comboBoxMap.insert(k, i.value().id);
		k++;
	}

	connect(this->salaryAccountingPeriod, SIGNAL(currentIndexChanged(int)), this, SLOT(showSelectedPeriod()));

	this->salaryAccountingPeriod->setCurrentIndex(0);
}

void SalaryPage::initSalaryTable (QTableView* salaryTable) {
	
	//��������� ������
	this->salaryTable = salaryTable;
	auto model = new SalaryTableModel();
	this->salaryTable->setModel( model);

	this->salaryTable->horizontalHeader()->setStretchLastSection(true);
	this->salaryTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->salaryTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//������� ���� � id
	//this->salaryTable->setColumnHidden( SalaryTableModel::COLUMN_ID, true);

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

//====SLOTS====//
void SalaryPage::showManager() {

	//��������� ���� � �����
	//��������� ��������� property, ���� ��������������, �� �� 1�� ����� �� �� �� ������
	QMessageBox::information(0, QString::fromWCharArray(L"��������"), QString::fromWCharArray(L"��������� ���� � ��������� ������"));
}

void SalaryPage::showSelectedPeriod() {
	
	QMessageBox::information(0, QString::fromWCharArray(L"�������"), QString::fromWCharArray(L"��������� ������� ��� ���������� ��"));
}