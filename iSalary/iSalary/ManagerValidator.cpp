#include "ManagerValidator.h"

ManagerValidator::ManagerValidator( IUserRepository *userRep, IManagerRepository *managerRep ) : UserValidator( userRep ) {
    this->managerRepository = managerRep;
}

bool ManagerValidator::isManagerValid( const Manager &manager, QString *errorOutput, bool checkPassword ) {
    QString error;
    bool isValid = this->isUserValid( manager, &error, checkPassword );

    QLinkedList<Manager> sameINNMangers = this->managerRepository->findByINN( manager.getINN() );
    if ( sameINNMangers.size() > 1 ) {
        error += QString::fromWCharArray( L"� ������� ��� ����������������� ��������� ������������ � �������� ���\n" );
        isValid = false;
    } else if ( sameINNMangers.size() == 1 && sameINNMangers.first().getId() != manager.getId() ) {
        error += QString::fromWCharArray( L"� ������� ��� ��������������� ������ ������������ � �������� ���" );
        isValid = false;
    }

    QLinkedList<Manager> samePassportManagers = this->managerRepository->findByPassport( manager.getPassportSerial(), manager.getPassportNumber() );
    if ( samePassportManagers.size() > 1 ) {
        error += QString::fromWCharArray( L"� ������� ��� ����������������� ��������� ������������ � �������� ������-������� ��������\n" );
        isValid = false;
    } else if ( samePassportManagers.size() == 1 && samePassportManagers.first().getId() != manager.getId() ) {
        error += QString::fromWCharArray( L"� ������� ��� ��������������� ������ ������������ � �������� ������-������� ��������" );
        isValid = false;
    }

    QRegExp anyLangChar( QString::fromWCharArray( L"[a-zA-Z�-��-�]" ) );

    if ( anyLangChar.indexIn( manager.getFirstName() ) < 0 ) {
        error += QString::fromWCharArray( L"��� ������ � �������� ���� �� ���� �����\n" );
        isValid = false;
    }

    if ( anyLangChar.indexIn( manager.getSecondName() ) < 0 ) {
        error += QString::fromWCharArray( L"������� ������ ��������� ���� �� ���� �����\n" );
        isValid = false;
    }

    if ( manager.getDateOfBirth() > QDate::currentDate().addYears( -13 ) ) {
        error += QString::fromWCharArray( L"���������� ������ ���� ���� �� 14 ��� \n" );
        isValid = false;
    }

    if ( manager.getDateOfBirth().addYears( 14 ) > manager.getPassportDateIssue() ) {
        error += QString::fromWCharArray( L"��������� ������ ��� �������� ������� ������ ����� ���������� 14 ���\n" );
        isValid = false;
    }

    if ( manager.getPassportDateIssue() > QDate::currentDate() ) {
        error += QString::fromWCharArray( L"���� ������ �������� �� ����� ���� ������ �������\n" );
        isValid = false;
    }

    bool isNumber = false;
    manager.getPassportSerial().toInt( &isNumber );
    if ( manager.getPassportSerial().size() != 4 || !isNumber ) {
        error += QString::fromWCharArray( L"����� �������� ������ �������� �� 4 ����\n" );
        isValid = false;
    }

    manager.getPassportNumber().toInt( &isNumber );
    if ( manager.getPassportNumber().size() != 6 || !isNumber ) {
        error += QString::fromWCharArray( L"����� �������� ������ �������� �� 6 ����\n" );
        isValid = false;
    }

    if ( manager.getPassportDateIssue() > QDate::currentDate() ) {
        error += QString::fromWCharArray( L"���� ������ �������� �� ����� ���� ������ �������\n" );
        isValid = false;
    }

    if ( manager.getPassportSerial().size() == 0 ) {
        error += QString::fromWCharArray( L"�� ��������� ����������, ������� ������ �������\n" );
        isValid = false;
    }

    manager.getINN().toULongLong( &isNumber );
    if ( manager.getINN().size() != 12 || !isNumber ) {
        error += QString::fromWCharArray( L"��� ������ �������� �� 12 ����\n" );
        isValid = false;
    }

    QRegExp ruLatDots( QString::fromWCharArray( L"[a-zA-Z�-��-�\,\.\- 0-9]*" ) );

    if ( anyLangChar.indexIn( manager.getAddress() ) < 0 ) {
        error += QString::fromWCharArray( L"����� ������ ��������� ���� �� ���� �����\n" );
        isValid = false;
    }

    ruLatDots.indexIn( manager.getAddress() );
    if ( ruLatDots.matchedLength() != manager.getAddress().size() ) {
        error += QString::fromWCharArray( L"����� ������ �������� ������ �� ����, ����, �����, ������� � ����\n" );
        isValid = false;
    }

    auto passportSource = manager.getPassportSource();
    if ( anyLangChar.indexIn( passportSource ) < 0 ) {
        error += QString::fromWCharArray( L" ���� \"������� �����\" ������ ��������� ���� �� ���� �����\n" );
        isValid = false;
    }

    ruLatDots.indexIn( passportSource );
    if ( ruLatDots.matchedLength() != passportSource.size() ) {
        error += QString::fromWCharArray( L"���� \"������� �����\" ������� �������� ������ �� ����, ����, �����, ������� � ����\n" );
        isValid = false;
    }

    *errorOutput = error;
    return isValid;
}

bool ManagerValidator::isLoginExist( const QString &login ) { return UserValidator::isLoginExist( login ); }

ManagerValidator::~ManagerValidator( void ) {}
