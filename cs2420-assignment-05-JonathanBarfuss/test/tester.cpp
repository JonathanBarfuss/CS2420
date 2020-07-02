#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "util_functions.h"
using namespace std;

TEST_CASE("Test palindrome")
{
  CHECK(palindrome("u"));
  CHECK(palindrome("radar"));
  CHECK(!palindrome("Welcome!"));
  CHECK(palindrome("noon"));
  CHECK(palindrome("Madam, I'm Adam"));
  CHECK(palindrome("Never odd or even"));
}

TEST_CASE("Test balancedBrackets")
{
  CHECK(balancedBrackets("(2 + 0) + 4"));
  CHECK(!balancedBrackets("(8 + 9 * (34 * 6)"));
  CHECK(balancedBrackets("class A { double x, y;}", '{', '}'));
  CHECK(!balancedBrackets("[4,5, [9, 8, 0, 3]]]", '[', ']'));
  CHECK(balancedBrackets("[[4,5, [9, 8, 0, 3]]]", '[', ']'));
}

TEST_CASE("Test evalutePostfixExpression")
{
  CHECK(evalutePostfixExpression("6 3 + 2 *") == 18);
  CHECK(evalutePostfixExpression("15 7 1 1 + - / 3 * 2 1 1 + + -") == 5);
  CHECK(evalutePostfixExpression("1 2 + 4 * 5 + 3 -") == -14);
  CHECK(static_cast<int>(1000 * evalutePostfixExpression("12 25 5 1 / / * 8 7 + -")) == 14904);
  CHECK(static_cast<int>(1000 * evalutePostfixExpression("70 14 4 5 15 3 / * - - / 6 +")) == 5757);
  CHECK(static_cast<int>(1000 * evalutePostfixExpression("3 5 6 * + 13 - 18 2 / +")) == -19888);
  CHECK_THROWS(evalutePostfixExpression("7 6 + 3 ; 6 -"));
  CHECK_THROWS(evalutePostfixExpression("14 + 2 3 *"));
  CHECK_THROWS(evalutePostfixExpression("14 2 3 +)"));
}

TEST_CASE("Test addingLargePositiveIntegers")
{
  CHECK(addingLargePositiveIntegers("850", "245") == "1095");
  CHECK(addingLargePositiveIntegers("987134", "609709037") == "610696171");
  CHECK(addingLargePositiveIntegers("8009927109737", "2920701009737") == "10930628119474");
  CHECK(addingLargePositiveIntegers("1000", "2927109737") == "2927110737");
  CHECK(addingLargePositiveIntegers("00000123", "77") == "00000200");
}