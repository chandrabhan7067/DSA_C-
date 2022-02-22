#include<iostream>
using namespace std;

void update(int &n){
    n++;
}

int main()
{
    int n = 2;
    cout<<"Before "<<n<<endl;
    update(n);
    cout<<"After "<<n<<endl;

}