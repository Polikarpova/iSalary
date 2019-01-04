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

void SalesPage::setUI( QTabWidget* tabWidget, QPushButton* salesForAllButton, QTableView* managersSalesTable, QTableView* unconfirmedSalesTable, QTableView* confirmedSalesTable)
{
	this->tabWidget = tabWidget;
	this->salesForAllButton = salesForAllButton;
	connect(this->salesForAllButton, &QPushButton::clicked, this, &SalesPage::buttonForAll);

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

	this->managersSalesTable->horizontalHeader()->setStretchLastSection( true);
	this->managersSalesTable->horizontalHeader()->setSectionResizeMode( 1, QHeaderView::ResizeToContents);
	this->managersSalesTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
	this->managersSalesTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
	this->managersSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->managersSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//скрытие поля с id
	this->managersSalesTable->setColumnHidden( ManagersSalesTableModel::COLUMN_ID, true);

	connect( this->managersSalesTable, &QTableView::clicked, this, &SalesPage::showManagersSales);
}

void SalesPage::initUnconfirmedSalesTable( QTableView* unconfirmedSalesTable) {

	this->unconfirmedSalesTable = unconfirmedSalesTable;
	auto model = new UnconfirmedSalesTableModel();
	this->unconfirmedSalesTable->setModel( model);

	this->unconfirmedSalesTable->horizontalHeader()->setStretchLastSection( true);
	
	this->unconfirmedSalesTable->horizontalHeader()->setSectionResizeMode( UnconfirmedSalesTableModel::COLUMN_FIO, QHeaderView::ResizeToContents);
	this->unconfirmedSalesTable->horizontalHeader()->setSectionResizeMode( UnconfirmedSalesTableModel::COLUMN_NAME, QHeaderView::ResizeToContents);
	this->unconfirmedSalesTable->horizontalHeader()->setSectionResizeMode( UnconfirmedSalesTableModel::COLUMN_COUNT, QHeaderView::ResizeToContents);
	this->unconfirmedSalesTable->horizontalHeader()->setSectionResizeMode( UnconfirmedSalesTableModel::COLUMN_PRICE, QHeaderView::ResizeToContents);
	this->unconfirmedSalesTable->horizontalHeader()->setSectionResizeMode( UnconfirmedSalesTableModel::COLUMN_COMMISION, QHeaderView::ResizeToContents);
	this->unconfirmedSalesTable->horizontalHeader()->setSectionResizeMode( UnconfirmedSalesTableModel::COLUMN_ACTION, QHeaderView::ResizeToContents);
	
	this->unconfirmedSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->unconfirmedSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//скрытие поля с id
	this->unconfirmedSalesTable->setColumnHidden( UnconfirmedSalesTableModel::COLUMN_ID, true);
}

void SalesPage::initConfirmedSalesTable( QTableView* confirmedSalesTable) {

	this->confirmedSalesTable = confirmedSalesTable;
	auto model = new ConfirmedSalesTableModel();
	this->confirmedSalesTable->setModel( model);

	this->confirmedSalesTable->horizontalHeader()->setStretchLastSection( true);
	this->confirmedSalesTable->horizontalHeader()->setSectionResizeMode( ConfirmedSalesTableModel::COLUMN_FIO, QHeaderView::ResizeToContents);
	this->confirmedSalesTable->horizontalHeader()->setSectionResizeMode( ConfirmedSalesTableModel::COLUMN_DATE, QHeaderView::ResizeToContents);
	this->confirmedSalesTable->horizontalHeader()->setSectionResizeMode( ConfirmedSalesTableModel::COLUMN_SALE_DATE, QHeaderView::ResizeToContents);
	this->confirmedSalesTable->horizontalHeader()->setSectionResizeMode( ConfirmedSalesTableModel::COLUMN_ACTION, QHeaderView::ResizeToContents);
	this->confirmedSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->confirmedSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//скрытие поля с id
	this->confirmedSalesTable->setColumnHidden( ConfirmedSalesTableModel::COLUMN_ID, true);
}


