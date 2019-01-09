#ifndef CODEC_H
#define CODEC_H

#include <qstring.h>
#include <qtextcodec.h>

QString toUnicode( const char *str );

QString toUnicode( const QString &str );

#endif