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

	void initProductWindow();
	void fillProducts();
	void setInputsEnabledPageProducts( bool isEnabled );
	void fillProduct( Product & product );

	void createHorizontalTabs();

private slots:
	void directAddProduct();
	void addProduct();
};

#endif // MAINWINDOW_H
