#include "test_employees_gui.h"

Test_Employees_GUI::Test_Employees_GUI( QSqlDatabase *sql, EmployeesPage *employeesPage ) {
	
	this->employeesPage = employeesPage;
	this->sql = sql;
	user_DB = new UserDB( sql );
	manager_DB = new ManagerDB( sql, user_DB );
	c = QTextCodec::codecForLocale();
}

Test_Employees_GUI::~Test_Employees_GUI() {

}

void Test_Employees_GUI::removeEmployee( int id ) {
	QSqlQuery query("DELETE FROM users WHERE id = " + QString::number( id ), *sql);
	bool isOk = query.exec();
}

QString Test_Employees_GUI::findElemInTable( int row, int col ){
	return employeesPage->managersTable->model()->data( employeesPage->managersTable->model()->index( row, col ) ).toString();
}

void Test_Employees_GUI::addOneEmployee( Manager manager) {
	
	employeesPage->addBtn->click();

	employeesPage->firstNameInput->setText( manager.getFirstName() );
	employeesPage->secondNameInput->setText( manager.getSecondName() );
	employeesPage->thirdNameInput->setText( manager.getThirdName() );
	employeesPage->birthdayInput->setDate( manager.getDateOfBirth() );
	employeesPage->passportSerialInput->setValue( manager.getPassportSerial().toInt() );
	employeesPage->passportNumberInput->setValue( manager.getPassportNumber().toInt() );
	employeesPage->passportSourceInput->setText( manager.getPassportSource() );
	employeesPage->passportIssueDate->setDate( manager.getPassportDateIssue() );
	employeesPage->addressInput->setText( manager.getAddress() );
	employeesPage->INNInput->setText( manager.getINN() );

	employeesPage->confirmAddBtn->click();
	employeesPage->refreshList();
}

void Test_Employees_GUI::directAddEmployee() {
	
	QCOMPARE( employeesPage->firstNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->secondNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->thirdNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->birthdayInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportSerialInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportNumberInput->isEnabled(), false );
	QCOMPARE( employeesPage->sexCheckGroup->isEnabled(), false );
	QCOMPARE( employeesPage->maleInput->isEnabled(), false );
	QCOMPARE( employeesPage->femaleInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportSourceInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportIssueDate->isEnabled(), false );
	QCOMPARE( employeesPage->addressInput->isEnabled(), false );
	QCOMPARE( employeesPage->INNInput->isEnabled(), false );
	QCOMPARE( employeesPage->loginInput->isEnabled(), false );
	QCOMPARE( employeesPage->passwordInput->isEnabled(), false );

	QCOMPARE( employeesPage->managersTable->isEnabled(), true );
	QCOMPARE( employeesPage->editBtn->isEnabled(), true );
	QCOMPARE( employeesPage->addBtn->isEnabled(), true );
	QCOMPARE( employeesPage->buttonStackedWidget->currentIndex(), 0 );

	employeesPage->addBtn->click();

	QCOMPARE( employeesPage->firstNameInput->isEnabled(), true );
	QCOMPARE( employeesPage->secondNameInput->isEnabled(), true );
	QCOMPARE( employeesPage->thirdNameInput->isEnabled(), true );
	QCOMPARE( employeesPage->birthdayInput->isEnabled(), true );
	QCOMPARE( employeesPage->passportSerialInput->isEnabled(), true );
	QCOMPARE( employeesPage->passportNumberInput->isEnabled(), true );
	QCOMPARE( employeesPage->sexCheckGroup->isEnabled(), true );
	QCOMPARE( employeesPage->maleInput->isEnabled(), true );
	QCOMPARE( employeesPage->femaleInput->isEnabled(), true );
	QCOMPARE( employeesPage->passportSourceInput->isEnabled(), true );
	QCOMPARE( employeesPage->passportIssueDate->isEnabled(), true );
	QCOMPARE( employeesPage->addressInput->isEnabled(), true );
	QCOMPARE( employeesPage->INNInput->isEnabled(), true );
	QCOMPARE( employeesPage->loginInput->isEnabled(), false );
	QCOMPARE( employeesPage->passwordInput->isEnabled(), false );

	//QCOMPARE( employeesPage->managersTable->isEnabled(), true );
	//QCOMPARE( employeesPage->addBtn->isEnabled(), true );
	QCOMPARE( employeesPage->confirmAddBtn->isEnabled(), true );
	QCOMPARE( employeesPage->cancelAddBtn->isEnabled(), true );
	QCOMPARE( employeesPage->buttonStackedWidget->currentIndex(), 2 );
}