void SalesPage::updateManagersTable() {

	//получаем нужную инфу из фасада(бд)
	QList<ManagerActiveSalesStatisticDTO> list;

	try {
	
		list = this->salesFacade->getActiveSalesStatistic();
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

void SalesPage::updateUnconfirmedTable() {

	//получаем нужную инфу из фасада(бд)
	QList<ActiveSaleDTO> list;

	try {
	
		list = this->salesFacade->getActiveSales();
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}

	this->deleteConfirmSalesFromList( list);	//удаляем не нужные строки

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
	model->refreshData( list);
	this->addActionButtonsToUnconfirmedTable( model);

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

void SalesPage::updateConfirmedTable() {

	//получаем нужную инфу из фасада(бд)
	QList<ActiveSaleDTO> list;

	try {
	
		list = this->salesFacade->getActiveSales();
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}

	this->deleteUnconfirmSalesFromList( list);	//удаляем не нужные строки

	//если это были изменены данные (1), то необходимо получить текущую строчку
	//узнаем текущую строчку
	int currentId = this->getSelectedConfirmedSalesId();

	//чистим Qhash
	this->confirmedSales.clear();
	//заполняем его новыми данными из бд
	for ( auto i = list.begin(); i != list.end(); i++) {
	
		this->confirmedSales.insert( i->id, *i);
	}

	//инициализируем и заполняем модель
	ConfirmedSalesTableModel* model = static_cast<ConfirmedSalesTableModel*>( this->confirmedSalesTable->model());
	model->refreshData( list);
	this->addActionButtonsToConfirmedTable( model);

	//если это (1) пытаемся установить его текущим
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

	for( int i = 0; i != rowCount; i++) {

		QPushButton* btn = new QPushButton(QString::fromWCharArray( L"+"));
		btn->setProperty("saleId", model->getRecordId(i));
		connect( btn, &QPushButton::clicked, this, &SalesPage::confirmSale);
		this->unconfirmedSalesTable->setIndexWidget(model->index(i,UnconfirmedSalesTableModel::COLUMN_ACTION), btn);
	}
}

void SalesPage::addActionButtonsToConfirmedTable(ConfirmedSalesTableModel* model) {

	int rowCount = model->rowCount(QModelIndex());

	for( int i = 0; i != rowCount; i++) {

		QPushButton* btn = new QPushButton(QString::fromWCharArray( L"-"));
		btn->setProperty("saleId", model->getRecordId(i));
		connect( btn, &QPushButton::clicked, this, &SalesPage::unconfirmSale);
		this->confirmedSalesTable->setIndexWidget(model->index(i,ConfirmedSalesTableModel::COLUMN_ACTION), btn);
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

	//получаем нужную инфу из фасада(бд)
	QList<ActiveSaleDTO> list;

	try {
	
		list = this->salesFacade->getActiveSalesForManager(id);
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}

	this->deleteConfirmSalesFromList(list);	//удаляем не нужные строки

	//чистим Qhash
	this->unconfirmedSales.clear();
	//заполняем его новыми данными из бд
	for ( auto i = list.begin(); i != list.end(); i++) {
	
		this->unconfirmedSales.insert( i->id, *i);
	}

	//инициализируем и заполняем модель
	UnconfirmedSalesTableModel* model = static_cast<UnconfirmedSalesTableModel*>( this->unconfirmedSalesTable->model());
	model->refreshData( list);
	this->addActionButtonsToUnconfirmedTable( model);
}

void SalesPage::viewSelectedManagerConfirmedSales(int id) {

	//получаем нужную инфу из фасада(бд)
	QList<ActiveSaleDTO> list;

	try {
	
		list = this->salesFacade->getActiveSalesForManager(id);
	} catch( QString* error) {
	
		this->errorHandler->handleError( error);
	}

	this->deleteUnconfirmSalesFromList(list);	//удаляем не нужные строки

	//чистим Qhash
	this->confirmedSales.clear();
	//заполняем его новыми данными из бд
	for ( auto i = list.begin(); i != list.end(); i++) {
	
		this->confirmedSales.insert( i->id, *i);
	}

	//инициализируем и заполняем модель
	ConfirmedSalesTableModel* model = static_cast<ConfirmedSalesTableModel*>( this->confirmedSalesTable->model());
	model->refreshData( list);
	this->addActionButtonsToConfirmedTable( model);
}

void SalesPage::setEnable(bool flag) {

	this->tabWidget->setEnabled(flag);
}

void SalesPage::showManagerSales( int id) {
	
	QModelIndex index = static_cast<ManagersSalesTableModel*>(this->managersSalesTable->model())->getIndexByRecordId(id);
	this->managersSalesTable->setCurrentIndex( index);
	this->managersSalesTable->clicked( index);
}

//===SLOTS===//
void SalesPage::dateChanged() {

	//показываются продажи сделанные в определенный день
	//обновляем все таблицы в соответствии с датой
	this->refreshPage();
}

void SalesPage::buttonForAll() {

	//снять в таблицы выделение
	this->setEnable(false);
	
	this->managersSalesTable->clearSelection();
	this->refreshPage();
	
	this->setEnable(true);
}

void SalesPage::showManagersSales() {

	this->setEnable(false);

	//показываем в unconfirmed и confirmed только определенного пользователя
	int currentId = this->getSelectedManagerSalesId();

	this->viewSelectedManagerUnconfirmedSales( currentId);
	this->viewSelectedManagerConfirmedSales( currentId);

	this->setEnable(true);
}

void SalesPage::confirmSale() {

	this->setEnable(false);

	int currentId = sender()->property("saleId").toInt();
	this->salesFacade->confirmSale(this->unconfirmedSales[currentId]);
	this->refreshPage();

	this->setEnable(true);
}

void SalesPage::unconfirmSale() {

	this->setEnable(false);

	int currentId = sender()->property("saleId").toInt();
	this->salesFacade->cancelConfirmSale(this->confirmedSales[currentId]);
	this->refreshPage();

	this->setEnable(true);
}