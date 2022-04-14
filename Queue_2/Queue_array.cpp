#include <iostream>
using namespace std;

class Queue
{
public:
    int front;
    int rear;
    int *arr;
    int size;

    Queue(int size)
    {
        this->size = size;
        this->front = 0;
        this->rear = 0;
        arr = new int[size];
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "stack is full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (front == rear)
        {
            return -1;
        }
        int ans = arr[front];
        front++;
        return ans;
    }

    bool Empty()
    {
        if (front == rear)
        {
            return true;
        }
        return false;
    }

    bool Full(){
        if(rear == size){
            return true;
        }
        return false;
    }

    int frontEle()
    {
        if (front == rear)
        {
            return -1;
        }
        return arr[front];
    }

    int rearEle()
    {
        if (rear == front)
        {
            return -1;
        }
        return arr[rear];
    }
};

int main()
{
    Queue Q(3);
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);

    cout<<Q.dequeue()<<endl;

    if(Q.Empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    if(Q.Full()){
        cout<<"Queue is full"<<endl;
    }
    else{
        cout<<"Queue is not full"<<endl;
    }
}