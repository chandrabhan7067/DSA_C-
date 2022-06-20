#include<iostream>
using namespace std;

int* mergeArray(int arr1[],int arr2[],int n, int m){
    int *newArray = new int[n+m];
    int i = 0, j = 0, k = 0;

    while(i < n && j < m){
        if(arr1[i] < arr2[j]){
            newArray[k] = arr1[i];
            i++;
            k++;
        }

        else{
            newArray[k] = arr2[j];
            j++;
            k++;
        }
    }

    while(i < n){
        newArray[k] = arr1[i];
        i++;
        k++;
    }

    while(j < m){
        newArray[k] = arr2[j];
        j++;
        k++;
    }

    return newArray;
}

int main()
{
    int arr1[] = {1,3,5,7};
    int arr2[] = {2,4,6,8,10};
    int n = 4;
    int m = 5;
    int *newArray = mergeArray(arr1,arr2,n,m);

    for (int i = 0; i < 9; i++)
    {
        cout<<newArray[i]<<" ";
    }
}