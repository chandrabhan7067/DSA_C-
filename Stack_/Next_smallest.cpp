#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void print(vector<int> ans)
{
    for (int i : ans)
    {
        cout << i << " ";
    }
}

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int value = arr[i];

        while (st.top() >= value)
        {
            st.pop();
        }
        ans[i] = st.top();
        cout << st.top() << endl;
        st.push(value);
    }
    return ans;
}

int main()
{
    vector<int> arr{2, 1, -1};
    int n = arr.size();
    vector<int> ans = nextSmallerElement(arr, n);
}