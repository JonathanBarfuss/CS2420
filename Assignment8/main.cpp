#include <iostream>
#include <string>
#include "priority_queue.h"
using namespace std;

int main(){
  
  //Creating and populating base queue
  PriorityQueue<string> practice;
  practice.enqueue("Captain America: Winter Soldier", 10);
  practice.enqueue("Avengers: Endgame", 8);
  practice.enqueue("Star Wars: Rogue One", 9);
  practice.enqueue("Star Wars: Revenge of the Sith", 7);
  practice.enqueue("Harry Potter and the Half Blood Prince", 5);
  practice.enqueue("The Lord of the Rings: The Two Towers", 3);
  practice.enqueue("A Monster Calls", 2);
  practice.enqueue("Knight and Day", 1);
  practice.enqueue("A Princess Bride", 6);
  practice.enqueue("Harry Potter and the Order of the Pheonix", 4);

  //Filling max and min queues
  PriorityQueue<string> max = practice;
  PriorityQueue<string> min(true);
  min = practice;

  //Output
  cout << "My favorite movies from most favorite to least:" << endl;
  for(int i = 0; i < 10; i++){
    cout << max.dequeue() << endl;
  }
  cout << endl;

  cout << "My favorite movies from least favorite to most:" << endl;
  for(int i = 0; i < 10; i++){
    cout << min.dequeue() << endl;
  }

  return 0;
}