void Test_Employees_GUI::directUpdateEmployee() {
	
	QCOMPARE( employeesPage->firstNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->secondNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->thirdNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->birthdayInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportSerialInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportNumberInput->isEnabled(), false );
	QCOMPARE( employeesPage->sexCheckGroup->isEnabled(), false );
	QCOMPARE( employeesPage->maleInput->isEnabled(), false );
	QCOMPARE( employeesPage->femaleInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportSourceInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportIssueDate->isEnabled(), false );
	QCOMPARE( employeesPage->addressInput->isEnabled(), false );
	QCOMPARE( employeesPage->INNInput->isEnabled(), false );
	QCOMPARE( employeesPage->loginInput->isEnabled(), false );
	QCOMPARE( employeesPage->passwordInput->isEnabled(), false );

	QCOMPARE( employeesPage->managersTable->isEnabled(), true );
	QCOMPARE( employeesPage->editBtn->isEnabled(), true );
	QCOMPARE( employeesPage->addBtn->isEnabled(), true );
	QCOMPARE( employeesPage->buttonStackedWidget->currentIndex(), 0 );

	employeesPage->editBtn->click();

	QCOMPARE( employeesPage->firstNameInput->isEnabled(), true );
	QCOMPARE( employeesPage->secondNameInput->isEnabled(), true );
	QCOMPARE( employeesPage->thirdNameInput->isEnabled(), true );
	QCOMPARE( employeesPage->birthdayInput->isEnabled(), true );
	QCOMPARE( employeesPage->passportSerialInput->isEnabled(), true );
	QCOMPARE( employeesPage->passportNumberInput->isEnabled(), true );
	QCOMPARE( employeesPage->sexCheckGroup->isEnabled(), true );
	QCOMPARE( employeesPage->maleInput->isEnabled(), true );
	QCOMPARE( employeesPage->femaleInput->isEnabled(), true );
	QCOMPARE( employeesPage->passportSourceInput->isEnabled(), true );
	QCOMPARE( employeesPage->passportIssueDate->isEnabled(), true );
	QCOMPARE( employeesPage->addressInput->isEnabled(), true );
	QCOMPARE( employeesPage->INNInput->isEnabled(), true );
	QCOMPARE( employeesPage->loginInput->isEnabled(), true );
	QCOMPARE( employeesPage->passwordInput->isEnabled(), true );

	//QCOMPARE( employeesPage->managersTable->isEnabled(), true );
	//QCOMPARE( employeesPage->addBtn->isEnabled(), true );
	QCOMPARE( employeesPage->confirmUpdateBtn->isEnabled(), true );
	QCOMPARE( employeesPage->cancelUpdateBtn->isEnabled(), true );
	QCOMPARE( employeesPage->buttonStackedWidget->currentIndex(), 1 );
}



