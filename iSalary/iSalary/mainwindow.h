#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "Manager.h"
#include "QStandardItemModel"
#include "QStandardItem"
#include "QTextCodec"
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
	QTextCodec* c ;
	QStandardItemModel *managersTableModel;
	int count;
	void setInputsVisible( bool isEnabled );
	void fillManager(Manager & manager);

private slots:
	void directAddManager();
	void addManager();
};

#endif // MAINWINDOW_H
