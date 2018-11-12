#pragma once
#include "Product.h"
#include <qvector.h>
#include <qstring.h>
struct ProductDTO {
	Product product;
	QVector<Product>products;
	bool isSuccess;
	bool isEmpty;

	QString name;
	double commission;
	int id;
};

