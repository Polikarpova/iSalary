#include "Sale.h"


Sale::Sale(void)
{
}


Sale::~Sale(void)
{
}

void Sale::setId( int _id ) {
	id = _id;
}
int Sale::getId() {
	return id;
}


void Sale::setSaleDate( QDate _saleDate ) {
	saleDate = _saleDate;
}
QDate Sale::getSaleDate() {
	return saleDate;
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


void Sale::setSalerId( int _id ) {
	saler_id = _id;
}
int Sale::getSalerId() {
	return saler_id;
}


void Sale::setSaler( Manager _saler ) {
	saler = _saler;
}
Manager Sale::getSaler() {
	return saler;
}


void Sale::setProductId( int _id ) {
	product_id = _id;
}
int Sale::getProductId() {
	return product_id;
}