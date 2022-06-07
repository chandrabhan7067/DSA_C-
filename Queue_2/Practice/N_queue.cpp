#include <iostream>
using namespace std;

class Kqueue
{
public:
    int n;
    int k;
    int freespot;
    int *front;
    int *rear;
    int *arr;
    int *next;

    Kqueue(int n, int k)
    {
        this->k = k;
        this->n = n;
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        arr = new int[n];
        this->freespot = 0;
    }

    void enqueue(int data, int qn)
    {
        if (freespot == -1)
        {
            cout << "no free spot is available" << endl;
            return;
        }

        int index = freespot;
        freespot = next[index];

        // check pushed element is first

        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }

        // link new element to the prev element
        else
        {
            next[rear[qn - 1]] = index;
        }

        next[index] = -1;

        // update rear
        rear[qn - 1] = index;

        // push element
        arr[index] = data;
    }

    int dequeue(int qn)
    {
        if (front[qn - 1] == -1)
        {
            cout << "Queue is in undeflow" << endl;
            return -1;
        }

        int index = front[qn - 1];
        // move front to one place towards

        front[qn - 1] = next[index];

        // manage freespot
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};

int main()
{
    Kqueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout << q.dequeue(1) << " ";
    cout << q.dequeue(2) << " ";
    cout << q.dequeue(1) << " ";
    cout << q.dequeue(1) << " ";
    cout << q.dequeue(1) << " ";
}