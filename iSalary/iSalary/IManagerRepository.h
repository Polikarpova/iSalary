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
    virtual bool findByINN( const QString& INN, Manager* manager) = 0;

    /**
    * ����� ��������� �� ���
    * @param passportSerial - ����� �������� ���������
    * @param passportNumber - ����� �������� ���������
    * @param[out] manager - ���������, �� �������� ����� ������� ���������� ��������, ���� ����� ������ ( ����� �������� NULL)
    * @return ������� �� ����� ��������� � ����� ���
    */
    virtual bool findByPassport( const QString& passportSerial, const QString passportNumber, Manager* manager) = 0;

    virtual ~IManagerRepository(void);
};

