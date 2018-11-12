#include "SalesPage.h"
#include <qmessagebox.h>
#include <qpushbutton.h>

SalesPage::SalesPage( SalesFacade * salesFacade){
    this->salesFacade = salesFacade;
}

SalesPage::~SalesPage( void) {
}

void SalesPage::refreshPage() {

	this->updateManagersTable();
	this->updateUnconfirmedTable();
	this->updateConfirmedTable();
}

void SalesPage::setErrorHandler( ErrorMessageHandler* errorHandler) {
    this->errorHandler = errorHandler;
}

void SalesPage::setUI( QDateEdit* salesDateInput, QTableView* managersSalesTable, QTableView* unconfirmedSalesTable, QTableView* confirmedSalesTable)
{
	this->salesDateInput = salesDateInput;
	this->salesDateInput->setDate(QDate::currentDate());
	connect(this->salesDateInput, &QDateEdit::dateChanged, this, &SalesPage::dateChanged);

	this->initManagersTable( managersSalesTable);
	this->initUnconfirmedSalesTable( unconfirmedSalesTable);
	this->initConfirmedSalesTable( confirmedSalesTable);

	this->refreshPage();
}

void SalesPage::initManagersTable( QTableView* managersSalesTable) {
	
	//��������� ������
	this->managersSalesTable = managersSalesTable;
	auto model = new ManagersSalesTableModel();
	this->managersSalesTable->setModel( model);

	this->managersSalesTable->horizontalHeader()->setStretchLastSection(true);
	this->managersSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->managersSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//������� ���� � id
	this->managersSalesTable->setColumnHidden( ManagersSalesTableModel::COLUMN_ID, true);

	connect( this->managersSalesTable, &QTableView::clicked, this, &SalesPage::showManagersSales);
}

void SalesPage::initUnconfirmedSalesTable( QTableView* unconfirmedSalesTable) {

	this->unconfirmedSalesTable = unconfirmedSalesTable;
	auto model = new UnconfirmedSalesTableModel();
	this->unconfirmedSalesTable->setModel( model);

	this->unconfirmedSalesTable->horizontalHeader()->setStretchLastSection(true);
	this->unconfirmedSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->unconfirmedSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//������� ���� � id
	this->unconfirmedSalesTable->setColumnHidden( UnconfirmedSalesTableModel::COLUMN_ID, true);
}

void SalesPage::initConfirmedSalesTable( QTableView* confirmedSalesTable) {

	this->confirmedSalesTable = confirmedSalesTable;
	auto model = new ConfirmedSalesTableModel();
	this->confirmedSalesTable->setModel( model);

	this->confirmedSalesTable->horizontalHeader()->setStretchLastSection(true);
	this->confirmedSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->confirmedSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//������� ���� � id
	this->confirmedSalesTable->setColumnHidden( ConfirmedSalesTableModel::COLUMN_ID, true);
}


void SalesPage::updateManagersTable() {

	//�������� ������ ���� �� ������(��)
	QList<ManagerActiveSalesStatisticDTO> list;

	try {
	
		list = this->salesFacade->getActiveSalesStatistic( this->salesDateInput->date() );
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}

	//���� ��� ���� �������� ������ (1), �� ���������� �������� ������� �������
	//������ ������� �������
	int currentId = this->getSelectedManagerSalesId();

	//������ Qhash
	this->managersSales.clear();
	//��������� ��� ������ ������� �� ��
	for ( auto iManager = list.begin(); iManager != list.end(); iManager++) {
	
		this->managersSales.insert( iManager->managerId, *iManager);
	}

	//�������������� � ��������� ������
	ManagersSalesTableModel* model = static_cast<ManagersSalesTableModel*>( this->managersSalesTable->model());
	model->refreshData( list);

	//���� ��� (1) �������� ���������� ��� �������
	if( currentId != -1) {
	
		QModelIndex index = model->getIndexByRecordId( currentId);
		if( index.isValid() ) {
		
			this->managersSalesTable->setCurrentIndex( index);
		}
	}
}

