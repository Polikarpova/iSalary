#pragma once
#include <QDate>

enum SaleStatus {
	CREATED,
	CONFIRMED,
	REMOVED
};

class Sale {
private:
	double cost;
	QDate saleDate;
	int count;
	Saler saler;
	SaleStatus status;

public:
	Sale(void);
	~Sale(void);

	
};

