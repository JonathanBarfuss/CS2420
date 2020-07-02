#ifndef _LINEAR_HASHTABLE_H_
#define _LINEAR_HASHTABLE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include "hash_functions.h"

template<typename T>
struct Cell {
  T info;
  bool empty = true;
};

template<typename T>
class LinearHashtable {
public:
  LinearHashtable(int capacity = 499):  sz(0), capacity(capacity), htable(new Cell<T>[capacity]()){}

  LinearHashtable(const LinearHashtable<T>& c) = delete;
  LinearHashtable<T>& operator=(const LinearHashtable<T>&& c) = delete;

  friend std::ostream& operator<<(std::ostream& out, const LinearHashtable<T>& t){
    for(int i = 1; i <= t.capacity; i++){
      out << std::setw(5) << (t.htable[i-1].empty ? "_" : std::to_string(t.htable[i-1].info));
      if(i % 12 == 0) out << std::endl;
    } 

    out << std::endl;
    return out;
  }

  void add(T e){
    if(full()) throw std::runtime_error("Table is full.");

    int t = hashCode(e);
    if(htable[t].empty){
      htable[t] = { e, false};
    } else {
      int i = 1;
      while (!htable[(t + i) % capacity].empty) i++;
      htable[(t + i) % capacity] = {e, false};
    }

    sz++;
  }

  bool remove(T e){
    if(empty()) return false;

    int t = hashCode(e);
    if(!htable[t].empty && htable[t].info == e){
      htable[t].empty = true;
      sz--;
      return true;
    } else {
      int i = 1;
      while (i < capacity){
        if(!htable[(t + i) % capacity].empty &&  htable[(t + i) % capacity].info == e){
          htable[(t + i) % capacity].empty = true;
          sz--;
          return true;
        }
        
        i++;
      }
      
      return false;
    }
  }

  bool contains(T e) {
    int t = hashCode(e);
    if(!htable[t].empty && htable[t].info == e){
      return true;
    } else {
      int i = 1;
      while (i < capacity){
        if(!htable[(t + i) % capacity].empty && htable[(t + i) % capacity].info == e) {
          return true;
        }

        i++;
      }
      return  false;
    }
  }

  bool empty(){ return sz == 0; }
  bool full(){ return sz == capacity; }
  int size() { return sz; }

  ~LinearHashtable(){
      delete[] htable;
  }
protected:
  int sz, capacity;
  Cell<T> *htable;

  int hashCode(T e){
    return divideHF(e, capacity);
  }
};
#endif