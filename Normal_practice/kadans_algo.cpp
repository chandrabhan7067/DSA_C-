#include <iostream>
#include <algorithm>
using namespace std;

// time  O(n logn)
// space  O(1)

long long maxSubarraySum(int arr[], int n)
{

    int sum = 0;
    int maxi = -99999;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        maxi = max(maxi, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}

int main()
{
    int arr[] =  {1,2,3,-2,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << maxSubarraySum(arr, n);
}