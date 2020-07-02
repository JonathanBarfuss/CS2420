#include "date.h"
#include <iostream>

using namespace std;

int main(){

  //Start off with an initial date of Feburary 10th, 2019
  Date* d = new Date(2019, 2, 10);

  //Convert to string and cout
  cout << d->str() << endl;

  //Add 3 months, convert to string and cout
  d->addMonths(3);
  cout << d->str() << endl;

  //Add 30 days, cout
  d->addDays(30);
  cout << *d << endl;

  //Add 20 days (with overriden operator+), cout
  *d = *d + 20;
  cout << *d << endl;

  //Format year, month, day and cout
  cout << d->format("yyyy/mm/dd", *d) << endl;

  //Delete
  delete d;
  d = nullptr;

  return 0;
}