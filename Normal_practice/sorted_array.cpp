#include<iostream>
using namespace std;

bool sorted(int arr[], int n){
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            return 0;
        }
        
    }
    return 1;
}

int main()
{
    int arr[] = {1,2,9,4,6};
    int n = 5;

    if(sorted(arr,n)){
        cout<<"sorted";
    }
    else{
        cout<<"not sorted";
    }
}