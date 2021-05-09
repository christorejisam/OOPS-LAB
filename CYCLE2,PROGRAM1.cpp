// CHRISTO REJI SAM
// CYCLE 2
//Program 1:  Write class which contains an integer array and a static function to find the average of that array and other necessary member functions. Create THREE objects. Read the values into the array using one object, and find the average. Let the second object modifies the value by multiplying each element by a certain multiplier. Repeat the process of finding the average usng first object.Using the third object arrange the numbers in ascending order and print.



//PROGRAM



#include <iostream>
using namespace std;
class avg{
private:
     static int a[30];
public:
     void get_data(int n);
     static void aver(int n);
     void mod(int n);
     void sorting(int n);
 };
 int avg::a[30];
 void avg::get_data(int n){
     int i;
   cout<< "\nEnter the elements\n";
        for(i=0;I<n;i++){
            cin>> a[i];
        }
 }
void avg::aver(int n){
   int i=0;
    float av,sum=0;
    for(i=0;i<n;i++)
        sum+=a[i];
    av=sum/n;
    cout<< "\nThe Average of the Array is \n" << av <<endl;
  }
void avg::mod(int n){
int inp,i;
   cout<<"\nEnter the multiplier to modify the Average\n";
   cin>> inp;
   for(i=0; i<n; i++)
   a[i]=a[i]*inp;
}
void avg::sorting(int n){
    int I,j,t;
for(i=0; i<(n-1; i++)
                             for(j=0; j<(n-i)-1; j++)
                             if(a[j]>a[j+1])
                             {
                                         t=a[j];
                                         a[j]=a[j+1];
                                         a[j+1]=t;
                                         }
                                         cout << "Sorted array is " << endl;
                                         for(i=0; i<n; i++)
                                         cout<< a[i] << endl;
}
int main(){
avg o1,o2,o3;
int size;
cout<< "\nEnter the total numbers of elements\n";
    cin>>size;
o1.get_data(size);
o1.aver(size);
o2.mod(size);
o3.sorting(size);
o1.aver(size);
return 0;
}
