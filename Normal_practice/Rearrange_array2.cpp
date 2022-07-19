#include <iostream>
using namespace std;

// Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]].

// time compelexity  O(n)
// space complexxity  O(1)

void Rearrange_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = (arr[arr[i]] % n) * n + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] /= n;
    }
}

int main()
{
    int arr[] = {4, 0, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    Rearrange_array(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}