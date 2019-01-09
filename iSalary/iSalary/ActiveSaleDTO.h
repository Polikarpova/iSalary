#pragma once

#include "ProductDTO.h"
#include <qdatetime.h>
#include <qstring.h>

/**
* Структура, описывающая активную продажу
*/
struct ActiveSaleDTO {
	
	int id;
	QString managerName;
	ProductDTO product;
	double price;
	int count;
	bool isConfirm;
	QDate confirmDate;
	QDate saleDate;
};