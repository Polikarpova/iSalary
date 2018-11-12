#pragma once

#include "qwidget.h"
#include "qmessagebox.h"

class ErrorMessageHandler {
public:
    ErrorMessageHandler( QWidget* blockWidget);
    ~ErrorMessageHandler(void);

    void handleError(QString* error);

private:
    QWidget* blockWidget;
};
