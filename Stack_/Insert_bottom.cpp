#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>&st, int num)
{
    if (st.empty())
    {
        st.push(num);
        return;
    }

    int temp = st.top();
    st.pop();
    solve(st, num);
    st.push(temp);
}

int main()
{
    int num = 5;
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    solve(st,num);

// for checking
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.top();
}