#include "test_product_db.h"
#include "test_user_db.h"
class Test
{
public:
	Test( QSqlDatabase sql );
	~Test(void);
	void startTesting();

private:
	QSqlDatabase  db;
	void test_DB();
	void test_GUI();
};

