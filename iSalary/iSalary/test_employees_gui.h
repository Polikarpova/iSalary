#ifndef TEST_EMPLOYEES_GUI_H
#define TEST_EMPLOYEES_GUI_H

#include <QObject>
#include <qtest.h>
#include "QTextCodec"
#include "EmployeesPage.h"
#include <QSqlDatabase>

class Test_Employees_GUI : public QObject
{
	Q_OBJECT
	friend class EmployeesPage;
public:
	Test_Employees_GUI( QSqlDatabase *sql, EmployeesPage *employeesPage );
	~Test_Employees_GUI();

private:
	EmployeesPage *employeesPage;
	UserDB *user_DB;
	ManagerDB *manager_DB;
	QSqlDatabase *sql;
	QTextCodec * c;

	QString findElemInTable( int row, int col );
	void directAddEmployee();
	void directUpdateEmployee();
	void addOneEmployee( Manager manager );
	void removeEmployee( int id );

private slots:
	void addEmployee();
	void cancelAddEmployee();
	void showEmployee();
	void updateEmployee();
	void cancelUpdateEmployee();
};

#endif // TEST_EMPLOYEES_GUI_H
