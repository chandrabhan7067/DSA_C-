#include<iostream>
using namespace std;

int main()
{
    int i = 10;
    int &j = i;
    cout<<i<<endl;
    cout<<j<<endl;
    i++;
    j++;
    cout<<i<<endl;
    cout<<j<<endl;
}