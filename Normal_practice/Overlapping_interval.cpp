#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<int>>overlappintIntervals(vector<vector<int>>arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int mini = arr[0][0];
    int maxi = arr[0][1];
    vector<vector<int>>ans;

    for (int i = 1; i < n; i++)
    {
        if(maxi < arr[i][0]){
            ans.push_back({mini,maxi});
            mini = arr[i][0];
            maxi = arr[i][1];
        }
        else{
            if(maxi < arr[i][1]){
                maxi = arr[i][1];
            }
        }
    }
    ans.push_back({mini,maxi});
    return ans;
}

int main()
{
    vector<vector<int>>v{{6,8},{1,9},{2,4},{4,7}};
    vector<vector<int>>ans = overlappintIntervals(v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<"(";
        for (int j = 0; j < ans[0].size(); j++)
        {
            
            cout<<ans[i][j]<<" ";
        }
        cout<<")";
        cout<<endl;
    }
    
}