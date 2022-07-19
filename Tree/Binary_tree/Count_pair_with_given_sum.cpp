#include<iostream>
#include<unordered_map>
using namespace std;

int countPairWithGivenSum(int arr[], int n, int k){
    unordered_map<int,int>m;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int val = k - arr[i];

        if(m[val]){
            cnt += m[val];
        }
        m[arr[i]]++;
    }
    return cnt;
}

int main()
{
    int arr[] = {1, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout<<countPairWithGivenSum(arr,n,k);
}