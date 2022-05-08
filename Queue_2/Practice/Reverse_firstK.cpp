#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// space complexity   O(k)
// time complexity is   O(n)

queue<int> reverse(queue<int> &q, int k)
{
    stack<int> st;

    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        st.push(val);
        q.pop();
    }

    // after this loop first k element is pushed in queue in back side
    while (!st.empty())
    {
        int val = st.top();
        q.push(val);
        st.pop();
    }

    // Now push queue front element to the back of queue

    int t = q.size() - k;

    for (int i = 0; i < t; i++)
    {
        int val = q.front();
        q.push(val);
        q.pop();
    }
    return q;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    reverse(q, 3);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}