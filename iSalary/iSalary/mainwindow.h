#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "QTextCodec"
#include "Product_DB.h"
#include "Product.h"
#include "Sale_DB.h"
#include "ActiveSale.h"
#include "ClosedSale.h"
#include "QStandardItemModel"
#include "QStandardItem"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
	QTextCodec* c ;
	QSqlDatabase  _db;
	int current_user_id;
	void createHorizontalTabs();

	Product_DB * product_db;
	QHash <int, Product> products;
	QStandardItemModel *productsTableModel;
	// DEFAULT - ��������� ���������, ADD_PRODUCT - ���������� ������, UPDATE_PRODUCT - ��������� ������
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
