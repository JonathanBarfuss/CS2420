#ifndef _UTIL_FUNCTIONS_H
#define _UTIL_FUNCTIONS_H
#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include "stack.h"
#include "queue.h"

std::string addingLargePositiveIntegers(const std::string& a, const std::string& b) {
    LinkedStack<int> s1;
    LinkedStack<int> s2;
    LinkedStack<int> total;
    int carry = 0;
    std::string finish;

    //Filling s1 and s2
    for (int i = 0; i < a.length(); i++) {
        s1.push(a[i] - '0');
    }
    for (int i = 0; i < b.length(); i++) {
        s2.push(b[i] - '0');
    }

    //Perform addition
    while(!s1.empty() || !s2.empty()){
        if(s1.empty()) {s1.push(0);}
        if(s2.empty()) {s2.push(0);}

        carry = s1.top() + s2.top() + (carry/10);
        total.push(carry%10);
        s1.pop();
        s2.pop();
    }
    if(carry/10 > 0){   //If the sum goes up a digit, we will need to add carry one more time
        total.push(carry/10);
    }

    //Pop total onto finish
    while(!total.empty()){
        finish += (total.top() + '0');
        total.pop();
    }

    return finish;
}

bool palindrome(const std::string& s){
    LinkedQueue<char> base;
    LinkedQueue<char> mirror;
    std::string d = s;

    //Code to get rid of other characters and convert to lowercase
    for (int i = 0; i < d.length(); i++){
        if(!isalpha(d[i])){
            d.erase(i, 1);
        }
        if(isspace(d[i])){d.erase(i,1);}

        d[i] = static_cast<char>(std::tolower(d[i]));
    }

    //Filling the base
    for (int i = 0; i < d.length()/2; i++) {
        base.enqueue(d[i]);
	}

    //Filling mirror
    for (int i = d.length()-1; i >= d.length()/2 && i>1; i--){
        mirror.enqueue(d[i]);
    }

    //Compare the two stacks
    while(!base.empty()){
        if (base.peekFront() != mirror.peekFront()){
            return false;
        }
        base.dequeue();
        mirror.dequeue();
    }
    return true;
}

bool balancedBrackets(std::string s, char start = '(', char end = ')') {
    LinkedStack<char> scale;

    //Loop through s. If a character is start, push the stack, if a character is end pop the stack.
    for (int i = 0; i < s.length(); i++){
        if(s[i] == start){
            scale.push(s[i]);
        }
        if(s[i] == end){
            if(scale.empty()){return false;}
            scale.pop();
        }
    }
    //If the stack is empty, then there was a balance
    return scale.empty();
}

double evalutePostfixExpression(std::string exp) {
    LinkedStack<double> s;
    std::stringstream parse(exp);

    //Loop through string and perform operations
    std::string word;
    while(parse >> word){
        if(word == "+"){
            double x = s.top();
            s.pop();
            double y = s.top();
            s.pop();
            s.push(x+y);
        } else if(word == "-"){
            double x = s.top();
            s.pop();
            double y = s.top();
            s.pop();
            s.push(x-y);
        } else if(word == "*"){
            double x = s.top();
            s.pop();
            double y = s.top();
            s.pop();
            s.push(x*y);
        } else if(word == "/"){
            double x = s.top();
            s.pop();
            double y = s.top();
            s.pop();
            s.push(x/y);
        } else {
            s.push(stod(word));
        }

        word = "";
    }

    //Return results
    double result = s.top();
    s.pop();
    if(!s.empty()){
        throw std::runtime_error("Invalid Expression");
    }
    return result;
}

#endif