#pragma once
#include "Sale.h"

class ClosedSale : public Sale {

  private:
    // QVector<SaleCorrectionData> correctionHistory;
    bool isRemoved;
    QString productName;
    double productCommission;

  public:
    ClosedSale( void );
    ~ClosedSale( void );

    // void correctSale( QVector<SaleCorrectionData> correction );
    void remove();
    void restore();
    QString getProductName();
    double getProductCommission();
    void setProduct( Product _product );
    Product getProduct();
};