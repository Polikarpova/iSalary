#pragma once
#include <QDate>
#include "Manager.h"
#include "Product.h"

enum SaleStatus {
	CREATED,
	CONFIRMED,
	REMOVED
};

class Sale {
private:
	QDate saleDate;
	double cost;
	int count;
	Manager saler;
	Product product;
	SaleStatus status;
	
public:
	Sale(void);
	~Sale(void);

	void setCost( double _cost );
	double getCost();

	void setCount( int _count );
	int getCount();

	void setSaler( Manager _saler );
	Manager getSaler();

	void setProduct( Product product );
	Product getProduct();
};

