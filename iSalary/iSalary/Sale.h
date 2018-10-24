#pragma once
#include <QDate>
#include "Manager.h"
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
	Manager saler;
	SaleStatus status;

public:
	Sale(void);
	~Sale(void);

	
};

