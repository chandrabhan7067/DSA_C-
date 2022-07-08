#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> kthLargestStream(int arr[], int n, int k)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> mini;

    for (int i = 0; i < k; i++)
    {
        if (i < k - 1)
        {
            ans.push_back(-1);
        }
        mini.push(arr[i]);
    }

    ans.push_back(mini.top());

    for (int i = k; i < n; i++)
    {
        if (mini.top() < arr[i])
        {
            mini.pop();
            mini.push(arr[i]);
        }
        ans.push_back(mini.top());
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    vector<int> ans = kthLargestStream(arr, n, k);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}