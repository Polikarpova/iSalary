#include "ManagerPage.h"


ManagerPage::ManagerPage( ProductFacade *productFacade, SaleFacade *saleFacade ) {
	this->productFacade = productFacade;
	this->saleFacade = saleFacade;
}


ManagerPage::~ManagerPage(void)
{
}

void ManagerPage::setUI(
	QLineEdit *currentSalaryOutput,
	QComboBox *productComboBox,
	QDoubleSpinBox *priceSaleInput,
	QSpinBox *countSaleProductsInput,
	QPushButton *addSaleButton,
	QLineEdit *productSearchInput,
	QPushButton *productSearchButton,
	QTableView *productTable,
	QTableView *confirmedSalesTable,
	QTableView *unconfirmedSalesTable
) {
	this->currentSalaryOutput = currentSalaryOutput;
	this->productComboBox = productComboBox;
	this->priceSaleInput = priceSaleInput;
	this->countSaleProductsInput = countSaleProductsInput;
	this->addSaleButton = addSaleButton;
	this->productSearchInput = productSearchInput;
	this->productSearchButton = productSearchButton;
	this->productTable = productTable;
	this->confirmedSalesTable = confirmedSalesTable;
	this->unconfirmedSalesTable = unconfirmedSalesTable;

	c = QTextCodec::codecForLocale();
	current_manager_id = 1;
	unconfirmedSalesTableModel = new QStandardItemModel;
	confirmedSalesTableModel = new QStandardItemModel;
	productsTableModel = new QStandardItemModel;
	fillManagersProductTable();
	fillManagersConfirmedSalesTable();
	fillManagersUnconfirmedSalesTable();

	productTable->setEditTriggers(0);
	confirmedSalesTable->setEditTriggers(0);
	unconfirmedSalesTable->setEditTriggers(0);

	connect( productSearchButton, SIGNAL( clicked() ), this, SLOT( searchManagersProductTable() ) );
	connect( addSaleButton, SIGNAL( clicked() ), this, SLOT( addSale() ) );
}

void ManagerPage::clearManagersConfirmedSalesTable() {
	confirmedSalesTableModel->clear();
	QStringList horizontalHeader;
    horizontalHeader.append( c->toUnicode( "Название" ) );
    horizontalHeader.append( c->toUnicode( "Количество" ) );
	horizontalHeader.append( c->toUnicode( "Стоимость" ) );
	horizontalHeader.append( c->toUnicode( "Процент комиссии" ) );
	confirmedSalesTableModel->setHorizontalHeaderLabels( horizontalHeader );
	confirmedSalesTable->setModel( confirmedSalesTableModel );
    //confirmedSalesTable->resizeColumnsToContents();
}

void ManagerPage::fillManagersConfirmedSalesTable() {
    clearManagersConfirmedSalesTable();
	
	SaleDTO result = saleFacade->getActiveSales( current_manager_id );
	if ( result.isSuccess == true ) {
		int allCount = 0, lastRow = 0;
		double allCost = 0, salary = 0;
		QVector<ActiveSale>sales = result.activeSales;
		for ( int idx = 0; idx < sales.size(); idx++ ) {
			if ( sales[idx].isConfirmed() == true ) {
				ActiveSale sale = sales[idx];
				ProductDTO productResult = productFacade->findById( sale.getProductId() );
				sale.setProduct( productResult.product );
				QStandardItem *item;
				item = new QStandardItem( sale.getProductName() );
				confirmedSalesTableModel->setItem( lastRow, 0, item );
				item = new QStandardItem( QString::number( sale.getCount() ) );
				confirmedSalesTableModel->setItem( lastRow, 1, item );
				item = new QStandardItem( QString::number( sale.getCost() ) );
				confirmedSalesTableModel->setItem( lastRow, 2, item );
				item = new QStandardItem( QString::number( sale.getProductCommission() ) + "%" );
				confirmedSalesTableModel->setItem( lastRow, 3, item );

				allCount += sale.getCount();
				allCost += sale.getCost();
				salary += sale.getCost() / 100 * sale.getProductCommission();
				lastRow++;
			}
		}
		QStandardItem *item;
		item = new QStandardItem(  c->toUnicode( "Итого:" ) );
		confirmedSalesTableModel->setItem( lastRow, 0, item );
		item = new QStandardItem( QString::number( allCount ) );
		confirmedSalesTableModel->setItem( lastRow, 1, item );
		item = new QStandardItem( QString::number( allCost ) );
		confirmedSalesTableModel->setItem( lastRow, 2, item );
		item = new QStandardItem( QString::number( salary ) );
		confirmedSalesTableModel->setItem( lastRow, 3, item );

		currentSalaryOutput->setText( QString::number( salary ) );
	}
}

