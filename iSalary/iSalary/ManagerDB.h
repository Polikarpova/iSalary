#pragma once

#include <qsqldatabase.h>
#include <qstring.h>
#include <qlist.h>

#include "Manager.h"
#include "UserDB.h"
#include "IManagerRepository.h"

class ManagerDB : protected UserDB, public IManagerRepository
{
public:

    /**
    * Конструктор.
    * @param database - экземпляр уже настроенной QSqlDatabase
    */
    ManagerDB( QSqlDatabase* database, UserDB* userDB);
    
    ~ManagerDB( void);

    /**
    * Получение записи о менеджере из БД по его ID
    * @throws TODO: SQLException
    * @throws Запись не найдена
    * @return запись Менеджера с заданным id
    */ 
    Manager getById( int id);

    /**
    * Получение списка записей о менеджерах из БД по его ID
    * @throws TODO: SQLException
    * @throws Запись не найдена
    * @return Список Записей менеджеров с id из заданого списка
    */ 
    QList<Manager> getAll();

    /**
    * Обновить запись о менеджере в БД
    * @param manager - обновляемый менеджер
    */
    void update( const Manager& manager) override;
    
    /**
    * Найти менеджера по ИНН
    * @param INN - ИНН менеджера
    * @param[out] manager - Указатель, по которому будет записан переданный менеджер, если будет найден ( можно передать NULL)
    * @return удалось ли найти менеджера с таким ИНН
    */
    bool findByINN( const QString& INN, Manager* manager) override;

    /**
    * Найти менеджера по ИНН
    * @param passportSerial - серия паспорта Менеджера
    * @param passportNumber - номер паспорта Менеджера
    * @param[out] manager - Указатель, по которому будет записан переданный менеджер, если будет найден ( можно передать NULL)
    * @return удалось ли найти менеджера с таким ИНН
    */
    bool findByPassport( const QString& passportSerial, const QString passportNumber, Manager* manager) override;

private:
    QSqlDatabase* db;       /**< экземпляр БД к которой будут применяться запросы */
    UserDB* userDB;

    QString tableName;
    QString firstNameField;
    QString secondNameField;
    QString thirdNameField;
    QString sexField;
    QString passportSerialField;
    QString passportNumberField;
    QString passportIssueDateField;
    QString addressField;
    QString INNField;
    QString emailField;
    QString mobileNumberField;
    QString dateOfEmploymentField;

    void init();

    Manager readOneRecord( const QSqlQuery& query);
};