void Test_Employees_GUI::addEmployee() {

	directAddEmployee();
	
	QString firstName = "Ivan";
	QString secondName = "Ivanov";
	QString thirdName = "Ivanovich";
	QString exp_FIO = secondName + " " + firstName + " " + thirdName;
	QDate date = QDate::currentDate();
	QString str_date = date.toString(Qt::DateFormat::LocalDate);

	Manager manager;
	manager.setFirstName( firstName );
	manager.setSecondName( secondName );
	manager.setThirdName( thirdName );
	manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
	manager.setPassportSerial( "1000" );
	manager.setPassportNumber( "100000" );
	manager.setPassportSource( "ABC" );
	manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
	manager.setAddress( "ABC" );
	manager.setINN( "012345678901" );

	addOneEmployee( manager );

	QCOMPARE( employeesPage->firstNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->secondNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->thirdNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->birthdayInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportSerialInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportNumberInput->isEnabled(), false );
	QCOMPARE( employeesPage->sexCheckGroup->isEnabled(), false );
	QCOMPARE( employeesPage->maleInput->isEnabled(), false );
	QCOMPARE( employeesPage->femaleInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportSourceInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportIssueDate->isEnabled(), false );
	QCOMPARE( employeesPage->addressInput->isEnabled(), false );
	QCOMPARE( employeesPage->INNInput->isEnabled(), false );
	QCOMPARE( employeesPage->loginInput->isEnabled(), false );
	QCOMPARE( employeesPage->passwordInput->isEnabled(), false );

	QCOMPARE( employeesPage->managersTable->isEnabled(), true );
	QCOMPARE( employeesPage->editBtn->isEnabled(), true );
	QCOMPARE( employeesPage->addBtn->isEnabled(), true );
	QCOMPARE( employeesPage->buttonStackedWidget->currentIndex(), 0 );

	QString FIO = findElemInTable( 0, 0 );
	QString res_str_date = date.toString( Qt::DateFormat::LocalDate );

	QCOMPARE( FIO, exp_FIO );
	QCOMPARE( res_str_date, str_date );
	int id = manager_DB->getAllIdAndName().last().first;
	removeEmployee( id );
	employeesPage->refreshList();
}

void Test_Employees_GUI::cancelAddEmployee() {

	directAddEmployee();

	employeesPage->cancelAddBtn->click();

	QCOMPARE( employeesPage->firstNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->secondNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->thirdNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->birthdayInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportSerialInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportNumberInput->isEnabled(), false );
	QCOMPARE( employeesPage->sexCheckGroup->isEnabled(), false );
	QCOMPARE( employeesPage->maleInput->isEnabled(), false );
	QCOMPARE( employeesPage->femaleInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportSourceInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportIssueDate->isEnabled(), false );
	QCOMPARE( employeesPage->addressInput->isEnabled(), false );
	QCOMPARE( employeesPage->INNInput->isEnabled(), false );
	QCOMPARE( employeesPage->loginInput->isEnabled(), false );
	QCOMPARE( employeesPage->passwordInput->isEnabled(), false );

	QCOMPARE( employeesPage->managersTable->isEnabled(), true );
	QCOMPARE( employeesPage->editBtn->isEnabled(), false );
	QCOMPARE( employeesPage->addBtn->isEnabled(), true );
	QCOMPARE( employeesPage->buttonStackedWidget->currentIndex(), 0 );
}

void Test_Employees_GUI::showEmployee() {

	QString firstName = "Dima";
	QString secondName = "Sokolov";
	QString thirdName = "Ivanovich";
	QString passportSerial = "1000";
	QString passportNumber = "100000";
	QString INN = "012345678901";

	Manager manager;
	manager.setFirstName( firstName );
	manager.setSecondName( secondName );
	manager.setThirdName( thirdName );
	manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
	manager.setPassportSerial( passportSerial );
	manager.setPassportNumber( passportNumber );
	manager.setPassportSource( "ABC" );
	manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
	manager.setAddress( "ABC" );
	manager.setINN( INN );

	addOneEmployee( manager );

	manager.setFirstName( "Ivan" );
	manager.setSecondName( "Ivanov" );
	manager.setThirdName( "Ivanovich" );
	manager.setPassportSerial( "1200" );
	manager.setPassportNumber( "123456" );
	manager.setINN( "123456789001" );

	addOneEmployee( manager );

	manager.setFirstName( firstName );
	manager.setSecondName( secondName );
	manager.setThirdName( thirdName );
	manager.setPassportSerial( passportSerial );
	manager.setPassportNumber( passportNumber );
	manager.setINN( INN );

	QString name = employeesPage->firstNameInput->text();
	
	employeesPage->managersTable->setFocus();
	QModelIndex newIndex = employeesPage->managersTable->model()->index(0, 0);
	employeesPage->managersTable->setCurrentIndex( newIndex );
	employeesPage->managersTable->clicked( newIndex );
	
	name = employeesPage->firstNameInput->text();

	QCOMPARE( employeesPage->firstNameInput->text(), manager.getFirstName() );
	QCOMPARE( employeesPage->secondNameInput->text(), manager.getSecondName() );
	QCOMPARE( employeesPage->thirdNameInput->text( ), manager.getThirdName() );
	QCOMPARE( employeesPage->birthdayInput->date(), manager.getDateOfBirth() );
	QCOMPARE( employeesPage->passportSerialInput->value(), manager.getPassportSerial().toInt() );
	QCOMPARE( employeesPage->passportNumberInput->value(), manager.getPassportNumber().toInt() );
	QCOMPARE( employeesPage->passportSourceInput->text(), manager.getPassportSource() );
	QCOMPARE( employeesPage->passportIssueDate->date(), manager.getPassportDateIssue() );
	QCOMPARE( employeesPage->addressInput->text(), manager.getAddress() );
	QCOMPARE( employeesPage->INNInput->text(), manager.getINN() );

	QList<QPair<int, QString>> managers = manager_DB->getAllIdAndName();
	removeEmployee( managers[0].first );
	removeEmployee( managers[1].first );
	employeesPage->refreshList();
}

