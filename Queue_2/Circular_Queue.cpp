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
        this->front = -1;
        this->rear = -1;
        this->arr = new int[size];
    }

    void Enqueue(int value)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full" << endl;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
    }

    int dqueue()
    {
        if (front == -1)
        {
            return -1;
        }

        int ans = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }

        else
        {
            front = (front + 1) % size;
        }

        return ans;
    }

    bool Empty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    bool Full(){
        if((rear + 1) % size == front){
            return true;
        }
        return false;
    }

    int frontEle(){
        if(front == -1){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int rearEle(){
        if(front == -1){
            return -1;
        }
        return arr[rear];
    }
};

int main()
{
    Queue Q(3);
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    // Q.Enqueue(40);
    // Q.Enqueue(40);

    Q.dqueue();
    // Q.dqueue();
    // Q.dqueue();

    Q.Enqueue(40);

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

    cout<<Q.frontEle()<<endl;
    cout<<Q.rearEle()<<endl;
}