#pragma once

#include "ProductDTO.h"
#include <qdatetime.h>
#include <qstring.h>

struct ActiveSaleDTO {
	
	int id;
	QString managerName;
	ProductDTO product;
	double price;
	int count;
	bool isConfirm;
	QDate confirmDate; /*???*/
};