#pragma once
#include "ActiveSale.h"
#include <qvector.h>
struct SaleDTO {
    ActiveSale activeSale;
    QVector<ActiveSale> activeSales;
    bool isSuccess;
    bool isEmpty;
};