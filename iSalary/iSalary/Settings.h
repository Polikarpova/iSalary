#pragma once
#include <qjsonobject.h>
#include <qjsondocument.h>
#include <qfile.h>

class Settings
{
public:
    Settings(void);
    ~Settings(void);
    QString databaseIP;
    QString databasePort;
    QString databaseName;
    QString databaseUser;
    QString databasePassword;
    static Settings read(QFile* settingsFile);
    static void writeDefault(QFile* settingsFile);

protected:
    static QString keyDatabaseIP;
    static QString defaultDatabaseIP;
    
    static QString keyDatabasePort;
    static QString defaultDatabasePort;

    static QString keyDatabaseName;
    static QString defaultDatabaseName;
    
    static QString keyDatabaseUser;
    static QString defaultDatabaseUser;
    
    static QString keyDatabasePassword;
    static QString defaultDatabasePassword;
};

