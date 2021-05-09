// CHRISTO REJI SAM
// CYCLE 3
// Program 7: Write a C++ program to create a class STUDENT with age name and register number. Using Inheritance, derive two classes MTech-stud and BTech-stud.List both the category of students in the increasing order of marks( for BTech-stud) and gpa( for MTech-stud). In case of tie, display whichever name comes first. Make sort() function as a virtual function.

// PROGRAM

#include<iostream>
#define max 5
using namespace std;

class Student{
    protected:
        int age[5],regno[5];
        string name[5];
        int n;
    public:
        Student(){

            for(int i=0;i<5;i++){
            cout<<"Enter register no. \n name \n age : ";
            cin>>regno[i]>>name[i]>>age[i];
        }
        }


        virtual void sort()=0;
        virtual void display() = 0;
};

class Btech:public Student{
    protected:
        int marks[10];
    public:
        Btech():Student(){
            cout<<"Enter marks : ";
            for(int i=0;i<5;i++){

            cin>>marks[i];
        }
    }

        void sort(){
            for(int i=0;i<5;i++){
                int min = i;
                for(int j=i+1;j<5;j++){
                    if(marks[j]<marks[min]){
                        min = j;
                    }
                }
                    if(min != i){
                        float temp = marks[i];
                        marks[i] = marks[min];
                        marks[min] = temp;

                        temp = regno[i];
                        regno[i] = regno[min];
                        regno[min] = temp;

                        temp = age[i];
                        age[i] = age[min];
                        age[min] = temp;

                        string temp1 = name[i];
                        name[i] = name[min];
                        name[min] = temp1;
                    }
                }
            }


        void display(){
            cout<<"Register no. |  Name  | marks"<<endl;
            for(int i = 0;i<5;i++){
                cout<<regno[i]<<"  "<<name[i]<<"  "<<marks[i]<<" ";
                cout<<"\n";
            }
        }

};

class Mtech:public Student{

protected:
        int gpa[5];
    public:
        Mtech():Student(){
            for(int i=0;i<5;i++){
            cout<<"Enter gpa : ";
            cin>>gpa[i];
        }
        }

        void sort(){
            for(int i=0;i<5;i++){
                int min = i;
                for(int j=i+1;j<5;j++){
                    if(gpa[j]<gpa[min]){
                        min = j;
                    }
                }
                    if(min != i){
                        float temp = gpa[i];
                        gpa[i] = gpa[min];
                        gpa[min] = temp;

                        temp = regno[i];
                        regno[i] = regno[min];
                        regno[min] = temp;

                        temp = age[i];
                        age[i] = age[min];
                        age[min] = temp;

                        string temp1 = name[i];
                        name[i] = name[min];
                        name[min] = temp1;
                    }
                }
            }


            void display(){
            cout<<"Register no. |  Name  | gpa"<<endl;
            for(int i = 0;i<5;i++){
                cout<<regno[i]<<"  "<<name[i]<<"  "<<gpa[i]<<" ";
                cout<<"\n";
            }
        }

};

int main(){
    Student* s;
    int x;
    cout << "Choose course :: \n";
    cout << "1. B.Tech \n";
    cout << "2. M.Tech \n";
    cout << "Your Choice :: ";
    cin >> x;
    switch(x){
        case 1: s = new Btech();
                break;
        case 2: s = new Mtech();
                break;
        default: cout<<"Invalid choice.";
                exit(0);
    }
     s->sort();
     cout<<"After sorting : \n" ;
     s->display() ;
     return 0;
}
