#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <qlabel.h>
#include <qtabbar.h>
#include <qtabwidget.h>
#include <qstring.h>
#include <qstringlist.h>

#include "ui_mainwindow.h"
#include "Codec.h"

#include "AuthPage.h"
#include "ProductPage.h"
#include "ManagerPage.h"
#include "EmployeesPage.h"
#include "SalesPage.h"
#include "SalaryPage.h"

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
#include "enums.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(
		AuthPage* authPage,
		EmployeesPage* employeesPage,
		SalesPage* salesPage,
		SalaryPage* salaryPage,
		ProductPage *productPage, 
		ManagerPage *managerPage, 
		QWidget *parent = 0
	);
	~MainWindow();

private:
	Ui::MainWindowClass ui;

	QSqlDatabase  _db;
    
	AuthPage* authPage;
	SalesPage* salesPage;
    EmployeesPage* employeesPage;
	SalaryPage* salaryPage;
	ProductPage *productPage;
	ManagerPage *managerPage;

	int current_user_id;
    ErrorMessageHandler* errorHandler;

	void createHorizontalTabs();

    void enterProgram( const UserDTO& user, UserType userType);
    


    void refreshBossPage( int page);

private slots:

	void exit();
};

#endif // MAINWINDOW_H