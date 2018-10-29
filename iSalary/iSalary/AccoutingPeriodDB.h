#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qvariant.h>
#include <qsqlerror.h>
#include <qdatetime.h>
#include "OpenAccoutingPeriod.h"
#include "AccoutingPeriod.h"

/*
CREATE TABLE `accouting_period` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `dataFrom` date NOT NULL,
  `dataTo` date DEFAULT NULL,
  `status` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
*/

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
    OpenAccoutingPeriod getCurrentPeriod();

	/**
	* ���������� ������� �� (�������� ��� ��������) �� ��������������
	* @param id - ������������� �������� ��
	* @throws TODO: SQLException
    * @throws ������ �� �������
	* @return - ������ � ����������� �� ������� �� (��� ���� OpenAccoutingPeriod ��� CloseAccoutingPeriod), ��� null ���� ������ �� �������
	*/
	AccoutingPeriod getById( int id);

	/**
	* ���������� ������� �� (�������� ��� ��������) �� ����, ������� ������ � �������� �������� ������� (������� ���� ������/�����)
	* @param date - ����
	* @throws TODO: SQLException
    * @throws ������ �� �������
	* @return - ������ � ����������� �� ������� �� (��� ���� OpenAccoutingPeriod ��� CloseAccoutingPeriod), ��� null ���� ������ �� �������
	*/
	AccoutingPeriod getByDate( QDateTime date);

	/**
    * ���������� ������ � ��������� ������� � ��
    * @throws TODO: SQLException
    * @throws ������ �� �������
    * @param ap - ����������� ��������
    */
	void insert( AccoutingPeriod ap);

	/**
    * ���������� ������ � ��������� ������� � ��
    * @throws TODO: SQLException
    * @throws ������ �� �������
    * @param ap - ����������� ��������
    */
	void update( AccoutingPeriod ap);

protected:

	/*
    * ������������� �����
    */
    void init();

	/*
    * ������ ����� ������ �� ������� (QSqlQuery)
    */
    //��� � ���? readOneRecord( const QSqlQuery& query) const;  

    /*
    * ���������� ������� (QSqlQuery) � ���������� ������
    */    
    void execQuery( QSqlQuery& query) const;
    
    /*
    * ��������� ������ - ���������� ���������� � ���������� �������
    */
    void handleError( const QSqlError& error) const;
    
    /*
    * ��������� ������ - ���������� ���������� � ���������� �������
    */
    void handleError( const QString& error) const;

    QSqlDatabase* db;       /**< ��������� �� � ������� ����� ����������� ������� */
    QString idField;		/**< �������� ���� � id � �� */
	QString dateFromField;  /**< �������� ���� � ����� ������ � �� */
    QString dateToField;    /**< �������� ���� � ����� ����� � �� */
    QString statusField;	/**< �������� ���� � ����� ������������ � �� */
    QString tableName;      /**< �������� ������� � �� */
};