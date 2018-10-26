#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "QTextCodec"
#include "Product_DB.h"
#include "Product.h"
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
	Product_DB * product_db;
    QSqlDatabase  _db;

	QHash <int, Product> products;
	QStandardItemModel *productsTableModel;
	int max_id_product;
	// DEFAULT - начальное состояние, ADD_PRODUCT - добавление товара, UPDATE_PRODUCT - изменение товара
	enum StatusType {DEFAULT, ADD_PRODUCT, UPDATE_PRODUCT};
	StatusType status;  

	void initProductWindow();
	void setInputsEnabledPageProducts( bool isEnabled );
	void clearInputsPageProducts();
	void fillProduct( Product & product );
	void fillProducts();

	void createHorizontalTabs();

private slots:
	void directAddProduct();
	void addProduct();
	void directUpdateProduct();
	void updateProduct();
	void showProduct();
};

#endif // MAINWINDOW_H
