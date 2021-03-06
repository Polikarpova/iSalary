#include "AccoutingPeriod.h"
#include "ActiveSale.h"
#include "CloseAccoutingPeriod.h"
#include <qlist.h>

class OpenAccoutingPeriod : public AccoutingPeriod {

  public:
    OpenAccoutingPeriod( void );

    void addSale( ActiveSale &sale );

    QList<ActiveSale> getSales();

    CloseAccoutingPeriod close();
};