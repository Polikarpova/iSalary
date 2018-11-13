#pragma once

#include <qobject.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qstackedwidget.h>
#include <qspinbox.h>
#include <qtableview.h>
#include <qstandarditemmodel.h>
#include <qtextcodec.h>

#include "ProductFacade.h"

class ProductPage : public QObject {
	Q_OBJECT
public:
	ProductPage( ProductFacade * productFacade );
	~ProductPage(void);
	void setUI( 
		QLineEdit *productSearchInput, 
		QPushButton *searchButton,
		QTableView *productTable,
		QLineEdit *productNameInput,
		QDoubleSpinBox *productPercentInput,
		QStackedWidget *productButtonsStackedWidget,
		QPushButton *addProductButton,
		QPushButton *deleteProductButton,
		QPushButton *editProductButton,
		QPushButton *cancelProductButton,
		QPushButton *saveProductButton,
		QPushButton *productCancelAddButton,
		QPushButton *productSubmitAddButton
	);

private:
	ProductFacade *productFacade;
	QTextCodec* c;

	QLineEdit *productSearchInput; 
	QPushButton *searchButton;
	QTableView *productTable;
	QStandardItemModel *productsTableModel;
	QLineEdit *productNameInput;
	QDoubleSpinBox *productPercentInput;
	QStackedWidget *productButtonsStackedWidget;
	QPushButton *addProductButton;
	QPushButton *deleteProductButton;
	QPushButton *editProductButton;
	QPushButton *cancelProductButton;
	QPushButton *saveProductButton;
	QPushButton *productCancelAddButton;
	QPushButton *productSubmitAddButton;

	enum StatusType {DEFAULT, ADD_PRODUCT, UPDATE_PRODUCT};
	StatusType status; 

	void setInputsEnabledPageProducts( bool isEnabled );
	void clearInputsPageProducts();
	void fillProduct( Product & product );
	void fillProducts();
	void clearTable();

private slots:
	void directAddProduct();
	void addProduct();
	void directUpdateProduct();
	void updateProduct();
	void showProduct();
	void removeProduct();
	void searchProduct();
};

