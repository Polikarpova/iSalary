#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

#include "AuthPage.h"

#include "QTextCodec"
#include "Product_DB.h"
#include "Product.h"
#include "QStandardItemModel"
#include "QStandardItem"

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
	MainWindow(AuthPage* authPage, QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;

    AuthPage* authPage;

	void createHorizontalTabs();
    void enterProgram( const UserDTO& user, UserType userType);
    
	QSqlDatabase  _db;

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

private slots:
	void directAddProduct();
	void addProduct();
	void directUpdateProduct();
	void updateProduct();
	void showProduct();
	void removeProduct();
	void searchProduct();
};

#endif // MAINWINDOW_H