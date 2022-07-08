#include <iostream>
#include <vector>
using namespace std;

// time complexity  O(n)

vector<int> subArray(int arr[], int n, int s)
{
    int start = 0;
    int end = 0;
    int sum = 0;
    vector<int> ans;

    while (start < n)
    {
        sum += arr[end];

        if (sum == s)
        {
            ans.push_back(start + 1);
            ans.push_back(end + 1);
            return ans;
        }

        else if (sum > s)
        {
            start++;
            end = start;
            sum = 0;
        }

        else
        {
            end++;
        }
    }
    if (sum == s)
    {
        ans.push_back(-1);
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 15;
    vector<int> ans = subArray(arr, n, s);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}