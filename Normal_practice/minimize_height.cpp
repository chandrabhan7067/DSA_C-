#include <iostream>
#include <algorithm>
using namespace std;

// time  O(n logn)
// space  O(1)

int minimizeHeight(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    int tempmin, tempmax;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - k < 0)
        {
            continue;
        }

        tempmin = min(arr[0] + k, arr[i] - k);
        tempmax = max(arr[n - 1] - k, arr[i - 1] + k);
        ans = min(ans, tempmax - tempmin);
    }
    return ans;
}

int main()
{
    int arr[] = {1, 5, 8, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout<<minimizeHeight(arr,n,k);
}