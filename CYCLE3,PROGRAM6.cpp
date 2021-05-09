// CHRISTO REJI SAM
// CYCLE 3
// Program 6: Employee class contain details like name,emp no,pay rate, constructor function and a pay() function. Manager class inherits from employee and has the option of drawing pay on hourly basis or salary basis and has an additional data issalaried(bool). Class Supervisor is derived from employee and has an additional field department and is always salaried. Base and both derived classes should contain pay() function with same name.

//PROGRAM

#include<iostream>
#define SAL1 75000
#define SAL2 2000
#define MAXSZ 10
using namespace std;
class Employee
{
    protected:
        long empno;
        float payrate;
        string name;
    public:
        Employee()
        {
            empno = 0000;
            payrate = 0;
            name = "NONE";
        }
        virtual void pay()=0;
};
class Manager: public Employee
{
    protected:
        string pay_basis; //can be "salary" or "hourly"
        bool issalaried;
    public:
        Manager() : Employee()
        {
            pay_basis = "NONE";
            issalaried = true;
        }
        void getval()
        {
            static int i = 1;
            cout << "\n\nEnter name of the Manager #"<<i<<" :: ";
            cin >> name;
            cout << "Enter Employee Number :: ";
            cin >> empno;
            cout << "Are you salaried? (yes or no) :: ";
            string x;
            cin >> x;
            if( x == "yes" )
                issalaried = true;
            else issalaried = false;
            if(issalaried)
            {
                cout << "Is it salary or hourly pay? (salary or hourly) :: ";
                cin >> pay_basis;
            }
            ++i;
        }
        void pay()
        {
            if( issalaried == true )
            {
                if( pay_basis == "salary" )
                {
                    payrate = SAL1;
                }
                if( pay_basis == "hourly")
                {
                    int x;
                    cout << "How many hours has this employee worked ? " << endl;
                    cin >> x;
                    payrate = x*SAL2;
                }
            }
        }
        void display()
        {
            cout << "Name :: " << name << endl
                 << "Payrate :: " << payrate << endl;
        }
};
class Supervisor: public Employee
{
    protected:
        string department;
    public:
        Supervisor() : Employee()
        {
            department = "NONE";
        }
        void getval()
        {
            static int i = 1;
            cout << "\n\nEnter name of the Supervisor#"<<i<<" :: ";
            cin >> name;
            cout << "Enter Employee Number :: ";
            cin >> empno;
            cout << "Enter department name :: ";
            cin >> department;
            ++i;
        }
        void pay()
        {
            payrate = SAL1*7/10;
        }
        void display()
        {
            cout << "Name :: " << name << endl
                 << "Payrate :: " << payrate << endl;
        }
};
int main()
{
    Employee *E;
    Supervisor S[MAXSZ];
    Manager M[MAXSZ];
    int x,n;
    while(1)
    {
        cout << "You're gonna enter data of :: \n"
             << "1. Manager \n"
             << "2. Supervisor \n"
             << "Or Enter 0 to exit \n"
             << "Enter your choice :: ";
        cin >> x;
        switch(x)
        {
            case 0:
                cout << "Okay, exiting...\n\n";
                exit(0);
            case 1:
                cout << "Enter no.of entries :: ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                  E=&M[i];
                  M[i].getval();
                  E->pay();
                }
                cout << "Managers and their payrates :: \n";
                for (int i = 0; i < n; i++)
                {
                  M[i].display();
                  cout << endl;
                }
                break;
            case 2:
                cout << "Enter no.of entries :: ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                  E=&S[i];
                  S[i].getval();
                  E->pay();
                }
                cout << "Managers and their payrates :: \n";
                for (int i = 0; i < n; i++)
                {
                  S[i].display();
                  cout << endl;
                }
                break;
            default:
                cout << "Invalid entry!!! Retry. \n\n";
        }
    }
    return 0;
}
