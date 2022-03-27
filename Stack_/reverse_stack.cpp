#include <iostream>
#include <vector>
using namespace std;

class stack
{
public:
    int top;
    int size;
    char *arr;

    stack(int s)
    {
        this->size = s;
        this->top = -1;
        arr = new char[s];
    }

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(char value)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = value;
            return;
        }
        else
        {
            cout << "stack is full" << endl;
        }
        // top++;
        // arr[top] = value;
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack empty" << endl;
        }

        // top--;
    }

    char peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }
};

int main()
{
    stack s(6);
    string st = "chan";
    for (int i = 0; i < st.length(); i++)
    {
        s.push(st[i]);
    }

    string str = "";
    while (!s.empty())
    {
        char ans = s.peek();
        str.push_back(ans);
        s.pop();
    }
    cout << str;
}