#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include "linear_hashtable.h"
#include "chained_hashtable.h"
#include "quadratic_hashtable.h"

using namespace std;
using namespace std::chrono;

int random_int(int min, int max){
  static default_random_engine e;
  static uniform_int_distribution<int> dist {min, max};
  return dist(e);
}

int main(){
  
  //Creating random numbers
  int randint[500];
  for(int i = 0; i < 500; i++){
    randint[i] = random_int(100000, 999999);
  }

  //Initial print
  cout << setw(19) << "Table" << setw(12) << "Add" << setw(12) << "Remove" << setw(12) << "Contains" << endl;


//Testing Linear Hashtable----------------------------------------------------------
  LinearHashtable<int> lt(500);

  //Add
  auto startltadd = high_resolution_clock::now();
  for(int i = 0; i < 500; i++){
    lt.add(randint[i]);
  }
  auto endltadd = high_resolution_clock::now();
  duration<double, milli> running_timeltadd = endltadd - startltadd;

  //Remove
  auto startltremove = high_resolution_clock::now();
  for(int i = 0; i < 500; i++){
    lt.remove(randint[i]);
  }
  auto endltremove = high_resolution_clock::now();
  duration<double, milli> running_timeltremove = endltremove - startltremove;

  //Contains
  auto startltcontains = high_resolution_clock::now();
  for(int i = 0; i < 500; i++){
    lt.contains(randint[i]);
  }
  auto endltcontains = high_resolution_clock::now();
  duration<double, milli> running_timeltcontains = endltcontains - startltcontains;

  //Print
  cout << setw(19) << "LinearHashTable:" << setw(12) << running_timeltadd.count() << setw(12) << running_timeltremove.count() << setw(12) << running_timeltcontains.count() << endl;


//Testing Quadratic Hashtable--------------------------------------------------------------------------
  QuadraticHashtable<int> qt(500);

  //Add
  auto startqtadd = high_resolution_clock::now();
  for(int i = 0; i < 500; i++){
    qt.add(randint[i]);
  }
  auto endqtadd = high_resolution_clock::now();
  duration<double, milli> running_timeqtadd = endqtadd - startqtadd;

  //Remove
  auto startqtremove = high_resolution_clock::now();
  for(int i = 0; i < 500; i++){
    qt.remove(randint[i]);
  }
  auto endqtremove = high_resolution_clock::now();
  duration<double, milli> running_timeqtremove = endqtremove - startqtremove;

  //Contains
  auto startqtcontains = high_resolution_clock::now();
  for(int i = 0; i < 500; i++){
    qt.contains(randint[i]);
  }
  auto endqtcontains = high_resolution_clock::now();
  duration<double, milli> running_timeqtcontains = endqtcontains - startqtcontains;

  //Print
  cout << setw(19) << "QuadraticHashTable:" << setw(12) << running_timeqtadd.count() << setw(12) << running_timeqtremove.count() << setw(12) << running_timeqtcontains.count() << endl;

//Testing Chained Hashtable----------------------------------------------------------------------------
  ChainedHashtable<int> ct(500);

  //Add
  auto startctadd = high_resolution_clock::now();
  for(int i = 0; i < 500; i++){
    ct.add(randint[i]);
  }
  auto endctadd = high_resolution_clock::now();
  duration<double, milli> running_timectadd = endctadd - startctadd;

  //Remove
  auto startctremove = high_resolution_clock::now();
  for(int i = 0; i < 500; i++){
    ct.remove(randint[i]);
  }
  auto endctremove = high_resolution_clock::now();
  duration<double, milli> running_timectremove = endctremove - startctremove;

  //Contains
  auto startctcontains = high_resolution_clock::now();
  for(int i = 0; i < 500; i++){
    ct.contains(randint[i]);
  }
  auto endctcontains = high_resolution_clock::now();
  duration<double, milli> running_timectcontains = endctcontains - startctcontains;

  //Print
  cout << setw(19) << "ChainedHashTable:" << setw(12) << running_timectadd.count() << setw(12) << running_timectremove.count() << setw(12) << running_timectcontains.count() << endl;



  return 0;
}