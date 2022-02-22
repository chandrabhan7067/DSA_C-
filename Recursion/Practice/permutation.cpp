#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>>ans){
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<",";
    }
}

void solve(vector<int>nums, int index, vector<vector<int>> &ans){
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        swap(nums[index], nums[i]);
        solve(nums,index+1,ans);
        swap(nums[index], nums[i]);
    }
}

int main()
{
    vector<int>nums{1,2,3};
    vector<vector<int>>ans;
    int index = 0;
    solve(nums,index,ans);
    print(ans);
}