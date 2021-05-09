// CHRISTO REJI SAM
// CYCLE 1
//Program 2: Define a class Date that contains details like year, month and  date. Write a C++ program to check the validity of the date that you enter and display the next date. Sample 1 : 02/ 03/ 1990
//Valid, Next date: 03/03/1990
//Sample 2: 29/02/1989 Not Valid

//PROGRAM

#include<iostream>
using namespace std;
class Date {
  private:
      int year, month, day;
      int leap = 0;
 public:
        void input() {
            cout<<"\n Enter the day: ";
            cin>>day;
            cout<<"\n Enter the month: ";
            cin>>month;
            cout<<"\n Enter the year: ";
            cin>>year;
        }
        int validate() {
            if ( day > 31 || month > 12 || day <= 0 || month <= 0 || year < 0)
return 0;
            else if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) {
                 if ( day > 31 )
                     return 0;
                 else
                     return 1;
             } else {
                if ( month == 2) {
                   if (year % 4 == 0) {
                      if ( year % 400 == 0) {
                          leap = 1;
                          if ( day > 29 )
                              return 0;
                          else
                              return 1;
                      } else if ( year % 100 == 0) {
                         leap = 0;
                         if ( day > 28 )
                             return 0;
                         else
                                return 1;
               } else {
                           leap = 1;
                           if ( day > 29 )
                                return 0;
                            else
                                return 1;
                     }
                } else {
                        if ( day > 28 )
                            return 0;
                        else
                            return 1;
                    }
                } else {
                        if ( day > 30 )
                            return 0;
                        else
                            return 1;
                }
            }
            return 0;
        }
        void output() {
            cout<<"\n Valid. Next date ";
            if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month
== 10 || month == 12 ) {
                 if ( day == 31 && month == 12 ) {
                     day = 1;
                     month = 1;
                     year++;
                } else if (day == 31){
                     day = 1;
                     month++;
                } else
                      day++;
            } else if (month == 4 || month == 6 || month == 9 || month == 11 ) {
               if (day == 30){
                   day = 1;
                   month++;
                } else
                   day++;
             } else if ( leap ) {
               if (day == 29){
                    day = 1;
                    month++;
                } else
                    day++;
               } else if (!leap) {
                 if (day == 28){
                     day = 1;
                     month++;
                  } else
                     day++;
            }
            cout<<day<<"/"<<month<<"/"<<year;
        }
} date;
int main() {
    int flag;
    cout<<"\n Enter the Date: \n";
    date.input();
    flag = date.validate();
    if ( flag )
        date.output();
   else
        cout<<"Not Valid";
    return 0;
}
