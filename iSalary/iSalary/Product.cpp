#include "Product.h"

Product::Product( void ) {
    id = 0;
    isDeleted = false;
}

Product::~Product( void ) {}

void Product::setId( int _id ) { id = _id; }

int Product::getId() { return id; }

void Product::setName( QString _name ) { name = _name; }

QString Product::getName() { return name; }

void Product::setCommission( double _commission ) { commission = _commission; }

double Product::getCommission() { return commission; }

void Product::setIsDeleted( bool value ) { isDeleted = value; }

bool Product::getIsDeleted() { return isDeleted; }