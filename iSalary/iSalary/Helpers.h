#pragma once

#include <qstring.h>


QString translite(const QString& str);

QString generateRandomString( int size = 6, const QString& charset = "abcdefghijklmnopqrstuvwxyz");