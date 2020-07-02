#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include "bst.h"

using namespace std;

/* PART 3: the main function */
int main(){
  
  //Loading binary search tree
  BinarySearchTree<char> alphabet;
  alphabet.insert('M');
  alphabet.insert('F');
  alphabet.insert('S');
  alphabet.insert('C');
  alphabet.insert('I');
  alphabet.insert('P');
  alphabet.insert('W');
  alphabet.insert('A');
  alphabet.insert('D');
  alphabet.insert('G');
  alphabet.insert('K');
  alphabet.insert('N');
  alphabet.insert('Q');
  alphabet.insert('U');
  alphabet.insert('Y');
  alphabet.insert('B');
  alphabet.insert('E');
  alphabet.insert('H');
  alphabet.insert('J');
  alphabet.insert('L');
  alphabet.insert('O');
  alphabet.insert('R');
  alphabet.insert('T');
  alphabet.insert('V');
  alphabet.insert('X');
  alphabet.insert('Z');

  //Printing tree
  alphabet.inorderTraversal(showTree);

  //Loading arrays
  Node<char>* ascending;
  Node<char>* descending;
  alphabet.toSortedArray(ascending);
  alphabet.toSortedArray(descending, true);

  //Printing arrays
  for(int i = 0; i < alphabet.size(); i++){
    cout << ascending[i].info << " ";
  }
  cout << endl;
  for(int i = 0; i < alphabet.size(); i++){
    cout << descending[i].info << " ";
  }
  cout << endl;

  return 0;
}
