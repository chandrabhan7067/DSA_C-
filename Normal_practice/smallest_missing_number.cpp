#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

// int missingNumber(int arr[], int n){
//     sort(arr, arr+n);
//     int s = 1;

//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i] == s){
//             s++;
//         }
//     }
//     return s;
// }


// another solution 

int missingNumber(int arr[], int n){
    unordered_map<int,int>mapping;

    for (int i = 0; i < n; i++)
    {
        mapping[arr[i]]++;
    }
    
    for (int i = 1; i <= n+1; i++)
    {
        if(mapping[i] == 0){
            return i;
        }
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<missingNumber(arr,n);
}