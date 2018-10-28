#include "Sale.h"


Sale::Sale(void)
{
}


Sale::~Sale(void)
{
}

void Sale::setCost( double _cost ) {
	cost = _cost;
}

double Sale::getCost() {
	return cost;
}

void Sale::setCount( int _count ) {
	count = _count;
}

int Sale::getCount() {
	return count;
}

void Sale::setSaler( Manager _saler ) {
	saler = _saler;
}

Manager Sale::getSaler() {
	return saler;
}

void Sale::setProduct( Product _product ) {
	product = _product;
}

Product Sale::getProduct() {
	return product;
}