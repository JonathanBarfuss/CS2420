#ifndef _SORTED_BAG_H_
#define _SORTED_BAG_H_

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include "safe_bag.h"


template <typename Item>
class SortedBag : public SafeBag<Item> {
    public:
        //Constructors
        SortedBag(): SafeBag<Item>() {}
        SortedBag(int size): SafeBag<Item>(size) {}
        SortedBag(Bag<Item>& a): SafeBag<Item>(a) {}

        virtual void add(Item e) {
            //Increase the size of the bag if we are going to exceed it
            if (Bag<Item>::sz == Bag<Item>::capacity) {
              Bag<Item>::expand();
            }

            //If the Bag is empty, simply add it to the first slot in elements and increase sz
            if(this->sz == 0){
                this->elements[0] = e;
                this->sz++;
                return;
            }

            //The next few lines of code compare each item in the elements array to the argument starting from the back.
            //If the elements item is bigger than the argument, then the item is copied one slot forward in the elements array.
            //Once the argument finds its spot in the array, it is placed there (since the array was already shifted)
            int i = this->sz-1;
            while(i >= 0 && this->elements[i] > e){
                this->elements[i+1] = this->elements[i];
                i--;
            }
            this->elements[i+1] = e;
            this->sz++;

            
        }
};

#endif