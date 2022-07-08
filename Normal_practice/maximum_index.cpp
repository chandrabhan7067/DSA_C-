#include<iostream>
using namespace std;
// Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] < A[j] and i < j.
 

int maxIndexDiff(int arr[], int n){
    int *mini = new int[n];
    int *maxi = new int[n];    

    mini[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        mini[i] = min(mini[i-1],arr[i]);
    }
    
    maxi[n-1] = arr[n-1];

    for (int i = n-2; i >= 0; i--)
    {
        maxi[i] = max(maxi[i+1], arr[i]);
    }
    
    int i = 0, j = 0;
    int ans = -1;

    while(i < n && j < n){
        if(mini[i] <= maxi[j]){
            ans = max(ans, j - i);
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxIndexDiff(arr,n);

}