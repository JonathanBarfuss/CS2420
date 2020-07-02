#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <sstream>
#include "sorted_bag.h"
using namespace std;

TEST_CASE("Sorted Bag") {
  SortedBag<int> one;
  one << 19 << 9 << 2 << 8 << 7 << 12 
      << 17 << 0 << 11 << 6 << 3 << 1;

  CHECK(one[0] == 0);
  CHECK(one[11] == 19);
  CHECK_THROWS(one[20]);
  CHECK_THROWS(one[20] = 1);
  CHECK((one << 13).size()== 13);
}

TEST_CASE("Sorted Bag - add") {
  SortedBag<int> one;
  one + 19 + 9 + 2 + 8 + 7 + 12 
      + 17 + 0 + 11 + 6 + 3 + 1;

  CHECK(one[1] == 1);
  CHECK(one[10] == 17);
  CHECK_THROWS(one[13]);
  CHECK_THROWS(one[13] = 1);
  CHECK((one << 13).size()== 13);
}

TEST_CASE("Sorted Bag - remove") {
  SortedBag<int> one;
  one + 19 + 9 + 2 + 8 ;

  CHECK(one.size() == 4);
  one - 2;
  CHECK(one.size() == 2);
  CHECK(one[1] == 8);
  CHECK(one[0] == 2);
  CHECK_THROWS(one[4]);
  CHECK_THROWS(one[4] = 1);
  --one;
  CHECK(one.size() == 1);
  CHECK(one[0] == 2);
  CHECK_THROWS(one[2]);
  --one;
  CHECK(one.size() == 0);
}

TEST_CASE("Sorted Bag - constructors") {
  SortedBag<int> one(4);
  
  CHECK(one[0] == 0);
  CHECK(one[3] == 0);
  CHECK_THROWS(one[5]);
  CHECK_THROWS(one[5] = 1);
  one << -1 << -10;
  stringstream sout;
  sout << one;
  CHECK(sout.str() == "-10 -1 0 0 0 0 ");

  SortedBag<int> two(one);
  CHECK(two[0] == -10);
  CHECK(two[3] == 0);
  CHECK_THROWS(two[7]);
  CHECK_THROWS(two[11] = 1);
  sout.str("");
  sout << two;
  CHECK(sout.str() == "-10 -1 0 0 0 0 ");
}
