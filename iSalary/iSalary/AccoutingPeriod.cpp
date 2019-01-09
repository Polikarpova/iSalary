#include "AccoutingPeriod.h"

AccoutingPeriod::AccoutingPeriod( void ) { this->id = -1; }

void AccoutingPeriod::setId( int id ) { this->id = id; }

void AccoutingPeriod::setDateFrom( QDate dateFrom ) { this->dateFrom = dateFrom; }