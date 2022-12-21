#include <cassert>
#include "../../../lib/sqlConnections/crmConnection.hpp"
int main(){
    try {
        crmConnection test;
    } catch (sqlException e) {
        qWarning() << e.getMsg();
        return 1;
    }
    return 0;
}
