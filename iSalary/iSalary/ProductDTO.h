#pragma once
#include "Product.h"
#include <qvector.h>
struct ProductDTO {
	Product product;
	QVector<Product>products;
	bool isSuccess;
	bool isEmpty;
};