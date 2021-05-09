// CHRISTO REJI SAM
// CYCLE 3
// Program 8: Implement the base class Shape and derive triangle,rectangle,circle and square classes from it. Implement functions to compute the area and perimeter of the polygon. Use the concept of pure virtual functions.


// PROGRAM

#include <iostream>
#include <math.h>

using namespace std;

class Shape
{
protected:
    float perimeter, area;

public:
    virtual void getData() = 0;
    void showData()
    {
        cout << "\n Perimeter: " << perimeter;
        cout << "\n Area: " << area;
    }
};

class Triangle : public Shape
{
    float s1, s2, s3;

public:
    bool validate()
    {
        if (s1 <= 0 || s2 <= 0 || s3 <= 0)
            return false;
        return true;
    }
    void calculate()
    {
        if (!validate())
        {
            cout << "\n Side lenght of Triangle cannot be less than or equal to 0!";
            area = perimeter = 0;
        }
        else
        {
            perimeter = s1 + s2 + s3;
            float s = (s1 + s2 + s3) / 2;
            area = sqrt(s * (s - s1) * (s - s2) * (s - s3));
        }
    }
    void getData()
    {
        cout << "\n Enter the side lengths \n";
        cout << "\n Side length 1: ";
        cin >> s1;
        cout << "\n Side length 2: ";
        cin >> s2;
        cout << "\n Side length 3: ";
        cin >> s3;
        calculate();
    }
};

class Rectangle : public Shape
{
    float l, b;

public:
    bool validate()
    {
        if (l <= 0 || b <= 0)
            return false;
        return true;
    }
    void calculate()
    {
        if (!validate())
        {
            cout << "\n Side lenght cannot be less than or equal to 0!";
            area = perimeter = 0;
        }
        else
        {
            perimeter = 2 * (l + b);
            area = l * b;
        }
    }
    void getData()
    {
        cout << "\n Enter the length of Rectangle: ";
        cin >> l;
        cout << "\n Enter the breadth of Rectangle: ";
        cin >> b;
        calculate();
    }
};

class Square : public Shape
{
    float s;

public:
    bool validate()
    {
        if (s <= 0)
            return false;
        return true;
    }
    void calculate()
    {
        if (!validate())
        {
            cout << "\n Side lenght cannot be less than or equal to 0!";
            area = perimeter = 0;
        }
        else
        {
            perimeter = 4 * s;
            area = s * s;
        }
    }
    void getData()
    {
        cout << "\n Enter the side length of the square: ";
        cin >> s;
        calculate();
    }
};

class Circle : public Shape
{
    float radius;

public:
    bool validate()
    {
        if (radius <= 0)
            return false;
        return true;
    }
    void calculate()
    {
        if (!validate())
        {
            cout << "\n Radius cannot be less than or equal to 0!";
            area = perimeter = 0;
        }
        else
        {
            area = 3.14 * radius * radius;
            perimeter = 2 * 3.14 * radius;
        }
    }
    void getData()
    {
        cout << "\n Enter the radius of the circle: ";
        cin >> radius;
        calculate();
    }
};

void triangle()
{
    Shape *S;
    Triangle T;
    S = &T;
    S->getData();
    S->showData();
}
void rectangle()
{
    Shape *S;
    Rectangle R;
    S = &R;
    S->getData();
    S->showData();
}
void square()
{
    Shape *S;
    Square Sq;
    S = &Sq;
    S->getData();
    S->showData();
}
void circle()
{
    Shape *S;
    Circle C;
    S = &C;
    S->getData();
    S->showData();
}

int main()
{
    int choice;
    bool again = true;
    char ch;
    while (again)
    {
        cout << "\n Select the shape";
        cout << "\n 1. Triangle";
        cout << "\n 2. Rectangle";
        cout << "\n 3. Square";
        cout << "\n 4. Circle";
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            triangle();
            break;
        case 2:
            rectangle();
            break;
        case 3:
            square();
            break;
        case 4:
            circle();
            break;
        default:
            cout << "\n Invalid Choice! Try Again!";
        }
        cout << "\n Do You Want To Continue? (Press n/N to exit)";
        cin >> ch;
        if (ch == 'N' || ch == 'n')
            again = false;
    }
    return 0;}
