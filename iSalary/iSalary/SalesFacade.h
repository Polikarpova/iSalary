#pragma once

#include "ManagerDB.h"
#include "Sale_DB.h"
#include "ActiveSaleDTO.h"

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
	void confirmSale(ActiveSaleDTO sale);

	/**
	* ����� �������� ������������� ����������� �������
	* sale - �������, ������������� ������� ����������
	*/
	void cancelConfirmSale(ActiveSaleDTO sale);

private:

	ManagerDB* m;
	Sale_DB* s;
};