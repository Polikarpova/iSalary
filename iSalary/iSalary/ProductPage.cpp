#include "ProductPage.h"


ProductPage::ProductPage( ProductFacade *productFacade ) {
	this->productFacade = productFacade;
}

ProductPage::~ProductPage() {

}

void ProductPage::setUI(
	QLineEdit *productSearchInput, 
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

	this->productTable->setEditTriggers(0);
	this->productTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->productTable->setSelectionMode( QAbstractItemView::SingleSelection);
	this->productTable->horizontalHeader()->setStretchLastSection(true);

	connect( this->productTable->selectionModel(), SIGNAL( currentChanged ( const QModelIndex &, const QModelIndex & ) ), this, SLOT( showProduct() ) );
	connect( this->addProductButton, SIGNAL( clicked() ), this, SLOT( directAddProduct() ) );
	connect( this->productCancelAddButton, SIGNAL( clicked() ), this, SLOT( directAddProduct() ) );
	connect( this->productSubmitAddButton, SIGNAL( clicked() ), this, SLOT( addProduct() ) );
	connect( this->editProductButton, SIGNAL( clicked() ), this, SLOT( directUpdateProduct() ) );
	connect( this->cancelProductButton, SIGNAL( clicked() ), this, SLOT( directUpdateProduct() ) );
	connect( this->saveProductButton, SIGNAL( clicked() ), this, SLOT( updateProduct() ) );
	connect( this->deleteProductButton, SIGNAL( clicked() ), this, SLOT( removeProduct() ) );
	connect( this->productSearchInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( searchProduct() ) );
	//connect( this->searchButton, SIGNAL( clicked() ), this, SLOT( searchProduct() ) );
}

void ProductPage::setWindow( QWidget *widget) {
	this->widget = widget;
}

void ProductPage::refreshPage() {

	this->fillProducts();
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
		if ( result.isEmpty == false ) {
			fillProducts();
			directAddProduct();
		} else {
			QMessageBox::warning(widget, QString::fromWCharArray( L"Ошибка"), QString::fromWCharArray( L"Товар с таким именем уже существует"));
		}
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
			if ( result.isEmpty == false ) {
				fillProducts();
				directUpdateProduct();
			} else {
				QMessageBox::warning(widget, QString::fromWCharArray( L"Ошибка"), QString::fromWCharArray( L"Товар с таким именем уже существует"));
			}
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
	QString nameProduct = productSearchInput->text().toLower();
	if ( nameProduct != "" ) {
		clearTable();
		ProductDTO result = productFacade->getAll();
		if ( result.isSuccess == true ) {
			if ( result.isEmpty == false ) {
				QVector<Product>products = result.products;
				int row = 0;
				for ( int i = 0; i < products.size(); i++ ) {
					QString name = products[i].getName().toLower();
					if (name.indexOf( nameProduct ) == 0) {
						QStandardItem *item;
						item = new QStandardItem( products[i].getName() );
						productsTableModel->setItem( row, 0, item );
						item = new QStandardItem( QString::number( products[i].getCommission() ) + "%" );
						productsTableModel->setItem( row, 1, item );
						row++;
					}
				}
			}
		}

		if (result.isSuccess == false ) {
			
		}
	} else {
		fillProducts();
	}
}

