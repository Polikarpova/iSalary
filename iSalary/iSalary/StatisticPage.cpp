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
	this->statisticTable = statisticTable;
	this->statisticSalesTable = statisticSalesTable;
	this->statisticCalendar = statisticCalendar;

	connect(this->statisticStartPeriod, &QDateEdit::dateChanged, this, &StatisticPage::startDateChanged);
	connect(this->statisticEndPeriod, &QDateEdit::dateChanged, this, &StatisticPage::endDateChanged);

	this->initStatisticTable(this->statisticTable);
	this->initStatisticSalesTable(this->statisticSalesTable);

	this->refreshPage();
}

void StatisticPage::initStatisticTable (QTableView* statisticTable) {

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
