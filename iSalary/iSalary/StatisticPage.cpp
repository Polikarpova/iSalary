#include "StatisticPage.h"

StatisticPage::StatisticPage( SalesFacade * salesFacade){
    this->salesFacade = salesFacade;
}

StatisticPage::~StatisticPage( void) {
}

void StatisticPage::refreshPage() {

	this->updateStatisticTable();
	this->updateStatisticSalesTable();
}

void StatisticPage::setErrorHandler( ErrorMessageHandler* errorHandler) {
    this->errorHandler = errorHandler;
}

void StatisticPage::setUI( QTabWidget* tabWidget, QDateEdit* statisticMonth, QTableView* statisticTable, QTableView* statisticSalesTable, QCalendarWidget* statisticCalendar ) {

	this->tabWidget = tabWidget;
	this->statisticMonth = statisticMonth;
	this->statisticCalendar = statisticCalendar;

	this->statisticMonth->setDate( QDate::currentDate() );
	connect(this->statisticMonth, &QDateEdit::dateChanged, this, &StatisticPage::monthChanged);

	this->initStatisticTable(statisticTable);
	this->initStatisticSalesTable(statisticSalesTable);

	this->refreshPage();
}

void StatisticPage::initStatisticTable (QTableView* statisticTable) {

	this->statisticTable = statisticTable;
	auto model = new StatisticTableModel();
	this->statisticTable->setModel( model);

	this->statisticTable->horizontalHeader()->setStretchLastSection( true);
	this->statisticTable->horizontalHeader()->setSectionResizeMode( StatisticTableModel::COLUMN_FIO, QHeaderView::ResizeToContents);
	this->statisticTable->horizontalHeader()->setSectionResizeMode( StatisticTableModel::COLUMN_SALES_COUNT, QHeaderView::ResizeToContents);
	this->statisticTable->horizontalHeader()->setSectionResizeMode( StatisticTableModel::COLUMN_INCOME, QHeaderView::ResizeToContents);
	this->statisticTable->horizontalHeader()->setSectionResizeMode( StatisticTableModel::COLUMN_LET, QHeaderView::ResizeToContents);
	this->statisticTable->horizontalHeader()->setSectionResizeMode( StatisticTableModel::COLUMN_OET, QHeaderView::ResizeToContents);
	this->statisticTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->statisticTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//скрытие поля с id
	this->statisticTable->setColumnHidden( StatisticTableModel::COLUMN_ID, true);

	connect( this->statisticTable, &QTableView::clicked, this, &StatisticPage::showManagersStatistic);
}

void StatisticPage::initStatisticSalesTable( QTableView* statisticSalesTable) {

	this->statisticSalesTable = statisticSalesTable;
	auto model = new StatisticSalesTableModel();
	this->statisticSalesTable->setModel( model);

	this->statisticSalesTable->horizontalHeader()->setStretchLastSection( true);
	this->statisticSalesTable->horizontalHeader()->setSectionResizeMode( StatisticSalesTableModel::COLUMN_FIO, QHeaderView::ResizeToContents);
	this->statisticSalesTable->horizontalHeader()->setSectionResizeMode( StatisticSalesTableModel::COLUMN_SALE_DATE, QHeaderView::ResizeToContents);
	this->statisticSalesTable->horizontalHeader()->setSectionResizeMode( StatisticSalesTableModel::COLUMN_COUNT, QHeaderView::ResizeToContents);
	this->statisticSalesTable->horizontalHeader()->setSectionResizeMode( StatisticSalesTableModel::COLUMN_NAME, QHeaderView::ResizeToContents);
	this->statisticSalesTable->horizontalHeader()->setSectionResizeMode( StatisticSalesTableModel::COLUMN_PRICE, QHeaderView::ResizeToContents);
	this->statisticSalesTable->horizontalHeader()->setSectionResizeMode( StatisticSalesTableModel::COLUMN_COMMISION, QHeaderView::ResizeToContents);
	this->statisticSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->statisticSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//скрытие поля с id
	//this->statisticTable->setColumnHidden( StatisticTableModel::COLUMN_ID, true);
}

void StatisticPage::updateStatisticTable() {

	QList<ManagerStatisticDTO> list;

	try {
		QDate current( statisticMonth->date() );
		QDate dateFrom( current.year(), current.month(), 1 );
		QDate dateTo( current.year(), current.month(), current.daysInMonth() );
		list = this->salesFacade->getManagersStatistic( dateFrom, dateTo);
	} catch ( QString* error) {
	
	}

	//чистим Qhash
	this->managerStatistic.clear();
	//заполняем его новыми данными из бд
	for ( auto i = list.begin(); i != list.end(); i++) {
	
		this->managerStatistic.insert( i->managerId, *i);
	}

	//инициализируем и заполняем модель
	StatisticTableModel* model = static_cast<StatisticTableModel*>( this->statisticTable->model());
	model->refreshData( list);
}

void StatisticPage::updateStatisticSalesTable() {

}

//===SLOTS===//
void StatisticPage::monthChanged() {

	this->refreshPage();
	this->statisticCalendar->setCurrentPage( this->statisticMonth->date().year(), this->statisticMonth->date().month() );
}

void StatisticPage::showManagersStatistic() {
	QMessageBox::information(0, "statistic", "show manager statistic");
}
