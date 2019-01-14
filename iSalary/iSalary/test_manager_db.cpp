#include "test_manager_db.h"

Test_Manager_DB::Test_Manager_DB( QSqlDatabase *sql ) {

	this->sql = sql;
	this->user_DB = new UserDB( sql );
    this->manager_DB = new ManagerDB( sql, user_DB );
}

Test_Manager_DB::~Test_Manager_DB() {

}

void Test_Manager_DB::removeManager( int id ) {
    
	QSqlQuery query( "DELETE FROM users WHERE id = " + QString::number( id ), *sql );
    bool isOk = query.exec();
}

void Test_Manager_DB::compareManagers( QList<Manager> first_managers, QList<Manager> second_managers) {
	
	QCOMPARE( first_managers.size(), second_managers.size() );
	for ( int i = 0 ; i < first_managers.size(); i++ ) {
		compareManagers( first_managers[i], second_managers[i] );
	}
}

void Test_Manager_DB::compareManagers( Manager first_manager, Manager second_manager ) {
	
	QCOMPARE( first_manager.getId(), second_manager.getId() );
	QCOMPARE( first_manager.getFirstName(), second_manager.getFirstName() );
	QCOMPARE( first_manager.getSecondName(), second_manager.getSecondName() );
	QCOMPARE( first_manager.getThirdName(), second_manager.getThirdName() );
	QCOMPARE( first_manager.getSex(), second_manager.getSex() );
	QCOMPARE( first_manager.getDateOfBirth(), second_manager.getDateOfBirth() );
	QCOMPARE( first_manager.getPassportSerial(), second_manager.getPassportSerial() );
	QCOMPARE( first_manager.getPassportNumber(), second_manager.getPassportNumber() );
	QCOMPARE( first_manager.getPassportSource(), second_manager.getPassportSource() );
	QCOMPARE( first_manager.getPassportDateIssue(), second_manager.getPassportDateIssue() );
	QCOMPARE( first_manager.getAddress(), second_manager.getAddress() );
	QCOMPARE( first_manager.getINN(), second_manager.getINN() );
}

void Test_Manager_DB::update() {
	
	User user;
    user = user_DB->insert( user, UserType::MANAGER );
    int manager_id = user.getId();

    QString firstName = "Ivan";
    QString secondName = "Ivanov";
    QString thirdName = "Ivanovich";

    Manager manager;
    manager.setId( manager_id );
    manager.setFirstName( firstName );
    manager.setSecondName( secondName );
    manager.setThirdName( thirdName );
    manager.setSex( Sex::MALE );
    manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
    manager.setPassportSerial( "1000" );
    manager.setPassportNumber( "100000" );
    manager.setPassportSource( "ABC" );
    manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
    manager.setAddress( "ABC" );
    manager.setINN( "012345678901" );

    manager_DB->update( manager );

	Manager res_manager = manager_DB->getById( manager_id );

	compareManagers( manager, res_manager );
}

void Test_Manager_DB::getAll() {
	
	User first_user;
    first_user = user_DB->insert( first_user, UserType::MANAGER );
    int first_manager_id = first_user.getId();

    QString firstName = "Ivan";
    QString secondName = "Ivanov";
    QString thirdName = "Ivanovich";

	QList<Manager>exp_managers;
    Manager manager;
    manager.setId( first_manager_id );
    manager.setFirstName( firstName );
    manager.setSecondName( secondName );
    manager.setThirdName( thirdName );
    manager.setSex( Sex::MALE );
    manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
    manager.setPassportSerial( "1000" );
    manager.setPassportNumber( "100000" );
    manager.setPassportSource( "ABC" );
    manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
    manager.setAddress( "ABC" );
    manager.setINN( "012345678901" );

    manager_DB->update( manager );
	exp_managers.append( manager );

	User second_user;
    second_user = user_DB->insert( second_user, UserType::MANAGER );
    int second_manager_id = second_user.getId();

	manager.setId( second_manager_id );
	manager.setFirstName( "Dima" );
    manager.setSecondName( "Sokolov" );
    manager.setThirdName( "Ivanovich" );
	manager.setPassportSerial( "1001" );
    manager.setPassportNumber( "100001" );
	manager.setINN( "123456789001" );

	manager_DB->update( manager );

	exp_managers.append( manager );

	QList<Manager> managers = manager_DB->getAll();

	compareManagers( exp_managers, managers );
}

