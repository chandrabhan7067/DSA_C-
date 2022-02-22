#include<iostream>
using namespace std;

void print(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int sorted(int arr[], int n){
    int s = 0;
    int e = n-1;
    
    while(s<=e){
        if(arr[s] > arr[e]) 
        {
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
        else{
            s++;
            e--;
        }
    }
}

int main()
{
    int arr[] = {7,4,6,8,2,9};
    int n = 6;
    print(arr,n);
    sorted(arr,n);
    print(arr,n);
}