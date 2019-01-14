#ifndef TEST_MANAGER_DB_H
#define TEST_MANAGER_DB_H

#include <QObject>
#include <qtest.h>
#include <QSqlDatabase>
#include "UserDB.h"
#include "ManagerDB.h"
#include "QTextCodec"

class Test_Manager_DB : public QObject
{
	Q_OBJECT

public:
	Test_Manager_DB( QSqlDatabase *sql );
	~Test_Manager_DB();

private:
	QSqlDatabase *sql;
	UserDB * user_DB;
	ManagerDB * manager_DB;
	QTextCodec * c;
	
	void removeManager( int id );
	void compareManagers( Manager first_manager, Manager second_manager );
	void compareManagers( QList<Manager> first_managers, QList<Manager> second_managers);

private slots:
	void update();
	void getAll();
	void findByINN();
	void findByPassport();
	void getAllIdAndName();
	void cleanup();
};

#endif // TEST_MANAGER_DB_H
