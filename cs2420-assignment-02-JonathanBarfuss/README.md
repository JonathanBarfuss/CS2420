# Assignment 2
Refactoring a date class to refresh students' C++ knowledge and skills.


In this assignment the professor provided a portion of the code in "include/date.h" and my job was to do the following:

-Add a second constructor that takes only a single year argument and initializes both month and day to 1.

-Add a third constructor that takes two arguments for year and month and initializes day to 1.

-Overload operator+ such that given a date object d, the expression d + n is the same as d.addDays(n) where n is the number of days to add.

-Complete the implementation of the str() function which returns a string representation of the date object in the format "Mon, day, year" For example, given a date object Date* d 
= new Date(2018, 9, 10), the call d->str() returns the string "Sep 10, 2018".

-Overload operator<< using a friend function, such that given a data object d, a statement like cout << d; is valid and prints to the console the string representation returned by d.str().

-Complete the implementation of the static function format() by returning a string representation of the date that matches the given pattern. This function should support the following three patterns mm/dd/yyyy (as in 05/14/2019), dd/mm/yyyy (as in 14/05/2019), yyyy/mm/dd (as in 2019/05/14).  For any other pattern, it should return "Not Supported".

-Create a main function to test the functions in the date class
