// CHRISTO REJI SAM
// CYCLE 3
//Program 3: Write a program using operator overloading to overload Stream operators (>> and << ) to read and display the objects of complex class.

// PROGRAM

#include <iostream>

using namespace std;

class Complex
{
    float real, img;

public:
    Complex()
    {
        real = 0;
        img = 0;
    }
    friend ostream &operator<<(ostream &, Complex &);
    friend istream &operator>>(istream &, Complex &);
};

ostream &operator<<(ostream &output, Complex &temp)
{
    output << "\n Complex Number: \n"
           << temp.real << " + i" << temp.img;
    return output;
}
istream &operator>>(istream &input, Complex &temp)
{
    cout << "\n Real part: ";
    input >> temp.real;
    cout << "\n Imaginary part: ";
    input >> temp.img;
    return input;
}

int main()
{
    Complex C;
    cin >> C;
    cout << C;
    return 0;
}
