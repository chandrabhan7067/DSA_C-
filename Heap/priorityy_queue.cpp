#include<queue>
#include<iostream>
using namespace std;

int main()
{

// max heap
    priority_queue<int>q;
    q.push(6);
    q.push(60);
    q.push(16);
    q.push(56);

    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    cout<<q.top()<<endl;


// min heap

cout<<"mean heap is"<<endl;
    priority_queue<int,vector<int>,greater<int> > minHeap;
    minHeap.push(6);
    minHeap.push(60);
    minHeap.push(16);
    minHeap.push(56);


    cout<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<minHeap.top()<<endl;
    cout<<minHeap.top()<<endl;
}