#include "SalesFacade.h"

SalesFacade::SalesFacade( ManagerDB *manager, Sale_DB *sale, AccoutingPeriodDB *period ) {

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
    } catch ( QString *error ) {
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
    } catch ( QString *error ) {
        isSuccess = false;
    }
    result.isSuccess = isSuccess;
    return result;
}

SaleDTO SalesFacade::getActiveSales( int manager_id ) {
    QVector<ActiveSale> activeSales = this->s->getActiveAll( manager_id );
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

    QVector<ActiveSale> activeSales = this->s->getActiveAllInPeriod( manager_id, currentAP.dateFrom );
    SaleDTO result;
    result.activeSales = activeSales;
    result.isEmpty = false;
    if ( activeSales.size() == 0 )
        result.isEmpty = true;
    bool isSuccess = true;
    result.isSuccess = isSuccess;
    return result;
}

void SalesFacade::confirmSale( const ActiveSaleDTO &sale ) { this->s->confirmSale( sale.id ); }

void SalesFacade::cancelConfirmSale( const ActiveSaleDTO &sale ) { this->s->unconfirmSale( sale.id ); }

QList<ActiveSaleDTO> SalesFacade::getActiveSales() { return this->s->getActiveSales(); }

QList<ActiveSaleDTO> SalesFacade::getConfirmedSalesFromPeriod( QList<int> managersIds, QDate dateFrom, QDate dateTo ) {

    QList<ActiveSaleDTO> result;

    for ( auto i = managersIds.begin(); i != managersIds.end(); i++ ) {

        result.append( s->getConfirmedSales( *i, dateFrom, dateTo ) );
    }

    return result;
}

QList<ActiveSaleDTO> SalesFacade::getConfirmedSalesSoldFromPeriod( QList<int> managersIds, QDate dateFrom, QDate dateTo ) {

    QList<ActiveSaleDTO> result;

    for ( auto i = managersIds.begin(); i != managersIds.end(); i++ ) {

        result.append( s->getConfirmedSalesSoldFromPeriod( *i, dateFrom, dateTo ) );
    }

    return result;
}

QList<ActiveSaleDTO> SalesFacade::getActiveSalesForManager( int managerId ) { return this->s->getActiveSalesForManager( managerId ); }

QList<ManagerActiveSalesStatisticDTO> SalesFacade::getActiveSalesStatistic() { return this->s->getManagerActiveSalesSatistic(); }

QList<ManagerSalaryDTO> SalesFacade::getManagersSalary( QDate dateFrom, QDate dateTo ) {

    QList<ManagerSalaryDTO> result;

    QList<QPair<int, QString>> managers = this->m->getAllIdAndName();

    //(Цикл)от salesDB получить по каждому юзеру список всех его подтвержденных продаж в данный рассчетный период (цена, количество, комиссия за товар)
    // SaleInfoDTO
    for ( auto i = managers.begin(); i != managers.end(); i++ ) {

        ManagerSalaryDTO manager;
        manager.managerId = i->first;
        manager.managerName = i->second;
        manager.income = 0;
        manager.salary = 0;

        if ( !dateTo.isValid() ) {

            dateTo = QDate::currentDate();
        }

        QList<SaleInfoDTO> salesInfo = this->s->getSalesInfoConfimedFromPeriod( manager.managerId, dateFrom, dateTo );

        //(Цикл)Посчитать для очередного юзера сумму прибыли и з/п (отдельно с комиссией) ManagerSalaryDTO
        for ( auto j = salesInfo.begin(); j != salesInfo.end(); j++ ) {

            manager.income += j->price * j->count;
            manager.salary += j->price * j->commission / 100.0 * j->count;
        }

        result.append( manager ); //добавляем очередного менеджера в список
    }

    return result;
}

QList<ManagerStatisticDTO> SalesFacade::getManagersStatistic( QDate dateFrom, QDate dateTo ) {

    QList<ManagerStatisticDTO> result;

    QList<QPair<int, QString>> managers = this->m->getAllIdAndName();

    double allIncome = 0;

    //(Цикл)от salesDB получить по каждому юзеру список всех его подтвержденных продаж в данный рассчетный период (цена, количество, комиссия за товар)
    // SaleInfoDTO
    for ( auto i = managers.begin(); i != managers.end(); i++ ) {

        ManagerStatisticDTO manager;
        manager.managerId = i->first;
        manager.managerName = i->second;
        manager.income = 0;
        manager.let = 0;
        manager.oet = 0;

        QString s = dateFrom.toString( "dd.MMMM.yyyy" );
        QString ss = dateTo.toString( "dd.MMMM.yyyy" );
        QList<SaleInfoDTO> salesInfo = this->s->getSalesInfoConfimedFromPeriod( manager.managerId, dateFrom, dateTo );

        //(Цикл)Посчитать для очередного юзера сумму прибыли и з/п (отдельно с комиссией) ManagerSalaryDTO
        for ( auto j = salesInfo.begin(); j != salesInfo.end(); j++ ) {

            manager.income += j->price * j->count;
            allIncome += manager.income;
        }

        //получить количество продаж за период
        manager.salesCount = this->s->getSalesInfoConfimedFromPeriod( manager.managerId, dateFrom, dateTo ).count();

        //получить данные для ЛЭТ
        double lastMonthIncome = 0;

        QDate from( dateFrom.addMonths( -1 ) );
        QDate to( from.year(), from.month(), from.daysInMonth() );

        salesInfo = this->s->getSalesInfoConfimedFromPeriod( manager.managerId, from, to );

        //(Цикл)Посчитать для очередного юзера сумму прибыли и з/п (отдельно с комиссией) ManagerSalaryDTO
        for ( auto j = salesInfo.begin(); j != salesInfo.end(); j++ ) {

            lastMonthIncome += j->price * j->count;
        }

        //высчитать ЛЭТ
        manager.let = lastMonthIncome ? manager.income / lastMonthIncome * 100 : 0;

        result.append( manager ); //добавляем очередного менеджера в список
    }

    //когда вся прибыль на данный период посчитана, надо теперь посчитать ОЭТ
    for ( auto i = result.begin(); i != result.end(); i++ ) {

        //считаем ОЭТ
        i->oet = allIncome ? i->income / allIncome * 100 : 0;
    }

    return result;
}

QList<AccoutingPeriodDTO> SalesFacade::getAllAccoutingPeriods() { return this->ap->getAllPeriods(); }

ManagerDTO SalesFacade::getManagerInfo( int id ) { return this->m->getManagerInfoById( id ); }