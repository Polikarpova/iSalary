#include "ProductFacade.h"


ProductFacade::ProductFacade( Product_DB * product_DB ) {
	this->product_DB = product_DB;
}


ProductFacade::~ProductFacade(void) {
}

ProductDTO ProductFacade::addProduct( Product product ) {
	bool isSuccess = true;
	ProductDTO result;
    try { 
	    if ( product_DB->findByName( product.getName() ).getId() == 0 ) {
            product_DB->create( product );
		    result.product = product;
		    result.isEmpty = false;
	    } else {
		    result.isEmpty = true;
	    }
    } catch ( QString* error) {
        isSuccess = false;
    }
	result.isSuccess = isSuccess;
	return result;
}

ProductDTO ProductFacade::updateProduct( Product product ) {
	bool isSuccess = true;
	ProductDTO result;
	try { 
        product_DB->update( product );
	    result.product = product;
	    result.isEmpty = false;
    } catch ( QString* error ) {
        isSuccess = false;
    }
	result.isSuccess = isSuccess;
	return result;
}

ProductDTO ProductFacade::removeProduct( int id ) {
	bool isSuccess = true;
	ProductDTO result;
    try { 
        product_DB->remove( id );
	    result.isEmpty = true;
    } catch ( QString* error) {
        isSuccess = false;
    }
	result.isSuccess = isSuccess;
	return result;
}

ProductDTO ProductFacade::findByName( QString productName ) {
	Product product = product_DB->findByName( productName );
	ProductDTO result;
	result.product = product;
	result.isEmpty = false;
	bool isSuccess = true;
	if ( product.getId() == 0 )
		result.isEmpty = true;
	result.isSuccess = isSuccess;
	return result;
}

ProductDTO ProductFacade::findById( int id ) {
	Product product = product_DB->findById( id );
	ProductDTO result;
	result.product = product;
	result.isEmpty = false;
	bool isSuccess = true;
	if ( product.getId() == 0 )
		isSuccess = false;
	result.isSuccess = isSuccess;
	return result;
}

ProductDTO ProductFacade::getAll() {
	QVector<Product>products = product_DB->getAll();
	ProductDTO result;
	result.products = products;
	result.isEmpty = false;
	if ( products.size() == 0 )
		result.isEmpty = true;
	bool isSuccess = true;
	result.isSuccess = isSuccess;
	return result;
}