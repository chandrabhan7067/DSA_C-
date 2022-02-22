#include<iostream>
using namespace std;

int main()
{
    int a = 10;
    cout<<sizeof(a)<<endl;

    int *p = &a;
    cout<<sizeof(p)<<endl;

    int *ptr = new int[5];
    cout<<sizeof(ptr);
}