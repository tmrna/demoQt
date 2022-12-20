#include <cassert>
#include "../../../lib/sqlConnections/adminConnection.hpp"
int main(){
    try {
        adminConnection test;
    } catch (sqlException e) {
        qWarning() << e.getMsg();
        return 1;
    }
    return 0;
}