void SalesPage::updateUnconfirmedTable() {

	//�������� ������ ���� �� ������(��)
	QList<ActiveSaleDTO> list;

	try {
	
		list = this->salesFacade->getActiveSales();
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}

	this->deleteConfirmSalesFromList( list);	//������� �� ������ ������

	//���� ��� ���� �������� ������ (1), �� ���������� �������� ������� �������
	//������ ������� �������
	int currentId = this->getSelectedUnconfirmedSalesId();

	//������ Qhash
	this->unconfirmedSales.clear();
	//��������� ��� ������ ������� �� ��
	for ( auto i = list.begin(); i != list.end(); i++) {
	
		this->unconfirmedSales.insert( i->id, *i);
	}

	//�������������� � ��������� ������
	UnconfirmedSalesTableModel* model = static_cast<UnconfirmedSalesTableModel*>( this->unconfirmedSalesTable->model());
	model->refreshData( list);
	this->addActionButtonsToUnconfirmedTable( model);

	//���� ��� (1) �������� ���������� ��� �������
	if( currentId != -1) {
	
		QModelIndex index = model->getIndexByRecordId( currentId);
		if( index.isValid() ) {
		
			this->unconfirmedSalesTable->setCurrentIndex( index);
		}
	}
}

void SalesPage::deleteConfirmSalesFromList( QList<ActiveSaleDTO>& list) {

	QMutableListIterator<ActiveSaleDTO> i(list);

	i.toBack();

	while (i.hasPrevious()) {
		if (i.previous().isConfirm) {
		
			i.remove();
		}
	}
}

void SalesPage::updateConfirmedTable() {

	//�������� ������ ���� �� ������(��)
	QList<ActiveSaleDTO> list;

	try {
	
		list = this->salesFacade->getActiveSales();
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}

	this->deleteUnconfirmSalesFromList( list);	//������� �� ������ ������

	//���� ��� ���� �������� ������ (1), �� ���������� �������� ������� �������
	//������ ������� �������
	int currentId = this->getSelectedConfirmedSalesId();

	//������ Qhash
	this->confirmedSales.clear();
	//��������� ��� ������ ������� �� ��
	for ( auto i = list.begin(); i != list.end(); i++) {
	
		this->confirmedSales.insert( i->id, *i);
	}

	//�������������� � ��������� ������
	ConfirmedSalesTableModel* model = static_cast<ConfirmedSalesTableModel*>( this->confirmedSalesTable->model());
	model->refreshData( list);
	this->addActionButtonsToConfirmedTable( model);

	//���� ��� (1) �������� ���������� ��� �������
	if( currentId != -1) {
	
		QModelIndex index = model->getIndexByRecordId( currentId);
		if( index.isValid() ) {
		
			this->confirmedSalesTable->setCurrentIndex( index);
		}
	}
}

void SalesPage::deleteUnconfirmSalesFromList( QList<ActiveSaleDTO>& list) {

	QMutableListIterator<ActiveSaleDTO> i(list);

	i.toBack();

	while (i.hasPrevious()) {
		if (!i.previous().isConfirm) {
		
			i.remove();
		}
	}
}


//===PRIVATE===//
void SalesPage::addActionButtonsToUnconfirmedTable(UnconfirmedSalesTableModel* model) {

	int rowCount = model->rowCount(QModelIndex());
	int lastColumn = model->columnCount(QModelIndex()) - 1;

	for( int i = 0; i != rowCount; i++) {

		QPushButton* btn = new QPushButton(QString::fromWCharArray( L"�����������"));
		btn->setProperty("saleId", model->getRecordId(i));
		connect( btn, &QPushButton::clicked, this, &SalesPage::confirmSale);
		this->unconfirmedSalesTable->setIndexWidget(model->index(i,lastColumn), btn);
	}
}

