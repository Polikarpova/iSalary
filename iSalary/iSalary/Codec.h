#ifndef CODEC_H
#define CODEC_H

#include <qtextcodec.h>

const QString& toUni( const QString& str){
    QTextCodec* c = QTextCodec::codecForName("UTF-8");
    return c->toUnicode(str.toLocal8Bit());
}

#endif