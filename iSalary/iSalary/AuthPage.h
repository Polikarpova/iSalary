#pragma once

#include <qlabel.h>
#include <qlineedit.h>
#include <qobject.h>
#include <qpushbutton.h>

#include "AuthorizationFacade.h"
#include "Codec.h"
#include "SignResultDTO.h"

class AuthPage : public QObject {
    Q_OBJECT
  public:
    AuthPage( AuthorizationFacade *authFacade );
    void setUI( QLineEdit *loginInput, QLineEdit *passwordInput, QPushButton *signInBtn, QLabel *errorOutput );
    ~AuthPage( void );

    int currentUserId();
  signals:
    void userLoggedIn( const UserDTO &user, UserType userType );

  private slots:
    void userTryLogIn();

  private:
    AuthorizationFacade *authFacade;

    QLineEdit *loginInput;
    QLineEdit *passwordInput;
    QPushButton *signInBtn;
    QLabel *errorOutput;

    SignInResultDTO currentUser;

    void showLogInError( const QString &error );
};
