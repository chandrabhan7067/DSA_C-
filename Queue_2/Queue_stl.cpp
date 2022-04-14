#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int>Q;

    Q.push(10);
    Q.push(20);
    Q.push(30);

    cout<<Q.back();
    cout<<endl;
    cout<<Q.front();
}