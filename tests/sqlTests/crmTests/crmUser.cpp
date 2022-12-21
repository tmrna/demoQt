#include <cassert>
#include "../../../lib/sqlConnections/crmConnection.hpp"

int main(){

  crmConnection test;
  // begin transaction
  test.init();
  // add user
  test.setQuery("insert into user (username, password) values (?, ?)");
  test.bindPositionalParam("testUser");
  test.bindPositionalParam("testPassword");
  if(!test.executeQuery()){
      qFatal("failed to insert user");
      return 1;
  }

  // fetch user
  test.setQuery("select username from user where username = ?");
  test.bindPositionalParam("testUser");
  if(!test.executeQuery()) return 1;
  if(test.querySize() != 1){
      qFatal("Username does not exist");
      return 1;
  }
  if(test.nextRes()){
      QString res = test.fetchResult(0).toString();
      assert(res == "testUser");
  }
  else{
      qFatal("failed to obtain results");
      return 1;
}

  // delete user
  test.setQuery("delete from user where username = ?");
  test.bindPositionalParam("testUser");
  if(!test.executeQuery()){
       qFatal("failed to remove user");
      return 1;
  }
  // end transaction
  test.commit();
}
