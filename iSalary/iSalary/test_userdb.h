#ifndef TEST_USERDB_H
#define TEST_USERDB_H

#include <QObject>
#include <qtest.h>
#include <QSqlDatabase>
#include "UserDB.h"
class Test_UserDB : public QObject
{
	Q_OBJECT

public:
	Test_UserDB(QSqlDatabase * sql);
	~Test_UserDB();

private:
	QSqlDatabase * sql;
	UserDB *userDB;

private slots:
	void test_getByIds();
};

#endif // TEST_USERDB_H