void Test_Manager_DB::findByINN() {

	User user;
    user = user_DB->insert( user, UserType::MANAGER );
    int manager_id = user.getId();

    QString firstName = "Ivan";
    QString secondName = "Ivanov";
    QString thirdName = "Ivanovich";

    Manager manager;
    manager.setId( manager_id );
    manager.setFirstName( firstName );
    manager.setSecondName( secondName );
    manager.setThirdName( thirdName );
    manager.setSex( Sex::MALE );
    manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
    manager.setPassportSerial( "1000" );
    manager.setPassportNumber( "100000" );
    manager.setPassportSource( "ABC" );
    manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
    manager.setAddress( "ABC" );
    manager.setINN( "012345678901" );

    manager_DB->update( manager );

	Manager res_manager = manager_DB->findByINN( manager.getINN() ).last();

	compareManagers( manager, res_manager );
}

void Test_Manager_DB::findByPassport() {

	User user;
    user = user_DB->insert( user, UserType::MANAGER );
    int manager_id = user.getId();

    QString firstName = "Ivan";
    QString secondName = "Ivanov";
    QString thirdName = "Ivanovich";

    Manager manager;
    manager.setId( manager_id );
    manager.setFirstName( firstName );
    manager.setSecondName( secondName );
    manager.setThirdName( thirdName );
    manager.setSex( Sex::MALE );
    manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
    manager.setPassportSerial( "1000" );
    manager.setPassportNumber( "100000" );
    manager.setPassportSource( "ABC" );
    manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
    manager.setAddress( "ABC" );
    manager.setINN( "012345678901" );

    manager_DB->update( manager );

	Manager res_manager = manager_DB->findByPassport( manager.getPassportSerial(), manager.getPassportNumber() ).last();

	compareManagers( manager, res_manager );
}

void Test_Manager_DB::getAllIdAndName() {
	
	User first_user;
    first_user = user_DB->insert( first_user, UserType::MANAGER );
    int first_manager_id = first_user.getId();

    QString firstName = "Ivan";
    QString secondName = "Ivanov";
    QString thirdName = "Ivanovich";

	QList<Manager>exp_managers;
    Manager manager;
    manager.setId( first_manager_id );
    manager.setFirstName( firstName );
    manager.setSecondName( secondName );
    manager.setThirdName( thirdName );
    manager.setSex( Sex::MALE );
    manager.setDateOfBirth( QDate( 2000, 01, 01 ) );
    manager.setPassportSerial( "1000" );
    manager.setPassportNumber( "100000" );
    manager.setPassportSource( "ABC" );
    manager.setPassportDateIssue( QDate( 2014, 01, 20 ) );
    manager.setAddress( "ABC" );
    manager.setINN( "012345678901" );

    manager_DB->update( manager );
	exp_managers.append( manager );

	User second_user;
    second_user = user_DB->insert( second_user, UserType::MANAGER );
    int second_manager_id = second_user.getId();

	manager.setId( second_manager_id );
	manager.setFirstName( "Dima" );
    manager.setSecondName( "Sokolov" );
    manager.setThirdName( "Ivanovich" );
	manager.setPassportSerial( "1001" );
    manager.setPassportNumber( "100001" );
	manager.setINN( "123456789001" );

	manager_DB->update( manager );

	exp_managers.append( manager );

	QList<QPair<int, QString>> idAndNameManagers = manager_DB->getAllIdAndName();

	QCOMPARE( exp_managers[0].getId(), idAndNameManagers[0].first );
	QString first_FIO = exp_managers[0].getSecondName() + " " +  exp_managers[0].getFirstName() + " " +  exp_managers[0].getThirdName();
	QCOMPARE( first_FIO, idAndNameManagers[0].second );
	QCOMPARE( exp_managers[1].getId(), idAndNameManagers[1].first );
	QString second_FIO = exp_managers[1].getSecondName() + " " +  exp_managers[1].getFirstName() + " " +  exp_managers[1].getThirdName();
	QCOMPARE(second_FIO, idAndNameManagers[1].second );
}

void Test_Manager_DB::cleanup() {

    QList<Manager> managers = manager_DB->getAll();
    for ( int manager_num = 0; manager_num < managers.size(); manager_num++ ) {
        
		int manager_id = managers[manager_num].getId();
		removeManager( manager_id );
    }
}