#include "SalesFacade.h"

SalesFacade::SalesFacade( ManagerDB* manager, Sale_DB* sale, AccoutingPeriodDB* period) {

	this->m = manager;
	this->s = sale;
	this->ap = period;
}

SaleDTO SalesFacade::addActiveSale( ActiveSale activeSale ) {
	bool isSuccess = true;
	SaleDTO result;
    try { 
        this->s->create( activeSale );
	    result.activeSale = activeSale;
	    result.isEmpty = false;
    } catch ( QString* error) {
        isSuccess = false;
    }
	result.isSuccess = isSuccess;
	return result;
}

SaleDTO SalesFacade::removeActiveSale( int id ) {
	bool isSuccess = true;
	SaleDTO result;
    try { 
        this->s->remove( id );
	    result.isEmpty = true;
    } catch ( QString* error) {
        isSuccess = false;
    }
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

SaleDTO SalesFacade::getActiveSalesInCurrentPeriod( int manager_id ) {
	
	AccoutingPeriodDTO currentAP = this->ap->getCurrentPeriod();
	
	QVector<ActiveSale>activeSales = this->s->getActiveAllInPeriod( manager_id, currentAP.dateFrom);
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

	//(����)�� salesDB �������� �� ������� ����� ������ ���� ��� �������������� ������ � ������ ���������� ������ (����, ����������, �������� �� �����) SaleInfoDTO
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
	
		//(����)��������� ��� ���������� ����� ����� ������� � �/� (�������� � ���������) ManagerSalaryDTO
		for( auto j = salesInfo.begin() ; j != salesInfo.end() ; j++) {
		
			manager.income += j->price * j->count;
			manager.salary += j->price * j->commission/100.0 * j->count;
		}

		result.append(manager); //��������� ���������� ��������� � ������
	}

	return result;
}

QList<ManagerStatisticDTO> SalesFacade::getManagersStatistic( QDate dateFrom, QDate dateTo) {

	QList<ManagerStatisticDTO> result;

	QList<QPair<int, QString> > managers = this->m->getAllIdAndName();

	double allIncome = 0;
	QMap<int, double> lastMonthIncome;

	//(����)�� salesDB �������� �� ������� ����� ������ ���� ��� �������������� ������ � ������ ���������� ������ (����, ����������, �������� �� �����) SaleInfoDTO
	for ( auto i = managers.begin(); i != managers.end() ; i++){

		ManagerStatisticDTO manager;
		manager.managerId = i->first;
		manager.managerName = i->second;
		manager.salesCount = 0;
		manager.income = 0;
		manager.let = 0;
		manager.oet = 0;

		if ( !dateTo.isValid()) {
		
			dateTo = QDate::currentDate();
		}

		QList<SaleInfoDTO> salesInfo = this->s->getSalesConfimedFromPeriod( manager.managerId, dateFrom, dateTo);
	
		//(����)��������� ��� ���������� ����� ����� ������� � �/� (�������� � ���������) ManagerSalaryDTO
		for( auto j = salesInfo.begin() ; j != salesInfo.end() ; j++) {
		
			manager.income += j->price * j->count;
			allIncome += manager.income;
		}

		//�������� ���������� ������ �� ������

		//�������� ������ ��� ���, ���� ������ ��� �����

		result.append(manager); //��������� ���������� ��������� � ������
	}

	//����� ��� ������� �� ������ ������ ���������, ���� ������ ��������� ���
	for ( auto i = result.begin(); i != result.end(); i ++ ) {
	
		//������� ���
		i->oet = allIncome ?  i->income/allIncome : 0;

		//��������� ���
		i->let = 0;
	}

	return result;
}

QList<AccoutingPeriodDTO> SalesFacade::getAllAccoutingPeriods() {

	return this->ap->getAllPeriods();
}

ManagerDTO SalesFacade::getManagerInfo( int id) {

	return this->m->getManagerInfoById( id);
}