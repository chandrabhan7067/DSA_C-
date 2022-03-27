#include<iostream>
#include<stack>
using namespace std;

// Time complexity is O(n^2)

void Insert_sorted(stack<int>&s, int num){
    if(s.empty()){
        s.push(num);
        return;
    }

    int temp = s.top();

    if(temp < num){
        s.push(num);
        return;
    }

    s.pop();
    Insert_sorted(s,num);
    s.push(temp);
}

void sort(stack<int>&s){
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    sort(s);
    Insert_sorted(s,temp);
}

int main()
{
    // 5 -2 9 -7 3
    stack<int>s;
    s.push(3);
    s.push(-7);
    s.push(9);
    s.push(-2);
    s.push(5);
    sort(s);
    cout<<"After sorting our linkedList is "<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}