void ManagerPage::clearManagersUnconfirmedSalesTable() {
	unconfirmedSalesTableModel->clear();
	QStringList horizontalHeader;
    horizontalHeader.append( c->toUnicode( "Название" ) );
    horizontalHeader.append( c->toUnicode( "Количество" ) );
	horizontalHeader.append( c->toUnicode( "Стоимость" ) );
	horizontalHeader.append( c->toUnicode( "Процент комиссии" ) );
	unconfirmedSalesTableModel->setHorizontalHeaderLabels( horizontalHeader );
	unconfirmedSalesTable->setModel( unconfirmedSalesTableModel );
    //unconfirmedSalesTable->resizeColumnsToContents();
}

void ManagerPage::fillManagersUnconfirmedSalesTable() {
    clearManagersUnconfirmedSalesTable();
	
	SaleDTO result = saleFacade->getActiveSales( current_manager_id );
	if ( result.isSuccess == true ) {
		int allCount = 0, lastRow = 0;
		double allCost = 0, salary = 0;
		QVector<ActiveSale>sales = result.activeSales;
		for ( int idx = 0; idx < sales.size(); idx++ ) {
			if ( sales[idx].isConfirmed() == false ) {
				ActiveSale sale = sales[idx];
				ProductDTO productResult = productFacade->findById( sale.getProductId() );
				sale.setProduct( productResult.product );
				QStandardItem *item;
				item = new QStandardItem( sale.getProductName() );
				unconfirmedSalesTableModel->setItem( lastRow, 0, item );
				item = new QStandardItem( QString::number( sale.getCount() ) );
				unconfirmedSalesTableModel->setItem( lastRow, 1, item );
				item = new QStandardItem( QString::number( sale.getCost() ) );
				unconfirmedSalesTableModel->setItem( lastRow, 2, item );
				item = new QStandardItem( QString::number( sale.getProductCommission() ) + "%" );
				unconfirmedSalesTableModel->setItem( lastRow, 3, item );

				allCount += sale.getCount();
				allCost += sale.getCost();
				salary += sale.getCost() / 100 * sale.getProductCommission();
				lastRow++;
			}
		}
		QStandardItem *item;
		item = new QStandardItem(  c->toUnicode( "Итого:" ) );
		unconfirmedSalesTableModel->setItem( lastRow, 0, item );
		item = new QStandardItem( QString::number( allCount ) );
		unconfirmedSalesTableModel->setItem( lastRow, 1, item );
		item = new QStandardItem( QString::number( allCost ) );
		unconfirmedSalesTableModel->setItem( lastRow, 2, item );
		item = new QStandardItem( QString::number( salary ) );
		unconfirmedSalesTableModel->setItem( lastRow, 3, item );
	}
}

void ManagerPage::addSale() {
	ActiveSale sale;
	fillSale( sale );
	SaleDTO result = saleFacade->addActiveSale( sale );
	fillManagersUnconfirmedSalesTable();
}

void ManagerPage::fillSale( ActiveSale & sale ) {
	Manager saler;
	saler.setFirstName( "Dima" );
	saler.setId( current_manager_id );
	sale.setSaler( saler );
	QString nameProduct = productComboBox->currentText();
	ProductDTO result = productFacade->findByName( nameProduct );
	sale.setProduct( result.product );
	sale.setCost( priceSaleInput->value() );
	sale.setCount( countSaleProductsInput->value() );
}


void ManagerPage::clearManagersProductsTable() {
	productsTableModel->clear();
	QStringList horizontalHeader;
    horizontalHeader.append( c->toUnicode( "Название" ) );
    horizontalHeader.append( c->toUnicode( "Комиссия" ) );
	productsTableModel->setHorizontalHeaderLabels( horizontalHeader );
	productTable->setModel( productsTableModel );
    //productTable->resizeColumnsToContents();
}

void ManagerPage::fillManagersProductTable() {
    clearManagersProductsTable();
	
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
			productComboBox->addItem( product.getName() );
		}
		addSaleButton->setEnabled( !products.empty() );
		productComboBox->setEnabled( !products.empty() );
	}

	if ( result.isSuccess == false ) {
		
	}
}

void ManagerPage::searchManagersProductTable() {
	QString nameProduct = productSearchInput->text();
	if ( nameProduct != "" ) {
		clearManagersProductsTable();
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
		fillManagersProductTable();
	}
}

