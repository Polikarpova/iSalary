#pragma once
#include "SqlErrorHandler.h"
#include "isqltable.h"
#include <qsqldatabase.h>
#include <qsqlerror.h>
#include <qsqlquery.h>

class ASqlTable : public ISqlTable {
  public:
    /*
     * Выполнение Запроса (QSqlQuery) с обработкой ошибки
     */
    virtual void execQuery( QSqlQuery &query ) const;

    /*
     * Обработка ошибки - выкидывает исключение с переданной ошибкой
     */
    virtual void handleError( QSqlError error ) const;

    /*
     * Обработка ошибки - выкидывает исключение с переданным текстом
     */
    virtual void handleError( const QString &error ) const;

    virtual void setErrorHandler( SqlErrorHandler * );

  protected:
    QSqlDatabase *db; /**< экземпляр БД к которой будут применяться запросы */
    SqlErrorHandler *errorHandler;
};
