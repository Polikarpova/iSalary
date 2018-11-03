#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

#include "AuthPage.h"
#include "EmployeesPage.h"

/**
* Перечисление основных виджетов программы
*/
enum ProgramWidgets {
    AUTH_WIDGET = 0,
    PROGRAM_WIDGET = 1
};

/**
* Перечисление основных виджетов по ролям
*/
enum UserRoleWidgets {
    BOSS_WIDGET = 0,
    MANAGER_WIDGET = 1
};

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
    MainWindow(AuthPage* authPage, EmployeesPage* employeesPage, QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;

    AuthPage* authPage;
    EmployeesPage* employeesPage;

	void createHorizontalTabs();
    void enterProgram( const UserDTO& user, UserType userType);
    
    enum BossPage {
        PAGE_EMPLOYEES = 0,
        PAGE_PRODUCTS,
        PAGE_CORRECTIONS,
        PAGE_SALES,
        PAGE_STATISTIC,
        PAGE_SALARY
    };

    void refreshBossPage( int page);
};

#endif // MAINWINDOW_H
