// CHRISTO REJI SAM
// CYCLE 2
//Program 3: Write a function called swap() that interchanges two int values belonging to an object, passed as parameter to it by the calling program. Write a C++ program to demonstrate call by value, call by reference and call by address.


//PROGRAM


#include <iostream>
#include <cctype>
using namespace std;
class swaping{
int x,y;
public:
    void get_data(){
    cout<<"Enter the X and Y \n";
    cin >> x >> y
    }
    void swap_value(swaping s);
    void swap_ref(swaping &s);
     void swap_add(swaping *s);
     void output(){
     cout <<"x ="<<x<<"\n"<<"y= "<<y<<endl;
     }
};
void swaping :: swap_value(swaping s){
int temp;
temp=s.x;
s.x=s.y;
s.y=temp;
}
void swaping::swap_ref(swaping &s){
int temp;
temp=s.x;
s.x=s.y;
s.y=temp;
}
void swaping::swap_add(swaping *s){
int temp;
temp=s->x;
s->x=s->y;
s->y=temp;
}
s->y=temp;
}
int main (){
    char fun;
swaping s1,s2;
s1.get_data();
while(fun!='E')
{
cout<<"Enter \n V for Call_by_value \n R for Call_by_Reference\n A for Call_by_Address\n E for exit"<<endl;
cin>>fun;
fun=toupper(fun);
switch(fun){
case 'V':s2.swap_value(s1);
break;
case 'R':s2.swap_ref(s1);
break;
case 'A':s2.swap_add(&s1);
break; default:cout<<"\n INVALID CHOICE \n";
}
s1.output();
}
}
