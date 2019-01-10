#include "Codec.h"

QString toUnicode( const char *str ) {
    QTextCodec *c = QTextCodec::codecForName( "UTF-8" );
    const QString &res = c->toUnicode( str );
    return res;
}

QString toUnicode( const QString &str ) { return toUnicode( str.toStdString().c_str() ); }