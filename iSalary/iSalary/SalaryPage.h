#pragma once

#include <qobject.h>
#include "Codec.h"
#include <QTableView>
#include <qcombobox.h>
#include <qlabel.h>
#include <qspinbox.h>
#include <qlineedit.h>
#include <QDateEdit>
#include <qradiobutton.h>
#include <qpushbutton.h>

#include "ErrorMessageHandler.h"

#include "SalesFacade.h"
#include "PersonnalAccountingFacade.h"
#include "ActiveSaleDTO.h"
#include "ManagerActiveSalesStatisticDTO.h"

#include "SalaryTableModel.h"
#include "SalaryTotalTableModel.h"
#include <qheaderview.h>
#include <qmodelindex>
#include <qabstractitemview.h>

class SalaryPage : public QObject{
    Q_OBJECT
public:
    SalaryPage( SalesFacade * salesFacade, PersonnalAccountingFacade* personnalAccountingFacade);
    void setUI( QComboBox* salaryAccountingPeriod, QTableView* salaryTable, QTableView* salaryTotalTable, QLabel* managerFIOLabel, QSpinBox* salaryPasportSeries,
				QSpinBox* salaryPasportNumber, QLineEdit* salaryPasportSourse, QDateEdit* salaryDateOfReceipt, QRadioButton* salaryMaleRButton, QRadioButton* salaryFemaleRButton,
				QLineEdit* salaryINN, QPushButton* closeAccountingPeriod, QPushButton* salesButton, QPushButton* dataButton);
    ~SalaryPage( void);

	void refreshPage();

	void setErrorHandler( ErrorMessageHandler* errorHandler);

protected slots:

	void showManager();

protected:

	void initSalaryTable (QTableView* salaryTable);
	void initSalaryTotalTable( QTableView* salaryTotalTable);
	//
	//int getSelectedManagerSalesId();
	//int getSelectedUnconfirmedSalesId();
	//int getSelectedConfirmedSalesId();

	///**
 //   * Обновление таблицы со списком менежеров и инормацией об активных продажах
 //   */
	//void updateManagersTable();
	//void updateUnconfirmedTable();
	//void updateConfirmedTable();
	
private:
	ErrorMessageHandler* errorHandler;

    SalesFacade* salesFacade;
    PersonnalAccountingFacade* personnalAccountingFacade;
	
	QComboBox* salaryAccountingPeriod;
	QTableView* salaryTable;
	QTableView* salaryTotalTable;
	
	QLabel* managerFIOLabel;
	QSpinBox* salaryPasportSeries;
	QSpinBox* salaryPasportNumber;
	QLineEdit* salaryPasportSourse;
	QDateEdit* salaryDateOfReceipt;
	QRadioButton* salaryMaleRButton;
	QRadioButton* salaryFemaleRButton;
	QLineEdit* salaryINN;

	QPushButton* closeAccountingPeriod;
	QPushButton* salesButton;
	QPushButton* dataButton;

	/*QHash<int, ActiveSaleDTO> unconfirmedSales;
	QHash<int, ActiveSaleDTO> confirmedSales;
	QHash<int, ManagerActiveSalesStatisticDTO> managersSales;

	void addActionButtonsToUnconfirmedTable(UnconfirmedSalesTableModel* model);
	void addActionButtonsToConfirmedTable(ConfirmedSalesTableModel* model);

	void deleteConfirmSalesFromList( QList<ActiveSaleDTO>& list);
	void deleteUnconfirmSalesFromList( QList<ActiveSaleDTO>& list);

	void viewSelectedManagerUnconfirmedSales(int id);
	void viewSelectedManagerConfirmedSales(int id);*/
};