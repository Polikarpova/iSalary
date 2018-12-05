#pragma once
#include <QString>
class Product {
private:
	QString name;
	double commission;
	int id;
	bool isDeleted;

public:
	Product(void);
	~Product(void);

	void setId( int _id );
	int getId();

	void setName( QString _name );
	QString getName();

	void setCommission( double _commission );
	double getCommission();

	void setIsDeleted( bool value );
	bool getIsDeleted();
};

