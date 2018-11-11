#pragma once

#include "ProductDTO.h"
#include "Product_DB.h"
class ProductFacade {
public:
	ProductFacade( Product_DB * product_DB );
	~ProductFacade(void);

	ProductDTO addProduct( Product product );
	ProductDTO updateProduct( Product product );
	ProductDTO removeProduct( int id );
	ProductDTO findByName( QString productName );
	ProductDTO findById( int id );
	ProductDTO getAll();
private:
	Product_DB *product_DB;
};

