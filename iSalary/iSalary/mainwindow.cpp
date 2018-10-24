#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)	: QMainWindow(parent)
{
	ui.setupUi(this);
	c = QTextCodec::codecForLocale();
	
}

MainWindow::~MainWindow()
{

}

