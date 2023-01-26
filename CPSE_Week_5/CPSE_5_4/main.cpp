#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "headers/set.h"
#include <fstream>

TEST_CASE("add Numbers (char, 3)"){
   set<char, 3> collection;
   std::ostringstream output;

   collection.add('a');
   output << collection;
   REQUIRE(output.str() == "[a, NULL, NULL]\n");
   output.str(std::string());
   
   collection.add('2');
   collection.add('3');
   output << collection;
   REQUIRE(output.str() == "[a, 2, 3]\n");
}

TEST_CASE("add non-Unique Numbers (char, 3)"){
   set<char, 3> collection;
   std::ostringstream output;

   collection.add('1');
   output << collection;
   REQUIRE(output.str() == "[1, NULL, NULL]\n");
   output.str(std::string());
   
   collection.add('2');
   collection.add('2');
   output << collection;
   REQUIRE(output.str() == "[1, 2, NULL]\n");
}

TEST_CASE("add and remove Number (char, 3)"){
   set<char, 3> collection;
   std::ostringstream output;

   collection.add('1');
   collection.add('2');
   collection.add('3');
   collection.remove('1');
   collection.remove('2');
   collection.remove('3');
   output << collection;
   REQUIRE(output.str() == "[NULL, NULL, NULL]\n");
   output.str(std::string());
   
   collection.add('1');
   collection.add('2');
   collection.add('3');
   collection.remove('1');
   output << collection;
   REQUIRE(output.str() == "[2, 3, NULL]\n");
}

TEST_CASE("add and Remove non-existing Number (char, 3)"){
   set<char, 3> collection;
   std::ostringstream output;

   collection.add('1');
   collection.remove('5');
   output << collection;
   REQUIRE(output.str() == "[1, NULL, NULL]\n");
   output.str(std::string());
   
   collection.add('2');
   collection.remove('3');
   output << collection;
   REQUIRE(output.str() == "[1, 2, NULL]\n");
}

TEST_CASE("add more then max size (char, 3)"){
   set<char, 3> collection;
   std::ostringstream output;

   for(unsigned int i = 97; i < 115; i++){
      collection.add(char(i));
   }

   output << collection; 
   REQUIRE(output.str() == "[a, b, c]\n");
}

TEST_CASE("contains (char, 3)"){
   set<char, 3> collection;
   collection.add('1');
   REQUIRE(collection.contains('1'));

   collection.remove('1');
   REQUIRE(!collection.contains('1'));
}

TEST_CASE("max (char, 3)"){
   set<char, 3> collection;
   
   collection.add('a');
   collection.add('b');
   collection.add('c');
   collection.add('d');
   REQUIRE(collection.max() == 'c');

   collection.remove('c');
   REQUIRE(collection.max() != 'c');
   REQUIRE(collection.max() == 'b');
}