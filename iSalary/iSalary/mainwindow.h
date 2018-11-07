#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "QTextCodec"

#include "AuthPage.h"
#include "SalesPage.h"

#include "Product_DB.h"
#include "Product.h"
#include "QStandardItemModel"
#include "QStandardItem"

#include "Sale_DB.h"
#include "ActiveSale.h"
#include "ClosedSale.h"

/**
* Ïåðå÷èñëåíèå îñíîâíûõ âèäæåòîâ ïðîãðàììû
*/
enum ProgramWidgets {
    AUTH_WIDGET = 0,
    PROGRAM_WIDGET = 1
};

/**
* Ïåðå÷èñëåíèå îñíîâíûõ âèäæåòîâ ïî ðîëÿì
*/
enum UserRoleWidgets {
    BOSS_WIDGET = 0,
    MANAGER_WIDGET = 1
};

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(AuthPage* authPage, SalesPage * salesPage, QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;

	QSqlDatabase  _db;
    
	AuthPage* authPage;
	SalesPage* salesPage;

	int current_user_id;
	void createHorizontalTabs();

    void enterProgram( const UserDTO& user, UserType userType);

	Product_DB * product_db;
	QHash <int, Product> products;
	QStandardItemModel *productsTableModel;
	enum StatusType {DEFAULT, ADD_PRODUCT, UPDATE_PRODUCT};
	StatusType status;  

	void initProductWindow();
	void setInputsEnabledPageProducts( bool isEnabled );
	void clearInputsPageProducts();
	void fillProduct( Product & product );
	void fillProducts();
	void clearTable();

	Sale_DB * sale_db;
	QHash <int, ActiveSale> sales;
	QStandardItemModel *unconfirmedSalesTableModel, *confirmedSalesTableModel;
	void initManagerWindow();
	void fillManagersProductTable();
	void clearManagersProductsTable();
	void fillSale( ActiveSale & sale );
	void fillManagersUnconfirmedSalesTable();
	void clearManagersUnconfirmedSalesTable();
	void fillManagersConfirmedSalesTable();
	void clearManagersConfirmedSalesTable();

private slots:
	void directAddProduct();
	void addProduct();
	void directUpdateProduct();
	void updateProduct();
	void showProduct();
	void removeProduct();
	void searchProduct();

	void searchManagersProductTable();
	void addSale();
};

#endif // MAINWINDOW_H