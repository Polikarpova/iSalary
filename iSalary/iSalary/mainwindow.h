#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

#include "AuthPage.h"

/**
* ������������ �������� �������� ���������
*/
enum ProgramWidgets {
    AUTH_WIDGET = 0,
    PROGRAM_WIDGET = 1
};

/**
* ������������ �������� �������� �� �����
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
    
};

#endif // MAINWINDOW_H
