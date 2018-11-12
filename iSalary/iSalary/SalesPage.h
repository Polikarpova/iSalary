#pragma once

#include "Codec.h"
#include <QDateEdit>
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
    void setUI( QDateEdit* salesDateInput, QTableView* managersSalesTable, QTableView* unconfirmedSalesTable, QTableView* confirmedSalesTable);
    ~SalesPage( void);

	void refreshPage();

	void setErrorHandler( ErrorMessageHandler* errorHandler);

protected slots:

	void dateChanged();

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
    
	QDateEdit* salesDateInput;
	QTableView* managersSalesTable;
	QTableView* unconfirmedSalesTable;
	QTableView* confirmedSalesTable;

	QHash<int, ActiveSaleDTO> unconfirmedSales;
	QHash<int, ActiveSaleDTO> confirmedSales;
	QHash<int, ManagerActiveSalesStatisticDTO> managersSales;

	void deleteConfirmSalesFromList( QList<ActiveSaleDTO>& list);
	void deleteUnconfirmSalesFromList( QList<ActiveSaleDTO>& list);
};