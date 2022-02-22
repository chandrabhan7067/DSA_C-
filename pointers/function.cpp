#include<iostream>
using namespace std;

void print(int *p){
    cout<<*p;
}

void update(int *p){
    p = p + 1;
    cout<<"inside"<<p;
    // *P = *p + 1;
}

int main()
{
    int a = 5;
    int *p = &a;
    cout<<*p<<endl;
    // print(p);
    update(p);
    cout<<*p<<endl;
}