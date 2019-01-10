#pragma once

#include <qdatetime.h>
#include <qstring.h>

QString translite( const QString &str ) {
    QString res = "";
    for ( auto ich = str.begin(); ich != str.end(); ich++ ) {
        if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "a" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "b" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "v" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "g" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "d" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "e" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "ye" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "zh" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "z" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "i" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "y" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "k" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "l" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "m" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "n" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "o" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "p" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "r" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "s" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "t" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "u" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "f" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "ch" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "z" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "ch" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "sh" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "ch" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "y" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "e" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "yu" );
        } else if ( ich->toLower() == QChar( L'�' ) ) {
            res += ( "ya" );
        } else {
            res += "_";
        }
    }
    return res;
}

QString generateRandomString( int size = 6, const QString &charset = "abcdefghijklmnopqrstuvwxyz" ) {
    QString str;
    for ( int i = 1; i <= size; i++ ) {
        str += charset[(int)( ( QDateTime::currentMSecsSinceEpoch() + rand() ) % charset.size() )];
    }
    return str;
}