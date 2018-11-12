#include "ActiveSale.h"


ActiveSale::ActiveSale(void)
{
	isConfirm = false;
}


ActiveSale::~ActiveSale(void)
{
}

void ActiveSale::confirm() {
	isConfirm = true;
}

void ActiveSale::cancelConfirm() {
	isConfirm = false;
}

bool ActiveSale::isConfirmed() {
	return isConfirm;
}

QString ActiveSale::getProductName() {
	return product.getName();
}

double ActiveSale::getProductCommission() {
	return product.getCommission();
}

void ActiveSale::setProduct( Product _product ) {
	product = _product;
}

Product ActiveSale::getProduct() {
	return product;
}