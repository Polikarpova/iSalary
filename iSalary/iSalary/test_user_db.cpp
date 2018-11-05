#include "test_user_db.h"

Test_User_DB::Test_User_DB( QSqlDatabase * _sql ) {
	sql = _sql;
	user_DB = new UserDB( _sql );
	c = QTextCodec::codecForName("CP1251");
}

Test_User_DB::~Test_User_DB()
{

}

void Test_User_DB::removeUser( int id ) {
	QSqlQuery query("DELETE FROM users WHERE id = " + QString::number( id ), *sql);
	bool isOk = query.exec();
}

void Test_User_DB::compareUsers( UserInfo res_user, UserInfo exp_user) {
	QCOMPARE( res_user.user.getId(), exp_user.user.getId() );
	QCOMPARE( res_user.user.getLogin(), exp_user.user.getLogin() );
	QCOMPARE( res_user.user.getPassword(), exp_user.user.getPassword() );
	QCOMPARE( res_user.type, exp_user.type );
}

void Test_User_DB::insert() {
	QString str = "a";
	UserType type = BOSS;
	UserInfo exp_user;
	exp_user.user.setLogin( str );
	exp_user.user.setPassword( str );
	exp_user.type = type;
	exp_user.user = user_DB->insert( exp_user.user, exp_user.type);
	UserInfo res_user = user_DB->findByLogin( exp_user.user.getLogin() );
	compareUsers( res_user, exp_user );
	removeUser( exp_user.user.getId() );
}

//void Test_User_DB::update() {
//	QString str = "a";
//	UserType type = BOSS;
//	UserInfo exp_user;
//	exp_user.user.setLogin( str );
//	exp_user.user.setPassword( str );
//	exp_user.type = type;
//	exp_user.user = user_DB->insert( exp_user.user, exp_user.type);
//	QString new_login = "abc";
//	exp_user.user.setLogin( new_login );
//	user_DB->update( exp_user.user );
//	UserInfo res_user = user_DB->findByLogin( new_login );
//	compareUsers( res_user, exp_user );
//	removeUser( exp_user.user.getId() );
//}

void Test_User_DB::getById() {
	QString str = "a";
	UserType type = BOSS;
	UserInfo exp_user;
	exp_user.user.setLogin( str );
	exp_user.user.setPassword( str );
	exp_user.type = type;
	exp_user.user = user_DB->insert( exp_user.user, exp_user.type);
	UserInfo res_user = user_DB->getById( exp_user.user.getId() );
	compareUsers( res_user, exp_user );
	removeUser( exp_user.user.getId() );
}

void Test_User_DB::getByIds() {
	
	QString str = "a";
	QList<int> l;
	QVector<int> exp_ids, new_ids;

	for ( int i = 1; i <= 5; i++ ) {
		User user;
		user.setLogin( str );
		user.setPassword( str );
		UserType type;
		i % 2 ? type = BOSS : type = MANAGER;
		User newUser = user_DB->insert( user, type );
		new_ids.append( newUser.getId() );
		if ( i % 2 ) {
			l.append( newUser.getId() );
			exp_ids.append( newUser.getId() );
		}
		str += 'a' + i;
	}

	QList<UserInfo> result = user_DB->getByIds( l );
	QVector<int>ids;
	for ( auto it = result.begin(); it != result.end(); it++ ) {
		ids.append( ( *it ).user.getId() );
	}
	QCOMPARE( ids.size(), exp_ids.size() );
	for ( int i = 0; i < ids.size(); i++ ) {
		QCOMPARE( ids[i], exp_ids[i] );
	}
	for ( int i = 0; i < new_ids.size(); i++ ) {
		removeUser( new_ids[i] );
	}
}

void Test_User_DB::findByLogin() {
	QString str = "a";
	UserType type = BOSS;
	UserInfo exp_user;
	exp_user.user.setLogin( str );
	exp_user.user.setPassword( str );
	exp_user.type = type;
	exp_user.user = user_DB->insert( exp_user.user, exp_user.type);
	UserInfo res_user = user_DB->findByLogin( exp_user.user.getLogin() );
	compareUsers( res_user, exp_user );
	removeUser( exp_user.user.getId() );
}

//void Test_User_DB::findByLogin_NotFound() {
//	QString str = "a";
//	UserType type = BOSS;
//	UserInfo exp_user;
//	exp_user.user.setLogin( str );
//	exp_user.user.setPassword( str );
//	exp_user.type = type;
//	exp_user.user = user_DB->insert( exp_user.user, exp_user.type);
//	str += "b";
//	UserInfo res_user = user_DB->findByLogin( str );
//	compareUsers( res_user, exp_user );
//	removeUser( exp_user.user.getId() );
//}

void Test_User_DB::findByLoginPassword() {
	QString str = "a";
	UserType type = BOSS;
	UserInfo exp_user;
	exp_user.user.setLogin( str );
	exp_user.user.setPassword( str );
	exp_user.type = type;
	exp_user.user = user_DB->insert( exp_user.user, exp_user.type);
	UserInfo res_user = user_DB->findByLoginPassword( exp_user.user.getLogin(), exp_user.user.getPassword() );
	compareUsers( res_user, exp_user );
	removeUser( exp_user.user.getId() );
}

//void Test_User_DB::findByLoginPassword_NotFound() {
//	QString str = "a";
//	UserType type = BOSS;
//	UserInfo exp_user;
//	exp_user.user.setLogin( str );
//	exp_user.user.setPassword( str );
//	exp_user.type = type;
//	exp_user.user = user_DB->insert( exp_user.user, exp_user.type);
//	str += "b";
//	UserInfo res_user = user_DB->findByLoginPassword( str, str );
//	compareUsers( res_user, exp_user );
//	removeUser( exp_user.user.getId() );
//}