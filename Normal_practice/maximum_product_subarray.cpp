#include <iostream>
#include <limits.h>
using namespace std;

// time complexity  O(n)
// space complexity  O(1)

int maxProductSubarray(int arr[], int n)
{
    int maxi = INT_MIN, product = 1;

    for (int i = 0; i < n; i++)
    {
        product *= arr[i];
        maxi = max(maxi, product);

        if (product == 0)
        {
            product = 1;
        }
    }

    product = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        product *= arr[i];
        maxi = max(maxi, product);

        if (product == 0)
        {
            product = 1;
        }
    }
    return maxi;
}

int main()
{
    int arr[] = {6, -3, -10, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxProductSubarray(arr, n);
}