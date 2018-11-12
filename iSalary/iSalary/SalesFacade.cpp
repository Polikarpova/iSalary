#include "SalesFacade.h"

SalesFacade::SalesFacade( ManagerDB* manager, Sale_DB* sale) {

	this->m = manager;
	this->s = sale;
}

void SalesFacade::confirmSale( ActiveSaleDTO sale) {

}


void SalesFacade::cancelConfirmSale( ActiveSaleDTO sale) {

}

QList<ActiveSaleDTO> SalesFacade::getActiveSales(){

	//QList<ManagerActiveSalesStatisticDTO> result;

	return this->s->getActiveSales();
}

QList<ActiveSaleDTO> SalesFacade::getActiveSalesForManager( int managerId){

	//QList<ManagerActiveSalesStatisticDTO> result;

	return this->s->getActiveSalesForManager(managerId);
}

QList<ManagerActiveSalesStatisticDTO> SalesFacade::getActiveSalesStatistic( QDate date){

	//QList<ManagerActiveSalesStatisticDTO> result;

	return this->s->getManagerActiveSalesSatistic();
}