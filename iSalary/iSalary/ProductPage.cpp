#include "ProductPage.h"


ProductPage::ProductPage( ProductFacade *productFacade ) {
	this->productFacade = productFacade;
}

ProductPage::~ProductPage() {

}

void ProductPage::setUI(
	QWidget* tabWidget,
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
	this->tabWidget = tabWidget;
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
	refreshPage();
	status = DEFAULT;

	this->productTable->setEditTriggers(0);
	this->productTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->productTable->setSelectionMode( QAbstractItemView::SingleSelection);
	this->productTable->horizontalHeader()->setStretchLastSection(true);

	connect( this->productTable->selectionModel(), SIGNAL( currentChanged ( const QModelIndex &, const QModelIndex & ) ), this, SLOT( showProduct() ) );
	connect( this->productTable->selectionModel(), SIGNAL( currentChanged ( const QModelIndex &, const QModelIndex & ) ), this, SLOT( enableEditAndRemoveButtons( ) ) );
	connect( this->addProductButton, SIGNAL( clicked() ), this, SLOT( directAddProduct() ) );
	connect( this->productCancelAddButton, SIGNAL( clicked() ), this, SLOT( directAddProduct() ) );
	connect( this->productSubmitAddButton, SIGNAL( clicked() ), this, SLOT( addProduct() ) );
	connect( this->editProductButton, SIGNAL( clicked() ), this, SLOT( directUpdateProduct() ) );
	connect( this->cancelProductButton, SIGNAL( clicked() ), this, SLOT( directUpdateProduct() ) );
	connect( this->saveProductButton, SIGNAL( clicked() ), this, SLOT( updateProduct() ) );
	connect( this->deleteProductButton, SIGNAL( clicked() ), this, SLOT( removeProduct() ) );
	connect( this->productSearchInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( searchProduct() ) );
}

void ProductPage::setErrorHandler( ErrorMessageHandler* errorHandler) {
    this->errorHandler = errorHandler;
}

void ProductPage::setWindow( QWidget *widget) {
	this->widget = widget;
}

void ProductPage::startBlockForRequest(){
    this->tabWidget->setEnabled( false );
}

void ProductPage::endBlockForRequest(){
    this->tabWidget->setEnabled( true );
}

void ProductPage::refreshPage() {
	this->startBlockForRequest();
	try {
		fillProducts();
	} catch ( QString* error ) {
        this->errorHandler->handleError( error );
    }
	this->endBlockForRequest();
}

void ProductPage::setEnabledWindow( bool enabled ) {
	this->productSearchInput->setEnabled( enabled );
	this->productTable->setEnabled( enabled );
	this->productNameInput->setEnabled( enabled );
	this->productPercentInput->setEnabled( enabled );
	this->productButtonsStackedWidget->setEnabled( enabled );
	this->addProductButton->setEnabled( enabled );
	this->deleteProductButton->setEnabled( enabled );
	this->editProductButton->setEnabled( enabled );
	this->cancelProductButton->setEnabled( enabled );
	this->saveProductButton->setEnabled( enabled );
	this->productCancelAddButton->setEnabled( enabled );
	this->productSubmitAddButton->setEnabled( enabled );
}

void ProductPage::setInputsEnabledPageProducts( bool isEnabled ) {
	productNameInput->setEnabled( isEnabled );
	productPercentInput->setEnabled( isEnabled );
}

void ProductPage::enableEditAndRemoveButtons() {
	setEnabledEditAndRemoveButtons( true );
}

void ProductPage::setEnabledEditAndRemoveButtons( bool isEnabled ) {
	deleteProductButton->setEnabled( isEnabled );
	editProductButton->setEnabled( isEnabled );
}

void ProductPage::clearInputsPageProducts() {
	productNameInput->clear();
	productPercentInput->clear();
	productPercentInput->setValue(0.01);
}

void ProductPage::directAddProduct() {
	if ( status == DEFAULT ) {
		productButtonsStackedWidget->setCurrentIndex( 2 );
		productSearchInput->setEnabled( false );
		productTable->setEnabled( false );
		addProductButton->setEnabled( false );
		setInputsEnabledPageProducts( true );
		clearInputsPageProducts();
		status = ADD_PRODUCT;
	} else {
		productButtonsStackedWidget->setCurrentIndex( 0 );
		productSearchInput->setEnabled( true );
		productTable->setEnabled( true );
		refreshPage();
		addProductButton->setEnabled( true );
		setInputsEnabledPageProducts( false );
		setEnabledEditAndRemoveButtons( false );
		status = DEFAULT;
	}
}

void ProductPage::selectProduct( Product product ) {
	int count = productTable->model()->rowCount();
	for ( int i = 0; i < count; i++ ) {
		QString productName = productsTableModel->data( productsTableModel->index( i, 0 ) ).toString();
		if ( productName == product.getName() ) {
			QModelIndex index = productTable->model()->index( i, 0 ); 
			productTable->setFocus();
			productTable->selectRow( i );
		}
	}
	showProduct();
}

void ProductPage::addProduct() {
	this->startBlockForRequest();
	try {

		if ( validator() == true ) {
			Product product;
			fillProduct( product );
			
			ProductDTO result = productFacade->addProduct( product );
				
			if ( result.isEmpty == false ) {
				fillProducts();
				directAddProduct();
				selectProduct( result.product );
			} else {
				QMessageBox::warning(widget, QString::fromWCharArray( L"Ошибка"), QString::fromWCharArray( L"Товар с таким именем уже существует"));
			}
		}

	} catch ( QString* error ) {
        this->errorHandler->handleError( error );
    }
	this->endBlockForRequest();
}

