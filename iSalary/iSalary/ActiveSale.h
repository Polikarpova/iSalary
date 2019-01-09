#pragma once
#include "Product.h"
#include "Sale.h"

class ActiveSale : public Sale {
  private:
    Product product;
    bool isConfirm;
    QDate confirmDate;

  public:
    ActiveSale( void );
    ~ActiveSale( void );

    void confirm();
    void cancelConfirm();

    bool isConfirmed();
    QString getProductName();
    double getProductCommission();
    Product getProduct();
    QDate getConfirmDate();
    void setConfirmDate( const QDate &date );

    void setProduct( Product product );
};