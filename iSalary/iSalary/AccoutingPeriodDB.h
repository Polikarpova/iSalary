#pragma once

#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qvariant.h>
#include <qsqlerror.h>
#include <qdatetime.h>
#include "OpenAccoutingPeriod.h"
#include "AccoutingPeriod.h"
#include "AccoutingPeriodDTO.h"

#include <qmessagebox.h>

/**
* ����� ������� � �� ��� �������� AccoutingPeriod
*
*/
class AccoutingPeriodDB {

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
    * ���������� ������� (QSqlQuery) � ���������� ������
    */    
    void execQuery( QSqlQuery& query) const;
    
    /**
    * ��������� ������ - ���������� ���������� � ���������� �������
    */
    void handleError( const QSqlError& error) const;
    
    /**
    * ��������� ������ - ���������� ���������� � ���������� �������
    */
    void handleError( const QString& error) const;

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

private:

    QSqlDatabase* db;       /**< ��������� �� � ������� ����� ����������� ������� */
    QString idField;		/**< �������� ���� � id � �� */
	QString dateFromField;  /**< �������� ���� � ����� ������ � �� */
    QString dateToField;    /**< �������� ���� � ����� ����� � �� */
    QString statusField;	/**< �������� ���� � ����� ������������ � �� */
    QString tableName;      /**< �������� ������� � �� */
};