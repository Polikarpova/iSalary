#pragma once

#include <qdatetime.h>

struct AccoutingPeriodDTO {

    int id;
    QDate dateFrom;
    QDate dateTo;
    int status; /* аналогичен перечислению AccoutingPeriodStatus */
};