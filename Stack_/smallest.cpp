#include <iostream>
#include <stack>
using namespace std;

class stackk
{
public:
    int top;
    int size;
    int *arr;

    stackk(int size)
    {
        this->size = size;
        this->top = -1;
        arr = new int[size];
    }

    void pushh(int value)
    {
        int min = 9999;
        if (top == -1)
        {
            min = value;
        }
        else
        {
            if (value < min)
            {
                top++;
                arr[top] == min;
            }
            else
            {
                top++;
                arr[top] = value;
            }
        }
    }

    int pop1()
    {
        if (top == -1)
        {
            return -1;
        }
        int ans = arr[top];
        top--;
        return ans;
    }

    int top1()
    {
        if (top == -1)
        {
            return -1;
        }
        return arr[top];
    }
};

int main()
{
    stack<int> s;
    stackk smallest(10);
    int arr[] = {3, 5, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout<<n;
    for (int i = 0; i < n; i++)
    {
        s.push(arr[i]);
        smallest.pushh(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << smallest.top1() << " ";
        smallest.pop1();
    }
}