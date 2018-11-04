#include "ErrorMessageHandler.h"


ErrorMessageHandler::ErrorMessageHandler( QWidget* blockWidget) {
    this->blockWidget = blockWidget;
}

void ErrorMessageHandler::handleError(QString* error) {
    QMessageBox::warning( blockWidget, "Ошибка", *error);
}

ErrorMessageHandler::~ErrorMessageHandler(void) {
}
