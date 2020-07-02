#include "util_functions.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
  
  //Testing Postfix expressions
  string postfix = "3 2 2 + - 5 *";
  double answer = evalutePostfixExpression(postfix);
  cout << answer << endl;

  postfix = "3 3 2 1 + - + 255 / 2 85 * / 3 +";
  answer = evalutePostfixExpression(postfix);
  cout << answer << endl;
  
  //Testing balanced brackets
  string par = "(Hi, I'm (not Julianne) Jonathan (not John))";
  bool result = balancedBrackets(par);
  if(result) {
    cout << "It is balanced!" << endl;
  } else {
    cout << "It isn't balanced :(" << endl;
  }

  par = "[[[[[I love brackets!!![!]!]]]";
  result = balancedBrackets(par, '[', ']');
  if(result) {
    cout << "It is balanced!" << endl;
  } else {
    cout << "It isn't balanced :(" << endl;
  }

  //Testing adding large positive integers
  string p1 = "9999";
  string p2 = "999";
  string sum = addingLargePositiveIntegers(p1, p2);
  cout << sum << endl;

  p1 = "115";
  p2 = "85";
  sum = addingLargePositiveIntegers(p1, p2);
  cout << sum << endl;
  
  //Testing Palindromes
  string test = "Madam, I'm Adam";

  bool p = palindrome(test);

  if (p){
    cout << "It is a palindrome" << endl;
  } else {
    cout << "It is not a palindrome" << endl;
  }

  test = "Able was I ere I saw Elba.";

  p = palindrome(test);

  if (p){
    cout << "It is a palindrome" << endl;
  } else {
    cout << "It is not a palindrome" << endl;
  }
  
  return 0;
}
