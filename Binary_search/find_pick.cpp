#include<iostream>
using namespace std;

int PickElement(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    // while (s<e)
    // {
    //     if (arr[mid] < arr[mid+1])
    //     {
    //         s = mid+1;
    //     }
    //     else{
    //         e = mid;
    //     }
    //     mid = s+(e-s)/2;
    // }
    // return s;

    while(s<=e){
        if (arr[mid] < arr[mid+1])
        {
            s = mid + 1;
        }
        else if (arr[mid] > arr[mid+1])
        {
            e = mid-1;
        }
        else{
            return arr[mid];
        }
        mid = s+(e-s)/2;
    }
}

int main()
{
    // int arr[] = {0,2,1,0};
    int arr[] = {3,8,10,17,1,0};

    int n = 6;
    cout<<PickElement(arr,n);
}