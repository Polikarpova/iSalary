#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)	: QMainWindow(parent)
{
	ui.setupUi(this);
	c = QTextCodec::codecForLocale();
	managersTableModel = new QStandardItemModel;
	QStringList horizontalHeader;
    horizontalHeader.append( c->toUnicode( "ФИО" ) );
    horizontalHeader.append( c->toUnicode( "Дата принятия" ) );
	managersTableModel->setHorizontalHeaderLabels( horizontalHeader );
	ui.managersTable->setModel( managersTableModel );
    ui.managersTable->resizeColumnsToContents();

	count = 0;

	connect( ui.newManagerButton, SIGNAL( clicked() ), this, SLOT( directAddManager() ) );
	connect( ui.submitAddManager, SIGNAL( clicked() ), this, SLOT( addManager() ) );
	
}

MainWindow::~MainWindow()
{

}

void MainWindow::directAddManager() {
	ui.addManagerButtons->setCurrentIndex( 1 );
	setInputsVisible( true );
}

void MainWindow::setInputsVisible( bool isEnabled ) {
	ui.firstName->setEnabled( isEnabled );
	ui.secondName->setEnabled( isEnabled );
	ui.thirdName->setEnabled( isEnabled );
	ui.dateOfBirth->setEnabled( isEnabled );
	ui.sexGroup->setEnabled ( isEnabled );
	ui.maleRButton->setEnabled( isEnabled );
	ui.femaleRButton->setEnabled( isEnabled );
	ui.serial->setEnabled( isEnabled );
	ui.number->setEnabled( isEnabled );
	ui.passport->setEnabled( isEnabled );
	ui.datePassport->setEnabled( isEnabled );
	ui.placeOfRegistration->setEnabled( isEnabled );
	ui.INN->setEnabled( isEnabled );
}

void MainWindow::addManager() {
	Manager manager;
	fillManager( manager );
    
	int idx = count;
	QStandardItem *item;
	QString fullName = manager.getSecondName() + " " + manager.getFirstName() + " " + manager.getThirdName();
	item = new QStandardItem( fullName );
    managersTableModel->setItem( idx, 0, item );
	item = new QStandardItem( manager.getDateOfEmployment().toString( "dd.MM.yyyy" ) );
    managersTableModel->setItem( idx, 1, item );
	count++;
	ui.addManagerButtons->setCurrentIndex( 0 );
	setInputsVisible(false);
}

void MainWindow::fillManager( Manager & manager ) {
	manager.setFirstName( ui.firstName->text() );
	manager.setSecondName( ui.secondName->text() );
	manager.setThirdName( ui.thirdName->text() );
	manager.setDateOfBirth( ui.dateOfBirth->date() );
	manager.setIsMale( ui.maleRButton->isChecked() );
	manager.setPassportSerial( QString::number( ui.serial->value() ) );
	manager.setPassportNumber( QString::number( ui.number->value() ) );
	manager.setPassportIssued( ui.passport->text() );
	manager.setPassportIssueDate( ui.datePassport->date() );
	manager.setPlaceOfRegistration( ui.placeOfRegistration->text() );
	manager.setINN( ui.INN->text() );
}