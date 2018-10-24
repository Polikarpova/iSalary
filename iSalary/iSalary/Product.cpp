#include "Product.h"


Product::Product(void)
{
}


Product::~Product(void)
{
}

void Product::setId( int _id ){
	id = _id;
}

int Product::getId() {
	return id;
}

void Product::setName( QString _name) {
	name = _name;
}

QString Product::getName() {
	return name;
}

void Product::setCommission( double _commission) {
	commission = _commission;
}

double Product::getCommission() {
	return commission;
}