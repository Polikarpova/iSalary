#pragma once

#include "ManagerDB.h"
#include "Sale_DB.h"
#include "AccoutingPeriodDB.h"
#include "ActiveSaleDTO.h"
#include "ManagerActiveSalesStatisticDTO.h"

/**
* Класс, предоставляющий доступ к функциям приложения, связанным с продажами
* @author Поликарпова
*/
class SalesFacade {
public:

	SalesFacade( ManagerDB* manager, Sale_DB* sale, AccoutingPeriodDB* period);

	/**
	* Метод подтверждает определённую продажу
	* sale - продажа, которая должна быть подтверждена
	*/
	void confirmSale( const ActiveSaleDTO& sale);

	/**
	* Метод отменяет подтверждение определённой продажи
	* sale - продажа, подтверждение которой отменяется
	*/
	void cancelConfirmSale( const ActiveSaleDTO& sale);

	/**
	* Возращает активные продажи (подтвержденные и неподтвержденные) всех менеджеров
	* @return список продаж
	*/
	QList<ActiveSaleDTO> getActiveSales();

	/**
	* Возращает активные продажи (подтвержденные и неподтвержденные) определенного менеджера
	* @param managerId - id менеджера
	* @return список продаж менеджера с указанным id
	*/
	QList<ActiveSaleDTO> getActiveSalesForManager( int managerId);

	/**
	* Возращает статистику продаж для страницы "Продажи" всех менеджеров за определенный день
	* @param date - дата
	* @return список со статистикой на каждого менеджера
	*/
	QList<ManagerActiveSalesStatisticDTO> getActiveSalesStatistic( QDate date);

private:

	ManagerDB* m;
	Sale_DB* s;
	AccoutingPeriodDB* ap;
};