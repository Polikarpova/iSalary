#include "test_product_gui.h"

Test_Product_GUI::Test_Product_GUI( QSqlDatabase *sql, ProductPage *productPage ) {
	this->productPage = productPage;
	this->sql = sql;
	product_DB = new Product_DB( sql, "products" );
	product_DB->init();
}

Test_Product_GUI::~Test_Product_GUI() {

}

void Test_Product_GUI::removeProduct( QString productName ) {
	Product product = product_DB->findByName( productName );
	QSqlQuery query("DELETE FROM products WHERE id = " + QString::number( product.getId() ), *sql);
	bool isOk = query.exec();
}

Product Test_Product_GUI::createProduct( QString productName, double productCommission ) {
	Product product;
	product.setName( productName );
	product.setCommission( productCommission );
	product_DB->create( product );
	return product;
} 

QString Test_Product_GUI::findElemInTable( int row, int col ){
	return productPage->productsTableModel->data( productPage->productsTableModel->index( row, col ) ).toString();
}



void Test_Product_GUI::directAddProduct() {

	productPage->addProductButton->click();

	QCOMPARE( productPage->productSearchInput->isEnabled(), false );
	QCOMPARE( productPage->productTable->isEnabled(), false );
	QCOMPARE( productPage->addProductButton->isEnabled(), false );
	QCOMPARE( productPage->productNameInput->isEnabled(), true );
	QCOMPARE( productPage->productPercentInput->isEnabled(), true );
	QCOMPARE( productPage->productButtonsStackedWidget->currentIndex(), 2 );

	QCOMPARE( productPage->productNameInput->text(), QString( "" ) );
	QCOMPARE( productPage->productPercentInput->value(), 0.01 );
}

void Test_Product_GUI::addProduct() {
	
	directAddProduct();
	Product product;
	product.setName( "Abc" );
	product.setCommission( 3.5 );

	productPage->productNameInput->setText( product.getName() );
	productPage->productPercentInput->setValue( product.getCommission() );
	productPage->productSubmitAddButton->click();

	QCOMPARE( productPage->productSearchInput->isEnabled(), true );
	QCOMPARE( productPage->productTable->isEnabled(), true );
	QCOMPARE( productPage->addProductButton->isEnabled(), true );
	QCOMPARE( productPage->productNameInput->isEnabled(), false );
	QCOMPARE( productPage->productPercentInput->isEnabled(), false );
	QCOMPARE( productPage->productButtonsStackedWidget->currentIndex(), 0 );

	QString productName = findElemInTable( 0, 0 );
	QString productPercent = findElemInTable( 0, 1 );

	QCOMPARE( productName, product.getName() );
	QCOMPARE( productPercent, QString::number( product.getCommission() ) + "%");

	removeProduct( productName );
}

void Test_Product_GUI::cancelAddProduct() {
	
	directAddProduct();
	Product product;
	product.setName( "Abc" );
	product.setCommission( 3.5 );

	productPage->productNameInput->setText( product.getName() );
	productPage->productPercentInput->setValue( product.getCommission() );
	productPage->productCancelAddButton->click();

	QCOMPARE( productPage->productSearchInput->isEnabled(), true );
	QCOMPARE( productPage->productTable->isEnabled(), true );
	QCOMPARE( productPage->addProductButton->isEnabled(), true );
	QCOMPARE( productPage->productNameInput->isEnabled(), false );
	QCOMPARE( productPage->productPercentInput->isEnabled(), false );
	QCOMPARE( productPage->productButtonsStackedWidget->currentIndex(), 0 );

	productPage->productNameInput->clear();
	productPage->productPercentInput->clear();
}



