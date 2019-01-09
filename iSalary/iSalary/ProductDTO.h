#pragma once
#include "Product.h"
#include <qstring.h>
#include <qvector.h>
struct ProductDTO {
    Product product;
    QVector<Product> products;
    bool isSuccess;
    bool isEmpty;

    QString name;
    double commission;
    int id;
};
