#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include <iostream>
#include <stdexcept>
#include <cmath>

template<typename T>
struct Cell {
  T info;
  int priority = 0;
};

template<typename T>
class PriorityQueue {
  private:
    int Size;
    int capacity;
    bool minimum_first;
    Cell<T> *cells;

  public:
    PriorityQueue(bool minimum_first = false): Size(0), capacity(8), minimum_first(minimum_first), cells(new Cell<T>[8]){}
    
    //Copy Constructor
    PriorityQueue(const PriorityQueue<T> &q): Size(q.size()), capacity(q.capacity), minimum_first(q.minimum_first), cells(new Cell<T>[q.capacity]) {
        for(int i = 0; i<size(); i++){
            cells[i] = q.cells[i];
        }
    }

    //Copy Assignment
    PriorityQueue<T>& operator=(const PriorityQueue<T>& c){
        delete[] cells;
        Size = c.size();
        capacity = c.capacity;
        cells = new Cell<T>[capacity];
        for(int i = 0; i<size(); i++){
            cells[i] = c.cells[i];
        }

        //Sorting the freshly copied cells
        buildHeap(!minimum_first);
        for(int i = size() - 1; i > 0; i--){
          swap(0, i);
          heapify(0, i, !minimum_first);
        }

        return *this;
    }

    bool full() const{
      return size() == capacity;
    }

    bool empty() const{
      return size() == 0;
    }

    int size() const{
      return Size;
    }

    //Function to add cells
    void enqueue(T e, int p){
        //Code to increase capacity if needed
        if(size() == capacity){
            Cell<T> *newCells = new Cell<T>[2 * capacity];

            for(int j = 0; j<size(); j++){
                newCells[j] = cells[j];
            }
            capacity *= 2;
            delete[] cells;
            cells = newCells;
        }

        //Adding new cell
        Cell<T> temp;
        temp.info = e;
        temp.priority = p;
        cells[Size++] = temp;

        //Sorting queue
        buildHeap(!minimum_first);
        for(int i = size() - 1; i > 0; i--){
          swap(0, i);
          heapify(0, i, !minimum_first);
        }
    }

    //Function to remove the last item on the list
    T dequeue(){
        if(empty()){
          throw std::runtime_error("The queue is empty");
        }
        
        //Switching the first cell with the last, then deleting the last one
        T temp = cells[0].info;
        cells[0] = cells[size()-1];
        Size--;

        //Sorting the queue
        buildHeap(!minimum_first);
        for(int i = size() - 1; i > 0; i--){
          swap(0, i);
          heapify(0, i, !minimum_first);
        }

        //heapify(0, size()-1, minimum_first);

        return temp;
    }

    T peek() const {
      if(empty()){
        throw std::runtime_error("The queue is empty");
      }
      return cells[0].info;
    }

    //Destructor
    ~PriorityQueue(){
        delete[] cells;
        cells = nullptr;
    }

  protected:
    void buildHeap(bool reversed){
      for(int i = size() / 2 - 1; i >= 0; i--){
          heapify(i, size(), reversed);
      }
    }

    void heapify(int p, int hsz, bool reversed){
      int left = 2 * p + 1;
      int right = left + 1;
      int largest = p;
      if(left < hsz && lessOrGreaterThan(p, left, reversed)){
          largest = left;
      }

      if(right < hsz && lessOrGreaterThan(largest, right, reversed)){
          largest = right;
      }

      if(largest != p){
          swap(p, largest);
          heapify(largest, hsz, reversed);
      }
    }

    virtual bool lessOrGreaterThan(int i, int j, bool reversed){
      return (reversed && cells[i].priority > cells[j].priority) || (!reversed && cells[i].priority < cells[j].priority);
    }

    virtual void swap(int i, int j){
      Cell<T> tmp = cells[i];
      cells[i] = cells[j];
      cells[j] = tmp;
    }

};
#endif