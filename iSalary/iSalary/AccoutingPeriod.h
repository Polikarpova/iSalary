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
    * @param database - ��������� ��� ����������� QSqlDatabase
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
};