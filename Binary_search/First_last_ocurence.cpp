#include <iostream>
using namespace std;

int first(int arr[], int n, int key)
{
    int start = 0;
    int last = n - 1;
    int mid = (start + last) / 2;
    int ans = -1;

    while(start <= last)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            last = mid - 1;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else{
            last = mid - 1;
        }
        mid = (start + last) / 2;
    }
    return ans;
}

int end(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    int mid = (s+e)/2;
    int ans = -1;

    while (s<=e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            s = mid+1;
        }
        else{
            e = mid -1;
        }
        mid = (s+e)/2;
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 3, 4};
    int n = 6;

    cout<<first(arr,n,3);
    cout<<end(arr,n,3);
}