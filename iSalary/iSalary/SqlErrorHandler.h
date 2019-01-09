#pragma once

#include <qstring.h>

#include <qsqlerror.h>

#include <qmessagebox.h>

class SqlErrorHandler {
  public:
    void handleSqlError( QSqlError *error ) { QMessageBox::critical( 0, QString::fromWCharArray( L"������ ��� ���������� ������� � ��" ), error->text() ); }
};
