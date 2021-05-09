// CHRISTO REJI SAM
// CYCLE 3
// Program 2:  Distance is measured in feet and inches unit. Use operator overloading for �+� operator for adding two such distances and �<� for comparing two such distances. (one of the operator function should be implemented as friend function.)


// PROGRAM

#include <iostream>

using namespace std;

class Distance
{
    int feet, inch;

public:

    void input()
    {
        cout << "\n Enter Feet: ";
        cin >> feet;
        cout << "\n Enter Inch: ";
        cin >> inch;

    }
    void display()
    {
        feet += inch / 12;
        inch %= 12;
        cout << "\n Feet: " << feet;
        cout << "\n Inch: " << inch;
    }
    Distance operator+(Distance &d)
    {
        Distance temp;
        temp.inch = inch + d.inch;
        temp.feet = feet + d.feet + temp.inch / 12;
        temp.inch %= 12;
        return temp;
    }
    friend Distance operator<(Distance &, Distance &);
};

Distance operator<(Distance &d1, Distance &d2)
{
    int inch1 = d1.feet * 12 + d1.inch;
    int inch2 = d2.feet * 12 + d2.inch;
    if (inch1 > inch2)
        return d1;
    else
        return d2;
}

int main()
{
    Distance d1;
    d1.input();
    d1.display();
    Distance d2;
    d2.input();
    d2.display();
    Distance d3 = d1 + d2;
    cout << "\n The sum : ";
    d3.display();
    cout << "\n The largest of the two ";
    Distance temp = d1 < d2;
    temp.display();
    return 0;
}
