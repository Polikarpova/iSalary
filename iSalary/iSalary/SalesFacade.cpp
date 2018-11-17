#include "SalesFacade.h"

SalesFacade::SalesFacade( ManagerDB* manager, Sale_DB* sale, AccoutingPeriodDB* period) {

	this->m = manager;
	this->s = sale;
	this->ap = period;
}

SaleDTO SalesFacade::addActiveSale( ActiveSale activeSale ) {
	bool isSuccess = this->s->create( activeSale );
	SaleDTO result;
	result.activeSale = activeSale;
	result.isEmpty = false;
	result.isSuccess = isSuccess;
	return result;
}

SaleDTO SalesFacade::removeActiveSale( int id ) {
	bool isSuccess = this->s->remove( id );
	SaleDTO result;
	result.isEmpty = true;
	result.isSuccess = isSuccess;
	return result;
}

SaleDTO SalesFacade::getActiveSales( int manager_id ) {
	QVector<ActiveSale>activeSales = this->s->getActiveAll( manager_id );
	SaleDTO result;
	result.activeSales = activeSales;
	result.isEmpty = false;
	if ( activeSales.size() == 0 )
		result.isEmpty = true;
	bool isSuccess = true;
	result.isSuccess = isSuccess;
	return result;
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

		if ( !dateTo.isValid()) {
		
			dateTo = QDate::currentDate();
		}

		QList<SaleInfoDTO> salesInfo = this->s->getSalesConfimedFromPeriod( manager.managerId, dateFrom, dateTo);
	
		//(Цикл)Посчитать для очередного юзера сумму прибыли и з/п (отдельно с комиссией) ManagerSalaryDTO
		for( auto j = salesInfo.begin() ; j != salesInfo.end() ; j++) {
		
			manager.income += j->price;
			manager.salary += j->price*j->commission/100.0;
		}

		result.append(manager); //добавляем очередного менеджера в список
	}

	return result;
}

QList<AccoutingPeriodDTO> SalesFacade::getAllAccoutingPeriods() {

	return this->ap->getAllPeriods();
}

ManagerDTO SalesFacade::getManagerInfo( int id) {

	return this->m->getManagerInfoById( id);
}