#include "ErrorMessageHandler.h"
#include "Codec.h"

ErrorMessageHandler::ErrorMessageHandler( QWidget* blockWidget) {
    this->blockWidget = blockWidget;
}

void ErrorMessageHandler::handleError(QString* error) {
    QMessageBox::warning( blockWidget, "������", toUni( *error));
}

ErrorMessageHandler::~ErrorMessageHandler(void) {
}
