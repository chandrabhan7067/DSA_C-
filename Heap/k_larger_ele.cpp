#include<iostream>
#include<queue>
using namespace std;

vector<int>kLarger(int arr[], int n, int k){
    priority_queue<int>pq;

    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
    }

    vector<int>ans;
    for(int i = 0; i < k; i++){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main()
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    vector<int>ans = kLarger(arr,n,k);

    for(auto i:ans){
        cout<<i<<" ";
    }    
    cout<<endl;
}