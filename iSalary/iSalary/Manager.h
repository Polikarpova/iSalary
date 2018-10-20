#pragma once
#include "user.h"
#include <QString>
#include <QDate>
class Manager : public User {
private:
	QString firstName;
	QString secondName;
	QString thirdName;
	QDate dateOfBirth;
	bool isMale;
	QString passportSerial;
	QString passportNumber;
	QString passportIssued;
	QDate passportIssueDate;
	QString placeOfRegistration;
	QString INN;
	QString email;
	QString mobileNumber;
	QDate dateOfEmployment;

public:
	Manager(void);
	Manager( 
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
	);
	~Manager(void);

	void setFirstName( QString _firstName );
	QString getFirstName();


	void setSecondName( QString _secondName );
	QString getSecondName();


	void setThirdName( QString _thirdName );
	QString getThirdName();


	void setDateOfBirth( QDate _dateOfBirth );
	QDate getDateOfBirth();


	void setIsMale( bool _isMale );
	bool getIsMale();


	void setPassportSerial( QString _passportSerial );
	QString getPassportSerial();


	void setPassportNumber( QString _passportNumber );
	QString getPassportNumber();


	void setPassportIssued( QString _passportIssued );
	QString getPassportIssued();


	void setPassportIssueDate( QDate _passportIssueDate );
	QDate getPassportIssueDate();


	void setPlaceOfRegistration( QString _placeOfRegistration );
	QString getPlaceOfRegistration();


	void setINN( QString _INN );
	QString getINN();


	void setEmail( QString _email );
	QString getEmail();


	void setMobileNumber( QString _mobileNumber );
	QString getMobileNumber();


	void setDateOfEmployment( QDate _dateOfEmployment );
	QDate getDateOfEmployment();
};