void Test_Product_GUI::showProduct() {

	QCOMPARE( productPage->editProductButton->isEnabled(), false );
	QCOMPARE( productPage->deleteProductButton->isEnabled(), false );

	createProduct( "AAA", 1.9 );
	productPage->refreshPage();
	productPage->productTable->setFocus();
	QModelIndex newIndex = productPage->productTable->model()->index(0, 0);
	productPage->productTable->setCurrentIndex(newIndex);
	
	QCOMPARE( productPage->editProductButton->isEnabled(), true );
	QCOMPARE( productPage->deleteProductButton->isEnabled(), true );

	QString productName = findElemInTable( 0, 0 );
	QString productPercent = findElemInTable( 0, 1 );

	QCOMPARE( productPage->productNameInput->text(), productName );
	QCOMPARE( QString::number( productPage->productPercentInput->value() ) + "%", productPercent );
	removeProduct( "AAA" );
	productPage->refreshPage();
}

void Test_Product_GUI::deleteProduct() {

	QCOMPARE( productPage->editProductButton->isEnabled(), false );
	QCOMPARE( productPage->deleteProductButton->isEnabled(), false );

	createProduct( "AAA", 1.9 );
	productPage->refreshPage();
	productPage->productTable->setFocus();
	QModelIndex newIndex = productPage->productTable->model()->index(0, 0);
	productPage->productTable->setCurrentIndex(newIndex);
	
	QCOMPARE( productPage->editProductButton->isEnabled(), true );
	QCOMPARE( productPage->deleteProductButton->isEnabled(), true );
	
	productPage->deleteProductButton->click();

	QCOMPARE( productPage->editProductButton->isEnabled(), false );
	QCOMPARE( productPage->deleteProductButton->isEnabled(), false );
	QCOMPARE( productPage->productSearchInput->isEnabled(), true );
	QCOMPARE( productPage->productTable->isEnabled(), true );
	QCOMPARE( productPage->addProductButton->isEnabled(), true );
	QCOMPARE( productPage->productNameInput->isEnabled(), false );
	QCOMPARE( productPage->productPercentInput->isEnabled(), false );
	QCOMPARE( productPage->productButtonsStackedWidget->currentIndex(), 0 );
	QCOMPARE( productPage->productNameInput->text(), QString( "" ) );
	QCOMPARE( productPage->productPercentInput->value(), 0.01 );

	QString productName = findElemInTable( 0, 0 );
	QString productPercent = findElemInTable( 0, 1 );

	QCOMPARE( productName, QString( "" ) );
	QCOMPARE( productPercent, QString( "" ) );
	removeProduct( "AAA" );
}



void Test_Product_GUI::directUpdateProduct() {

	QCOMPARE( productPage->editProductButton->isEnabled(), false );
	QCOMPARE( productPage->deleteProductButton->isEnabled(), false );

	productPage->refreshPage();
	productPage->productTable->setFocus();
	QModelIndex newIndex = productPage->productTable->model()->index(0, 0);
	productPage->productTable->setCurrentIndex(newIndex);
	
	QCOMPARE( productPage->editProductButton->isEnabled(), true );
	QCOMPARE( productPage->deleteProductButton->isEnabled(), true );

	productPage->editProductButton->click();

	QCOMPARE( productPage->productSearchInput->isEnabled(), false );
	QCOMPARE( productPage->productTable->isEnabled(), false );
	QCOMPARE( productPage->addProductButton->isEnabled(), false );
	QCOMPARE( productPage->productNameInput->isEnabled(), true );
	QCOMPARE( productPage->productPercentInput->isEnabled(), true );
	QCOMPARE( productPage->productButtonsStackedWidget->currentIndex(), 1 );

	QString productName = findElemInTable( 0, 0 );
	QString productPercent = findElemInTable( 0, 1 );

	QCOMPARE( productPage->productNameInput->text(), productName );
	QCOMPARE( QString::number( productPage->productPercentInput->value() ) + "%", productPercent );
}

