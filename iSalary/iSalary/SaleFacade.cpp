#include "SaleFacade.h"


SaleFacade::SaleFacade( Sale_DB *sale_DB ) {
	this->sale_DB = sale_DB;
}


SaleFacade::~SaleFacade(void) {
}

SaleDTO SaleFacade::addActiveSale( ActiveSale activeSale ) {
	bool isSuccess = sale_DB->create( activeSale );
	SaleDTO result;
	result.activeSale = activeSale;
	result.isEmpty = false;
	result.isSuccess = isSuccess;
	return result;
}

SaleDTO SaleFacade::removeActiveSale( int id ) {
	bool isSuccess = sale_DB->remove( id );
	SaleDTO result;
	result.isEmpty = true;
	result.isSuccess = isSuccess;
	return result;
}

SaleDTO SaleFacade::getActiveSales( int manager_id ) {
	QVector<ActiveSale>activeSales = sale_DB->getActiveAll( manager_id );
	SaleDTO result;
	result.activeSales = activeSales;
	result.isEmpty = false;
	if ( activeSales.size() == 0 )
		result.isEmpty = true;
	bool isSuccess = true;
	result.isSuccess = isSuccess;
	return result;
}
