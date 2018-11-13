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
}

void AuthPage::userTryLogIn(){
    QString login = this->loginInput->text();
    QString password = this->passwordInput->text();

    if( login.isEmpty()) {
		this->showLogInError( QString::fromWCharArray( L"������� �����"));
    } else if ( password.isEmpty()) {
        this->showLogInError( QString::fromWCharArray( L"������� ������"));
    } else {
        SignInResultDTO signInRes = this->authFacade->signIn(login, password);
        if( signInRes.success) {
			this->currentUser = signInRes;
            emit this->userLoggedIn( signInRes.user, signInRes.userType);
        } else {
            this->showLogInError( QString::fromWCharArray( L"����� ��� ������ �������"));
        }
    }
    
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