void Test_Product_GUI::updateProduct() {

	createProduct( "AAA", 1.9 );
	directUpdateProduct();

	QString newProductName = "ABC";
	productPage->productNameInput->setText( newProductName );

	productPage->saveProductButton->click();

	QCOMPARE( productPage->editProductButton->isEnabled(), true );
	QCOMPARE( productPage->deleteProductButton->isEnabled(), true );
	QCOMPARE( productPage->productSearchInput->isEnabled(), true );
	QCOMPARE( productPage->productTable->isEnabled(), true );
	QCOMPARE( productPage->addProductButton->isEnabled(), true );
	QCOMPARE( productPage->productNameInput->isEnabled(), false );
	QCOMPARE( productPage->productPercentInput->isEnabled(), false );
	QCOMPARE( productPage->productButtonsStackedWidget->currentIndex(), 0 );

	QString productName = findElemInTable( 0, 0 );
	QString productPercent = findElemInTable( 0, 1 );

	QCOMPARE( newProductName, productName );
	QCOMPARE( productPercent, QString( "1.9%" ) );
	QCOMPARE( productPage->productNameInput->text(), productName );
	QCOMPARE( QString::number( productPage->productPercentInput->value() ) + "%", productPercent );
	removeProduct( newProductName );
	productPage->refreshPage();
}

void Test_Product_GUI::cancelUpdateProduct() {

	QString exp_product_name = "AAA";
	double product_commission = 1.9;
	QString exp_product_commission = QString::number( product_commission ) + "%";

	createProduct( exp_product_name, product_commission );
	directUpdateProduct();

	productPage->cancelProductButton->click();

	QCOMPARE( productPage->editProductButton->isEnabled(), true );
	QCOMPARE( productPage->deleteProductButton->isEnabled(), true );
	QCOMPARE( productPage->productSearchInput->isEnabled(), true );
	QCOMPARE( productPage->productTable->isEnabled(), true );
	QCOMPARE( productPage->addProductButton->isEnabled(), true );
	QCOMPARE( productPage->productNameInput->isEnabled(), false );
	QCOMPARE( productPage->productPercentInput->isEnabled(), false );
	QCOMPARE( productPage->productButtonsStackedWidget->currentIndex(), 0 );

	QString productName = findElemInTable( 0, 0 );
	QString productPercent = findElemInTable( 0, 1 );

	QCOMPARE( exp_product_name, productName );
	QCOMPARE( exp_product_commission, productPercent );
	QCOMPARE( productPage->productNameInput->text(), productName );
	QCOMPARE( QString::number( productPage->productPercentInput->value() ) + "%", productPercent );
	removeProduct( productName );
	productPage->refreshPage();
}



void Test_Product_GUI::searchProduct() {
	
	Product firstProduct, secondProduct;
	firstProduct.setName( "AAA" );
	firstProduct.setCommission( 1.9 );
	secondProduct.setName( "ABC" );
	secondProduct.setCommission( 33.5 );

	createProduct( firstProduct.getName(), firstProduct.getCommission() );
	createProduct( secondProduct.getName(), secondProduct.getCommission() );

	productPage->refreshPage();
	productPage->productSearchInput->setText( "A" );

	QString firstProductName = findElemInTable( 0, 0 );
	QString firstProductPercent = findElemInTable( 0, 1 );
	QString secondProductName = findElemInTable( 1, 0 );
	QString secondProductPercent = findElemInTable( 1, 1 );

	QCOMPARE( firstProductName, firstProduct.getName() );
	QCOMPARE( firstProductPercent, QString::number( firstProduct.getCommission() ) + "%" );
	QCOMPARE( secondProductName, secondProduct.getName() );
	QCOMPARE( secondProductPercent, QString::number( secondProduct.getCommission() ) + "%" );

	productPage->productSearchInput->setText( "AA" );

	firstProductName = findElemInTable( 0, 0 );
	firstProductPercent = findElemInTable( 0, 1 );
	secondProductName = findElemInTable( 1, 0 );
	secondProductPercent = findElemInTable( 1, 1 );

	QCOMPARE( firstProductName, firstProduct.getName() );
	QCOMPARE( firstProductPercent, QString::number( firstProduct.getCommission() ) + "%" );
	QCOMPARE( secondProductName, QString( "" ) );
	QCOMPARE( secondProductPercent, QString( "" ) );

	productPage->productSearchInput->clear();
	removeProduct( firstProduct.getName() );
	removeProduct( secondProduct.getName() );
	productPage->refreshPage();
}