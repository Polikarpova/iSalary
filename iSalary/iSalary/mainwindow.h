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

	void initProductWindow();
	void fillProducts();

	void createHorizontalTabs();
};

#endif // MAINWINDOW_H
