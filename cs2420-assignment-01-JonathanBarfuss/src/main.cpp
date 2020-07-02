//TODO: main method goes here
#include <iostream>
#include "range.h"
#include <vector>
using namespace std;

int main(){

//--------------First testing an integer range with input from the console----------------------
    cout << "Integer range with input from the console" << endl;
    int x;
    int y;
    int z;
    int w;

    //Input
    cout << "Enter your first integer: " << endl;
    cin >> x;
    cout << "Enter your second integer: " << endl;
    cin >> y;
    cout << "Enter the step: " << endl;
    cin >> z;
    cout << "Enter a value you wish to see is in the range: " << endl;
    cin >> w;

    Range<int> first(x,y,z);
    vector<int> firstVector = first.values();

    //Results
    cout << "The length of the range is " << first.length() << endl;
    cout << "The sum of all the numbers is " << first.sum() << endl;
    cout << "The average of all the numbers is " << first.average() << endl;
    cout << "The max value is " << first.max() << endl;
    cout << "The min value is " << first.min() << endl;
    if(first.contains(w)){
        cout << "The range has the value " << w << endl;
    }
    else{
        cout << "The range does not have the value " << w << endl;
    }
    cout << "The values in the range are " << first << endl;
    cout << "The values in the newly created vector list are ";
    for(int i=0; i<firstVector.size();i++){
        cout << firstVector.at(i) << " ";
    }
    cout << endl;

//----------------Second testing a double range (without input from the console)--------------
    cout << endl << "Double range without input from the console" << endl;
    Range<double> second(25.466,21,-0.502);
    vector<double> secondVector = second.values();

    //Results
    cout << "The length of the range is " << second.length() << endl;
    cout << "The sum of all the numbers is " << second.sum() << endl;
    cout << "The average of all the numbers is " << second.average() << endl;
    cout << "The max value is " << second.max() << endl;
    cout << "The min value is " << second.min() << endl;
    if(second.contains(24.464)){
        cout << "The range has the value 24.464" << endl;
    }
    else{
        cout << "The range does not have the value 24.464" << endl;
    }
    cout << "The values in the range are " << second << endl;
    cout << "The values in the newly created vector list are ";
    for(int i=0; i<secondVector.size();i++){
        cout << secondVector.at(i) << " ";
    }
    cout << endl;

//----------------------Third testing a float range (without input from the console)---------------------------
    cout << endl << "Float range without input from the console" << endl;
    Range<float> third(20.8,100,9.2);
    vector<float> thirdVector = third.values();

    //Results
    cout << "The length of the range is " << third.length() << endl;
    cout << "The sum of all the numbers is " << third.sum() << endl;
    cout << "The average of all the numbers is " << third.average() << endl;
    cout << "The max value is " << third.max() << endl;
    cout << "The min value is " << third.min() << endl;
    if(third.contains(100)){
        cout << "The range has the value 100" << endl;
    }
    else{
        cout << "The range does not have the value 100" << endl;
    }
    cout << "The values in the range are " << third << endl;
    cout << "The values in the newly created vector list are ";
    for(int i=0; i<thirdVector.size();i++){
        cout << thirdVector.at(i) << " ";
    }
    cout << endl;

    return 0;
}