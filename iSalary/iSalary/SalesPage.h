#pragma once

#include <QDateEdit>
#include <QTableView>
#include <qobject.h>

#include "SalesFacade.h"
#include "ActiveSaleDTO.h"
#include "ManagerActiveSalesStatisticDTO.h"

#include "ManagersSalesTableModel.h"
#include <qheaderview.h>
#include <qmodelindex>
#include <qabstractitemview.h>

class SalesPage : public QObject{
    Q_OBJECT
public:
    SalesPage( SalesFacade * salesFacade);
    void setUI( QDateEdit* salesDateInput, QTableView* managersSalesTable, QTableView* unconfirmedSalesTable, QTableView* confirmedSalesTable);
    ~SalesPage( void);

signals:

protected slots:

	void dateChanged();

protected:

	void initManagersTable (QTableView* managersSalesTable);
	void initUnconfirmedSalesTable( QTableView* unconfirmedSalesTable);
	void initConfirmedSalesTable( QTableView* confirmedSalesTable);

private:
    SalesFacade * salesFacade;
    
	QDateEdit* salesDateInput;
	QTableView* managersSalesTable;
	QTableView* unconfirmedSalesTable;
	QTableView* confirmedSalesTable;

	QHash<int, ActiveSaleDTO> unconfirmedSales;
	QHash<int, ActiveSaleDTO> confirmedSales;
	QHash<int, ManagerActiveSalesStatisticDTO> managersSales;
};