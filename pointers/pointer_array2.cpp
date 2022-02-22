#include<iostream>
using namespace std;

int main()
{
    int arr[10] = {1,2,3};
    //cout<<arr<<endl;
    //cout<<&arr<<endl;
    //cout<<&arr[0]<<endl;

    int *p = &arr[0];
    //cout<<p<<endl;
    //cout<<*p<<endl;
    //cout<<&p<<endl;

    int *ptr = &arr[0];
    cout<<ptr<<endl;
    ptr = ptr + 1;
    cout<<ptr<<endl;
}