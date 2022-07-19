#include<iostream>
#include<algorithm>
using namespace std;

long long int minimumSum(int arr[], int n){
    long long int a = 0, b = 0;
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        if(i % 2 == 0){
            a = a * 10 + arr[i];
        }
        else{
            b = b * 10 + arr[i];
        }
    }
    return a + b;
}

int main()
{
    int arr[] = {5, 3, 0, 7, 4};
    int n = sizeof(arr)/sizeof(arr+n);
    // cout<<n;
    cout<<minimumSum(arr, n);
}