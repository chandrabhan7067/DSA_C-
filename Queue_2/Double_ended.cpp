#include<iostream>
using namespace std;

class Deque
{
    int size;
    int *arr;
    int front;
    int rear;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    void pushFront(int x)
    {
        // check full condition
        if(isFull()){
            cout<<"queue is full";
            return;
        }
        
        else if(isEmpty()){
            front = rear = 0;
        }
        
        else if(front == 0){
            front = size-1;
        }

        else{
            front--;
        }
        arr[front] = x;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    void pushRear(int x)
    {
        if(isFull()){
            cout<<"Queue is full"<<endl;
        }
        
        else if(isEmpty()){
            front = rear = 0;
        }
        
		else{
			rear = (rear + 1) % size;
		}
       arr[rear] = x;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
       if(isEmpty()){
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear){ // for single element
            front = rear = -1;
        }

		else{
			front = (front + 1) % size;
		}
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
		if(isEmpty()){
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;
        
        if(front == rear){ // check queue is empty
            front = rear = -1;
        }
        
        else if(rear == 0){ 
            rear = size - 1;
        }
        else{
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
       if(isEmpty()){
           return -1;
       }
      return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
      if(isEmpty()){
           return -1;
       }
      return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
		 if((rear + 1) % size == front){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    Deque q(3);
    q.pushFront(10);
    q.pushRear(20);
    q.pushRear(30);

    cout<<q.getFront();
    cout<<q.getRear();

    if(q.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    if(q.isFull()){
        cout<<"Queue is full"<<endl;
    }
    else{
        cout<<"Queue is not full"<<endl;
    }

}