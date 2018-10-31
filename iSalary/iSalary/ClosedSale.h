#pragma once
#include "sale.h"
class ClosedSale : public Sale {

private:
	// QVector<SaleCorrectionData> correctionHistory;
	bool isRemoved;
	QString productName;
	double productCommission;

public:
	ClosedSale(void);
	~ClosedSale(void);

	// void correctSale( QVector<SaleCorrectionData> correction );
	void remove();
	void restore();
	QString getProductName() override;
	double getProductCommission() override;
	void setProduct( Product product ) override;
	Product getProduct() override;
};

