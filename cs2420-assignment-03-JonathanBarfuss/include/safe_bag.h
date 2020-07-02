#ifndef _SAFE_BAG_H_
#define _SAFE_BAG_H_

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include "bag.h"

template <typename Item>
class SafeBag : public Bag<Item> {
    public:
        //Constructors
        SafeBag(): Bag<Item>() {}
        SafeBag(int size): Bag<Item>(size) {}
        SafeBag(const Bag<Item>& a): Bag<Item>(a) {}

        //Overloaded remove()
        virtual SafeBag<Item>& remove(){
            if(Bag<Item>::sz == 0){
                throw std::runtime_error("SafeBag is already empty");
            }else{
                Bag<Item>::sz--;
                return *this;
            }
        }

        //Overloaded operator[] functions
        virtual Item operator[](int ndx) const { 
            if(ndx < 0 || ndx > Bag<Item>::sz){
                throw std::runtime_error("Index is out of bounds");
            }
            return Bag<Item>::elements[ndx]; 
        }
        virtual Item& operator[](int ndx) { 
            if(ndx < 0 || ndx > Bag<Item>::sz){
                throw std::runtime_error("Index is out of bounds");
            }
            return Bag<Item>::elements[ndx]; 
        }

};


#endif