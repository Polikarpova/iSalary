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
* �����, ��������������� ������ � �������� ����������, ��������� � ��������� � �����������
* @author �����������
*/
class SalesFacade {
public:

	SalesFacade( ManagerDB* manager, Sale_DB* sale, AccoutingPeriodDB* period);

	SaleDTO addActiveSale( ActiveSale activeSale );
	SaleDTO removeActiveSale( int id );
	SaleDTO getActiveSales( int manager_id );

	SaleDTO getActiveSalesInCurrentPeriod( int manager_id );

	/**
	* ����� ������������ ����������� �������
	* sale - �������, ������� ������ ���� ������������
	*/
	void confirmSale( const ActiveSaleDTO& sale);

	/**
	* ����� �������� ������������� ����������� �������
	* sale - �������, ������������� ������� ����������
	*/
	void cancelConfirmSale( const ActiveSaleDTO& sale);

	/**
	* ��������� �������� ������� (�������������� � ����������������) ���� ����������
	* @return ������ ������
	*/
	QList<ActiveSaleDTO> getActiveSales();

	/**
	* ��������� ������� ����������, �������������� � �������� ������
	* @param managersIds - �������������� ����������
	* @param dateFrom - ������ �������
	* @param dateTo - ����� �������
	* @return ������ ������
	*/
	QList<ActiveSaleDTO> getConfirmedSalesFromPeriod( QList<int> managersIds, QDate dateFrom, QDate dateTo );

	/**
	* ��������� �������������� ������� ����������, ��������� � �������� ������
	* @param managersIds - �������������� ����������
	* @param dateFrom - ������ �������
	* @param dateTo - ����� �������
	* @return ������ ������
	*/
	QList<ActiveSaleDTO> getConfirmedSalesSoldFromPeriod( QList<int> managersIds, QDate dateFrom, QDate dateTo );

	/**
	* ��������� �������� ������� (�������������� � ����������������) ������������� ���������
	* @param managerId - id ���������
	* @return ������ ������ ��������� � ��������� id
	*/
	QList<ActiveSaleDTO> getActiveSalesForManager( int managerId);

	/**
	* ��������� ���������� ������ ��� �������� "�������" ���� ����������
	* @return ������ �� ����������� �� ������� ���������
	*/
	QList<ManagerActiveSalesStatisticDTO> getActiveSalesStatistic();

	/**
	* ���������� ������ ���� ������� �� ������������ ������
	* @param dateFrom - ������ �������
	* @param dateTo - ����� �������
	* @return ������ ������� ��� ������ ������
	*/
	QList<ManagerSalaryDTO> getManagersSalary( QDate dateFrom, QDate dateTo);

	/**
	* ���������� ������ �� ����������� � �������� ���� ���������� �� ������������ ������
	* @param dateFrom - ������ �������
	* @param dateTo - ����� �������
	* @return ������ �� ����������� ��� ������ ������
	*/
	QList<ManagerStatisticDTO> getManagersStatistic( QDate dateFrom, QDate dateTo);

	/**
	* ���������� ������ �� ����� ��
	* @return ������ �� ����� ��. ������ ������� �� ������ ������������ ������, ��� ��� ������ ���� ���� �� ���� �� (�� �� ����� �������)
	*/
	QList<AccoutingPeriodDTO> getAllAccoutingPeriods();

	/**
	* ���������� ���������� � ��������� �� id
	* @param id - ������������� �������� ���������
	* @return ����������� � ���������, ��� null, ���� �������� �� ������
	*/
	ManagerDTO getManagerInfo( int id);

private:

	ManagerDB* m;
	Sale_DB* s;
	AccoutingPeriodDB* ap;
};