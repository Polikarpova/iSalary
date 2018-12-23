#pragma once

#include <qobject.h>
#include <qlineedit.h>
#include <QDateEdit>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <qtableview.h>
#include <qstandarditemmodel.h>
#include <qtextcodec.h>
#include <qcombobox.h>
#include <qheaderview.h>
#include <qmessagebox.h>

#include "ProductFacade.h"
#include "SalesFacade.h"

class ManagerPage : public QObject {
	Q_OBJECT
public:
	ManagerPage( ProductFacade *productFacade, SalesFacade *saleFacade );
	~ManagerPage(void);
	void setUI(
		QLineEdit *currentSalaryOutput,
		QLineEdit *productNameOutput,
		QDateEdit *dateSaleInput,
		QDoubleSpinBox *priceSaleInput,
		QSpinBox *countSaleProductsInput,
		QPushButton *addSaleButton,
		QLineEdit *productSearchInput,
		QTableView *productTable,
		QTableView *confirmedSalesTable,
		QTableView *unconfirmedSalesTable
	);
	void setCurrentManagerId( int id );
	void refreshPage();
	void setWindow( QWidget *widget );

private:
	ProductFacade *productFacade;
	SalesFacade *saleFacade;
	QTextCodec *c;
	int current_manager_id;
	QWidget* widget;

	QLineEdit *currentSalaryOutput;
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

	bool validator();

	void fillManagersProductTable();
	void clearManagersProductsTable();
	void fillSale( ActiveSale & sale );
	void fillManagersUnconfirmedSalesTable();
	void clearManagersUnconfirmedSalesTable();
	void fillManagersConfirmedSalesTable();
	void clearManagersConfirmedSalesTable();

private slots:
	void searchManagersProductTable();
	void addSale();
	void removeSale();
	void showProduct();
};

