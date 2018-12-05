#include "AuthPage.h"


AuthPage::AuthPage( AuthorizationFacade * authFacade){
    this->authFacade = authFacade;
	this->currentUser.success = false;
}

void AuthPage::setUI( QLineEdit* loginInput, QLineEdit* passwordInput, QPushButton* signInBtn, QLabel* errorOutput){
    this->loginInput = loginInput;
    this->passwordInput = passwordInput;
    this->signInBtn = signInBtn;
    this->errorOutput = errorOutput;
    this->errorOutput->setText("");

    connect( this->signInBtn, &QPushButton::clicked, this, &AuthPage::userTryLogIn);
    connect( this->passwordInput, &QLineEdit::returnPressed, this, &AuthPage::userTryLogIn);
}

void AuthPage::userTryLogIn(){
    QString login = this->loginInput->text();
    QString password = this->passwordInput->text();

    this->loginInput->setEnabled( false);
    this->passwordInput->setEnabled( false);
    this->signInBtn->setEnabled( false);

    if( login.isEmpty()) {
		this->showLogInError( QString::fromWCharArray( L"¬ведите логин"));
    } else if ( password.isEmpty()) {
        this->showLogInError( QString::fromWCharArray( L"¬ведите пароль"));
    } else {
        SignInResultDTO signInRes = this->authFacade->signIn(login, password);
        if( signInRes.success) {
			this->currentUser = signInRes;

            this->loginInput->setText("");
            this->passwordInput->setText("");

            emit this->userLoggedIn( signInRes.user, signInRes.userType);
        } else {
            this->showLogInError( QString::fromWCharArray( L"Ћогин или пароль неверны"));
        }
    }
    
    this->loginInput->setEnabled( true);
    this->passwordInput->setEnabled( true);
    this->signInBtn->setEnabled( true);
}
    
void AuthPage::showLogInError( const QString& error){
    errorOutput->setText( toUnicode(error));
}


AuthPage::~AuthPage(void)
{
}

int AuthPage::currentUserId() {

	if( this->currentUser.success) {
	
		return this->currentUser.user.id;
	}

	return -1;
}
