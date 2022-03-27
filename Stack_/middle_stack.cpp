#include<iostream>
#include<stack>
using namespace std;

// time complexity is  O(n)

void solve(stack<int>&s,int N,int count)
{
    if(count == N/2){
        s.pop();
        return;
    }

    int temp = s.top();
    s.pop();

    solve(s,N,count+1);

    s.push(temp);
}


int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // cout<<s.top();
    solve(s,5,0);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}