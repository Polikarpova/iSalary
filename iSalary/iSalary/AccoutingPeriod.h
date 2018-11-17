#pragma once

#include "Salary.h"
#include "Manager.h"

/**
* ����������� �������� ��
* @author ��������
*/
enum AccoutingPeriodStatus {
    OPEN = 1,      /**< �� ������ */
    CLOSE = 0      /**< �� ������ */
};

/**
* ����������� ����� ����������� �������� ��������� �������� "��������� ������"
* @author �����������
*/
class AccoutingPeriod {

public:

	/**
    * �����������.
    */
    AccoutingPeriod( void);

	/**
	* ����������
	*/
	virtual ~AccoutingPeriod() = 0 {};

	/**
	* ������� �������� ��� ������ ���������
	* @param m - ��������, ��� �������� ��������� ��������
	* @return - ������ � ����������� � �������� � �� ����������� ��������� ������
	*/
    Salary calcSalary( Manager& m);

	void setId( int id);
	void setDateFrom( QDate dateFrom);

private:

	int id;	/**< id ���������� ������� */
	QDate dateFrom;	/**< ���� �������� */
};