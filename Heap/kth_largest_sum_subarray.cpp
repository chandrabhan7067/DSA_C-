#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// time complexity   O(n^2 logk)
// space complexity   O(n^2)

// int K_th_Largest_Sum_Contiguous_Subarray(vector<int>arr, int n, int k){
//     vector<int>ans;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             ans.push_back(sum);
//         }
//     }
//     sort(ans.begin(), ans.end());
//     return ans[ans.size()-k];
// }

// space O(k)

int K_th_Largest_Sum_Contiguous_Subarray(vector<int> arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> mini;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (mini.size() < k)
            {
                mini.push(sum);
            }
            else
            {
                if (mini.top() < sum)
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

int main()
{
    vector<int> arr{3, 2, 1};
    int n = arr.size();
    int k = 2;
    cout << K_th_Largest_Sum_Contiguous_Subarray(arr, n, k);
}