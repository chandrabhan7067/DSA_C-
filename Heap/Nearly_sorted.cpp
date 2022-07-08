#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int>nearlySorted(vector<int>arr, int n, int k){
    priority_queue<int,vector<int>,greater<int> > mini;

    for (int i = 0; i < n; i++)
    {
        mini.push(arr[i]);
    }

    vector<int>ans;
    
    while(!mini.empty()){
        ans.push_back(mini.top());
        mini.pop();
    }
    return ans;
}

int main()
{
    vector<int>arr{6,5,3,2,8,10,9};
    int n = arr.size();
    int k = 3;

    vector<int>ans = nearlySorted(arr,n,k);

    for(auto i:ans){
        cout<<i<<" ";
    }
}