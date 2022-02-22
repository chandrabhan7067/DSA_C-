#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a = 5;
    int *ptr = &a;
    cout << sizeof(a) << endl;
    cout << sizeof(&a) << endl;
    cout << "Value of a is:" << a << endl;
    cout << "Address of a is:" << &a << endl;
    cout << "Address of a is:" << ptr << endl;
    cout << "value of a is:" << *ptr << endl;
    cout << "size of operator is:" << sizeof(ptr) << endl;

    // cout<<"before value of a is:"<<*ptr<<endl;
    // (*ptr)++;
    // cout<<"after value of a is:"<<a<<endl;

    // int *q = ptr;
    // cout<<*q;

    cout << "Before" << ptr << endl;
    ptr++;
    cout << "After" << ptr << endl;

    cout << "try" << endl;
    // int arr[] = {4, 5, 6, 7};
    // int *p = arr;
    // cout<<p<<endl;
    // cout << *arr + 9;

    char s[] = "hello";
    char *p = s;
    cout << s[0] << " " << p;
}