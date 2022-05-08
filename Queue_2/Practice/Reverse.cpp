#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    queue<int>Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);

    stack<int>st;

    while(!Q.empty()){
        int ele = Q.front();
        st.push(ele);
        Q.pop();
    }


    while(!st.empty()){
        int ele = st.top();
       Q.push(ele);
        st.pop();
    }
    
// print the element
    while(!Q.empty()){
        cout<<Q.front();
        Q.pop();
    }

}