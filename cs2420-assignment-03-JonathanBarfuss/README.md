# Assignment 3
Created a template dynamic array (bag) that grows when items are added.

The assignment provided the following description:
"In this assignment, you are given an implementation of a Bag class (include/bag.h) which manages a dynamic array of items that can grow as more items are added. 

First, you are asked to add the following to the Bag<> class in file include/bag.h.

Overload operator+ such that given a bag b, the expression b + n is the same as b.add(n) where n is an item to add to bag b.
Overload the prefix operator-- such that given a bag b, the expression --b is the same as calling b.remove() to remove the last item in the bag. 
Overload operator- such that given a bag b, the expression b - n is the same as calling b.remove() to remove the last n items in the bag. 
Overload operator<< using a friend function, such that given a bag b, a statement like cout << b; is valid and prints to the console a space-separated list of items in the bag.

Secondly, in a file named include/safe_bag.h, create a template class named SafeBag<> that inherits from Bag<> and override the remove() function so as to throw an std::runtime_error if its size is 0. It also should override the operator[] functions to throw an std::runtime_error when the given index is < 0 or > size. This class should also have three constructors each matching and calling a corresponding  Bag<> constructor.

Similarly, in a file named include/sorted_bag.h. create a template class named SortedBag<> that inherits from SafeBag<>. This class should override the add() function such that when an item is added to the bag it's added in its correct order in the bag. For example, if add(19) is called a bag with the existing items of 2, 7, 8, 21, 30, 55, the value 19 will be added in its place between 8 and 21. This class should also have three constructors each matching and calling a corresponding  SafeBag<> constructor.

Finally, inside the src/main.cpp file, write a main() function that uses the std::make_unique() function to create multiple SortedBag<> objects and test every function or operator in them."
