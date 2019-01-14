#pragma once

#include "Codec.h"
#include <QDateEdit>
#include <QTableView>
#include <qobject.h>
#include <qpushbutton.h>

#include "ErrorMessageHandler.h"

#include "ActiveSaleDTO.h"
#include "ManagerActiveSalesStatisticDTO.h"
#include "SalesFacade.h"

#include "ConfirmedSalesTableModel.h"
#include "ManagersSalesTableModel.h"
#include "UnconfirmedSalesTableModel.h"
#include <qabstractitemview.h>
#include <qheaderview.h>
#include <qmodelindex>

#include "test_salary_gui.h"
#include "test_sales_gui.h"
class SalesPage : public QObject {
    Q_OBJECT
    friend class Test_Sales_GUI;
    friend class Test_Salary_GUI;

  public:
    SalesPage( SalesFacade *salesFacade );
    void setUI( QTabWidget *tabWidget, QPushButton *salesForAllButton, QTableView *managersSalesTable, QTableView *unconfirmedSalesTable,
                QTableView *confirmedSalesTable );
    ~SalesPage( void );

    void refreshPage();

    void setErrorHandler( ErrorMessageHandler *errorHandler );

    void showManagerSales( int id );

  protected slots:

    void buttonForAll();
    void showManagersSales();
    void confirmSale();
    void unconfirmSale();

  protected:
    void initManagersTable( QTableView *managersSalesTable );
    void initUnconfirmedSalesTable( QTableView *unconfirmedSalesTable );
    void initConfirmedSalesTable( QTableView *confirmedSalesTable );

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
    ErrorMessageHandler *errorHandler;

    SalesFacade *salesFacade;

    QTabWidget *tabWidget;
    QPushButton *salesForAllButton;
    QTableView *managersSalesTable;
    QTableView *unconfirmedSalesTable;
    QTableView *confirmedSalesTable;

    QHash<int, ActiveSaleDTO> unconfirmedSales;
    QHash<int, ActiveSaleDTO> confirmedSales;
    QHash<int, ManagerActiveSalesStatisticDTO> managersSales;

    void addActionButtonsToUnconfirmedTable( UnconfirmedSalesTableModel *model );
    void addActionButtonsToConfirmedTable( ConfirmedSalesTableModel *model );

    void deleteConfirmSalesFromList( QList<ActiveSaleDTO> &list );
    void deleteUnconfirmSalesFromList( QList<ActiveSaleDTO> &list );

    void viewSelectedManagerUnconfirmedSales( int id );
    void viewSelectedManagerConfirmedSales( int id );

    void setEnable( bool flag );
};