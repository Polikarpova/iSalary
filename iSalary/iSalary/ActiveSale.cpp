#include "ActiveSale.h"


ActiveSale::ActiveSale(void)
{
}


ActiveSale::~ActiveSale(void)
{
}

void ActiveSale::confirm() {
	isConfirm = true;
}

void ActiveSale::cancelConfirm() {
	isConfirm = false;
}