#pragma once

#include "ProductDTO.h"
#include <qdatetime.h>

struct ActiveSaleDTO {
	
	int id;
	ProductDTO product;
	bool isConfirm;
	QDate confirmDate;
};