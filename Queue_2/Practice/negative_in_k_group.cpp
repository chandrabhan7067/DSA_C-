#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> solve(int arr[], int n, int k)
{
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }

    if (dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    for (int i = k; i < n; i++)
    {
        // remove elemenet which are not presern in window size
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // addition

        if (arr[i] < 0)
        {
            dq.push_back(i);
        }

        if (dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int arr[] = {-8, 2, 3, -6, 10};
    int n = 5;
    int k = 2;
    solve(arr, n, k);
}