void ProductPage::directUpdateProduct() {
	bool isSelected = !productTable->selectionModel()->selectedIndexes().empty();
	if ( status == DEFAULT && isSelected == true ) {
		productButtonsStackedWidget->setCurrentIndex( 1 );
		productSearchInput->setEnabled( false );
		addProductButton->setEnabled( false );
		productTable->setEnabled( false );
		setInputsEnabledPageProducts( true );
		status = UPDATE_PRODUCT;
	} else {
		productButtonsStackedWidget->setCurrentIndex( 0 );
		productSearchInput->setEnabled( true );
		productTable->setEnabled( true );
		refreshPage();
		addProductButton->setEnabled( true );
		setInputsEnabledPageProducts( false );
		status = DEFAULT;
	}
}

void ProductPage::updateProduct() {
	this->startBlockForRequest();
	try {

		if ( validator() == true ) {
			QString productName = productNameInput->text();
			int id = productsTableModel->data( productsTableModel->index( productTable->currentIndex().row(), 2 ) ).toInt();
			ProductDTO result = productFacade->findByName( productName );

			if ( result.product.getId() == id || result.isEmpty == true ) {
				productName = productsTableModel->data( productsTableModel->index( productTable->currentIndex().row(), 0 ) ).toString();
				result = productFacade->findByName( productName );
				Product product = result.product;
				fillProduct( product );
				result = productFacade->updateProduct( product );
				
				fillProducts();
				directUpdateProduct();
				selectProduct( result.product );
			} else {
				QMessageBox::warning(widget, QString::fromWCharArray( L"Ошибка"), QString::fromWCharArray( L"Товар с таким именем уже существует"));
			}

		}

	} catch ( QString* error ) {
        this->errorHandler->handleError( error );
    }
	this->endBlockForRequest();
}

void ProductPage::removeProduct() {
	this->startBlockForRequest();
	try {

		bool isSelected = !productTable->selectionModel()->selectedIndexes().empty();
		if ( isSelected ) {
			int row = productTable->currentIndex().row();
			QString productName = productsTableModel->data( productsTableModel->index( productTable->currentIndex().row(), 0 ) ).toString();
			ProductDTO result = productFacade->findByName( productName );
			result = productFacade->removeProduct( result.product.getId() );
			fillProducts();
			clearInputsPageProducts();
		}

	} catch ( QString* error ) {
        this->errorHandler->handleError( error );
    }
	this->endBlockForRequest();
	setEnabledEditAndRemoveButtons( false );
}

void ProductPage::showProduct() {
	this->startBlockForRequest();
	try {

		QString productName = productsTableModel->data( productsTableModel->index( productTable->currentIndex().row(), 0 ) ).toString();
		ProductDTO result = productFacade->findByName( productName );
		Product product = result.product;
		productNameInput->setText( product.getName() );
		productPercentInput->setValue( product.getCommission() );

	} catch ( QString* error ) {
        this->errorHandler->handleError( error );
    }
	this->endBlockForRequest();
	productTable->setFocus();
}

bool ProductPage::validatorProductName( QString productName ) {
	QString rusAlp = QString::fromWCharArray( L"а-яА-Я" );
	QRegExp regexp("(([a-zA-Z" + rusAlp + "]\s*)+([0-9]\s*)*-?)+");
	return regexp.exactMatch( productName );
}

bool ProductPage::validator() {
	bool isValidate = true;
	QString emptyFieldNames = "";
	if ( productNameInput->text() == "" ) {
		isValidate = false;
		emptyFieldNames += QString::fromWCharArray( L"Название" );
	}
	else if ( validatorProductName( productNameInput->text() ) == false ) {
		isValidate = false;
		emptyFieldNames += QString::fromWCharArray( L"Неверное Название" );
	}
	if ( productPercentInput->value() == 0 ) {
		isValidate = false;
		if (emptyFieldNames != "") {
			emptyFieldNames += ", ";
		}
		emptyFieldNames += QString::fromWCharArray( L"Процент коммиссии" );
	}
	QString errorText = QString::fromWCharArray( L"Пустые поля: ");
	errorText += emptyFieldNames;
	if ( isValidate == false ) {
		QMessageBox::warning( widget, QString::fromWCharArray( L"Ошибка" ), errorText );
	}

	return isValidate;
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
	//setEnabledEditAndRemoveButtons( false );
    
	for (int col = 0; col < 2; col++) {
		productTable->horizontalHeader()->setSectionResizeMode(col, QHeaderView::ResizeToContents);
	}
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
			item = new QStandardItem( QString::number( product.getId() ) );
			productsTableModel->setItem( idx, 2, item );
		}
		productTable->setColumnHidden( 2, true);
	}
	//productTable->setFocus();
	//setEnabledEditAndRemoveButtons( false );
}

void ProductPage::searchProduct() {
	this->startBlockForRequest();
	try {

		QString nameProduct = productSearchInput->text().toLower();
		if ( nameProduct != "" ) {
			clearTable();
			ProductDTO result = productFacade->getAll();
			
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

		} else {
			fillProducts();
		}
		
	} catch ( QString* error ) {
        this->errorHandler->handleError( error );
    }
	this->endBlockForRequest();

	setEnabledEditAndRemoveButtons( false );
	productSearchInput->setFocus();
}

