#ifndef _BAG_H_
#define _BAG_H_

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

template<typename Item>
class Bag {
public:
  Bag(): capacity(INITIAL_CAPACITY), sz(0), 
    elements(std::make_unique<Item[]>(capacity)) {}

  Bag(int size): capacity(size), sz(size), 
    elements(std::make_unique<Item[]>(capacity)){}

  //Copy Constructor
  Bag(Bag<Item>& a): capacity(a.capacity), sz(a.sz),
    elements(std::make_unique<Item[]>(capacity)) {
    for (int i = 0; i < a.sz; i++) elements[i] = a.elements[i];
  }

  //Getters
  virtual int size() { return sz; }
  virtual Item get(int ndx) const { return elements[ndx]; }
  
  //Add
  virtual void add(Item e) {
    if (sz == capacity) {
      expand();
    }

    (*this)[sz++] = e;
  }

  //Remove
  virtual Bag<Item>& remove() {
    sz--;
    return *this;
  }

  //Return the first or last elements
  virtual Item* begin() { return elements.get(); }
  virtual Item* end() { return elements.get() + sz; }

  //Copy Assignment
  virtual Bag<Item>& operator=(Bag<Item>& a) {
    auto newElements = std::make_unique<Item[]>(a.capacity);
    for (int i = 0; i < a.sz; i++) newElements[i] = a.elements[i];
    elements = move(newElements);
    capacity = a.capacity;
    sz = a.sz;

    return *this;
  }

  //Overloaded operators
  virtual Item operator[](int ndx) const { return elements[ndx]; }
  virtual Item& operator[](int ndx) { return elements[ndx]; }
  virtual Bag<Item>& operator<<(Item e) {
    add(e);
    return *this;
  }
  friend std::ostream& operator<<(std::ostream& snout, Bag<Item>& b){
    for (int i = 0; i < b.sz; i++){
      snout << b.elements[i] << " ";
    }
    return snout;
  }
  virtual Bag<Item>& operator+(Item e){ 
    add(e);
    return *this;
  }
  virtual void operator--(){  remove();  }
  virtual void operator-(int n){
    for (int i = 0; i <n; i++){ remove();  }
  }
  virtual ~Bag(){}

protected:
  int capacity;
  int sz;
  std::unique_ptr<Item[]> elements;
  static const int INITIAL_CAPACITY = 8;

  void expand() {
    auto newElements = std::make_unique<Item[]>(capacity * 2);
    for (int i = 0; i < capacity; i++) newElements[i] = elements[i];
    elements = std::move(newElements);

    capacity *= 2;
  }
};

#endif