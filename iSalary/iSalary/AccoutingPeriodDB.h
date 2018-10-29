#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qvariant.h>
#include <qsqlerror.h>
#include <qdatetime.h>
#include "OpenAccoutingPeriod.h"
#include "AccoutingPeriod.h"

/*
CREATE TABLE `accouting_period` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `dataFrom` date NOT NULL,
  `dataTo` date DEFAULT NULL,
  `status` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
*/

/**
* Класс доступа к БД для сущности AccoutingPeriod
*
*/
class AccoutingPeriodDB {

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
    OpenAccoutingPeriod getCurrentPeriod();

	/**
	* Возвращает искомый РП (открытый или закрытый) по идентификатору
	* @param id - идентификатор искомого РП
	* @throws TODO: SQLException
    * @throws Запись не найдена
	* @return - объект с информацией об искомом РП (это либо OpenAccoutingPeriod или CloseAccoutingPeriod), или null если запись не найдена
	*/
	AccoutingPeriod getById( int id);

	/**
	* Возвращает искомый РП (открытый или закрытый) по дате, которая входит в интервал искомого периода (включая дату начала/конца)
	* @param date - дата
	* @throws TODO: SQLException
    * @throws Запись не найдена
	* @return - объект с информацией об искомом РП (это либо OpenAccoutingPeriod или CloseAccoutingPeriod), или null если запись не найдена
	*/
	AccoutingPeriod getByDate( QDateTime date);

	/**
    * Добавление записи о расчетном периоде в БД
    * @throws TODO: SQLException
    * @throws Запись не найдена
    * @param ap - добавляемая сущность
    */
	void insert( AccoutingPeriod ap);

	/**
    * Обновление записи о расчетном периоде в БД
    * @throws TODO: SQLException
    * @throws Запись не найдена
    * @param ap - обновляемая сущность
    */
	void update( AccoutingPeriod ap);

protected:

	/*
    * Инициализация полей
    */
    void init();

	/*
    * Чтение одной записи из Запроса (QSqlQuery)
    */
    //тут у нас? readOneRecord( const QSqlQuery& query) const;  

    /*
    * Выполнение Запроса (QSqlQuery) с обработкой ошибки
    */    
    void execQuery( QSqlQuery& query) const;
    
    /*
    * Обработка ошибки - выкидывает исключение с переданной ошибкой
    */
    void handleError( const QSqlError& error) const;
    
    /*
    * Обработка ошибки - выкидывает исключение с переданным текстом
    */
    void handleError( const QString& error) const;

    QSqlDatabase* db;       /**< экземпляр БД к которой будут применяться запросы */
    QString idField;		/**< Название поля с id в БД */
	QString dateFromField;  /**< Название поля с датой начала в БД */
    QString dateToField;    /**< Название поля с датой конца в БД */
    QString statusField;	/**< Название поля с типом пользователя в БД */
    QString tableName;      /**< Название таблицы в БД */
};