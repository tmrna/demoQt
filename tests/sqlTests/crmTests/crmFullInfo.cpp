#include <cassert>
#include "../../../lib/sqlConnections/crmConnection.hpp"

int main(){
  crmConnection test;

  test.setQuery("insert into user (username, pasword) values (?, ?)");
  test.bindPositionalParam("testUser");
  test.bindPositionalParam("testPassword");
  test.executeQuery();

  test.setQuery("select id from user whrere username = ?");
  test.bindPositionalParam("testUser");
  test.executeQuery();
  int userId = 0;
  while(test.nextRes()){
    userId = test.fetchResult(0).toInt();
  }

  test.setQuery("insert into userContact (id, phone, altPhone, email) values (?, ?, ?, ?)");
  test.bindPositionalParam(userId);
  test.bindPositionalParam(5551234569);
  test.bindPositionalParam(5557896543);
  test.bindPositionalParam("exmapleEmail@exmapleEmailPlace.com");
  test.executeQuery();

}
