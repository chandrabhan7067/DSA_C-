#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

int checkPreorderBST(int arr[], int n)
{
    int root = INT_MIN;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] > st.top())
        {
            root = st.top();
            st.pop();
        }

        if (arr[i] < root)
        {
            return 0;
        }
        st.push(arr[i]);
    }
    return 1;
}

int main()
{
    int arr[] = {2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << checkPreorderBST(arr, n);
}