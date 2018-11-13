#include "ProductPage.h"


ProductPage::ProductPage( ProductFacade *productFacade ) {
	this->productFacade = productFacade;
}

ProductPage::~ProductPage() {

}

void ProductPage::setUI(
	QLineEdit *productSearchInput, 
	QPushButton *searchButton,
	QTableView *productTable,
	QLineEdit *productNameInput,
	QDoubleSpinBox *productPercentInput,
	QStackedWidget *productButtonsStackedWidget,
	QPushButton *addProductButton,
	QPushButton *deleteProductButton,
	QPushButton *editProductButton,
	QPushButton *cancelProductButton,
	QPushButton *saveProductButton,
	QPushButton *productCancelAddButton,
	QPushButton *productSubmitAddButton
) {
	this->productSearchInput = productSearchInput;
	this->searchButton = searchButton;
	this->productTable = productTable;
	this->productNameInput = productNameInput;
	this->productPercentInput = productPercentInput;
	this->productButtonsStackedWidget = productButtonsStackedWidget;
	this->addProductButton = addProductButton;
	this->deleteProductButton = deleteProductButton;
	this->editProductButton = editProductButton;
	this->cancelProductButton = cancelProductButton;
	this->saveProductButton = saveProductButton;
	this->productCancelAddButton = productCancelAddButton;
	this->productSubmitAddButton = productSubmitAddButton;

	c = QTextCodec::codecForLocale();
	productsTableModel = new QStandardItemModel;
	fillProducts();
	status = DEFAULT;

	productTable->setEditTriggers(0);
	connect( this->productTable->selectionModel(), SIGNAL( currentChanged ( const QModelIndex &, const QModelIndex & ) ), this, SLOT( showProduct() ) );
	connect( this->addProductButton, SIGNAL( clicked() ), this, SLOT( directAddProduct() ) );
	connect( this->productCancelAddButton, SIGNAL( clicked() ), this, SLOT( directAddProduct() ) );
	connect( this->productSubmitAddButton, SIGNAL( clicked() ), this, SLOT( addProduct() ) );
	connect( this->editProductButton, SIGNAL( clicked() ), this, SLOT( directUpdateProduct() ) );
	connect( this->cancelProductButton, SIGNAL( clicked() ), this, SLOT( directUpdateProduct() ) );
	connect( this->saveProductButton, SIGNAL( clicked() ), this, SLOT( updateProduct() ) );
	connect( this->deleteProductButton, SIGNAL( clicked() ), this, SLOT( removeProduct() ) );
	connect( this->searchButton, SIGNAL( clicked() ), this, SLOT( searchProduct() ) );
}

void ProductPage::setInputsEnabledPageProducts( bool isEnabled ) {
	productNameInput->setEnabled( isEnabled );
	productPercentInput->setEnabled( isEnabled );
}

void ProductPage::clearInputsPageProducts() {
	productNameInput->clear();
	productPercentInput->clear();
}

void ProductPage::directAddProduct() {
	if ( status == DEFAULT ) {
		productButtonsStackedWidget->setCurrentIndex( 2 );
		addProductButton->setEnabled( false );
		productTable->setEnabled( false );
		setInputsEnabledPageProducts( true );
		clearInputsPageProducts();
		status = ADD_PRODUCT;
	} else {
		productButtonsStackedWidget->setCurrentIndex( 0 );
		addProductButton->setEnabled( true );
		productTable->setEnabled( true );
		setInputsEnabledPageProducts( false );
		status = DEFAULT;
	}
}

void ProductPage::addProduct() {
	Product product;
	fillProduct( product );
	ProductDTO result = productFacade->addProduct( product );
	if ( result.isSuccess == true ) {
		fillProducts();
		directAddProduct();
	} else {
		
	}
}

