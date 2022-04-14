#include<iostream>
#include<stack>
using namespace std;


int main()
{
    stack<int>st;
    st.push(10);
    st.push(20);
    cout<<st.top()<<endl;
    st.pop();
    if(st.empty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
}