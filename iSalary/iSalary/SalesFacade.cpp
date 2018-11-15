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

	return this->s->getActiveSales();
}

QList<ActiveSaleDTO> SalesFacade::getActiveSalesForManager( int managerId){

	return this->s->getActiveSalesForManager(managerId);
}

QList<ManagerActiveSalesStatisticDTO> SalesFacade::getActiveSalesStatistic( QDate date){

	return this->s->getManagerActiveSalesSatistic();
}

QList<ManagerSalaryDTO> SalesFacade::getManagersSalary( QDate dateFrom, QDate dateTo) {

	QList<ManagerSalaryDTO> result;

	QList<QPair<int, QString> > managers = this->m->getAllIdAndName();

	//(Цикл)от salesDB получить по каждому юзеру список всех его подтвержденных продаж в данный рассчетный период (цена, количество, комиссия за товар) SaleInfoDTO
	for ( auto i = managers.begin(); i != managers.end() ; i++){

		ManagerSalaryDTO manager;
		manager.managerId = i->first;
		manager.managerName = i->second;
		manager.income = 0;
		manager.salary = 0;

		QList<SaleInfoDTO> salesInfo = this->s->getSalesConfimedFromPeriod( manager.managerId, dateFrom, dateTo);
	
		//(Цикл)Посчитать для очередного юзера сумму прибыли и з/п (отдельно с комиссией) ManagerSalaryDTO
		for( auto j = salesInfo.begin() ; j != salesInfo.end() ; i++) {
		
			manager.income += j->price;
			manager.salary += j->price*j->commission;
		}

		result.append(manager); //добавляем очередного менеджера в список
	}

	return result;
}

QList<AccoutingPeriodDTO> SalesFacade::getAllAccoutingPeriods() {

	return this->ap->getAllPeriods();
}