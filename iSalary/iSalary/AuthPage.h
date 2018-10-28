#pragma once

#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qobject.h>

#include "AuthorizationFacade.h"
#include "SignResultDTO.h"

class AuthPage : public QObject{
    Q_OBJECT
public:
    AuthPage( AuthorizationFacade * authFacade);
    void setUI( QLineEdit* loginInput, QLineEdit* passwordInput, QPushButton* signInBtn, QLabel* errorOutput);
    ~AuthPage( void);

signals:
    void userLoggedIn( const UserDTO& user, UserType userType);

private slots:
    void userTryLogIn();

private:
    AuthorizationFacade * authFacade;
    
    QLineEdit* loginInput;
    QLineEdit* passwordInput; 
    QPushButton* signInBtn;
    QLabel* errorOutput;

    void showLogInError( const QString& error);
};

