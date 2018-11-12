#pragma once
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVariant>
#include <QSqlResult>
#include "ActiveSale.h"
#include "ClosedSale.h"
#include "Manager.h"
#include <QVector>
#include <QSqlError>

#include <qlist.h>
#include "ManagerActiveSalesStatisticDTO.h"
#include "ActiveSaleDTO.h"

class Sale_DB
{
public:
	Sale_DB( QSqlDatabase &db, QString table_name );
	~Sale_DB(void);
	void init();
	bool create( ActiveSale sale );
	bool remove( int id );
	void fillSale( ActiveSale & sale, const QSqlQuery * sqlQuery );
	QVector<ActiveSale> getActiveAll( int manager_id );

	/**
    * ��������� ������ � ������� �� �� �� ��� ID
    * @throws TODO: SQLException
    * @throws ������ �� �������
    * @return ������ ������� � �������� id
    */ 
    int getById( int id);

	QList<ActiveSaleDTO> getActiveSales();
	QList<ManagerActiveSalesStatisticDTO> getManagerActiveSalesSatistic();

protected:
	QString TABLE_NAME;
	ActiveSale read(const QSqlQuery * sqlQuery);
	ManagerActiveSalesStatisticDTO readToDTO( const QSqlQuery& query);
	ActiveSaleDTO readActiveSalesToDTO( const QSqlQuery& query);
	void execQuery( QSqlQuery& query) const;

	/*
    * ��������� ������ - ���������� ���������� � ���������� �������
    */
    void handleError( const QSqlError& error) const;
    
    /*
    * ��������� ������ - ���������� ���������� � ���������� �������
    */
    void handleError( const QString& error) const;

private:
	QSqlDatabase _db;
};

