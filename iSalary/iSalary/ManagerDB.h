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
    * �����������.
    * @param database - ��������� ��� ����������� QSqlDatabase
    */
    ManagerDB( QSqlDatabase* database, UserDB* userDB);
    
    ~ManagerDB( void);

    /**
    * ��������� ������ � ��������� �� �� �� ��� ID
    * @throws TODO: SQLException
    * @throws ������ �� �������
    * @return ������ ��������� � �������� id
    */ 
    Manager getById( int id);

    /**
    * ��������� ������ ������� � ���������� �� �� �� ��� ID
    * @throws TODO: SQLException
    * @throws ������ �� �������
    * @return ������ ������� ���������� � id �� �������� ������
    */ 
    QList<Manager> getAll();

    /**
    * �������� ������ � ��������� � ��
    * @param manager - ����������� ��������
    */
    void update( const Manager& manager) override;
    
    /**
    * ����� ��������� �� ���
    * @param INN - ��� ���������
    * @param[out] manager - ���������, �� �������� ����� ������� ���������� ��������, ���� ����� ������ ( ����� �������� NULL)
    * @return ������� �� ����� ��������� � ����� ���
    */
    bool findByINN( const QString& INN, Manager* manager) override;

    /**
    * ����� ��������� �� ���
    * @param passportSerial - ����� �������� ���������
    * @param passportNumber - ����� �������� ���������
    * @param[out] manager - ���������, �� �������� ����� ������� ���������� ��������, ���� ����� ������ ( ����� �������� NULL)
    * @return ������� �� ����� ��������� � ����� ���
    */
    bool findByPassport( const QString& passportSerial, const QString passportNumber, Manager* manager) override;

private:
    QSqlDatabase* db;       /**< ��������� �� � ������� ����� ����������� ������� */
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

