#include <iostream>
#include <memory>
#include "bag.h"
#include "safe_bag.h"
#include "sorted_bag.h"
using namespace std;

int main() {
  
  //Testing a SortedBag<int>--------------------------------------
  auto test = make_unique<SortedBag<int>>();

  //Add variables and print
  test->add(3);
  test->add(4);
  test->add(5);
  *test + 6;
  *test << 9 << 11;
  cout << *test << endl;

  //Subtract using -- and print
  --*test;
  cout << *test << endl;

  //Subtract using - and print
  *test - 2;
  cout << *test << endl;

  //Using the assignment operator
  auto testcopy = *test;
  cout << testcopy << endl;

  //Using the copy constructor
  auto testcopy2 = make_unique<SortedBag<int>>(*test);
  cout << *testcopy2 << endl;

  //Printing a specific element from testcopy
  cout << testcopy[2] << endl << endl;


  //Testing a SortedBag<int> (specifically ordering)--------------------------------------------------
  auto test3 = make_unique<SortedBag<int>>();

  //To test this one, I'm just adding elements and printing to see if it puts them in order
  test3->add(4);
  test3->add(17);
  test3->add(10);
  test3->add(2);
  cout << *test3 << endl << endl;


  //Testing a SortedBag<double> (specifically safebag features)------------------------------------------------
  auto test2 = make_unique<SortedBag<double>>();

  //Add variables and print
  test2->add(4.5);
  *test2 + 6.4;
  *test2 + 3.7;
  cout << *test2 << endl;

  //Subtract all variables and print
  *test2 - 3;
  cout << *test2;

  //Remove one more time to see if safebag will catch the error
  test2->remove();
  cout << "The program didn't stop";

  return 0;
}