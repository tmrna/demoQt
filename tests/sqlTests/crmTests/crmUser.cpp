#include <cassert>
#include "../../../lib/sqlConnections/crmConnection.hpp"

int main(){

  crmConnection test;
  test.init();
  test.setQuery("insert into user (username, password) values (?, ?)");
  test.bindPositionalParam("testUser");
  test.bindPositionalParam("testPassword");
  if(!test.executeQuery()) return 1;
  test.commit();

  test.init();
  test.setQuery("delete from user where username = ?");
  test.bindPositionalParam("testUser");
  if(!test.executeQuery()) return 1;
  test.commit();

}
