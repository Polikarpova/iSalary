#pragma once

#include "ManagerDB.h"
#include "Sale_DB.h"
#include "AccoutingPeriodDB.h"
#include "ActiveSaleDTO.h"
#include "ManagerActiveSalesStatisticDTO.h"
#include "ManagerSalaryDTO.h"
#include <qdatetime.h>

#include "SaleInfoDTO.h"
#include "ManagerSalaryDTO.h"
#include "AccoutingPeriodDTO.h"
#include "ManagerDTO.h"
#include "SaleDTO.h"

#include "ManagerStatisticDTO.h"

/**
* Класс, предоставляющий доступ к функциям приложения, связанным с продажами и менеджерами
* @author Поликарпова
*/
class SalesFacade {
public:

	SalesFacade( ManagerDB* manager, Sale_DB* sale, AccoutingPeriodDB* period);

	SaleDTO addActiveSale( ActiveSale activeSale );
	SaleDTO removeActiveSale( int id );
	SaleDTO getActiveSales( int manager_id );

	SaleDTO getActiveSalesInCurrentPeriod( int manager_id );

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
	* Возращает продажи менеджеров, подтвержденные в заданный период
	* @param managersIds - идентификаторы менеджеров
	* @param dateFrom - начала периода
	* @param dateTo - конец периода
	* @return список продаж
	*/
	QList<ActiveSaleDTO> getConfirmedSalesFromPeriod( QList<int> managersIds, QDate dateFrom, QDate dateTo );

	/**
	* Возращает подтвержденные продажи менеджеров, проданных в заданный период
	* @param managersIds - идентификаторы менеджеров
	* @param dateFrom - начала периода
	* @param dateTo - конец периода
	* @return список продаж
	*/
	QList<ActiveSaleDTO> getConfirmedSalesSoldFromPeriod( QList<int> managersIds, QDate dateFrom, QDate dateTo );

	/**
	* Возращает активные продажи (подтвержденные и неподтвержденные) определенного менеджера
	* @param managerId - id менеджера
	* @return список продаж менеджера с указанным id
	*/
	QList<ActiveSaleDTO> getActiveSalesForManager( int managerId);

	/**
	* Возращает статистику продаж для страницы "Продажи" всех менеджеров
	* @return список со статистикой на каждого менеджера
	*/
	QList<ManagerActiveSalesStatisticDTO> getActiveSalesStatistic();

	/**
	* Возвращает список всех зарплат за определенный период
	* @param dateFrom - начала периода
	* @param dateTo - конец периода
	* @return список зарплат или пустой список
	*/
	QList<ManagerSalaryDTO> getManagersSalary( QDate dateFrom, QDate dateTo);

	/**
	* Возвращает список со статистикой о продажах всех менеджеров за определенный период
	* @param dateFrom - начала периода
	* @param dateTo - конец периода
	* @return список со статистикой или пустой список
	*/
	QList<ManagerStatisticDTO> getManagersStatistic( QDate dateFrom, QDate dateTo);

	/**
	* Возвращает список со всеми РП
	* @return список со всеми РП. Список никогда не должен возвращаться пустым, так как всегда есть хотя бы один РП (он же будет текущим)
	*/
	QList<AccoutingPeriodDTO> getAllAccoutingPeriods();

	/**
	* Возвращает информация о менеджере по id
	* @param id - идентификатор искомого менеджера
	* @return информацией о менеджере, или null, если менеджер не найден
	*/
	ManagerDTO getManagerInfo( int id);

private:

	ManagerDB* m;
	Sale_DB* s;
	AccoutingPeriodDB* ap;
};