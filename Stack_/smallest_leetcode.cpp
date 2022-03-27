#include<iostream>
#include<stack>
using namespace std;

class Stack{
    stack<int>s1,s2;

    void push(int val){
        if(s1.empty()){
            s1.push(val);
            s2.push(val);
            return;
        }
        s1.push(val);
        s2.push(min(val,s2.top()));
    }

    void pop(){
        s1.pop();
        s2.pop();
    }

    int top(){
        return s1.top();
    }

    int getMin(){
        return s2.top();
    }
};

int main()
{
    // stack<int>s1;
    // Stack s1;
    // cout<<s1.getMin();
}