#pragma once
#include "SaleDTO.h"
#include "Sale_DB.h"

class SaleFacade
{
public:
	SaleFacade( Sale_DB *sale_DB );
	~SaleFacade(void);

	SaleDTO addActiveSale( ActiveSale activeSale );
	SaleDTO removeActiveSale( int id );
	SaleDTO getActiveSales( int manager_id );

private:
	Sale_DB *sale_DB;
};

