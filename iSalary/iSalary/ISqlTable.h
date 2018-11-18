#pragma once
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qstring.h>

class ISqlTable
{
public:
    virtual void createTable() = 0;
};

