#include "mainwindow.h"
#include <qlabel.h>
#include <qtextcodec.h>

MainWindow::MainWindow( AuthPage* authPage, EmployeesPage* employeesPage, QWidget *parent ) : QMainWindow(parent) {
	ui.setupUi(this);
	
    ui.auth_program_stackedWidget->setCurrentIndex( AUTH_WIDGET);

	createHorizontalTabs();

    this->errorHandler = new ErrorMessageHandler( this);

    this->authPage = authPage;
    this->authPage->setUI( ui.loginInput, ui.passwordInput, ui.enterButton, ui.errorLabel);

    this->employeesPage = employeesPage;
    this->employeesPage->setUI(
        ui.managersTable,
        ui.login,
        ui.password,
        ui.firstName,
        ui.secondName,
        ui.thirdName,
        ui.dateOfBirth,
        ui.pasportSeries,
        ui.pasportNumber,
        ui.sexGroup,
        ui.maleRButton,
        ui.femaleRButton,
        ui.pasportSourse,
        ui.dateOfReceipt,
        ui.registration,
        ui.INN,
        ui.managersButtonsStackedWidget,
        ui.managerEditButton,
        ui.addManagerButton,
        ui.saveManagerButton,
        ui.cancelManagerButton,
        ui.managerSubmitAddButton,
        ui.managerCancelAddButton
    );
    this->employeesPage->setErrorHandler( errorHandler);
    connect( ui.tabWidget, &QTabWidget::currentChanged, this, &MainWindow::refreshBossPage);
    //this->employeesPage->refreshList();

    connect(this->authPage, &AuthPage::userLoggedIn, this, &MainWindow::enterProgram);
}

void MainWindow::enterProgram( const UserDTO& user, UserType userType){
    if( userType == MANAGER) {
        ui.boss_manager_stackedWidget->setCurrentIndex( MANAGER_WIDGET);
    } else if ( userType == BOSS ){
        ui.boss_manager_stackedWidget->setCurrentIndex( BOSS_WIDGET);
        this->refreshBossPage(0);
    }
    ui.auth_program_stackedWidget->setCurrentIndex( PROGRAM_WIDGET);
}

void MainWindow::createHorizontalTabs() {

	QStringList tabs_text;
	QTextCodec *c = QTextCodec::codecForLocale();
	tabs_text << c->toUnicode("Сотрудники") << c->toUnicode("Товары") << c->toUnicode("Корректировки") << c->toUnicode("Продажи") <<
				  c->toUnicode("Статистика")<< c->toUnicode("Зарплата");
	QTabWidget *tabw = ui.tabWidget;
	
	for( int i = 0; i < 6; i++) {
		tabw->setTabText(i, "");
	}
	
	QTabBar *tabbar = tabw->tabBar();

	for( int i = 0; i < 6; i++) {
		QLabel *lbl = new QLabel();
		lbl->setText(tabs_text[i]);
		tabbar->setTabButton(i, QTabBar::LeftSide, lbl);
	}
}

void MainWindow::refreshBossPage( int page){

    switch( page){
        case PAGE_EMPLOYEES: this->employeesPage->refreshList(); break;
        default:;
    }
}


MainWindow::~MainWindow() {
    delete this->errorHandler;
}
