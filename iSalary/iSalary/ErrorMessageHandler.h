#pragma once

#include "qmessagebox.h"
#include "qwidget.h"

class ErrorMessageHandler {
  public:
    ErrorMessageHandler( QWidget *blockWidget );
    ~ErrorMessageHandler( void );

    void handleError( QString *error );

  private:
    QWidget *blockWidget;
};
