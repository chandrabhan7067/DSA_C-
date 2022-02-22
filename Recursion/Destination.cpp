#include<iostream>
using namespace std;

void check(int src, int des){
    cout<<"sorce "<<src<<" desition "<<des<<endl;
    if (src == des)
    {
        cout<<"pahuch gya";
        return;
    }
    src++;
    check(src,des);
}

int main()
{
    int src = 1;
    int des = 10;
    check(src,des);
}