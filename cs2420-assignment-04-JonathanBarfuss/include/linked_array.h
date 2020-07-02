#ifndef _LINKED_ARRAY_H_
#define _LINKED_ARRAY_H_

#include <iostream>
#include <initializer_list>


//Node struct
template <typename T>
struct Node {
    Node<T>* next;
    Node<T>* prev;
    T info;

    //Constructors
    Node(T info): info(info), next(nullptr), prev(nullptr){}
    Node(T info, Node<T>* nxt, Node<T>* prv): info(info), next(nxt), prev(prv){}
};

//Iterator class
template <typename T>
class LinkedListIterator{
private:
        Node<T>* current = nullptr;
public:
        LinkedListIterator(Node<T>* c) : current(c) {}
        LinkedListIterator<T>& operator++() {
            current = current->next;
        }
        T operator*() {
            return current->info;
        }
        bool operator==(const LinkedListIterator<T>& rt) const {
            if (current == rt.current) {
                return true;
            } else {
                return false;
            }
        }
        bool operator!=(const LinkedListIterator<T>& rt) const {
            if (current != rt.current) {
                return true;
            } else {
                return false;
            }
        }
};

//Linked Array class
template <typename T>
class LinkedArray {
private:
    Node<T>* first = nullptr;
    Node<T>* last = nullptr;
    unsigned count = 0;

    void removeAll() {
        //Current is a pointer to the info at the front
        auto current = first;

        //While current isn't nullptr (or the back)
        while(current){
            //Temp is a pointer to where current points
            auto temp = current;
            //Move current to the next item
            current = current->next;
            //Delete what temp is pointing at
            delete temp;
        }

        first = nullptr;
        last = nullptr;
        count = 0u;
    }

public:
    //Constructors
    LinkedArray() {}    //No initializer list because first, last, and count are already defined
    LinkedArray(const LinkedArray<T>& c) {
    auto current = c.first; //Current is a pointer to the first node
    while(current){
        push(current->info);
        current = current->next;
    }
    }
    LinkedArray(const std::initializer_list<T>& lst){
        for(auto it = lst.begin(); it != lst.end(); ++it){
            push(*it);
        }
    }

    //Functions
    LinkedArray<T>& operator=(const LinkedArray<T>& lst){   //Assignment operator
        removeAll();    
        auto current = lst.first;
        while(current){
            push(current->info);
            current = current->next;
        }
        return *this;
    }
    unsigned push(T info){
        //Create new node pointer
        auto node = new Node<T>(info, nullptr, last);

        //If the list is empty, point the front and back to node
        if(!last){
            first = last = node;
        } else{     //If the list isn't empty point the previous last node to the new node, then make the back pointer point to the new back
            last->next = node;
            last = node;
        }

        count++;
        return count;
    }
    unsigned push(const std::initializer_list<T>& lst){
        for(auto it = lst.begin(); it != lst.end(); ++it){
            push(*it);
        }
        return count;
    }
    T pop(){
        if(count == 0){throw std::runtime_error("There are no items in the array to remove");}
        if(count == 1){
            T temp = last->info;    //Temp is made to hold onto the information in the node
            delete last;
            last = first = nullptr;
            count--;
            return temp;
        } else {
            T temp = last->info;
            auto node = last;       //node is a pointer to the last node
            last = last->prev;      //last now points to the node before
            delete node;            //the original last is deleted
            last->next = nullptr;   //the new last now points to nullptr
            count--;                //count decrements
            return temp;            //return the info that was in the last node
        }
    }
    unsigned unshift(T info){
        auto node = new Node<T>(info, first, nullptr);

        if(first){
            first->prev = node;
            first = node;
        } else {
            last = first = node;
        }
        count++;
        return count;
    }
    unsigned unshift(const std::initializer_list<T>& lst){
        //This for loop should iterate through the list in reverse, so the first item in the list is added to the front last
        for(auto it = std::rbegin(lst); it != std::rend(lst); ++it){
            unshift(*it);
        }
        return count;
    }
    T shift(){
        if(count == 0){throw std::runtime_error("There are no items in the array to remove");}
        if(count == 1){
            T temp = first->info;
            delete first;
            last = first = nullptr;
            count--;
            return temp;
        } else {
            T temp = first->info;
            auto node = first;
            first = first->next;
            delete node;
            first->prev = nullptr;
            count--;
            return temp;
        }
    }
    void concat(const LinkedArray<T>& la){
        for(LinkedListIterator<T> it(la.first); it != nullptr; ++it){
            push(*it);
        }
    }
    LinkedListIterator<T> find(T info){
        auto current = first;
        while(current){
            if(current->info == info){
                return LinkedListIterator<T>(current);
            }

            current = current->next;
        }
        return LinkedListIterator<T>(nullptr);
    }
    friend std::ostream& operator<<(std::ostream& sprout, LinkedArray<T>& la){
        auto current = la.first;
        while(current){
            sprout << current->info;
            current = current->next;
            if(current){    //This ensures the last number doesn't have a comma after it
                sprout << ",";
            }
        }
        return sprout;
    }
    bool empty() const{
        return first == nullptr;
    }
    unsigned length() const{
        return count;
    }
    LinkedListIterator<T> begin(){return LinkedListIterator<T>(first);}
    LinkedListIterator<T> end(){return LinkedListIterator<T>(nullptr);}
    
    ~LinkedArray() {
        removeAll();
    }

};


#endif