void SalesPage::addActionButtonsToConfirmedTable(ConfirmedSalesTableModel* model) {

	int rowCount = model->rowCount(QModelIndex());
	int lastColumn = model->columnCount(QModelIndex()) - 1;

	for( int i = 0; i != rowCount; i++) {

		QPushButton* btn = new QPushButton(QString::fromWCharArray( L"������"));
		btn->setProperty("saleId", model->getRecordId(i));
		connect( btn, &QPushButton::clicked, this, &SalesPage::unconfirmSale);
		this->confirmedSalesTable->setIndexWidget(model->index(i,lastColumn), btn);
	}
}

int SalesPage::getSelectedManagerSalesId() {

	auto model = static_cast<ManagersSalesTableModel*>( this->managersSalesTable->model());
	return model->getRecordId( this->managersSalesTable->currentIndex().row());
}

int SalesPage::getSelectedUnconfirmedSalesId() {

	auto model = static_cast<UnconfirmedSalesTableModel*>( this->unconfirmedSalesTable->model());
	return model->getRecordId( this->unconfirmedSalesTable->currentIndex().row());
}

int SalesPage::getSelectedConfirmedSalesId() {

	auto model = static_cast<ConfirmedSalesTableModel*>( this->confirmedSalesTable->model());
	return model->getRecordId( this->confirmedSalesTable->currentIndex().row());
}

void SalesPage::viewSelectedManagerUnconfirmedSales(int id) {

	//�������� ������ ���� �� ������(��)
	QList<ActiveSaleDTO> list;

	try {
	
		list = this->salesFacade->getActiveSalesForManager(id);
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}

	this->deleteConfirmSalesFromList(list);	//������� �� ������ ������

	//������ Qhash
	this->unconfirmedSales.clear();
	//��������� ��� ������ ������� �� ��
	for ( auto i = list.begin(); i != list.end(); i++) {
	
		this->unconfirmedSales.insert( i->id, *i);
	}

	//�������������� � ��������� ������
	UnconfirmedSalesTableModel* model = static_cast<UnconfirmedSalesTableModel*>( this->unconfirmedSalesTable->model());
	model->refreshData( list);
	this->addActionButtonsToUnconfirmedTable( model);
}

void SalesPage::viewSelectedManagerConfirmedSales(int id) {

	//�������� ������ ���� �� ������(��)
	QList<ActiveSaleDTO> list;

	try {
	
		list = this->salesFacade->getActiveSalesForManager(id);
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}

	this->deleteUnconfirmSalesFromList(list);	//������� �� ������ ������

	//������ Qhash
	this->confirmedSales.clear();
	//��������� ��� ������ ������� �� ��
	for ( auto i = list.begin(); i != list.end(); i++) {
	
		this->confirmedSales.insert( i->id, *i);
	}

	//�������������� � ��������� ������
	ConfirmedSalesTableModel* model = static_cast<ConfirmedSalesTableModel*>( this->confirmedSalesTable->model());
	model->refreshData( list);
	this->addActionButtonsToConfirmedTable( model);
}

//===SLOTS===//
void SalesPage::dateChanged() {

	//��������� ��� ������� � ������������ � �����
	this->refreshPage();
}

void SalesPage::showManagersSales() {

	//���������� � unconfirmed � confirmed ������ ������������� ������������
	int currentId = this->getSelectedManagerSalesId();

	this->viewSelectedManagerUnconfirmedSales( currentId);
	this->viewSelectedManagerConfirmedSales( currentId);
}

void SalesPage::confirmSale() {

	int currentId = sender()->property("saleId").toInt();
	this->salesFacade->confirmSale(this->unconfirmedSales[currentId]);
	this->refreshPage();
}

void SalesPage::unconfirmSale() {

	int currentId = sender()->property("saleId").toInt();
	this->salesFacade->cancelConfirmSale(this->confirmedSales[currentId]);
	this->refreshPage();
}