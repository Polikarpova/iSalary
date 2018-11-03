#pragma once

#include "Salary.h"
#include "Manager.h"

/**
* Пречисление статусов РП
* @author Курносов
*/
enum AccoutingPeriodStatus {
    OPEN = 1,      /**< РП открыт */
    CLOSE = 0      /**< РП закрыт */
};

/**
* Абстрактный класс описывающий основное поведение сущности "Расчетный период"
* @author Поликарпова
*/
class AccoutingPeriod {

public:

	/**
    * Конструктор.
    * @param database - экземпляр уже настроенной QSqlDatabase
    */
    AccoutingPeriod( void);

	/**
	* Считает зарплату для одного менеджера
	* @param m - менеджер, для которого считается зарплата
	* @return - объект с информацией о зарплате в за определённый расчетный период
	*/
    Salary calcSalary( Manager& m);
};