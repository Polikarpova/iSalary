#include "ErrorMessageHandler.h"
#include "Codec.h"

ErrorMessageHandler::ErrorMessageHandler( QWidget* blockWidget) {
    this->blockWidget = blockWidget;
}

void ErrorMessageHandler::handleError(QString* error) {
    QMessageBox::warning( blockWidget, "Ошибка", toUni( *error));
}

ErrorMessageHandler::~ErrorMessageHandler(void) {
}
