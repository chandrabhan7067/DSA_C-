#include<iostream>
using namespace std;

int Divide_IntoEqualPart(int arr[], int n){
    int sum1 = 0;
    for(int i = 0; i < n; i++){
        sum1 += arr[i];
    }

    int sum2 = 0;

    for (int i = 0; i < n; i++)
    {
        sum2 += arr[i];

        if(sum2 == sum1){
            return i+1;
        }
        sum1 -= arr[i];
    }
    return -1;
}

int main()
{
    int arr[] = {1,3,5,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<Divide_IntoEqualPart(arr,n);
}