#ifndef _BAG_H_
#define _BAG_H_

#include <iostream>
template<typename Item>
class Bag {
public:
    Bag(): sz(0), capacity(8), elements(new Item[capacity]){}
    Bag(int size): sz(size), capacity(size), elements(new Item[size]){}
    Bag(const Bag<Item>& c): sz(c.sz), capacity(c.capacity) {
        elements = new Item[capacity];
        for(int i = 0; i < c.sz; i++){
            elements[i] = c.elements[i];
        }
    }

    Bag<Item>& operator=(const Bag<Item>& c){
       Item* newElements = new Item[c.capacity];
       for(int i = 0; i < sz; i++){
             newElements[i] = c.elements[i];
       }
       
       delete[] elements;
       elements = newElements;
       sz = c.sz;
       capacity = c.capacity;

       return *this;
    }

    // Required to support range-based for loop
    Item* begin(){ return elements; }
    Item* end(){ return elements + sz; }

    void add(Item e){
        if(sz == capacity){
            Item* newElements = new Item[capacity * 2];
            for(int i = 0; i < sz; i++){
                newElements[i] = elements[i];
            }
            delete[] elements;
            elements = newElements;
            capacity *= 2;
        }
        elements[sz++] = e;
    }

    Item operator[](int i) const{
        return elements[i];
    }

    Item& operator[](int i) {
        return elements[i];
    }
    
    
    Bag<Item>& remove(){
        sz--;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Bag<Item>& c){
        for(int i = 0; i < c.sz; i++){
            out << c.elements[i] << " ";
        }

        return out;
    }

    void sortByBubble(bool reversed = false){
      for(int i = 0; i < sz - 1; i++){
        for(int j = 1; j < sz - i; j++){
          if(lessOrGreaterThan(j, j - 1, reversed)){
            swap(j, j-1);
          }
        }
      }
    }

    void sortBySelection(bool reversed = false){
      for(int i = 0; i < sz; i++){
        swap(i, minOrMaxInRange(i, sz, reversed));
      }
    }

    void sortByInsertion(bool reversed = false){
      for(int i = 1; i < sz; i++){
        for(int j = i; j >= 1 && lessOrGreaterThan(j, j-1, reversed); j--){
          swap(j, j-1);
        }
      }
    }

    ~Bag(){
        delete[] elements;
    }
protected:
    int  sz, capacity;
    Item *elements;
    
    void swap(int i, int j){
      auto tmp = elements[i];
      elements[i] = elements[j];
      elements[j] = tmp;
    }

    bool lessOrGreaterThan(int i, int j, bool reversed = false){
      return (!reversed && elements[i] < elements[j]) || (reversed && elements[i] > elements[j]);
    }

    int minOrMaxInRange(int begin, int end, bool reversed = false){
      int minOrMax = begin;
      for(int i = begin; i < end; i++){
          if(lessOrGreaterThan(i, minOrMax, reversed)){
              minOrMax = i;
          }
      }

      return minOrMax;
    }
  };
#endif