void Test_Employees_GUI::updateEmployee() {

	Manager manager;
	manager.setFirstName( "Ivan" );
	manager.setSecondName( "Ivanov" );
	manager.setThirdName( "Ivanovich" );
	manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
	manager.setPassportSerial( "1000" );
	manager.setPassportNumber( "100000" );
	manager.setPassportSource( "ABC" );
	manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
	manager.setAddress( "ABC" );
	manager.setINN( "012345678901" );

	addOneEmployee( manager );

	directUpdateEmployee();

	QString firstName = "Dima";
	QString secondName = "Sokolov";
	QString thirdName = "Ivanovich";
	QString exp_FIO = secondName + " " + firstName + " " + thirdName;
	QDate date = QDate::currentDate();
	QString str_date = date.toString(Qt::DateFormat::LocalDate);

	employeesPage->firstNameInput->setText( firstName );
	employeesPage->secondNameInput->setText( secondName );
	employeesPage->thirdNameInput->setText( thirdName );

	employeesPage->confirmUpdateBtn->click();
	employeesPage->refreshList();

	QString FIO = findElemInTable( 0, 0 );
	QString res_str_date = date.toString( Qt::DateFormat::LocalDate );

	QCOMPARE( FIO, exp_FIO );
	QCOMPARE( res_str_date, str_date );
	int id = manager_DB->getAllIdAndName().last().first;
	removeEmployee( id );
	employeesPage->refreshList();
}

void Test_Employees_GUI::cancelUpdateEmployee() {

	Manager manager;
	manager.setFirstName( "Ivan" );
	manager.setSecondName( "Ivanov" );
	manager.setThirdName( "Ivanovich" );
	manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
	manager.setPassportSerial( "1000" );
	manager.setPassportNumber( "100000" );
	manager.setPassportSource( "ABC" );
	manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
	manager.setAddress( "ABC" );
	manager.setINN( "012345678901" );

	addOneEmployee( manager );

	directUpdateEmployee();

	employeesPage->cancelUpdateBtn->click();

	QCOMPARE( employeesPage->firstNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->secondNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->thirdNameInput->isEnabled(), false );
	QCOMPARE( employeesPage->birthdayInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportSerialInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportNumberInput->isEnabled(), false );
	QCOMPARE( employeesPage->sexCheckGroup->isEnabled(), false );
	QCOMPARE( employeesPage->maleInput->isEnabled(), false );
	QCOMPARE( employeesPage->femaleInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportSourceInput->isEnabled(), false );
	QCOMPARE( employeesPage->passportIssueDate->isEnabled(), false );
	QCOMPARE( employeesPage->addressInput->isEnabled(), false );
	QCOMPARE( employeesPage->INNInput->isEnabled(), false );
	QCOMPARE( employeesPage->loginInput->isEnabled(), false );
	QCOMPARE( employeesPage->passwordInput->isEnabled(), false );

	QCOMPARE( employeesPage->managersTable->isEnabled(), true );
	QCOMPARE( employeesPage->editBtn->isEnabled(), true );
	QCOMPARE( employeesPage->addBtn->isEnabled(), true );
	QCOMPARE( employeesPage->buttonStackedWidget->currentIndex(), 0 );

	int id = manager_DB->getAllIdAndName().last().first;
	removeEmployee( id );
	employeesPage->refreshList();
}

