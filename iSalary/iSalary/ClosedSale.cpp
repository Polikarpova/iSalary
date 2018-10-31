#include "ClosedSale.h"


ClosedSale::ClosedSale(void)
{
}


ClosedSale::~ClosedSale(void)
{
}

QString ClosedSale::getProductName() {
	return productName;
}

double ClosedSale::getProductCommission() {
	return productCommission;
}

void ClosedSale::setProduct( Product _product ){
	productName = _product.getName();
	productCommission = _product.getCommission();
}

Product ClosedSale::getProduct() {
	Product product;
	product.setName( productName );
	product.setCommission( productCommission );
	return product;
}