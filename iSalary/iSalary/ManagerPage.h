#pragma once

#include <qobject.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <qtableview.h>
#include <qstandarditemmodel.h>
#include <qtextcodec.h>
#include <qcombobox.h>

#include "ProductFacade.h"
#include "SaleFacade.h"

class ManagerPage : public QObject {
	Q_OBJECT
public:
	ManagerPage( ProductFacade *productFacade, SaleFacade *saleFacade );
	~ManagerPage(void);
	void setUI(
		QLineEdit *currentSalaryOutput,
		QComboBox *productComboBox,
		QDoubleSpinBox *priceSaleInput,
		QSpinBox *countSaleProductsInput,
		QPushButton *addSaleButton,
		QLineEdit *productSearchInput,
		QPushButton *productSearchButton,
		QTableView *productTable,
		QTableView *confirmedSalesTable,
		QTableView *unconfirmedSalesTable
	);

private:
	ProductFacade *productFacade;
	SaleFacade *saleFacade;
	QTextCodec *c;
	int current_manager_id;

	QLineEdit *currentSalaryOutput;
	QComboBox *productComboBox;
	QDoubleSpinBox *priceSaleInput;
	QSpinBox *countSaleProductsInput;
	QPushButton *addSaleButton;
	QLineEdit *productSearchInput;
	QPushButton *productSearchButton;
	QTableView *productTable;
	QTableView *confirmedSalesTable;
	QTableView *unconfirmedSalesTable;
	QStandardItemModel *unconfirmedSalesTableModel; 
	QStandardItemModel *confirmedSalesTableModel;
	QStandardItemModel *productsTableModel;

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
};

