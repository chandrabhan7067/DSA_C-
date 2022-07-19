#include<iostream>
#include<limits.h>
using namespace std;

int Smallest_sum_contiguous_subarray(int arr[], int n){
    int ans = INT_MAX;
    int curr = 0;

    for (int i = 0; i < n; i++)
    {
        curr = curr + arr[i];
        curr = min(curr, arr[i]);

        if(ans > curr){
            ans = curr;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {2, 6, 8, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<Smallest_sum_contiguous_subarray(arr,n);
}