#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "QTextCodec"

#include "AuthPage.h"
#include "ProductPage.h"
#include "ManagerPage.h"

#include "Product_DB.h"
#include "Product.h"
#include "Sale_DB.h"
#include "ActiveSale.h"
#include "ClosedSale.h"
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
	MainWindow(AuthPage* authPage, ProductPage *productPage, ManagerPage *managerPage, QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
	QSqlDatabase  _db;
    AuthPage* authPage;
	ProductPage *productPage;
	ManagerPage *managerPage;

	void createHorizontalTabs();
    void enterProgram( const UserDTO& user, UserType userType);

private slots:

};

#endif // MAINWINDOW_H