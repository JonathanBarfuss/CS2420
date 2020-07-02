#include <iostream>
#include <chrono>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <random>
#include "linked_list.h"
#include "bag.h"

using namespace std;
using namespace chrono;

char random(char min, char max){
    static default_random_engine en;
    static uniform_int_distribution dist {min, max};
    return dist(en);
}

int main(){
  //Generating lists and bags---------------------------------------------------------------------------------------
  List<char> orderedList;
  List<char> randomList;
  
  orderedList.add_back('a').add_back('b').add_back('c').add_back('d').add_back('e').add_back('f').add_back('g');

  for(int i = 0; i<7; i++){
    randomList.add_back(random('a', 'z'));
  }

  Bag<char> orderedBag;
  Bag<char> randomBag;
  orderedBag.add('a');
  orderedBag.add('b');
  orderedBag.add('c');
  orderedBag.add('d');
  orderedBag.add('e');
  orderedBag.add('f');
  orderedBag.add('g');

  for(int i = 0; i<4; i++){
    orderedBag.add(random('a','z'));
  }

  Bag<char> arraySortedBubble(orderedBag);
  Bag<char> arraySortedSelection(orderedBag);
  Bag<char> arraySortedInsertion(orderedBag);
  Bag<char> arrayRandomBubble(randomBag);
  Bag<char> arrayRandomSelection(randomBag);
  Bag<char> arrayRandomInsertion(randomBag);
  Bag<char> arrayReveresedBubble(orderedBag);
  Bag<char> arrayReveresedSelection(orderedBag);
  Bag<char> arrayReveresedInsertion(orderedBag);

  List<char> listSortedBubble(orderedList);
  List<char> listSortedSelection(orderedList);
  List<char> listSortedInsertion(orderedList);
  List<char> listRandomBubble(randomList);
  List<char> listRandomSelection(randomList);
  List<char> listRandomInsertion(randomList);
  List<char> listReveresedBubble(orderedList);
  List<char> listReveresedSelection(orderedList);
  List<char> listReveresedInsertion(orderedList);

  //Testing------------------------------------------------------------------------------------------------
  
//Sorted arrays
  auto start = high_resolution_clock::now();
  arraySortedBubble.sortByBubble();
  auto end = high_resolution_clock::now();
  duration<double, nano> arraySortedBubbleRunningTime = end - start;

  start = high_resolution_clock::now();
  arraySortedSelection.sortBySelection();
  end = high_resolution_clock::now();
  duration<double, nano> arraySortedSelectionRunningTime = end - start;

  start = high_resolution_clock::now();
  arraySortedInsertion.sortByInsertion();
  end = high_resolution_clock::now();
  duration<double, nano> arraySortedInsertionRunningTime = end - start;

//Random arrays
  start = high_resolution_clock::now();
  arrayRandomBubble.sortByBubble();
  end = high_resolution_clock::now();
  duration<double, nano> arrayRandomBubbleRunningTime = end - start;

  start = high_resolution_clock::now();
  arrayRandomSelection.sortBySelection();
  end = high_resolution_clock::now();
  duration<double, nano> arrayRandomSelectionRunningTime = end - start;      

  start = high_resolution_clock::now();
  arrayRandomInsertion.sortByInsertion();
  end = high_resolution_clock::now();
  duration<double, nano> arrayRandomInsertionRunningTime = end - start; 

//Reveresed arrays
  start = high_resolution_clock::now();
  arrayReveresedBubble.sortByBubble(true);
  end = high_resolution_clock::now();
  duration<double, nano> arrayReveresedBubbleRunningTime = end - start; 

  start = high_resolution_clock::now();
  arrayReveresedSelection.sortBySelection(true);
  end = high_resolution_clock::now();
  duration<double, nano> arrayReveresedSelectionRunningTime = end - start; 

  start = high_resolution_clock::now();
  arrayReveresedInsertion.sortByInsertion(true);
  end = high_resolution_clock::now();
  duration<double, nano> arrayReveresedInsertionRunningTime = end - start; 

//Sorted lists
  start = high_resolution_clock::now();
  listSortedBubble.sortByBubble();
  end = high_resolution_clock::now();
  duration<double, nano> listSortedBubbleRunningTime = end - start;

  start = high_resolution_clock::now();
  listSortedSelection.sortBySelection();
  end = high_resolution_clock::now();
  duration<double, nano> listSortedSelectionRunningTime = end - start;

  start = high_resolution_clock::now();
  listSortedInsertion.sortByInsertion();
  end = high_resolution_clock::now();
  duration<double, nano> listSortedInsertionRunningTime = end - start;

//Random lists
  start = high_resolution_clock::now();
  listRandomBubble.sortByBubble();
  end = high_resolution_clock::now();
  duration<double, nano> listRandomBubbleRunningTime = end - start;

  start = high_resolution_clock::now();
  listRandomSelection.sortBySelection();
  end = high_resolution_clock::now();
  duration<double, nano> listRandomSelectionRunningTime = end - start;      

  start = high_resolution_clock::now();
  listRandomInsertion.sortByInsertion();
  end = high_resolution_clock::now();
  duration<double, nano> listRandomInsertionRunningTime = end - start; 

//Reveresed lists
  start = high_resolution_clock::now();
  listReveresedBubble.sortByBubble(true);
  end = high_resolution_clock::now();
  duration<double, nano> listReveresedBubbleRunningTime = end - start; 

  start = high_resolution_clock::now();
  listReveresedSelection.sortBySelection(true);
  end = high_resolution_clock::now();
  duration<double, nano> listReveresedSelectionRunningTime = end - start; 

  start = high_resolution_clock::now();
  listReveresedInsertion.sortByInsertion(true);
  end = high_resolution_clock::now();
  duration<double, nano> listReveresedInsertionRunningTime = end - start; 

  //Printing----------------------------------------------------------------------------

  cout << setw(40) << "1 - Array-based Report" << endl;
  cout << setw(15) << " " << setw(15) << "Sorted" << setw(15) << "Random" << setw(15) << "Reversed" << endl;
  cout << setw(15) << "Bubble" << setw(15) <<  arraySortedBubbleRunningTime.count() << setw(15) <<  arrayRandomBubbleRunningTime.count() << setw(15) <<  arrayReveresedBubbleRunningTime.count() << endl;
  cout << setw(15) << "Selection" << setw(15) <<  arraySortedSelectionRunningTime.count() << setw(15) <<  arrayRandomSelectionRunningTime.count() << setw(15) <<  arrayReveresedSelectionRunningTime.count() << endl;
  cout << setw(15) << "Insertion" << setw(15) <<  arraySortedInsertionRunningTime.count() << setw(15) <<  arrayRandomInsertionRunningTime.count() << setw(15) <<  arrayReveresedInsertionRunningTime.count() << endl;
  
  cout << setw(40) << "2 - Linked-list-based Report" << endl;
  cout << setw(15) << " " << setw(15) << "Sorted" << setw(15) << "Random" << setw(15) << "Reversed" << endl;
  cout << setw(15) << "Bubble" << setw(15) <<  listSortedBubbleRunningTime.count() << setw(15) <<  listRandomBubbleRunningTime.count() << setw(15) <<  listReveresedBubbleRunningTime.count() << endl;
  cout << setw(15) << "Selection" << setw(15) <<  listSortedSelectionRunningTime.count() << setw(15) <<  listRandomSelectionRunningTime.count() << setw(15) <<  listReveresedSelectionRunningTime.count() << endl;
  cout << setw(15) << "Insertion" << setw(15) <<  listSortedInsertionRunningTime.count() << setw(15) <<  listRandomInsertionRunningTime.count() << setw(15) <<  listReveresedInsertionRunningTime.count() << endl;


  return 0;
}