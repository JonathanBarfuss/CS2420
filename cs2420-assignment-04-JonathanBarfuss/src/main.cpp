#include <iostream>
#include "linked_array.h"
using namespace std;

int main(){
  //Testing an int LinkedArray
  LinkedArray<int> test;
  test.push({1,2,3});
  test.push(4);
  test.push(5);
  test.unshift({-1,0});

  cout << test.shift() << endl;
  cout << test << endl;
  cout << test.length() << endl;
  cout << test.empty() << endl;
  cout << *(test.find(3)) << endl;

  //Making a second int LinkedArray to test concat and the copy assignment
  LinkedArray<int> test2;
  test2.push({6,7,8});
  test.concat(test2);
  cout << test << endl;
  cout << test.pop() << endl;
  cout << test << endl;

  for(int e : test2){
    cout << test2.shift();
  }
  cout << endl;

  test2 = test;
  cout << test2 << endl;


  //Testing a char LinkedArray
  LinkedArray<char> test3;
  test3.push({'J','o','n','a','t','h','a','n'});
  cout << test3 << endl;
  while(!(test3.empty())){
    cout << test3.shift();
  }
  cout << endl;

  return 0;
}