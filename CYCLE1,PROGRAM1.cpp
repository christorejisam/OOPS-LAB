//CHRISTO REJI SAM
//CYCLE 1
//Program 1:  A phone number, such as (212) 767-8900, can be thought of as having three parts:  the area code (212), the exchange (767), and the number (8900). Write a C++ program that uses a structure to store these three parts of a phone number separately. Call the  structure phone. Create two structure variables of type phone. Initialize one, and have the user input a number for the other one. Then display both numbers. The interchange might look like this:
//Enter your area code, exchange, and number: 415 555 1212
//My number is (212) 767-8900
//Your number is (415) 555-1212

//PROGRAM

#include<iostream>
using namespace std;
struct Phone {
    int area_code, exchange, number;
} p1, p2;
int main() {
    p1.area_code = 212;
    p1.exchange = 767;
    p1.number = 8900;
    cout<<"\n Enter your area code, exchange and number : \n";
    cin>>p2.area_code>>p2.exchange>>p2.number;
    cout<<"\n My number is ("<<p1.area_code<<") " << p1.exchange << "-" << p1.number;
    cout<<"\n Your number is ("<<p2.area_code<<") "<<p2.exchange<<"-"<<p2.number;
    return 0;                                                                                                                                                                                     }
