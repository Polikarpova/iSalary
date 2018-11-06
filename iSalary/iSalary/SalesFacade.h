#pragma once

#include "ManagerDB.h"
#include "Sale_DB.h"
#include "ActiveSaleDTO.h"

/**
* Класс, предоставляющий доступ к функциям приложения, связанным с продажами
* @author Поликарпова
*/
class SaleFacade {
public:

	SaleFacade( ManagerDB* manager, Sale_DB* sale);

	/**
	* Метод подтверждает определённую продажу
	* sale - продажа, которая должна быть подтверждена
	*/
	void confirmSale(ActiveSaleDTO sale);

	/**
	* Метод отменяет подтверждение определённой продажи
	* sale - продажа, подтверждение которой отменяется
	*/
	void cancelConfirmSale(ActiveSaleDTO sale);

private:

	ManagerDB* m;
	Sale_DB* s;
};