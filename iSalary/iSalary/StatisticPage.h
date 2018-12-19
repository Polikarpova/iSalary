#pragma once

#include "Codec.h"
#include <QDateEdit>
#include <QTableView>
#include <qcalendarwidget.h>
#include <qobject.h>

#include "ErrorMessageHandler.h"

#include "SalesFacade.h"

#include "ActiveSaleDTO.h"
#include "ManagerStatisticDTO.h"

#include "StatisticTableModel.h"
#include "StatisticSalesTableModel.h"

#include <qheaderview.h>
#include <qmodelindex>
#include <qabstractitemview.h>

class StatisticPage : public QObject{
    Q_OBJECT
public:
    StatisticPage( SalesFacade * salesFacade);
    void setUI( QTabWidget* tabWidget, QDateEdit* statisticStartPeriod, QDateEdit* statisticEndPeriod, QTableView* statisticTable, QTableView* statisticSalesTable, QCalendarWidget* statisticCalendar);
    ~StatisticPage( void);

	void refreshPage();

	void setErrorHandler( ErrorMessageHandler* errorHandler);

protected slots:

	void startDateChanged();
	void endDateChanged();

	void showManagersStatistic();

protected:

	void initStatisticTable (QTableView* statisticTable);
	void initStatisticSalesTable( QTableView* statisticSalesTable);

	void updateStatisticTable();
	void updateStatisticSalesTable();
	
private:
	ErrorMessageHandler* errorHandler;

    SalesFacade * salesFacade;
    
	QTabWidget* tabWidget;
	QDateEdit* statisticStartPeriod;
	QDateEdit* statisticEndPeriod;
	QTableView* statisticTable;
	QTableView* statisticSalesTable;
	QCalendarWidget* statisticCalendar;

	QHash<int, ManagerStatisticDTO> managerStatistic;
	QHash<int, ActiveSaleDTO> confirmedSales;
};
