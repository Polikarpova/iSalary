#pragma once

#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qvariant.h>
#include <qsqlerror.h>
#include <qdatetime.h>
#include <qmessagebox.h>

#include "OpenAccoutingPeriod.h"
#include "AccoutingPeriod.h"
#include "AccoutingPeriodDTO.h"
#include "ASqlTable.h"

/**
* ����� ������� � �� ��� �������� AccoutingPeriod
*
*/
class AccoutingPeriodDB : public ASqlTable {

public:
	/**
    * �����������.
    * @param database - ��������� ��� ����������� QSqlDatabase
    */
    AccoutingPeriodDB( QSqlDatabase* database);

	/**
	* ���������� ������ � ������� �������� ��
	* @return - ������ � ������� ��
	*/
    AccoutingPeriodDTO getCurrentPeriod();

	/**
	* ���������� ������� �� (�������� ��� ��������) �� ��������������
	* @param id - ������������� �������� ��
	* @throws TODO: SQLException
    * @throws ������ �� �������
	* @return - ������ � ����������� �� ������� �� (��� ���� OpenAccoutingPeriod ��� CloseAccoutingPeriod), ��� null ���� ������ �� �������
	*/
	AccoutingPeriod* getById( int id);

	/**
	* ���������� ������� �� (�������� ��� ��������) �� ����, ������� ������ � �������� �������� ������� (������� ���� ������/�����)
	* @param date - ����
	* @throws TODO: SQLException
    * @throws ������ �� �������
	* @return - ������ � ����������� �� ������� �� (��� ���� OpenAccoutingPeriod ��� CloseAccoutingPeriod), ��� null ���� ������ �� �������
	*/
	AccoutingPeriod* getByDate( QDateTime date);

	/**
    * ���������� ������ � ��������� ������� � ��
    * @throws TODO: SQLException
    * @throws ������ �� �������
    * @param ap - ����������� ��������
    */
	void insert( AccoutingPeriod* ap);

	/**
    * ���������� ������ � ��������� ������� � ��
    * @throws TODO: SQLException
    * @throws ������ �� �������
    * @param ap - ����������� ��������
    */
	void update( AccoutingPeriod* ap);

	/**
	* ���������� ������ �� ����� ��
	* @return ������ �� ����� ��. ������ ������� �� ������ ������������ ������, ��� ��� ������ ���� ���� �� ���� �� (�� �� ����� �������)
	*/
	QList<AccoutingPeriodDTO> getAllPeriods();

protected:

	/**
    * ������������� �����
    */
    void init();

	/**
    * ������ ����� ������ �� ������� (QSqlQuery)
    */
    AccoutingPeriodDTO readOneRecord( const QSqlQuery& query) const;  

	/**
	* ������� ����� ������ ���������� ������, ���� � �� ��� �� ������ �������
	* ������ ���������������� ������� �������
	*/
	void initAccountingPeriod();

	void openAccountingPeriod();

	void closePeriod( int id, QDate dateFrom);

	/**
	* ���������, ���� �� ������� ������� ������. ���� ��, �� �� ����������� � ���������� �����.
	*/
	void checkCurrentPeriod();

    void createTable() override;

private:

    QString idField;		/**< �������� ���� � id � �� */
	QString dateFromField;  /**< �������� ���� � ����� ������ � �� */
    QString dateToField;    /**< �������� ���� � ����� ����� � �� */
    QString statusField;	/**< �������� ���� � ����� ������������ � �� */
    QString tableName;      /**< �������� ������� � �� */
};