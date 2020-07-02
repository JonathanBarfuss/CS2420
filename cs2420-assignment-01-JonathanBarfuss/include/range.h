//TODO: Class Range defined
#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Range{
    private:
//Variables
        T start;
        T end;
        T step;
        vector<T> nums;        //nums for "numbers"

    public:
//Initializer
        Range(T s, T e, T st = 1) : start(s), end(e), step(st) {
            //The vector is created at initializatoin
            T x = s;
            if(st>0){       //If statement is to check if the step is going up or down
                while(x<=e){
                    nums.push_back(x);
                    x += st;
                }
            }
            else{
                while(x>=e){
                nums.push_back(x);
                x += st;
                }
            }
        }

//Functions
        int length(){
            return nums.size();
        }
        T sum(){
            T x = 0;
            for(int i = 0; i < nums.size(); i++){
                x += nums[i];
            }
            return x;
        }
        T average(){
            return sum()/nums.size();
        }
        T max(){
            //If the step is positive, the last value is the highest. If the step is negative, the first value is highest.
            if (step > 0){
                //return nums[nums.size()-1];
                return nums.back();
            }
            else{
                return nums.front();
            }
        }
        T min(){
            //If the step is negative, the last value is the lowest. If the step is positive, the first value is the lowest.
            if (step < 0){
                //return nums[nums.size()-1];
                return nums.back();
            }
            else{
                return nums.front();
            }
        }
        vector<T> values(){
            return nums;
        }
        bool contains(T x){
            bool maybe = 0;
            //This for loop checks the number against every value in the vector. If it equivalent to any value, it will return true
            for(int i = 0; i < nums.size(); i++){
                if (x == nums[i])
                    maybe = 1;
            }
            return maybe;
        }
        friend ostream& operator<<(ostream& shout, Range& r){
            //This loop prints a step and two spaces to memory, for every step
            for(int i = 0; i < r.nums.size(); i++){
                shout << r.nums[i] << "  ";
            }
            return shout;
        }

};