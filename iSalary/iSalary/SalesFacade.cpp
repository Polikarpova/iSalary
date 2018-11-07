#include "SalesFacade.h"

SalesFacade::SalesFacade( ManagerDB* manager, Sale_DB* sale) {

	this->m = manager;
	this->s = sale;
}