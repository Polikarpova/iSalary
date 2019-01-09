#pragma once

#include "ISqlTable.h"
#include <qlist.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qstring.h>
#include <qstringlist.h>

QStringList getDatabasesList( QSqlDatabase *db ) {
    QString sql = "SHOW DATABASES";
    QSqlQuery query( *db );
    query.prepare( sql );
    query.exec();

    QStringList databaseList;
    while ( query.next() ) {
        databaseList.append( query.value( "Database" ).value<QString>() );
    }
    return databaseList;
}

bool isDatabaseExist( QSqlDatabase *db, QString dbName ) { return getDatabasesList( db ).contains( dbName ); }

bool createDbIfNotExist( QSqlDatabase *db, QString dbName ) {
    bool isSuccess = true;
    if ( !isDatabaseExist( db, dbName ) ) {
        QString sql = "CREATE DATABASE `" + dbName + "` ;";
        QSqlQuery query( *db );
        query.prepare( sql );
        isSuccess = query.exec();
        QString err = query.lastError().text() + db->lastError().text();
    }
    return isSuccess;
}

/**
 * @param tables - QList наследников ISqlTable
 */
template <class TISqlTable> bool createDbAndTables( QSqlDatabase *db, QString dbName, QList<TISqlTable *> tables ) {

    bool created = createDbIfNotExist( db, dbName );
    db->setDatabaseName( dbName );
    db->open();
    QString dbname_ = db->databaseName();
    for ( auto iTable = tables.begin(); iTable != tables.end(); iTable++ ) {
        ( *iTable )->createTable();
    }
    return created;
}