#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

// Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number

vector<vector<int>> fourSum(vector<int> arr, int k)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    set<vector<int>> temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int start = j + 1;
            int end = n - 1;

            while (start < end)
            {
                long long int sum = arr[i] + arr[j] + arr[start] + arr[end];

                if (sum == k)
                {
                    temp.insert({arr[i], arr[j], arr[start], arr[end]});
                    start++;
                    end--;
                }

                else if (sum > k)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
    }
    vector<vector<int>> ans(temp.begin(), temp.end());
    return ans;
}

int main()
{
    vector<int> arr{10,2,3,4,5,7,8};
    int k = 23;

    vector<vector<int>> ans = fourSum(arr, k);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout<<endl;
    }
}