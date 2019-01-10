#pragma once

#include <qdatetime.h>
#include <qstring.h>

QString translite( const QString &str ) {
    QString res = "";
    for ( auto ich = str.begin(); ich != str.end(); ich++ ) {
        if ( ich->toLower() == QChar( L'à' ) ) {
            res += ( "a" );
        } else if ( ich->toLower() == QChar( L'á' ) ) {
            res += ( "b" );
        } else if ( ich->toLower() == QChar( L'â' ) ) {
            res += ( "v" );
        } else if ( ich->toLower() == QChar( L'ã' ) ) {
            res += ( "g" );
        } else if ( ich->toLower() == QChar( L'ä' ) ) {
            res += ( "d" );
        } else if ( ich->toLower() == QChar( L'å' ) ) {
            res += ( "e" );
        } else if ( ich->toLower() == QChar( L'¸' ) ) {
            res += ( "ye" );
        } else if ( ich->toLower() == QChar( L'æ' ) ) {
            res += ( "zh" );
        } else if ( ich->toLower() == QChar( L'ç' ) ) {
            res += ( "z" );
        } else if ( ich->toLower() == QChar( L'è' ) ) {
            res += ( "i" );
        } else if ( ich->toLower() == QChar( L'é' ) ) {
            res += ( "y" );
        } else if ( ich->toLower() == QChar( L'ê' ) ) {
            res += ( "k" );
        } else if ( ich->toLower() == QChar( L'ë' ) ) {
            res += ( "l" );
        } else if ( ich->toLower() == QChar( L'ì' ) ) {
            res += ( "m" );
        } else if ( ich->toLower() == QChar( L'í' ) ) {
            res += ( "n" );
        } else if ( ich->toLower() == QChar( L'î' ) ) {
            res += ( "o" );
        } else if ( ich->toLower() == QChar( L'ï' ) ) {
            res += ( "p" );
        } else if ( ich->toLower() == QChar( L'ð' ) ) {
            res += ( "r" );
        } else if ( ich->toLower() == QChar( L'ñ' ) ) {
            res += ( "s" );
        } else if ( ich->toLower() == QChar( L'ò' ) ) {
            res += ( "t" );
        } else if ( ich->toLower() == QChar( L'ó' ) ) {
            res += ( "u" );
        } else if ( ich->toLower() == QChar( L'ô' ) ) {
            res += ( "f" );
        } else if ( ich->toLower() == QChar( L'õ' ) ) {
            res += ( "ch" );
        } else if ( ich->toLower() == QChar( L'ö' ) ) {
            res += ( "z" );
        } else if ( ich->toLower() == QChar( L'÷' ) ) {
            res += ( "ch" );
        } else if ( ich->toLower() == QChar( L'ø' ) ) {
            res += ( "sh" );
        } else if ( ich->toLower() == QChar( L'ù' ) ) {
            res += ( "ch" );
        } else if ( ich->toLower() == QChar( L'û' ) ) {
            res += ( "y" );
        } else if ( ich->toLower() == QChar( L'ý' ) ) {
            res += ( "e" );
        } else if ( ich->toLower() == QChar( L'þ' ) ) {
            res += ( "yu" );
        } else if ( ich->toLower() == QChar( L'ÿ' ) ) {
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