void ProductPage::directUpdateProduct() {
	bool isSelected = !productTable->selectionModel()->selectedIndexes().empty();
	if ( status == DEFAULT && isSelected == true ) {
		productButtonsStackedWidget->setCurrentIndex( 1 );
		productTable->setEnabled( false );
		setInputsEnabledPageProducts( true );
		status = UPDATE_PRODUCT;
	} else {
		productButtonsStackedWidget->setCurrentIndex( 0 );
		productTable->setEnabled( true );
		setInputsEnabledPageProducts( false );
		status = DEFAULT;
	}
}

void ProductPage::updateProduct() {
	QString productName = productsTableModel->data( productsTableModel->index( productTable->currentIndex().row(), 0 ) ).toString();
	ProductDTO result = productFacade->findByName( productName );
	if ( result.isSuccess == true ) {
		Product product = result.product;
		fillProduct( product );
		result = productFacade->updateProduct( product );
		if (result.isSuccess == true) {
			fillProducts();
			directUpdateProduct();
		}
	}
	
	if ( result.isSuccess == false) {
		
	}
}

void ProductPage::removeProduct() {
	bool isSelected = !productTable->selectionModel()->selectedIndexes().empty();
	if ( isSelected ) {
		int row = productTable->currentIndex().row();
		QString productName = productsTableModel->data( productsTableModel->index( productTable->currentIndex().row(), 0 ) ).toString();
		ProductDTO result = productFacade->findByName( productName );
		if ( result.isSuccess == true ) {
			result = productFacade->removeProduct( result.product.getId() );
			if ( result.isSuccess == true ) {
				fillProducts();
				clearInputsPageProducts();
			}
		}
		
		if ( result.isSuccess == false ) {
		
		}
	}
}

void ProductPage::showProduct() {
	QString productName = productsTableModel->data( productsTableModel->index( productTable->currentIndex().row(), 0 ) ).toString();
	ProductDTO result = productFacade->findByName( productName );
	if ( result.isSuccess == true ) {
		Product product = result.product;
		productNameInput->setText( product.getName() );
		productPercentInput->setValue( product.getCommission() );
	}

	if ( result.isSuccess == false ) {
	
	}
}

void ProductPage::fillProduct( Product & product ) {
	product.setName( productNameInput->text() );
	product.setCommission( productPercentInput->value() );
}

void ProductPage::clearTable() {
	productsTableModel->clear();
	QStringList horizontalHeader;
    horizontalHeader.append( c->toUnicode( "Название" ) );
    horizontalHeader.append( c->toUnicode( "Комиссия" ) );
	productsTableModel->setHorizontalHeaderLabels( horizontalHeader );
	productTable->setModel( productsTableModel );
    //productTable->resizeColumnsToContents();
}

void ProductPage::fillProducts() {
    clearTable();
	ProductDTO result = productFacade->getAll();
	if ( result.isSuccess == true ) {
		QVector<Product>products = result.products;
		for ( int idx = 0; idx < products.size(); idx++) {
			Product product = products[idx];
			QStandardItem *item;
			item = new QStandardItem( product.getName() );
			productsTableModel->setItem( idx, 0, item );
			item = new QStandardItem( QString::number( product.getCommission() ) + "%" );
			productsTableModel->setItem( idx, 1, item );
		}
		deleteProductButton->setEnabled( !products.empty() );
	}
}

void ProductPage::searchProduct() {
	QString nameProduct = productSearchInput->text();
	if ( nameProduct != "" ) {
		clearTable();
		ProductDTO result = productFacade->findByName( nameProduct );
		if ( result.isSuccess == true ) {
			if ( result.isEmpty == false ) {
				QStandardItem *item;
				item = new QStandardItem( result.product.getName() );
				productsTableModel->setItem( 0, 0, item );
				item = new QStandardItem( QString::number( result.product.getCommission() ) + "%" );
				productsTableModel->setItem( 0, 1, item );
			}
		}

		if (result.isSuccess == false ) {
			
		}
	} else {
		fillProducts();
	}
}

