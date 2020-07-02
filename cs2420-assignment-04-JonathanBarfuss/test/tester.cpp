#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include "linked_array.h"
using namespace std;

TEST_CASE("Push and pop")
{
  LinkedArray<double> numbers;
  numbers.push(4.5);
  CHECK(numbers.length() == 1);
  numbers.push({7.2, 9.4, 10.6});
  CHECK(numbers.length() == 4);
  CHECK(numbers.pop() == 10.6);
  CHECK(numbers.length() == 3);
  CHECK(numbers.pop() == 9.4);
  CHECK(numbers.pop() == 7.2);
  CHECK(numbers.length() == 1);
  CHECK(numbers.pop() == 4.5);
  CHECK(numbers.empty());
  CHECK_THROWS(numbers.pop());
}

TEST_CASE("Unshift and shift")
{
  LinkedArray<double> numbers;
  CHECK(numbers.empty());
  numbers.unshift(4.5);
  numbers.unshift({10.6, 9.4, 7.2});
  CHECK(numbers.length() == 4);
  CHECK(numbers.shift() == 10.6);
  CHECK(numbers.length() == 3);
  CHECK(numbers.shift() == 9.4);
  CHECK(numbers.shift() == 7.2);
  CHECK(numbers.length() == 1);
  CHECK(numbers.shift() == 4.5);
  CHECK(numbers.empty());
  CHECK_THROWS(numbers.shift());
}

TEST_CASE("Mixed push, unshift, pop, and shift")
{
  LinkedArray<int> numbers;
  numbers.push(4);
  numbers.unshift(7);
  numbers.push(9);
  numbers.unshift(12);
  CHECK(numbers.pop() == 9);
  CHECK(numbers.shift() == 12);
  CHECK(numbers.shift() == 7);
  CHECK(numbers.pop() == 4);
  CHECK(numbers.empty());
  CHECK_THROWS(numbers.shift());
  CHECK_THROWS(numbers.pop());
}

TEST_CASE("initializer_list")
{
  LinkedArray<double> numbers {4.5, 5.0, 9.5};
  CHECK(numbers.length() == 3);
  numbers.unshift({.5, 1.5, 3.});
  CHECK(numbers.length() == 6);
  CHECK(numbers.shift() == .5);
  numbers.push({10.5, 12.5, 15.0});
  CHECK(numbers.pop() == 15);

  LinkedArray<double> nums = numbers;
  CHECK(nums.shift() == 1.5);
  CHECK(nums.pop() == 12.5);
  CHECK(nums.length() == 5);

  LinkedArray<double> temp {14.5, 15.0, 19.5};
  temp = numbers;
  CHECK(temp.length() == 7);
}

TEST_CASE("Find")
{
  LinkedArray<int> numbers;
  numbers.push(4);
  numbers.unshift(7);
  numbers.push(9);
  numbers.unshift(12);
  numbers.unshift(2);
  CHECK(*numbers.find(7) == 7);
  CHECK(*numbers.find(4) == 4);
  CHECK(*numbers.find(2) == 2);
  CHECK(*numbers.find(9) == 9);
  CHECK(numbers.find(15) == numbers.end());
}

TEST_CASE("Concat")
{
  LinkedArray<int> numbers;
  numbers.push(4);
  numbers.unshift(7);
  numbers.push(9);
  numbers.unshift(12);
  numbers.unshift(2);
  CHECK(numbers.length() == 5);

  LinkedArray<int> moreNumbers;
  moreNumbers.unshift(12);
  moreNumbers.unshift(23);
  CHECK(moreNumbers.length() == 2);

  moreNumbers.concat(numbers);
  CHECK(moreNumbers.length() == 7);
  CHECK(*moreNumbers.find(12) == 12);
}

TEST_CASE("Begin and end")
{
  LinkedArray<int> numbers;
  numbers.push(4);
  numbers.push(7);
  numbers.push(9);
  numbers.unshift(1);
  CHECK(*numbers.begin() == 1);
  CHECK(numbers.end() == LinkedListIterator<int>(nullptr));

  for (auto n : numbers)
  {
    CHECK(n == *numbers.find(n));
  }
}

TEST_CASE("Constructors and assignment")
{
  LinkedArray<int> numbers;
  numbers.push(4);
  numbers.push(7);
  numbers.push(9);
  numbers.unshift(2);

  LinkedArray<int> moreNumbers;
  moreNumbers.unshift(12);
  moreNumbers.unshift(23);

  LinkedArray<int> numbers2(numbers);
  CHECK(numbers.length() == numbers2.length());
  for (int i = 0; i < 4; i++)
  {
    CHECK(numbers.pop() == numbers2.pop());
  }

  CHECK(numbers.empty());

  numbers = moreNumbers;
  CHECK(numbers.shift() == moreNumbers.shift());
  CHECK(numbers.length() == moreNumbers.length());
}

TEST_CASE("Operator<<")
{
  stringstream sout1, sout2;
  LinkedArray<int> numbers;
  sout1 << numbers;
  numbers.push(4);
  numbers.push(7);
  numbers.push(9);
  numbers.unshift(2);
  sout2 << numbers;

  CHECK(sout1.str() == "");
  CHECK(sout2.str() == "2,4,7,9");
}