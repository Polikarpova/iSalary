#pragma once

#include "ManagerDB.h"
#include "Sale_DB.h"
#include "ActiveSaleDTO.h"

/**
* �����, ��������������� ������ � �������� ����������, ��������� � ���������
* @author �����������
*/
class SaleFacade {
public:

	SaleFacade( ManagerDB* manager, Sale_DB* sale);

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