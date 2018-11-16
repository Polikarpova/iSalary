#pragma once

#include "Manager.h"

/**
* ��������� ������, ��������������� ������ � ���������� �� ��� � ������ ��������
* ����� ��� �������� �� ������� ������������ ����� ��� ������
* @author ��������
*/
class IManagerRepository
{
public:
    
    /**
    * ����� ��������� �� ���
    * @param INN - ��� ���������
    * @param[out] manager - ���������, �� �������� ����� ������� ���������� ��������, ���� ����� ������ ( ����� �������� NULL)
    * @return ������� �� ����� ��������� � ����� ���
    */
    virtual QLinkedList<Manager> findByINN( const QString& INN) = 0;

    /**
    * ����� ��������� �� ���
    * @param passportSerial - ����� �������� ���������
    * @param passportNumber - ����� �������� ���������
    * @param[out] manager - ���������, �� �������� ����� ������� ���������� ��������, ���� ����� ������ ( ����� �������� NULL)
    * @return ������� �� ����� ��������� � ����� ���
    */
    virtual QLinkedList<Manager> findByPassport( const QString& passportSerial, const QString passportNumber) = 0;
    
    /**
    * �������� ������ � ��������� � ��, ���������� ������� ���� �� ������������ � ����� �� id 
    * @param manager - ����������� ��������
    */
    virtual void update( const Manager& manager) = 0;

};

