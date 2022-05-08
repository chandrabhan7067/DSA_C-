#include <iostream>
#include <queue>
using namespace std;

// using queue
// time complexity is 
// space complexity is 

void solve(queue<int>&q)
{
    queue<int> newQ;
    int mid = q.size() / 2;
    // cout<<mid;

    for (int i = 0; i < mid; i++)
    {
        int val = q.front();
        newQ.push(val);
        q.pop();
    }

    while (!newQ.empty())
    {
        int val1 = newQ.front();
        q.push(val1);
        newQ.pop();

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

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}