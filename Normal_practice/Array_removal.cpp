#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

// Given an array arr[] of size N and an integer K. The task is to find the minimum number of elements that should be removed, such that Amax-Amin<=K. After the removal of elements, Amax and Amin is considered among the remaining elemen

int arrayRemoval(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = n;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        while (arr[i] - arr[j] > k)
        {
            j++;
        }
        ans = min(ans, j + n - 1 - i);
    }
    return ans;
}

int main()
{
    int arr[] = {1, 5, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << arrayRemoval(arr, n, k);
}