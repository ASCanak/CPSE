#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "headers/set.h"

TEST_CASE("add Numbers (Float, 5)"){
   set<float, 5> collection;
   std::ostringstream output;

   collection.add(1);
   output << collection;
   REQUIRE(output.str() == "[1, 0, 0, 0, 0]\n");
   output.str(std::string());
   
   collection.add(2);
   collection.add(3);
   output << collection;
   REQUIRE(output.str() == "[1, 2, 3, 0, 0]\n");
}

TEST_CASE("add non-Unique Numbers (Float, 5)"){
   set<float, 5> collection;
   std::ostringstream output;

   collection.add(1);
   output << collection;
   REQUIRE(output.str() == "[1, 0, 0, 0, 0]\n");
   output.str(std::string());
   
   collection.add(2);
   collection.add(2);
   output << collection;
   REQUIRE(output.str() == "[1, 2, 0, 0, 0]\n");
}

TEST_CASE("add and remove Number (Float, 5)"){
   set<float, 5> collection;
   std::ostringstream output;

   collection.add(1);
   collection.remove(1);
   output << collection;
   REQUIRE(output.str() == "[0, 0, 0, 0, 0]\n");
   output.str(std::string());
   
   collection.add(1);
   collection.add(2);
   collection.add(3);
   collection.remove(1);
   output << collection;
   REQUIRE(output.str() == "[2, 3, 0, 0, 0]\n");
}

TEST_CASE("add and Remove non-existing Number (Float, 5)"){
   set<float, 5> collection;
   std::ostringstream output;

   collection.add(1);
   collection.remove(5);
   output << collection;
   REQUIRE(output.str() == "[1, 0, 0, 0, 0]\n");
   output.str(std::string());
   
   collection.add(2);
   collection.remove(3);
   output << collection;
   REQUIRE(output.str() == "[1, 2, 0, 0, 0]\n");
}

TEST_CASE("add more then max size (Float, 5)"){
   set<float, 5> collection;
   std::ostringstream output;

   for(unsigned int i = 1; i < 15; i++){
      collection.add(i);
   }

   output << collection; 
   REQUIRE(output.str() == "[1, 2, 3, 4, 5]\n");
}

TEST_CASE("contains (Float, 5)"){
   set<float, 5> collection;
   collection.add(1);
   REQUIRE(collection.contains(1));

   collection.remove(1);
   REQUIRE(!collection.contains(1));
}

TEST_CASE("add Numbers (unsigned int, 8)"){
   set<unsigned int, 8> collection;
   std::ostringstream output;

   collection.add(1);
   output << collection;
   REQUIRE(output.str() == "[1, 0, 0, 0, 0, 0, 0, 0]\n");
   output.str(std::string());
   
   collection.add(2);
   collection.add(3);
   output << collection;
   REQUIRE(output.str() == "[1, 2, 3, 0, 0, 0, 0, 0]\n");
}

TEST_CASE("add non-Unique Numbers (unsigned int, 8)"){
   set<unsigned int, 8> collection;
   std::ostringstream output;

   collection.add(1);
   output << collection;
   REQUIRE(output.str() == "[1, 0, 0, 0, 0, 0, 0, 0]\n");
   output.str(std::string());
   
   collection.add(2);
   collection.add(2);
   output << collection;
   REQUIRE(output.str() == "[1, 2, 0, 0, 0, 0, 0, 0]\n");
}

TEST_CASE("add and remove Number (unsigned int, 8)"){
   set<unsigned int, 8> collection;
   std::ostringstream output;

   collection.add(1);
   collection.remove(1);
   output << collection;
   REQUIRE(output.str() == "[0, 0, 0, 0, 0, 0, 0, 0]\n");
   output.str(std::string());
   
   collection.add(1);
   collection.add(2);
   collection.add(3);
   collection.remove(1);
   output << collection;
   REQUIRE(output.str() == "[2, 3, 0, 0, 0, 0, 0, 0]\n");
}

TEST_CASE("add and Remove non-existing Number (unsigned int, 8)"){
   set<unsigned int, 8> collection;
   std::ostringstream output;

   collection.add(1);
   collection.remove(5);
   output << collection;
   REQUIRE(output.str() == "[1, 0, 0, 0, 0, 0, 0, 0]\n");
   output.str(std::string());
   
   collection.add(2);
   collection.remove(3);
   output << collection;
   REQUIRE(output.str() == "[1, 2, 0, 0, 0, 0, 0, 0]\n");
}

TEST_CASE("add more then max size (unsigned int, 8)"){
   set<unsigned int, 8> collection;
   std::ostringstream output;

   for(unsigned int i = 1; i < 15; i++){
      collection.add(i);
   }

   output << collection; 
   REQUIRE(output.str() == "[1, 2, 3, 4, 5, 6, 7, 8]\n");
}

TEST_CASE("contains (unsigned int, 8)"){
   set<unsigned int, 8> collection;
   collection.add(1);
   REQUIRE(collection.contains(1));

   collection.remove(1);
   REQUIRE(!collection.contains(1));
}