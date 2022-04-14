#include<iostream>
using namespace std;

class Queue{
    public:
        int size;
        int front;
        int rear;
        int *arr;

        Queue(int size){
            this->size = size;
            this->rear = -1;
            this->front = -1;
            arr = new int[size];
        }

    void enqueueR(int value){
        if((rear + 1) % size == front){
            cout<<"Queue is full"<<endl;
        }

        if(front = -1){
            front = rear = 0;
        }
        else{
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
    }

    void enqueueF(int value){
        if((rear + 1) % size == front){
            cout<<"Queue is full"<<endl;
        }

        if(front = -1){
            front = rear = 0;
        }

        else if(front == 0){
            front = size - 1;
        }

        else{
            front--;
        }
        arr[front] = value;
    }

    int dequeueF(){
        if(front == -1){
            return -1;
        }

        int ans = arr[front];

        if(front == rear){
            front = rear = -1;
        }

        // else if(front == 0){
        //     front = size - 1;
        // }

        else{
            front = (front + 1) % size;
        }

        return ans;
    }

    int dequeueR(){
        if(front == -1){
            return -1;
        }

        int ans = arr[rear];

        if(front == rear){
            front = rear = -1;
        }

        else if(rear == 0){
            rear = size - 1;
        }

        else{
            rear = (rear - 1) % size;
        }
        return ans;
    }

    int getF(){
        if(front == -1){
            return -1;
        }
        return arr[front];
    }

    int getR(){
        if(front == -1){
            return -1;
        }
        return arr[rear];
    }
};

int main()
{
    Queue Q(3);
    Q.enqueueR(30);
    Q.enqueueR(40);
    Q.enqueueF(10);

    cout<<Q.getF()<<endl;
    cout<<Q.getR()<<endl;
}