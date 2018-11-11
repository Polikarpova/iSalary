#pragma once

#include "ManagerDB.h"
#include "Sale_DB.h"
#include "ActiveSaleDTO.h"
#include "ManagerActiveSalesStatisticDTO.h"

/**
* �����, ��������������� ������ � �������� ����������, ��������� � ���������
* @author �����������
*/
class SalesFacade {
public:

	SalesFacade( ManagerDB* manager, Sale_DB* sale);

	/**
	* ����� ������������ ����������� �������
	* sale - �������, ������� ������ ���� ������������
	*/
	void confirmSale( ActiveSaleDTO sale);

	/**
	* ����� �������� ������������� ����������� �������
	* sale - �������, ������������� ������� ����������
	*/
	void cancelConfirmSale( ActiveSaleDTO sale);

	/**
	* ��������� �������� ������� (�������������� � ����������������) ������������� ���������
	* @param managerId - id ���������
	* @return ������ ������ ��������� � ��������� id
	*/
	QList<ActiveSaleDTO> getActiveSales( int managerId);

	/**
	* ��������� ���������� ������ ��� �������� "�������" ���� ���������� �� ������������ ����
	* @param date - ����
	* @return ������ �� ����������� �� ������� ���������
	*/
	QList<ManagerActiveSalesStatisticDTO> getActiveSalesStatistic( QDate date);

private:

	ManagerDB* m;
	Sale_DB* s;
};