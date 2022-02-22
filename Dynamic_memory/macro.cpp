#include<iostream>
using namespace std;

// #define AREA(a,b) (a*b)
#define AREA(a,b) (((a) > (b))? (a):(b))

int main()
{
    int n = 2;
    int n2 = 5;

    cout<<"The area is "<<AREA(n,n2);

    
}
