#ifndef TEST_USER_DB_H
#define TEST_USER_DB_H

#include <QObject>
#include <qtest.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "UserDB.h"
#include "QTextCodec"
class Test_User_DB : public QObject
{
	Q_OBJECT

public:
	Test_User_DB( QSqlDatabase * sql );
	~Test_User_DB();

private:
	QSqlDatabase * sql;
	UserDB *user_DB;
	QTextCodec * c;

	void compareUsers(UserInfo res_user, UserInfo exp_user);
	void removeUser( int id );

private slots:
	void insert();
	//void update();
	void getById();
	void getByIds();
	void findByLogin();
	//void findByLogin_NotFound();
	void findByLoginPassword();
	//void findByLoginPassword_NotFound();
};

#endif // TEST_USER_DB_H
