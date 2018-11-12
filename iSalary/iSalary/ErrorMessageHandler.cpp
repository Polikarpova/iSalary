#include "ErrorMessageHandler.h"
#include "Codec.h"

ErrorMessageHandler::ErrorMessageHandler( QWidget* blockWidget) {
    this->blockWidget = blockWidget;
}

void ErrorMessageHandler::handleError(QString* error) {
	QMessageBox::warning( blockWidget, QString::fromWCharArray( L"Îøèáêà"), toUnicode( error->toStdString().c_str()));
}

ErrorMessageHandler::~ErrorMessageHandler(void) {
}
