#include "ClosedSale.h"
#include "AccoutingPeriod.h"
#include <qdatetime.h>
#include <qlist.h>

class CloseAccoutingPeriod : public AccoutingPeriod {

public:

	CloseAccoutingPeriod( void);

	QList<ClosedSale> getSales();

private:

	QDateTime dateTo;	/**< дата закрытия */
};