#include<iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}


void insertion(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;

        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
    
}

int main()
{
    int arr[] = {2, 6, 21, 6, 8};
    int n = 5;
    insertion(arr, n);
    print(arr, n);
}