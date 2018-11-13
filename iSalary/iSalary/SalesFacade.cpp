#include "SalesFacade.h"

SalesFacade::SalesFacade( ManagerDB* manager, Sale_DB* sale, AccoutingPeriodDB* period) {

	this->m = manager;
	this->s = sale;
	this->ap = period;
}

void SalesFacade::confirmSale( const ActiveSaleDTO& sale) {

	this->s->confirmSale( sale.id);
}


void SalesFacade::cancelConfirmSale( const ActiveSaleDTO& sale) {

	this->s->unconfirmSale ( sale.id);
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

QList<ManagerSalaryDTO> SalesFacade::getManagersSalary( QDate dateFrom, QDate dateTo) {

	QList<ManagerSalaryDTO> result;

	//от userDB получить все id менеджеров
	//  V
	//(Цикл)от salesDB получить по каждому юзеру список всех его подтвержденных продаж в данный рассчетный период (цена, количество, комиссия за товар) SaleDTO
	//  V
	//(Цикл)Посчитать для каждого юзера сумму прибыли и з/п (отдельно с комиссией) ManagerSalaryDTO
	//  V

	return result;
}