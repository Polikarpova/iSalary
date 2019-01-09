#pragma once

#include <qheaderview.h>
#include <qlineedit.h>
#include <qmessagebox.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qregexp.h>
#include <qspinbox.h>
#include <qstackedwidget.h>
#include <qstandarditemmodel.h>
#include <qtableview.h>
#include <qtextcodec.h>

#include "ErrorMessageHandler.h"
#include "ProductFacade.h"

#include "test_product_gui.h"

class ProductPage : public QObject {
    Q_OBJECT
    friend class Test_Product_GUI;

  public:
    ProductPage( ProductFacade *productFacade );
    ~ProductPage( void );
    void setUI( QWidget *tabWidget, QLineEdit *productSearchInput, QTableView *productTable, QLineEdit *productNameInput, QDoubleSpinBox *productPercentInput,
                QStackedWidget *productButtonsStackedWidget, QPushButton *addProductButton, QPushButton *deleteProductButton, QPushButton *editProductButton,
                QPushButton *cancelProductButton, QPushButton *saveProductButton, QPushButton *productCancelAddButton, QPushButton *productSubmitAddButton );
    void refreshPage();
    void setWindow( QWidget *widget );
    void setErrorHandler( ErrorMessageHandler *errorHandler );

  private:
    ErrorMessageHandler *errorHandler;
    ProductFacade *productFacade;
    QTextCodec *c;

    QWidget *tabWidget;
    QWidget *widget;

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

    enum StatusType { DEFAULT, ADD_PRODUCT, UPDATE_PRODUCT };
    StatusType status;

    bool validator();
    bool validatorProductName( QString productName );
    void setEnabledEditAndRemoveButtons( bool isEnabled );
    void setInputsEnabledPageProducts( bool isEnabled );
    void clearInputsPageProducts();
    void fillProduct( Product &product );
    void fillProducts();
    void clearTable();
    void selectProduct( Product product );
    void setEnabledWindow( bool enabled );
    void startBlockForRequest();
    void endBlockForRequest();

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
