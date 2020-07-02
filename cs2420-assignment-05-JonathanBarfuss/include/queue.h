#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "stack.h"

template <typename T>
class Queue {
public:
  virtual bool full() const = 0;
  virtual bool empty() const = 0;
  virtual void enqueue(T e) = 0;
  virtual T peekFront() const = 0;
  virtual T peekBack() const = 0;
  virtual void dequeue() = 0;
  virtual ~Queue(){}
};

template <typename T>
class LinkedQueue : public Queue<T> {
public:
  LinkedQueue();
  LinkedQueue(const LinkedQueue<T>& q);
  LinkedQueue<T>& operator=(const LinkedQueue<T>& q);
  bool full() const;
  bool empty() const;
  void enqueue(T e);
  T peekFront() const;
  T peekBack() const;
  void dequeue();
  ~LinkedQueue();

private:
  Node<T>* front;
  Node<T>* back;
  LinkedQueue<T>& copy(const LinkedQueue<T>& q);
  void destroy();
};

// Implemenation
template <typename T>
LinkedQueue<T>::LinkedQueue(): front(nullptr), back(nullptr){}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& q){
  copy(q);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& q){
  destroy();
  return copy(q);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::copy(const LinkedQueue<T>& q){
  front = nullptr;
  back = nullptr;
  auto current = q.front;
  while(current){
    auto newNode = new Node<T>(current->info);
    if(front == nullptr){ // empty list
      front = newNode;
    } else {
      back->next = newNode;
    }
    back = newNode;
    current = current->next;
  }

  return *this;
}

template <typename T>
void LinkedQueue<T>::destroy(){
  auto current = front;
  while(current){
    auto temp = current;
    current = current->next;
    delete temp;
  }
}

template <typename T>
bool LinkedQueue<T>::full() const{
  return false;
}

template <typename T>
bool LinkedQueue<T>::empty() const{
  return front == nullptr;
}

template <typename T>
void LinkedQueue<T>::enqueue(T e){
  auto node = new Node<T>(e);
  if(front == nullptr){
    front = node;
  }else{
    back->next = node;
  }

  back = node;
}

template <typename T>
T LinkedQueue<T>::peekFront() const {
  if(empty()){
    throw std::runtime_error("Queue is empty");
  }
  return front->info;
}

template <typename T>
T LinkedQueue<T>::peekBack() const {
  if(empty()){
    throw std::runtime_error("Queue is empty");
  }
  return back->info;
}

template <typename T>
void LinkedQueue<T>::dequeue(){
  if(empty()){
    throw std::runtime_error("Queue is empty");
  }

  auto tmp = front;
  front = front->next;
  delete tmp;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
  destroy();
}

#endif