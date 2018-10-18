#include "mainwindow.h"
#include <qlabel.h>
#include <qtextcodec.h>

MainWindow::MainWindow( QWidget *parent ) : QMainWindow(parent) {
	ui.setupUi(this);
	
	createHorizontalTabs();
}

void MainWindow::createHorizontalTabs() {

	QStringList tabsText;
	QTextCodec *c = QTextCodec::codecForLocale();
	tabsText << c->toUnicode("Сотрудники") << c->toUnicode("Товары") << c->toUnicode("Корректировки") << c->toUnicode("Продажи") <<
				  c->toUnicode("Статистика")<< c->toUnicode("Зарплата");
	QTabWidget *tabw = ui.tabWidget;
	
	for( int i = 0; i < 6; i++) {
		tabw->setTabText(i, "");
	}
	
	QTabBar *tabbar = tabw->tabBar();

	for( int i = 0; i < 6; i++) {
		QLabel *lbl = new QLabel();
		lbl->setText(tabsText[i]);
		tabbar->setTabButton(i, QTabBar::LeftSide, lbl);
	}
}

MainWindow::~MainWindow() {

}
