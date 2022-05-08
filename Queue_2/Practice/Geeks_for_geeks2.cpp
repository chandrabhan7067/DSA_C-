#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// using stack

void solve(queue<int> &q)
{
    int mid = q.size() / 2;

    stack<int> st;

    for (int i = 0; i < mid; i++)
    {
        int val = q.front();
        st.push(val);
        q.pop();
    }

    while (!st.empty())
    {
        int val = st.top();
        q.push(val);
        st.pop();
    }

    for (int i = 0; i < mid; i++)
    {
        int val = q.front();
        q.push(val);
        q.pop();
    }

    for (int i = 0; i < mid; i++)
    {
        int val = q.front();
        st.push(val);
        q.pop();
    }

    while (!st.empty())
    {
        int val1 = st.top();
        q.push(val1);
        st.pop();

        int val2 = q.front();
        q.push(val2);
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    solve(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}