#include <iostream>
#include <algorithm>
using namespace std;

bool tripletSum(int arr[], int n, int x)
{
    sort(arr, arr + n);
    int sum = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            sum = arr[i] + arr[j] + arr[k];

            if (sum == x)
            {
                return true;
            }

            else if (sum > x)
            {
                k--;
            }

            else
            {
                j++;
            }
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 2, 4, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 100;

    cout << tripletSum(arr, n, x);
}