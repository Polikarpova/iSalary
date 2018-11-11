#include "SalesFacade.h"

SalesFacade::SalesFacade( ManagerDB* manager, Sale_DB* sale) {

	this->m = manager;
	this->s = sale;
}

void SalesFacade::confirmSale( ActiveSaleDTO sale) {

}


void SalesFacade::cancelConfirmSale( ActiveSaleDTO sale) {

}

QList<ManagerActiveSalesStatisticDTO> SalesFacade::getActiveSalesStatistic( QDate date){

	//QList<ManagerActiveSalesStatisticDTO> result;

	return this->s->getManagerActiveSalesSatistic();
}