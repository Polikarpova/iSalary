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

/**
* �����, ��������������� ������ � �������� ����������, ��������� � ���������
* @author �����������
*/
class SalesFacade {
public:

	SalesFacade( ManagerDB* manager, Sale_DB* sale, AccoutingPeriodDB* period);

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

private:

	ManagerDB* m;
	Sale_DB* s;
	AccoutingPeriodDB* ap;
};