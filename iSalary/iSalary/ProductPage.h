#pragma once

#include <qobject.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qstackedwidget.h>
#include <qspinbox.h>
#include <qtableview.h>
#include <qstandarditemmodel.h>
#include <qtextcodec.h>
#include <qheaderview.h>
#include <qmessagebox.h>
#include <qregexp.h>

#include "ProductFacade.h"

class ProductPage : public QObject {
	Q_OBJECT
public:
	ProductPage( ProductFacade * productFacade );
	~ProductPage(void);
	void setUI( 
		QLineEdit *productSearchInput, 
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
	void refreshPage();
	void setWindow( QWidget *widget );

private:
	ProductFacade *productFacade;
	QTextCodec* c;

	QWidget* widget;

	QLineEdit *productSearchInput; 
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

	bool validator();
	bool validatorProductName( QString productName );
	void setEnabledEditAndRemoveButtons( bool isEnabled );
	void setInputsEnabledPageProducts( bool isEnabled );
	void clearInputsPageProducts();
	void fillProduct( Product & product );
	void fillProducts();
	void clearTable();
	void selectProduct( Product product );

private slots:
	void enableEditAndRemoveButtons();
	void directAddProduct();
	void addProduct();
	void directUpdateProduct();
	void updateProduct();
	void showProduct();
	void removeProduct();
	void searchProduct();
};

