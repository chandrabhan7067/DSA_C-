#include<iostream>
using namespace std;

void update(int **p2){
    // p2 = p2 + 1;        // No change in this statment
    // *p2 = *p2 + 1;       // yes change in this statment
    **p2 = **p2 + 1;        // yes change in this statment
}

int main()
{
    int a = 10;
    int *p = &a;
    int **p2 = &p;

    cout<<"before "<<a<<endl;
    cout<<"before "<<p<<endl;
    cout<<"before "<<p2<<endl;
    update(p2);
    cout<<"After "<<a<<endl;
    cout<<"After "<<p<<endl;
    cout<<"After "<<p2<<endl;

    cout<<"try"<<endl<<endl;
    char ch[] = "chandu";
    char *ptr = &ch[0];
    ptr++;
    cout<<*ptr;
     
}

