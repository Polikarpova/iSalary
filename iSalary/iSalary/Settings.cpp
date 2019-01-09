#include "Settings.h"

QString Settings::keyDatabaseIP = "databaseIP";
QString Settings::defaultDatabaseIP = "127.0.0.1";

QString Settings::keyDatabasePort = "databasePort";
QString Settings::defaultDatabasePort = "3306";

QString Settings::keyDatabaseName = "databaseName";
QString Settings::defaultDatabaseName = "mdkp";

QString Settings::keyDatabaseUser = "databaseUser";
QString Settings::defaultDatabaseUser = "root";

QString Settings::keyDatabasePassword = "databasePassword";
QString Settings::defaultDatabasePassword = "root";

Settings::Settings( void ) {
    this->databaseIP = defaultDatabaseIP;
    this->databaseName = defaultDatabaseName;
    this->databasePassword = defaultDatabasePassword;
    this->databaseUser = defaultDatabaseUser;
}

Settings Settings::read( QFile *settingsFile ) {
    settingsFile->open( QIODevice::ReadOnly );
    QJsonDocument settingsJsonDoc = QJsonDocument::fromJson( settingsFile->readAll() );
    settingsFile->close();
    QJsonObject settingsJson = settingsJsonDoc.object();

    Settings settings;
    try {
        settings.databaseIP = settingsJson.take( keyDatabaseIP ).toString();
    } catch ( ... ) {
        settings.databaseIP = defaultDatabaseIP;
    }
    try {
        settings.databasePort = settingsJson.take( keyDatabasePort ).toString();
    } catch ( ... ) {
        settings.databasePort = defaultDatabasePort;
    }
    try {
        settings.databaseName = settingsJson.take( keyDatabaseName ).toString();
    } catch ( ... ) {
        settings.databaseName = defaultDatabaseName;
    }
    try {
        settings.databasePassword = settingsJson.take( keyDatabasePassword ).toString();
    } catch ( ... ) {
        settings.databasePassword = defaultDatabasePassword;
    }
    try {
        settings.databaseUser = settingsJson.take( keyDatabaseUser ).toString();
    } catch ( ... ) {
        settings.databaseUser = defaultDatabaseUser;
    }
    return settings;
}

void Settings::writeDefault( QFile *settingsFile ) {
    QJsonDocument doc;
    QJsonObject settingsJson;
    settingsJson.insert( keyDatabaseIP, defaultDatabaseIP );
    settingsJson.insert( keyDatabasePort, defaultDatabasePort );
    settingsJson.insert( keyDatabaseName, defaultDatabaseName );
    settingsJson.insert( keyDatabaseUser, defaultDatabaseUser );
    settingsJson.insert( keyDatabasePassword, defaultDatabasePassword );
    doc.setObject( settingsJson );

    settingsFile->open( QIODevice::WriteOnly );
    settingsFile->write( doc.toJson() );
    settingsFile->close();
}

Settings::~Settings( void ) {}