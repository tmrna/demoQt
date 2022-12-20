#include <cassert>
#include <iostream>

#include "../../../lib/sqlConnections/erpConnection.hpp"
int main(){
    try {
        erpConnection testConn;
    } catch (sqlException e) {
        qWarning() << e.getMsg();
        return 1;
    }
    return 0;
}
