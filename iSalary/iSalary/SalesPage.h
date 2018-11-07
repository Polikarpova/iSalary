#pragma once

#include <QDateEdit>
#include <QTableView>
#include <qobject.h>

#include "SalesFacade.h"
#include "SignResultDTO.h"

class SalesPage : public QObject{
    Q_OBJECT
public:
    SalesPage( SalesFacade * salesFacade);
    void setUI( QDateEdit* salesDateInput, QTableView* managersSalesTable, QTableView* unconfirmedSalesTable, QTableView* confirmedSalesTable);
    ~SalesPage( void);

signals:

private slots:

private:
    SalesFacade * salesFacade;
    
	QDateEdit* salesDateInput;
	QTableView* managersSalesTable;
	QTableView* unconfirmedSalesTable;
	QTableView* confirmedSalesTable;

    void showLogInError( const QString& error);
};

