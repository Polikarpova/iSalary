#include "SalesPage.h"
#include <qmessagebox.h>

SalesPage::SalesPage( SalesFacade * salesFacade){
    this->salesFacade = salesFacade;
}

SalesPage::~SalesPage( void) {
}

void SalesPage::setUI( QDateEdit* salesDateInput, QTableView* managersSalesTable, QTableView* unconfirmedSalesTable, QTableView* confirmedSalesTable)
{
	this->salesDateInput = salesDateInput;
	this->salesDateInput->setDate(QDate::currentDate());
	connect(this->salesDateInput, &QDateEdit::dateChanged, this, &SalesPage::dateChanged);

	this->initManagersTable( managersSalesTable);
	this->initUnconfirmedSalesTable( unconfirmedSalesTable);
	this->initConfirmedSalesTable( confirmedSalesTable);
}

void SalesPage::initManagersTable( QTableView* managersSalesTable) {
	
 //   connect( this->managersTable, &QTableView::clicked, this, &EmployeesPage::showDetails);

	//настройки таблиц
	this->managersSalesTable = managersSalesTable;
	auto model = new ManagersSalesTableModel();
	this->managersSalesTable->setModel( model);

	this->managersSalesTable->horizontalHeader()->setStretchLastSection(true);
	this->managersSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->managersSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);

	//скрытие поля с id
	//this->managersTable->setColumnHidden( EmployeesTableModel::COLUMN_ID, true);
}

void SalesPage::initUnconfirmedSalesTable( QTableView* unconfirmedSalesTable) {

	this->unconfirmedSalesTable = unconfirmedSalesTable;

}

void SalesPage::initConfirmedSalesTable( QTableView* confirmedSalesTable) {

	this->confirmedSalesTable = confirmedSalesTable;
}

//===SLOTS===//
void SalesPage::dateChanged() {

	//обновляем все таблицы в соответсвии с датой
	QMessageBox::information(0, "Date changed", "You choose this date: " + this->salesDateInput->date().toString());
}