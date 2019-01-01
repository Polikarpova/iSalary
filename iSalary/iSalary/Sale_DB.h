#pragma once
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVariant>
#include <QSqlResult>
#include "ActiveSale.h"
#include "ClosedSale.h"
#include "Manager.h"
#include <QVector>
#include <QSqlError>

#include <qlist.h>
#include "ManagerActiveSalesStatisticDTO.h"
#include "ActiveSaleDTO.h"
#include "SaleInfoDTO.h"

#include "ASqlTable.h"

class Sale_DB : public ASqlTable
{
public:
	Sale_DB( QSqlDatabase* db, QString table_name );
	~Sale_DB(void);
	void init();
    void createTable() override;

	void create( ActiveSale sale );
	void remove( int id );
	void fillSale( ActiveSale & sale, const QSqlQuery * sqlQuery );
	
	QVector<ActiveSale> getActiveAll( int manager_id );

	QVector<ActiveSale> getActiveAllInPeriod( int manager_id, QDate dateFrom );
	
	/**
    *         ID
    * @throws TODO: SQLException
    * @throws   
    * @return     id
    */ 
    int getById( int id);

	/**
	* Возвращает список всех активных продаж всех менеджеров
	* @return список с активными продажами или пустой список
	*/
	QList<ActiveSaleDTO> getActiveSales();
	
	/**
	* Возвращает список всех активных продаж определённого менеджера
	* @param managerId - идентификатор менеджера
	* @return список с активными продажами или пустой список
	*/
	QList<ActiveSaleDTO> getActiveSalesForManager( int managerId);
	
	/**
	* Возвращает список со статистикой об активных продажах для каждого из менеджеров
	* @return список со статистикой или пустой список
	*/
	QList<ManagerActiveSalesStatisticDTO> getManagerActiveSalesSatistic();

	/**
	* Возвращает информацию о продажах, которые были подтверждены в определенный период времени
	* @param id - идентификатор менеджера
	* @param from - дата начала периода (включая её)
	* @param to - дата окончания периода (включая её)
	* @return список с продажами или пустой список, если ничего не найдено
	*/
	QList<SaleInfoDTO> getSalesConfimedFromPeriod( int id, QDate from, QDate to);

	/**
	* Возвращает количество подтвержденных продаж, совершенных менеджером за заданный период
	* @param id - идентификатор менеджера
	* @param from - дата начала периода (включая её)
	* @param to - дата окончания периода (включая её)
	* @return количество подтвержденных продаж или 0
	*/
	int getConfirmedSalesCount( int managerId, QDate from, QDate to);

	/**
	* Подтверждает определённую продажу
	* @param id - идентификатор продажи
	*/
	void confirmSale( int id);
	
	/**
	* Снимает подтверждение с определённой продажи
	* @param id - идентификатор продажи
	*/
	void unconfirmSale( int id);

protected:
	QString TABLE_NAME;
	ActiveSale read(const QSqlQuery * sqlQuery);
	ActiveSaleDTO readActiveSalesToDTO( const QSqlQuery& query);

private:

	ManagerActiveSalesStatisticDTO readToDTO( const QSqlQuery& query, const QSqlQuery& queryWithManagerData);
	ManagerActiveSalesStatisticDTO readEmptyResultToDTO( const QSqlQuery& query);
};
