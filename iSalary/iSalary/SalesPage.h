#pragma once

#include "Codec.h"
#include <QDateEdit>
#include <qpushbutton.h>
#include <QTableView>
#include <qobject.h>

#include "ErrorMessageHandler.h"

#include "SalesFacade.h"
#include "ActiveSaleDTO.h"
#include "ManagerActiveSalesStatisticDTO.h"

#include "ManagersSalesTableModel.h"
#include "UnconfirmedSalesTableModel.h"
#include "ConfirmedSalesTableModel.h"
#include <qheaderview.h>
#include <qmodelindex>
#include <qabstractitemview.h>

class SalesPage : public QObject{
    Q_OBJECT
public:
    SalesPage( SalesFacade * salesFacade);
    void setUI( QTabWidget* tabWidget, QDateEdit* salesDateInput, QPushButton* salesForAllButton, QTableView* managersSalesTable, QTableView* unconfirmedSalesTable, QTableView* confirmedSalesTable);
    ~SalesPage( void);

	void refreshPage();

	void setErrorHandler( ErrorMessageHandler* errorHandler);

protected slots:

	void dateChanged();
	void buttonForAll();
	void showManagersSales();
	void confirmSale();
	void unconfirmSale();

protected:

	void initManagersTable (QTableView* managersSalesTable);
	void initUnconfirmedSalesTable( QTableView* unconfirmedSalesTable);
	void initConfirmedSalesTable( QTableView* confirmedSalesTable);
	
	int getSelectedManagerSalesId();
	int getSelectedUnconfirmedSalesId();
	int getSelectedConfirmedSalesId();

	/**
    * Обновление таблицы со списком менежеров и инормацией об активных продажах
    */
	void updateManagersTable();
	void updateUnconfirmedTable();
	void updateConfirmedTable();
	
private:
	ErrorMessageHandler* errorHandler;

    SalesFacade * salesFacade;
    
	QTabWidget* tabWidget;
	QDateEdit* salesDateInput;
	QPushButton* salesForAllButton;
	QTableView* managersSalesTable;
	QTableView* unconfirmedSalesTable;
	QTableView* confirmedSalesTable;

	QHash<int, ActiveSaleDTO> unconfirmedSales;
	QHash<int, ActiveSaleDTO> confirmedSales;
	QHash<int, ManagerActiveSalesStatisticDTO> managersSales;

	void addActionButtonsToUnconfirmedTable(UnconfirmedSalesTableModel* model);
	void addActionButtonsToConfirmedTable(ConfirmedSalesTableModel* model);

	void deleteConfirmSalesFromList( QList<ActiveSaleDTO>& list);
	void deleteUnconfirmSalesFromList( QList<ActiveSaleDTO>& list);

	void viewSelectedManagerUnconfirmedSales(int id);
	void viewSelectedManagerConfirmedSales(int id);

	void setEnable(bool flag);
};