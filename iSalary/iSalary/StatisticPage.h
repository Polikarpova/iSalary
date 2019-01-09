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

/**
* Класс, описывающий логику страницы "Статистика"
*/
class StatisticPage : public QObject{
    Q_OBJECT
public:

    StatisticPage( SalesFacade * salesFacade);
    
	/**
	* Функция уставновки элементов ui, находящихся на странице, для непосредственного доступа к ним внутри класса StatisticPage
	*/
	void setUI( QTabWidget* tabWidget, QDateEdit* statisticMonth, QTableView* statisticTable, QTableView* statisticSalesTable, QCalendarWidget* statisticCalendar);
    
	~StatisticPage( void);

	/**
	* Функция обновления страницы
	*/
	void refreshPage();

	void setErrorHandler( ErrorMessageHandler* errorHandler);

protected slots:

	void monthChanged();
	void showManagersStatistic();

protected:

	void initStatisticTable (QTableView* statisticTable);
	void initStatisticSalesTable( QTableView* statisticSalesTable);

	void updateStatisticTable();
	void updateStatisticSalesTable();

	void viewSelectedManagerStatisticSales(int id);
	
private:
	ErrorMessageHandler* errorHandler;

    SalesFacade * salesFacade;
    
	QTabWidget* tabWidget;
	QDateEdit* statisticMonth;
	QTableView* statisticTable;
	QTableView* statisticSalesTable;
	QCalendarWidget* statisticCalendar;

	QHash<int, ManagerStatisticDTO> managerStatistic;
	QHash<int, ActiveSaleDTO> confirmedSales;

	void setEnable(bool flag);
	int getSelectedManagerId();

	void paintCalendar();
	void clearCalendar();
};
