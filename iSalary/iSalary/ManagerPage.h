#pragma once

#include <QDateEdit>
#include <qcombobox.h>
#include <qheaderview.h>
#include <qlineedit.h>
#include <qmessagebox.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <qstandarditemmodel.h>
#include <qtableview.h>
#include <qtextcodec.h>

#include "ErrorMessageHandler.h"
#include "ProductFacade.h"
#include "SalesFacade.h"
#include "test_auth_gui.h"
#include "test_manager_gui.h"

class ManagerPage : public QObject {
    Q_OBJECT
    friend class Test_Manager_GUI;
    friend class Test_Auth_GUI;

  public:
    ManagerPage( ProductFacade *productFacade, SalesFacade *saleFacade );
    ~ManagerPage( void );
    void setUI( QWidget *tabWidget, QLineEdit *currentSalaryOutput, QLineEdit *possibleSalaryOutput, QLineEdit *productNameOutput, QDateEdit *dateSaleInput,
                QDoubleSpinBox *priceSaleInput, QSpinBox *countSaleProductsInput, QPushButton *addSaleButton, QLineEdit *productSearchInput,
                QTableView *productTable, QTableView *confirmedSalesTable, QTableView *unconfirmedSalesTable );
    void setCurrentManagerId( int id );
    void refreshPage();
    void setErrorHandler( ErrorMessageHandler *errorHandler );

  private:
    ProductFacade *productFacade;
    SalesFacade *saleFacade;
    QTextCodec *c;
    int current_manager_id;
    QWidget *tabWidget;
    ErrorMessageHandler *errorHandler;

    QLineEdit *currentSalaryOutput;
    QLineEdit *possibleSalaryOutput;
    QLineEdit *productNameOutput;
    QDateEdit *dateSaleInput;
    QDoubleSpinBox *priceSaleInput;
    QSpinBox *countSaleProductsInput;
    QPushButton *addSaleButton;
    QLineEdit *productSearchInput;
    QTableView *productTable;
    QTableView *confirmedSalesTable;
    QTableView *unconfirmedSalesTable;
    QStandardItemModel *unconfirmedSalesTableModel;
    QStandardItemModel *confirmedSalesTableModel;
    QStandardItemModel *productsTableModel;

    void fillManagersProductTable();
    void clearManagersProductsTable();
    void fillSale( ActiveSale &sale );
    void fillManagersUnconfirmedSalesTable();
    void clearManagersUnconfirmedSalesTable();
    void fillManagersConfirmedSalesTable();
    void clearManagersConfirmedSalesTable();
    void startBlockForRequest();
    void endBlockForRequest();

  private slots:
    void searchManagersProductTable();
    void addSale();
    void removeSale();
    void showProduct();
};
