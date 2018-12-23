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
	int id;
	QDate saleDate;
	double cost;
	int count;
	int saler_id;
	Manager saler;
	int product_id;
	SaleStatus status;
	
public:
	Sale(void);
	~Sale(void);

	void setId( int _id );
	int getId();

	void setSaleDate( QDate _saleDate );
	QDate getSaleDate();

	void setCost( double _cost );
	double getCost();

	void setCount( int _count );
	int getCount();

	void setSalerId( int _id );
	int getSalerId();

	void setSaler( Manager _saler );
	Manager getSaler();

	void setProductId( int _id );
	int getProductId();

	virtual void setProduct( Product product ) = 0 {};
	virtual Product getProduct() = 0 {};

	virtual QString getProductName() = 0 {};
	virtual double getProductCommission() = 0 {};
};