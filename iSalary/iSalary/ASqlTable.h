#pragma once
#include "isqltable.h"
#include "qsqldatabase.h"
#include "qsqlerror.h"
#include "qsqlquery.h"

class ASqlTable :
    public ISqlTable
{
public:
    
    /*
    * ���������� ������� (QSqlQuery) � ���������� ������
    */    
   virtual void execQuery( QSqlQuery& query) const;

   
    /*
    * ��������� ������ - ���������� ���������� � ���������� �������
    */
    virtual void handleError( QSqlError error) const;
    
    /*
    * ��������� ������ - ���������� ���������� � ���������� �������
    */
    virtual void handleError( const QString& error) const;

protected:
    QSqlDatabase* db;       /**< ��������� �� � ������� ����� ����������� ������� */
};

