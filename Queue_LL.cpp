#include <iostream>
using namespace std;

class Queue
{
public:
    int data;
    Queue *front = NULL;
    Queue *rear = NULL;
    Queue *next;

    void enqueue(int value)
    {
        Queue *temp = new Queue;
        temp->data = value;
        temp->next = NULL;

        if (front == NULL)
        {
            front = rear = temp;
        }

        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    int dequeue()
    {
        if (front == NULL)
        {
            return -1;
        }
        int ans = front->data;
        front = front->next;
        return ans;
    }

    bool Empty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }

    int rearEle()
    {
        if (front == NULL)
        {
            return -1;
        }
        return rear->data;
    }
};

int main()
{
    Queue Q;
    Q.enqueue(10);
    Q.enqueue(5);
    cout << Q.rearEle();

    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;

    if (Q.Empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
}