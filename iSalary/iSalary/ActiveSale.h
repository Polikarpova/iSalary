#pragma once
#include "sale.h"
class ActiveSale : public Sale {
private:
	Product product;
	bool isConfirm;
	QDate confirmDate;

public:
	ActiveSale(void);
	~ActiveSale(void);

	void confirm();
	void cancelConfirm();
};

