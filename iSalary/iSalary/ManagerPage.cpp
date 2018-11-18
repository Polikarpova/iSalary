#include "ManagerPage.h"


ManagerPage::ManagerPage( ProductFacade *productFacade, SalesFacade *saleFacade ) {
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
	this->productTable = productTable;
	this->confirmedSalesTable = confirmedSalesTable;
	this->unconfirmedSalesTable = unconfirmedSalesTable;

	c = QTextCodec::codecForLocale();
	unconfirmedSalesTableModel = new QStandardItemModel;
	confirmedSalesTableModel = new QStandardItemModel;
	productsTableModel = new QStandardItemModel;

	this->productTable->setEditTriggers(0);
	this->productTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->productTable->setSelectionMode( QAbstractItemView::SingleSelection);
	this->productTable->horizontalHeader()->setStretchLastSection(true);
	
	this->confirmedSalesTable->setEditTriggers(0);
	this->confirmedSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->confirmedSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);
	this->confirmedSalesTable->horizontalHeader()->setStretchLastSection(true);

	this->unconfirmedSalesTable->setEditTriggers(0);
	this->unconfirmedSalesTable->setSelectionBehavior( QAbstractItemView::SelectRows);
	this->unconfirmedSalesTable->setSelectionMode( QAbstractItemView::SingleSelection);
	this->unconfirmedSalesTable->horizontalHeader()->setStretchLastSection(true);

	connect( this->productSearchInput, SIGNAL( textChanged( const QString & ) ), this, SLOT( searchManagersProductTable() ) );
	connect( addSaleButton, SIGNAL( clicked() ), this, SLOT( addSale() ) );
}

void ManagerPage::setCurrentManagerId( int id ) {
	this->current_manager_id = id;
}

void ManagerPage::refreshPage() {
	fillManagersProductTable();
	fillManagersConfirmedSalesTable();
	fillManagersUnconfirmedSalesTable();
}

void ManagerPage::clearManagersConfirmedSalesTable() {
	confirmedSalesTableModel->clear();
	QStringList horizontalHeader;
    horizontalHeader.append( c->toUnicode( "��������" ) );
    horizontalHeader.append( c->toUnicode( "����������" ) );
	horizontalHeader.append( c->toUnicode( "���������" ) );
	horizontalHeader.append( c->toUnicode( "������� ��������" ) );
	confirmedSalesTableModel->setHorizontalHeaderLabels( horizontalHeader );
	confirmedSalesTable->setModel( confirmedSalesTableModel );
    //confirmedSalesTable->resizeColumnsToContents();
}

void ManagerPage::fillManagersConfirmedSalesTable() {
    clearManagersConfirmedSalesTable();
	
	SaleDTO result = saleFacade->getActiveSalesInCurrentPeriod( current_manager_id );
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
		item = new QStandardItem(  c->toUnicode( "�����:" ) );
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
    horizontalHeader.append( c->toUnicode( "��������" ) );
    horizontalHeader.append( c->toUnicode( "����������" ) );
	horizontalHeader.append( c->toUnicode( "���������" ) );
	horizontalHeader.append( c->toUnicode( "������� ��������" ) );
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
		item = new QStandardItem(  c->toUnicode( "�����:" ) );
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
    horizontalHeader.append( c->toUnicode( "��������" ) );
    horizontalHeader.append( c->toUnicode( "��������" ) );
	productsTableModel->setHorizontalHeaderLabels( horizontalHeader );
	productTable->setModel( productsTableModel );
    //productTable->resizeColumnsToContents();
}

void ManagerPage::fillManagersProductTable() {
    clearManagersProductsTable();
	this->productComboBox->clear();

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
		ProductDTO result = productFacade->getAll();
		if ( result.isSuccess == true ) {
			if ( result.isEmpty == false ) {
				QVector<Product>products = result.products;
				int row = 0;
				for ( int i = 0; i < products.size(); i++ ) {
					if (products[i].getName().indexOf( nameProduct ) == 0) {
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
		fillManagersProductTable();
	}
}

