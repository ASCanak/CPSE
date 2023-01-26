#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "headers/set.h"

TEST_CASE("max"){
   set<double, 4> collection;
   
   collection.add(5.39);
   collection.add(10.24);
   collection.add(1);
   collection.add(934.23);
   collection.add(6934.23);
   REQUIRE(collection.max() == 934.23);

   collection.remove(934.23);
   REQUIRE(collection.max() != 934.23);
   REQUIRE(collection.max() == 10.24);
}