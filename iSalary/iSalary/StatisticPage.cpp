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

void StatisticPage::setUI( QTabWidget* tabWidget, QDateEdit* statisticStartPeriod, QDateEdit* statisticEndPeriod, QTableView* statisticTable, QTableView* statisticSalesTable, QCalendarWidget* statisticCalendar ) {

	this->tabWidget = tabWidget;
	this->statisticStartPeriod = statisticStartPeriod;
	this->statisticEndPeriod = statisticEndPeriod;
	this->statisticSalesTable = statisticSalesTable;
	this->statisticCalendar = statisticCalendar;

	this->initStatisticTable(this->statisticTable);
	this->initStatisticSalesTable(this->statisticSalesTable);

	connect(this->statisticStartPeriod, &QDateEdit::dateChanged, this, &StatisticPage::startDateChanged);
	connect(this->statisticEndPeriod, &QDateEdit::dateChanged, this, &StatisticPage::endDateChanged);

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
	//this->statisticTable->setColumnHidden( StatisticTableModel::COLUMN_ID, true);

	connect( this->statisticTable, &QTableView::clicked, this, &StatisticPage::showManagersStatistic);
}

void StatisticPage::initStatisticSalesTable( QTableView* statisticSalesTable) {

}

void StatisticPage::updateStatisticTable() {

}

void StatisticPage::updateStatisticSalesTable() {

}

//===SLOTS===//
void StatisticPage::startDateChanged() {

}

void StatisticPage::endDateChanged() {

	//проверка на то, чтобы дата не была раньше или равна дате, установленной в statisticStartPeriod
	//в противном случае устанавливаем на дату statisticStartPeriod + 1 день
}

void showManagersStatistic() {

}
