#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Date {
public:
  //Initializers
  Date(int y): year(y), month(1), day(1){}

  Date(int y, int m): year(y), month(m), day(1){}

  Date(int y, int m, int d): year(y), month(m), day(d){}

  //Functions
  Date& addMonths(int n){
    year  += (month + n) / 12;
    month = (month + n) % 12;
    return *this;
  }

  Date& addDays(int n) {
    int d = daysToDate() + n;
    int y = year, m = 1;
    while(d > daysInMonth(y, m)){
      d -= daysInMonth(y, m);
      m++;
      if(m > 12){
        m = 1;
        y++;
      }
    }
    day = d;
    month = m;
    year = y;

    return *this;
  }

  static bool isLeapYear(int y) {
    return (y % 4 || (y % 100 == 0 && y % 400)) ? false : true;
  }

  std::string str() {
    //Added an array of the names of each month
    std::string mnames[12] {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return mnames[month - 1] + " " + std::to_string(day) + ", " + std::to_string(year);
  }

  int daysToDate(){
    int days_in_month[]{31, isLeapYear(year) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    for(int m = 0; m < month - 1; m++){
      days += days_in_month[m];
    }
    days += day;
    return days;
  }

  Date operator+(int n){  //Copied code from addDays()
    int d = daysToDate() + n;
    int y = year, m = 1;
    while(d > daysInMonth(y, m)){
      d -= daysInMonth(y, m);
      m++;
      if(m > 12){
        m = 1;
        y++;
      }
    }
    day = d;
    month = m;
    year = y;

    return *this;
  }

  friend std::ostream& operator<<(std::ostream& pout, Date& d){
    pout << d.str();
    return pout;
  }

  static std::string format(std::string pattern, const Date& d){
    //Converting int to string
    std::string dayf = std::to_string(d.day);
    std::string monthf = std::to_string(d.month);
    std::string yearf = std::to_string(d.year);

    //This formats days and months properly to have zeroes if they are only 1 digit
    if (d.day<10){
      dayf = "0" + dayf;
    }
    if(d.month<10){
      monthf = "0" + monthf;
    }
    
    //Returns string based off of inputed format
    if (pattern == "mm/dd/yyyy"){
      return monthf + "/" + dayf + "/" + yearf;
    } 
    else if(pattern == "dd/mm/yyyy"){
      return dayf + "/" + monthf + "/" + yearf;
    }
    else if(pattern == "yyyy/mm/dd"){
      return yearf + "/" + monthf + "/" + dayf;
    }
    else{
      return "Not supported";
    }


  }

private:
  int year, month, day;

  static int daysInMonth(int y, int m){
    int days_in_month[]{31, isLeapYear(y) ? 29 : 28, 31,
                        30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[m - 1];
  }
};

#endif