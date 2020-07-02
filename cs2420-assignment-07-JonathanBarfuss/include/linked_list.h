#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_
#include <initializer_list>

template<typename T>
struct Node {
  T info;
  Node<T>* next;
  Node<T>* prev;

  Node(T info): info(info), next(nullptr), prev(nullptr){}
  Node(T info, Node<T>* nxt, Node<T>* prv): info(info), next(nxt), prev(prv){}
};

template<typename T>
class ListIterator {
private:
  Node<T>* current = nullptr;
public:
  ListIterator(Node<T>* node): current(node){}
  T operator*(){
    return current->info;
  }
  ListIterator<T>& operator++(){
    current = current->next;
    return *this;
  }

  bool operator==(const ListIterator<T>& rhs) const {
    return current == rhs.current;
  }

  bool operator!=(const ListIterator<T>& rhs) const {
    return current != rhs.current;
  }

  operator bool() const{
    return current;
  }

  //Getter function
  Node<T>* getNode() const{
    return current;
  }
};

template<typename T>
class List {
public:
  List(){}
  List(const List<T>& lst) {
    Node<T>* current = lst.front;
    while(current){
      add_back(current->info);
      current = current->next;
    }
  }

  List(const std::initializer_list<T>& lst){
    for(auto it = lst.begin(); it != lst.end(); ++it){
      add_back(*it);
    }
  }

  List<T>& operator=(const List<T>& lst) {
    removeAll();
    auto current = lst.front;
    while(current){
      add_back(current->info);
      current = current->next;
    }

    return *this;
  }

  List<T>& add_back(T info){
    auto node = new Node<T>(info, nullptr, back);
    if(back){ 
      back->next = node;
      back = node;
    }else{
      front = back = node;
    }

    sz++;
    return *this;
  }

  List<T>& add_front(T info){
    auto node = new Node<T>(info, front, nullptr);
    if(front){
      front->prev = node;
      front = node;
    } else {
      back = front = node;
    }

    sz++;
    return *this;
  }

  bool remove_front(){
    if(front == back){
      if(!front){
        return false;
      }

      delete front;
      front = back = nullptr;
    } else{
      auto tmp = front;
      front = front->next;
      front->prev = nullptr;
      delete tmp;
    }

    sz--;
    return true;
  }

  bool remove_back(){
    if(front == back){
      if(!front){
        return false;
      }

      delete back;
      front = back = nullptr;
    } else{
      auto pred = back->prev;
      pred->next = nullptr;

      delete back;
      back = pred;
    }

    sz--;
    return true;
  }

  bool remove(T info){
    if(!front){
      return false;
    }else if(front->info == info){
      auto tmp = front;
      front = front->next;
      front->prev = nullptr;
      delete tmp;
      sz--;
      return true;
    } else {
      auto current = front->next;
      while(current){
        if(current->info == info){

          if(current == back){
            back = current->prev;
          } else {
            current->next->prev = current->prev;
          }
            
          current->prev->next = current->next;
          delete current;
          sz--;
          return true;
        }

        current = current->next;
      }
    }

    return false;
  }

  ListIterator<T> find(T info){
    auto current = front;
    while(current){
      if(current->info == info){
        return ListIterator<T>(current);
      }

      current = current->next;
    }

    return ListIterator<T>(nullptr);
  }

  ListIterator<T> begin(){return ListIterator<T>(front); }
  ListIterator<T> end(){return ListIterator<T>(back->next); }

  friend std::ostream& operator<<(std::ostream& out,  const List<T>& lst){
    auto current = lst.front;
    while(current){
      out << current->info << " ";

      current = current->next;
    }

    return out;
  }
  bool empty() const { return sz == 0; }
  unsigned size() const { return sz; }
  void clear(){ removeAll(); }

  void sortByBubble(bool reversed = false){
    for(int i = 0; i <= sz*sz; i++){
      //Since linkedLists don't have index numbers, it had to be iterated through instead
      Node<T>* p = front->next;
      for(int j = 1; j < sz; j++){
        if(lessOrGreaterThan(p, p->prev, reversed)){
          swap(p, p->prev);
        }
        //Iterating
        p = p->next;
      }
    }
  }

  void sortBySelection(bool reversed = false){
    Node<T>* p = front;
    Node<T>* min; //To keep track of what just took the minimum place
    for(int i = 0; i < sz-1; i++){
      swap(p, min = minOrMaxInRange(p, back, reversed));
      p = min->next;
    }
  }

  void sortByInsertion(bool reversed = false){
    Node<T>* inode = front->next;
    for(int i = 1; i < sz; i++){
      int count = 0;
      Node<T>* jnode = inode;
      while(jnode->prev != nullptr && lessOrGreaterThan(jnode, jnode->prev, reversed)){
        if(count < 1) {inode = jnode->prev;}
        swap(jnode, jnode->prev);
        count++;
      }
      inode = inode->next;
    }
  }

  ~List(){
    removeAll();
  }

protected:
  unsigned sz = 0;
  Node<T>* front = nullptr;
  Node<T>* back = nullptr;

  void swap(Node<T>* a, Node<T>* d){
    bool f = false;
    bool b = false;

  //I broke swap into 4 scenarios: If a is right before d, if a is right after d, if a equals d, and if a is seperated from d

    if(a->prev == d){
      //Step 1
      if(a != back){      //In case these are the last 2 nodes
        a->next->prev = d;
      } else{
        back = d;
      }
      //Step 2
      d->next = a->next;
      //Step 3
      if(d != front){     //In case these are the first 2 nodes
        d->prev->next = a;
      } else{
        front = a;
      }
      //Steps 4-6
      a->prev = d->prev;
      d->prev = a;
      a->next = d;
    } else if (d->prev == a){
      //Step 1
      if(d != back){      //In case these are the last 2 nodes
        d->next->prev = a;
      } else{
        back = a;
      }
      //Step 2
      a->next = d->next;
      //Step 3
      if(a != front){     //In case these are the first 2 nodes
        a->prev->next = d;
      } else{
        front = d;
      }
      //Steps 4-6
      d->prev = a->prev;
      a->prev = d;
      d->next = a;
    }else if (d == a){
      return;
    } else {
      //Step 1
      if(a == back) {
        back = d;
        b = true;
      } else{
        a->next->prev = d;
      }
      //Step 2
      if(a == front){
        front = d;
        f = true;
      } else {
        a->prev->next = d;
      }
      //Step 3
      if(d == front && !f){
        front = a;
      } else {
        d->prev->next = a;
      }
      //Step 4
      if(d == back && !b){
        back = a;
      } else {
        d->next->prev = a;
      }
      //Step 5
      Node<T>* tempd = d->next;
      d->next = a->next;
      a->next = tempd;
      //Step 6
      Node<T>* tempa = a->prev;
      a->prev = d->prev;
      d->prev = tempa;

    }


  }

  bool lessOrGreaterThan(Node<T>* i, Node<T>* j, bool reversed = false){
    return (!reversed && i->info < j->info) || (reversed && i->info > j->info);
  }

  Node<T>* minOrMaxInRange(Node<T>* begin, Node<T>* end, bool reversed = false){
    Node<T>* minOrMax = begin;
    Node<T>* present = begin->next;
    do{
        if(lessOrGreaterThan(present, minOrMax, reversed)){
            minOrMax = present;
        }
        present = present->next;
    }while(present != end->next);

    return minOrMax;
  }
  
  void removeAll(){
    auto current = front;
    while(current){
      auto tmp = current;
      current = current->next;
      delete tmp;
    }

    front = nullptr;
    back = nullptr;
    sz = 0u;
  }
};

#endif
