#pragma once

#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qvariant.h>
#include <qsqlerror.h>
#include <qdatetime.h>
#include <qmessagebox.h>

#include "OpenAccoutingPeriod.h"
#include "AccoutingPeriod.h"
#include "AccoutingPeriodDTO.h"
#include "ASqlTable.h"

/**
* Класс доступа к БД для сущности AccoutingPeriod
*
*/
class AccoutingPeriodDB : public ASqlTable {

public:
	/**
    * Конструктор.
    * @param database - экземпляр уже настроенной QSqlDatabase
    */
    AccoutingPeriodDB( QSqlDatabase* database);

	/**
	* Возвращает объект с текущим открытым РП
	* @return - объект с текущим РП
	*/
    AccoutingPeriodDTO getCurrentPeriod();

	/**
	* Возвращает искомый РП (открытый или закрытый) по идентификатору
	* @param id - идентификатор искомого РП
	* @throws TODO: SQLException
    * @throws Запись не найдена
	* @return - объект с информацией об искомом РП (это либо OpenAccoutingPeriod или CloseAccoutingPeriod), или null если запись не найдена
	*/
	AccoutingPeriod* getById( int id);

	/**
	* Возвращает искомый РП (открытый или закрытый) по дате, которая входит в интервал искомого периода (включая дату начала/конца)
	* @param date - дата
	* @throws TODO: SQLException
    * @throws Запись не найдена
	* @return - объект с информацией об искомом РП (это либо OpenAccoutingPeriod или CloseAccoutingPeriod), или null если запись не найдена
	*/
	AccoutingPeriod* getByDate( QDateTime date);

	/**
    * Добавление записи о расчетном периоде в БД
    * @throws TODO: SQLException
    * @throws Запись не найдена
    * @param ap - добавляемая сущность
    */
	void insert( AccoutingPeriod* ap);

	/**
    * Обновление записи о расчетном периоде в БД
    * @throws TODO: SQLException
    * @throws Запись не найдена
    * @param ap - обновляемая сущность
    */
	void update( AccoutingPeriod* ap);

	/**
	* Возвращает список со всеми РП
	* @return список со всеми РП. Список никогда не должен возвращаться пустым, так как всегда есть хотя бы один РП (он же будет текущим)
	*/
	QList<AccoutingPeriodDTO> getAllPeriods();

protected:

	/**
    * Инициализация полей
    */
    void init();

	/**
    * Чтение одной записи из Запроса (QSqlQuery)
    */
    AccoutingPeriodDTO readOneRecord( const QSqlQuery& query) const;  

	/**
	* Создает самый первый рассчетный период, если в БД нет ни одного периода
	* Период инициализируется текущим месяцем
	*/
	void initAccountingPeriod();

	void openAccountingPeriod();

	void closePeriod( int id, QDate dateFrom);

	/**
	* Проверяет, надо ли закрыть текущий период. Если да, то он закрывается и начинается новый.
	*/
	void checkCurrentPeriod();

    void createTable() override;

private:

    QString idField;		/**< Название поля с id в БД */
	QString dateFromField;  /**< Название поля с датой начала в БД */
    QString dateToField;    /**< Название поля с датой конца в БД */
    QString statusField;	/**< Название поля с типом пользователя в БД */
    QString tableName;      /**< Название таблицы в БД */
};