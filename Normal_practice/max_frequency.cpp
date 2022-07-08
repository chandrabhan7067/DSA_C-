#include <limits.h>
#include <iostream>
#include <unordered_map>
using namespace std;

int maxFrequency(int arr[], int n)
{
    int maxFre = 0;
    int ans;
    unordered_map<int, int> mapping;

    for (int i = 0; i < n; i++)
    {
        mapping[arr[i]]++;
        maxFre = max(maxFre, mapping[arr[i]]);
    }

    for (int i = 0; i < n; i++)
    {
        if (mapping[arr[i]] == maxFre)
        {
            ans = arr[i];
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 2};
    int n = 5;
    cout << maxFrequency(arr, n);
}