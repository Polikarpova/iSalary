#include "Manager.h"


Manager::Manager(void) {
	dateOfEmployment = QDate::currentDate();
}
Manager::Manager(
	QString _firstName,
	QString _secondName,
	QString _thirdName,
	QDate _dateOfBirth,
	bool _isMale,
	QString _passportSerial,
	QString _passportNumber,
	QString _passportIssued,
	QDate _passportIssueDate,
	QString _placeOfRegistration,
	QString _INN,
	QString _email,
	QString _mobileNumber,
	QDate _dateOfEmployment
) {
	firstName = _firstName;
	secondName = _secondName;
	thirdName = _thirdName;
	dateOfBirth = _dateOfBirth;
	isMale = _isMale;
	passportSerial = _passportSerial;
	passportNumber = _passportNumber;
	passportIssued = _passportIssued;
	passportIssueDate = _passportIssueDate;
	placeOfRegistration = _placeOfRegistration;
	INN = _INN;
	email = _email;
	mobileNumber = _mobileNumber;
	dateOfEmployment = _dateOfEmployment;
}
Manager::~Manager(void) {
}


void Manager::setId( int _id ) {
	id = _id;
}
int Manager::getId() {
	return id;
}


void Manager::setFirstName( QString _firstName ) {
	firstName = _firstName;
}
QString Manager::getFirstName() {
	return firstName;
}


void Manager::setSecondName( QString _secondName ) {
	secondName = _secondName;
}
QString Manager::getSecondName() {
	return secondName;
}


void Manager::setThirdName( QString _thirdName ) {
	thirdName = _thirdName;
}
QString Manager::getThirdName() {
	return thirdName;
}


void Manager::setDateOfBirth( QDate _dateOfBirth ) {
	dateOfBirth = _dateOfBirth;
}
QDate Manager::getDateOfBirth() {
	return dateOfBirth;
}


void Manager::setIsMale( bool _isMale ) {
	isMale = _isMale;
}
bool Manager::getIsMale() {
	return isMale;
}


void Manager::setPassportSerial( QString _passportSerial ) {
	passportSerial = _passportSerial;
}
QString Manager::getPassportSerial() {
	return passportSerial;
}


void Manager::setPassportNumber( QString _passportNumber ) {
	passportNumber = _passportNumber;
}
QString Manager::getPassportNumber() {
	return passportNumber;
}


void Manager::setPassportIssued( QString _passportIssued ) {
	passportIssued = _passportIssued;
}
QString Manager::getPassportIssued() {
	return passportIssued;
}


void Manager::setPassportIssueDate( QDate _passportIssueDate ) {
	passportIssueDate = _passportIssueDate;
}
QDate Manager::getPassportIssueDate() {
	return passportIssueDate;
}


void Manager::setPlaceOfRegistration( QString _placeOfRegistration ) {
	placeOfRegistration = _placeOfRegistration;
}
QString Manager::getPlaceOfRegistration() {
	return placeOfRegistration;
}


void Manager::setINN( QString _INN ) {
	INN = _INN;
}
QString Manager::getINN() {
	return INN;
}


void Manager::setEmail( QString _email ) {
	email = _email;
}
QString Manager::getEmail() {
	return email;
}


void Manager::setMobileNumber( QString _mobileNumber ) {
	mobileNumber = _mobileNumber;
}
QString Manager::getMobileNumber() {
	return mobileNumber;
}


void Manager::setDateOfEmployment( QDate _dateOfEmployment ) {
	dateOfEmployment = _dateOfEmployment;
}
QDate Manager::getDateOfEmployment() {
	return dateOfEmployment;
}