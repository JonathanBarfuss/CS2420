#ifndef _HASH_FUNCTION_H_
#define _HASH_FUNCTION_H_

#include <iostream>
#include <cmath>

template <typename T>
int divideHF(T e, int capacity){
  return e % capacity;
}

template <typename T>
int folding(T e, int capacity){
    T fold[3];
    T temp = e;
    
    for(int i = 0; i < 3; i++){
        fold[i] = e / pow(10, 4-2*i);
        temp -= fold[i];
    }
    
    return (fold[1] + fold[2] + fold[3]) % capacity;
}

template <typename T>
int mid_squared(T e, int capacity){
  T temp = pow(e/100,2);
  temp = (temp / 1000); 
  temp = (temp % 1000); 
  return temp % capacity;
}

template <typename T>
int selecting_digits(T e, int capacity){
  T temp = (e / 1000) % 100;
  temp = temp * 10 + ((e/10)%10);
  return temp % capacity;
}

#endif