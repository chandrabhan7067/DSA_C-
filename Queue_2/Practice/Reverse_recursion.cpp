#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// time complexity   O(n)

void reverse(stack<int> &st, queue<int> &q)
{
    if (st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();
    q.push(temp);
    reverse(st, q);
}

int main()
{
    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);

    stack<int> st;
    while (!Q.empty())
    {
        st.push(Q.front());
        Q.pop();
    }

    // cout<<st.top();

    reverse(st, Q);

    cout << Q.front();
}