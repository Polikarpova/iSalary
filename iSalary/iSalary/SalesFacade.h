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

/**
* �����, ��������������� ������ � �������� ����������, ��������� � ���������
* @author �����������
*/
class SalesFacade {
public:

	SalesFacade( ManagerDB* manager, Sale_DB* sale, AccoutingPeriodDB* period);

	SaleDTO addActiveSale( ActiveSale activeSale );
	SaleDTO removeActiveSale( int id );
	SaleDTO getActiveSales( int manager_id );

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
	* ��������� �������� ������� (�������������� � ����������������) ������������� ���������
	* @param managerId - id ���������
	* @return ������ ������ ��������� � ��������� id
	*/
	QList<ActiveSaleDTO> getActiveSalesForManager( int managerId);

	/**
	* ��������� ���������� ������ ��� �������� "�������" ���� ���������� �� ������������ ����
	* @param date - ����
	* @return ������ �� ����������� �� ������� ���������
	*/
	QList<ManagerActiveSalesStatisticDTO> getActiveSalesStatistic( QDate date);

	/**
	* ���������� ������ ���� ������� �� ������������ ������
	* @param dateFrom - ������ �������
	* @param dateTo - ����� �������
	* @return ������ ������� ��� ������ ������
	*/
	QList<ManagerSalaryDTO> getManagersSalary( QDate dateFrom, QDate dateTo);

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