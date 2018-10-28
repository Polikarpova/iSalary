#include "AuthPage.h"


AuthPage::AuthPage( AuthorizationFacade * authFacade){
    this->authFacade = authFacade;
}

void AuthPage::setUI( QLineEdit* loginInput, QLineEdit* passwordInput, QPushButton* signInBtn, QLabel* errorOutput){
    this->loginInput = loginInput;
    this->passwordInput = passwordInput;
    this->signInBtn = signInBtn;
    this->errorOutput = errorOutput;
    this->errorOutput->setText("");

    connect( this->signInBtn, &QPushButton::clicked, this, &AuthPage::userTryLogIn);
}

void AuthPage::userTryLogIn(){
    QString login = this->loginInput->text();
    QString password = this->passwordInput->text();

    if( login.isEmpty()) {
        this->showLogInError( "¬ведите логин");
    } else if ( password.isEmpty()) {
        this->showLogInError( "¬ведите пароль");
    } else {
        SignInResultDTO signInRes = this->authFacade->signIn(login, password);
        if( signInRes.success) {
            emit this->userLoggedIn( signInRes.user, signInRes.userType);
        } else {
            this->showLogInError( "Ћогин или пароль неверны");
        }
    }
    
}
    
void AuthPage::showLogInError( const QString& error){
    errorOutput->setText( error);
}

AuthPage::~AuthPage(void)
{
}
