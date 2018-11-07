#include "test_userdb.h"

Test_UserDB::Test_UserDB(QSqlDatabase * _sql)
{
	sql = _sql;
	userDB = new UserDB( _sql );

}

Test_UserDB::~Test_UserDB()
{

}

void Test_UserDB::test_getByIds() {
	
	QString str = "a";
	QList<int> l;
	QVector<int> exp_ids, new_ids;

	for ( int i = 1; i <= 5; i++ ) {
		User user;
		user.setLogin( str );
		user.setPassword( str );
		UserType type;
		i % 2 ? type = BOSS : type = MANAGER;
		User newUser = userDB->insert( user, type );
		//new_ids.append( newUser.getId() );
		if ( i % 2 ) {
			l.append( newUser.getId() );
			exp_ids.append( newUser.getId() );
		}
		str += 'a' + i;
	}

	QList<UserInfo> result = userDB->getByIds( l );
	QVector<int>ids;
	for ( auto it = result.begin(); it != result.end(); it++ ) {
		ids.append( ( *it ).user.getId() );
	}
	QCOMPARE( ids.size(), exp_ids.size() );
	for ( int i = 0; i < ids.size(); i++ ) {
		QCOMPARE( ids[i], exp_ids[i] );
	}

}
