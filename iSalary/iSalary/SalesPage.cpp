#include "SalesPage.h"
#include <qmessagebox.h>

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
	
	//настройки таблиц
	this->managersSalesTable = managersSalesTable;
	auto model = new ManagersSalesTableModel();
	this->managersSalesTable->setModel( model);

	this->managersSalesTable->horizontalHeader()->setStretchLastSection(true);
	this->managersSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->managersSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//скрытие поля с id
	//this->managersSalesTable->setColumnHidden( ManagersSalesTableModel::COLUMN_ID, true);

	//connect( this->managersSalesTable, &QTableView::clicked, this, &EmployeesPage::showDetails);
}

void SalesPage::initUnconfirmedSalesTable( QTableView* unconfirmedSalesTable) {

	this->unconfirmedSalesTable = unconfirmedSalesTable;
	auto model = new UnconfirmedSalesTableModel();
	this->unconfirmedSalesTable->setModel( model);

	this->unconfirmedSalesTable->horizontalHeader()->setStretchLastSection(true);
	this->unconfirmedSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->unconfirmedSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//скрытие поля с id
	//this->unconfirmedSalesTable->setColumnHidden( UnconfirmedSalesTableModel::COLUMN_ID, true);

	//connect( this->unconfirmedSalesTable, &QTableView::clicked, this, &EmployeesPage::showDetails);
}

void SalesPage::initConfirmedSalesTable( QTableView* confirmedSalesTable) {

	this->confirmedSalesTable = confirmedSalesTable;
}

void SalesPage::updateManagersTable() {

	//получаем нужную инфу из фасада(бд)
	QList<ManagerActiveSalesStatisticDTO> list;

	try {
	
		list = this->salesFacade->getActiveSalesStatistic( this->salesDateInput->date() );
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}


	//если это были изменены данные (1), то необходимо получить текущую строчку
	//узнаем текущую строчку
	int currentId = this->getSelectedManagerSalesId();

	//чистим Qhash
	this->managersSales.clear();
	//заполняем его новыми данными из бд
	for ( auto iManager = list.begin(); iManager != list.end(); iManager++) {
	
		this->managersSales.insert( iManager->managerId, *iManager);
	}

	//инициализируем и заполняем модель
	ManagersSalesTableModel* model = static_cast<ManagersSalesTableModel*>( this->managersSalesTable->model());
	model->refreshData( list);

	//если это (1) пытаемся установить его текущим
	if( currentId != -1) {
	
		QModelIndex index = model->getIndexByRecordId( currentId);
		if( index.isValid() ) {
		
			this->managersSalesTable->setCurrentIndex( index);
		}
	}
}

void SalesPage::updateConfirmedTable() {

	//получаем нужную инфу из фасада(бд)
	QList<ActiveSaleDTO> list;

	try {
	
		list = this->salesFacade->getActiveSales();
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}


	//если это были изменены данные (1), то необходимо получить текущую строчку
	//узнаем текущую строчку
	int currentId = this->getSelectedUnconfirmedSalesId();

	//чистим Qhash
	this->unconfirmedSales.clear();
	//заполняем его новыми данными из бд
	for ( auto i = list.begin(); i != list.end(); i++) {
	
		this->unconfirmedSales.insert( i->id, *i);
	}

	//инициализируем и заполняем модель
	UnconfirmedSalesTableModel* model = static_cast<UnconfirmedSalesTableModel*>( this->unconfirmedSalesTable->model());
	this->deleteConfirmSalesFromList(list);	//удаляем не нужные строки
	model->refreshData( list);

	//если это (1) пытаемся установить его текущим
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

void SalesPage::updateUnconfirmedTable() {

}

int SalesPage::getSelectedManagerSalesId() {

	auto model = static_cast<ManagersSalesTableModel*>( this->managersSalesTable->model());
	return model->getRecordId( this->managersSalesTable->currentIndex().row());
}

int SalesPage::getSelectedUnconfirmedSalesId() {

	auto model = static_cast<UnconfirmedSalesTableModel*>( this->unconfirmedSalesTable->model());
	return model->getRecordId( this->unconfirmedSalesTable->currentIndex().row());
}

//===SLOTS===//
void SalesPage::dateChanged() {

	//обновляем все таблицы в соответствии с датой
	//QMessageBox::information( 0, toUnicode("Дата изменилась"), toUnicode("Вы выбрали эту дату: ") + this->salesDateInput->date().toString() ); //debug

	this->updateManagersTable();
}