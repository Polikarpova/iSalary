#pragma once

#include "ManagerDB.h"
#include "Sale_DB.h"
#include "AccoutingPeriodDB.h"
#include "ActiveSaleDTO.h"
#include "ManagerActiveSalesStatisticDTO.h"

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

private:

	ManagerDB* m;
	Sale_DB* s;
	AccoutingPeriodDB* ap;
};