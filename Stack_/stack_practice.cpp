#include <iostream>
using namespace std;

#define n 100

class Stack
{
    int *arr;
    int top;
public:

    Stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack overflow";
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop()
    {

        if (top == -1)
        {
            cout << "Empty";
            return;
        }
        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Empty";
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

int main()
{

    Stack st;
    st.push(10);
    st.push(2);
    cout << st.Top()<<endl;
    st.pop();
    cout << st.Top()<<endl;
}