#ifndef TEST_PRODUCT_GUI_H
#define TEST_PRODUCT_GUI_H

#include "ProductPage.h"
#include "Product_DB.h"
#include "QTextCodec"
#include <QObject>
#include <QSqlDatabase>
#include <qtest.h>

class Test_Product_GUI : public QObject {
    Q_OBJECT
    friend class ProductPage;

  public:
    Test_Product_GUI( QSqlDatabase *sql, ProductPage *productPage );
    ~Test_Product_GUI();

  private:
    ProductPage *productPage;
    Product_DB *product_DB;
    QSqlDatabase *sql;

    void removeProduct( QString productName );
    Product createProduct( QString productName, double productCommission );
    QString findElemInTable( int row, int col );
    void directAddProduct();
    void directUpdateProduct();

  private slots:
    void addProduct();
    void cancelAddProduct();

    void showProduct();

    void deleteProduct();

    void updateProduct();
    void cancelUpdateProduct();

    void searchProduct();
};

#endif // TEST_PRODUCT_GUI_H
