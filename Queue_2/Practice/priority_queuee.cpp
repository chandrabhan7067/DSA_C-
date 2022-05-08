#include<iostream>
#include<queue>
using namespace std;

//in priority queue element are push in nonincreasing order it means if we insert the element in queue like 30, 50, 40, 60 than the priority queue arrange the element like 60, 50, 40, 30

int main()
{
    priority_queue<int>q;

    q.push(40);
    q.push(43);
    q.push(30);
    cout<<q.top();

    while (!q.empty())      
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    
}