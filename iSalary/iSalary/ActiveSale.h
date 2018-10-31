#pragma once
#include "sale.h"
#include "product.h"
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
	bool isConfirmed();
	QString getProductName() override;
	double getProductCommission() override;
	void setProduct( Product product ) override;
	Product getProduct() override;
};

