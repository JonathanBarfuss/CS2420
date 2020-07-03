Assignment 10.

The assignment provided the following description:

"A dictionary is a template data structure used to store a collection of pairs. Each pair has a key and a value (Think of a word and its meaning as a pair). Keys must be unique, but several keys can map to the same value. A dictionary data structure has the two template types (K for keys and V for values)

Implement the Pair<K,V> data structure which has two template data members: key (of type K) and value (of type V). Overload the <, >,  and == operators such that two pairs are equal if their keys are equal and a pair u is < another pair v if u.key < v.key. The same goes for the > operator. Finally, implement the operator<< using a friend function. 

Implement the Dictionary class using the given AVLTree class and the Pair<K,V> structure from Part 1. More specifically, create a class named Dictionary that privately inherits from AVLTree. Such private inheritance makes all the public and protected members of the AVLTree class available inside the Dictionary class as private members. Finally, implement the operator<< using a friend function that calls the in-order traversal function of the AVLTree.

In your main function, use this Dictionary class to store and print the codes and names of all 50 states of the USA, with the two-letter code as the key and the full name as the value."
