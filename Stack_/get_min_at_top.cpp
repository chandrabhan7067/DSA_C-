#include <iostream>
#include <stack>
using namespace std;

stack<int> pushIntStack(int arr[], int n)
{
    stack<int> st;
    st.push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < st.top())
        {
            st.push(arr[i]);
        }
        else
        {
            int temp = st.top();
            st.push(temp);
        }
    }
    return st;
}

void minAtTop(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    int arr[] = {1, 6, 43, 1, 2, 0, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    stack<int> st = pushIntStack(arr, n);

    minAtTop(st);
}