#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }
    // call of exclude

    solve(nums, output, index + 1, ans);

    // call for include

    int ele = nums[index];
    output.push_back(ele);
    solve(nums, output, index + 1, ans);
}

int main()
{
    vector<int> nums{1, 2, 3};
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    print(ans);
}