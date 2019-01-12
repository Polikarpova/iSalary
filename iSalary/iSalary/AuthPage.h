#pragma once

#include <qlabel.h>
#include <qlineedit.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qstackedwidget.h>

#include "AuthorizationFacade.h"
#include "Codec.h"
#include "SignResultDTO.h"
#include "test_auth_gui.h"

class AuthPage : public QObject {
    Q_OBJECT
    friend class Test_Auth_GUI;

  public:
    AuthPage( AuthorizationFacade *authFacade );
    void setUI( QLineEdit *loginInput, QLineEdit *passwordInput, QPushButton *signInBtn, QLabel *errorOutput, QStackedWidget *auth_program_stackedWidget,
                QStackedWidget *boss_manager_stackedWidget );
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
    QStackedWidget *auth_program_stackedWidget;
    QStackedWidget *boss_manager_stackedWidget;

    SignInResultDTO currentUser;

    void showLogInError( const QString &error );
};
