// CHRISTO REJI SAM
// CYCLE 3
//Program 5: Polar coordinates are represented in angle and radius format while rectangular
coordinates represented as (x,y). Define classes for both types and include member
functions to convert from polar to rectangular coordinates.(conversion from class to class.)


// PROGRAM

#include <iostream>
#include <math.h>
#define PI 3.14
using namespace std;
class Polar
{
    float rad, angle;
public:
    Polar(float r, float a)
    {
        rad = r;
        angle = a;
    }
    void show()
    {
        cout << "\n Entered Polar Form: \n radius: " << rad << "\n angle: " << angle;
    }
    float getRadius()
    {
        return rad;
    }
    float getAngle()
    {
        return angle;
    }
};
class Rectangular
{
    float x, y;
public:
    void operator=(Polar P)
    {
        x = P.getRadius() * cos((P.getAngle() * PI) / 180);
        y = P.getRadius() * sin((P.getAngle() * PI) / 180);
    }
    void show()
    {
        cout << "\n In Rect. form: \n x: " << x << "\n y: " << y;
    }
};
int main()
{
    float r, a;
    cout << "\n Input Radius: ";
    cin >> r;
    cout << "\n Input Angle: ";
    cin >> a;
    Polar P(r, a);
    P.show();
    Rectangular R;
    R = P;
    R.show();
    return 0;
}
