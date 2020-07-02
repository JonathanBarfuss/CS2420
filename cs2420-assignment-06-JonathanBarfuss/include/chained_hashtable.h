#ifndef _CHAINED_HASHTABLE_H_
#define _CHAINED_HASHTABLE_H_

#include <iostream>
#include <iomanip>
#include "hash_functions.h"

template<typename T>
struct Node {
  T info;
  Node<T>* link;
  Node(T info): info(info), link(nullptr){}
};

template<typename T>
class ChainedHashtable {
public:
  ChainedHashtable(int capacity = 499):  sz(0), capacity(capacity), htable(new Node<T>*[capacity]()){}
  ChainedHashtable(const ChainedHashtable<T>& c) = delete;
  ChainedHashtable<T>& operator=(const ChainedHashtable<T>&& c) = delete;

  friend std::ostream& operator<<(std::ostream& out, const ChainedHashtable<T>& t){
    int width = std::to_string(t.capacity).size();
    for(int i = 0; i < t.capacity; i++){
      out << std::setw(width) << i << ": ";

      auto current = t.htable[i];
      while(current){
        out << current->info << " ";
        if(current->link) out << "-> ";
        current = current->link;
      }
      out << std::endl;
    } 
    
    return out;
  }

  void add(T e){
    int t = hashCode(e);
    if(htable[t]){
      auto node = new Node<T>(e);
      node->link = htable[t];
      htable[t] = node;
    }else {
      htable[t] = new Node<T>(e);
    }

    sz++;
  }

  bool remove(T e){
    if(empty()) throw std::runtime_error("Table is empty.");

    int t = hashCode(e);
    auto current = htable[t];
    Node<T>* beforeCurrent = nullptr;
    while(current){
      if(current->info == e){
        if(beforeCurrent){
          beforeCurrent->link = current->link;
        } else{
          htable[t] = nullptr;
        }

        delete current;
        sz--;
        return true;
      }
      beforeCurrent = current;
      current = current->link;
    }
    return false;
  }

  bool	contains(T e) {
    int t = hashCode(e);
    auto current = htable[t];
    while(current){
      if(current->info == e){
        return true;
      }
      current = current->link;
    }
    return  false;
  }

  bool empty(){ return sz == 0; }
  bool full(){ return sz == capacity; }
  int size() { return sz; }

  ~ChainedHashtable(){
      delete[] htable;
  }
protected:
  int sz, capacity;
  Node<T>** htable;

  int hashCode(T e){
    return divideHF(e, capacity);
  }
};
#endif
