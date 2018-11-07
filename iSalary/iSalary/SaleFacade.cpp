#include "SalesFacade.h"

SaleFacade::SaleFacade( ManagerDB* manager, Sale_DB* sale) {

	this->m = manager;
	this->s = sale;
}