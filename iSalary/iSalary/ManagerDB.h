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
    QLinkedList<Manager> findByINN( const QString& INN) override;

    /**
    * ����� ��������� �� ���
    * @param passportSerial - ����� �������� ���������
    * @param passportNumber - ����� �������� ���������
    * @param[out] manager - ���������, �� �������� ����� ������� ���������� ��������, ���� ����� ������ ( ����� �������� NULL)
    * @return ������� �� ����� ��������� � ����� ���
    */
    QLinkedList<Manager> findByPassport( const QString& passportSerial, const QString passportNumber) override;

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
    QString passportSourceField;
    QString addressField;
    QString INNField;
    QString emailField;
    QString mobileNumberField;
    QString dateOfEmploymentField;
    QString dateOfBitrthField;

    void init();

    Manager readOneRecord( const QSqlQuery& query);
};

