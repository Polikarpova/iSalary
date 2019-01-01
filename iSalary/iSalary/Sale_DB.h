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
    * ��������� ������ � ������� �� �� �� ��� ID
    * @throws TODO: SQLException
    * @throws ������ �� �������
    * @return ������ ������� � �������� id
    */ 
    int getById( int id);

	/**
	* ���������� ������ ���� �������� ������ ���� ����������
	* @return ������ � ��������� ��������� ��� ������ ������
	*/
	QList<ActiveSaleDTO> getActiveSales();
	
	/**
	* ���������� ������ ���� �������� ������ ������������ ���������
	* @param managerId - ������������� ���������
	* @return ������ � ��������� ��������� ��� ������ ������
	*/
	QList<ActiveSaleDTO> getActiveSalesForManager( int managerId);
	
	/**
	* ���������� ������ �� ����������� �� �������� �������� ��� ������� �� ����������
	* @return ������ �� ����������� ��� ������ ������
	*/
	QList<ManagerActiveSalesStatisticDTO> getManagerActiveSalesSatistic();

	/**
	* ���������� ���������� � ��������, ������� ���� ������������ � ������������ ������ �������
	* @param id - ������������� ���������
	* @param from - ���� ������ ������� (������� �)
	* @param to - ���� ��������� ������� (������� �)
	* @return ������ � ��������� ��� ������ ������, ���� ������ �� �������
	*/
	QList<SaleInfoDTO> getSalesConfimedFromPeriod( int id, QDate from, QDate to);

	/**
	* ���������� ���������� �������������� ������, ����������� ���������� �� �������� ������
	* @param id - ������������� ���������
	* @param from - ���� ������ ������� (������� �)
	* @param to - ���� ��������� ������� (������� �)
	* @return ���������� �������������� ������ ��� 0
	*/
	int getConfirmedSalesCount( int managerId, QDate from, QDate to);

	/**
	* ������������ ����������� �������
	* @param id - ������������� �������
	*/
	void confirmSale( int id);
	
	/**
	* ������� ������������� � ����������� �������
	* @param id - ������������� �������
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
