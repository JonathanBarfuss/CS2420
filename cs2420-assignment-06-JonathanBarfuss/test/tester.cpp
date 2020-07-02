#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <random>
#include "linear_hashtable.h"
#include "chained_hashtable.h"
#include "quadratic_hashtable.h"

using namespace std;

int random_int(int min, int max){
  static default_random_engine e;
  return uniform_int_distribution<>{min, max}(e);
}

TEST_CASE("Test LinearHashtable"){
  ChainedHashtable<int> ht(57);
  int rcount = 0;

  CHECK(ht.empty());
  ht.add(11);
  ht.add(57);
  ht.add(114);
  ht.add(58);
  CHECK(ht.size() == 4);
  CHECK(!ht.full());

  int fst, lst;
  for (int i = 0; i < 50; i++) {
    if(i == 0) ht.add(fst = random_int(1, 99));
    else ht.add(lst = random_int(1, 99));
  }
   
  CHECK(ht.size() == 54);
  CHECK(ht.contains(lst));
  
  while(ht.contains(lst)){
    ht.remove(lst);
    rcount++;
  }

  CHECK(!ht.contains(lst));
  CHECK(ht.size() == 54 - rcount);
  ht.add(7 * 1);
  ht.add(7 * 2);
  ht.add(7 * 3);
  ht.add(7 * 4);
  CHECK(ht.full());
  CHECK(ht.remove(57));
  CHECK(!ht.full());
}

TEST_CASE("Test ChainedHashtable"){
  ChainedHashtable<int> ht(57);
  int rcount = 0;

  CHECK(ht.empty());
  ht.add(11);
  ht.add(57);
  ht.add(114);
  ht.add(58);
  CHECK(ht.size() == 4);
  CHECK(!ht.full());

  int fst, lst;
  for (int i = 0; i < 50; i++) {
    if(i == 0) ht.add(fst = random_int(1, 99));
    else ht.add(lst = random_int(1, 99));
  }
   
  CHECK(ht.size() == 54);
  CHECK(ht.contains(lst));
  
  while(ht.contains(lst)){
    ht.remove(lst);
    rcount++;
  }

  CHECK(!ht.contains(lst));
  CHECK(ht.size() == 54 - rcount);
  ht.add(7 * 1);
  ht.add(7 * 2);
  ht.add(7 * 3);
  ht.add(7 * 4);
  CHECK(ht.full());
  CHECK(ht.remove(57));
  CHECK(!ht.full());
}

TEST_CASE("Test QuadraticHashtable"){
  QuadraticHashtable<int> ht(57);
  int rcount = 0;

  CHECK(ht.empty());
  ht.add(11);
  ht.add(57);
  ht.add(114);
  ht.add(58);
  CHECK(ht.size() == 4);
  CHECK(!ht.full());

  int fst, lst;
  for (int i = 0; i < 50; i++) {
    if(i == 0) ht.add(fst = random_int(1, 99));
    else ht.add(lst = random_int(1, 99));
  }
   
  CHECK(ht.size() == 54);
  CHECK(ht.contains(lst));
  
  while(ht.contains(lst)){
    ht.remove(lst);
    rcount++;
  }

  CHECK(!ht.contains(lst));
  CHECK(ht.size() == 54 - rcount);
  ht.add(7 * 1);
  ht.add(7 * 2);
  ht.add(7 * 3);
  ht.add(7 * 4);
  CHECK(ht.full());
  CHECK(ht.remove(57));
  CHECK(!ht.full());
}