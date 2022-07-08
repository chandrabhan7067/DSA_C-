#include <iostream>
#include <unordered_map>
using namespace std;

//  time O(n)  and space  O(1) 

void print(int *arr, int n)
{
    for (int i = 0; i < 2; i++)
    {
        cout << arr[i] << " ";
    }
}

int *findMissingAndRepeating(int *arr, int n)
{
    unordered_map<int, int> m;
    // int *ans = new int[2];
    int ans[2] = {0};

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (m[i] == 0)
        {
            ans[1] = i;
        }
        else if (m[i] > 1)
        {
            ans[0] = i;
        }
    }
    // return ans;
    print(ans, 2);
}

// first element is repeating character and second is missing character

int main()
{
    int arr[] = {1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    findMissingAndRepeating(arr, n);
}