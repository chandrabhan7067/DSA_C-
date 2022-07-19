#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> nextPermutation(vector<int> arr)
{
    int n = arr.size();
    int index = -1;
    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] > arr[i - 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
    }
    else
    {
        int pre = index;
        for (int i = index + 1; i < n; i++)
        {
            if (arr[index - 1] < arr[i] && arr[i] < arr[pre])
            {
                pre = i;
            }
        }
        swap(arr[index - 1], arr[pre]);
        reverse(arr.begin() + index, arr.end());
    }
    return arr;
}

int main()
{
    vector<int> arr{1, 2, 3, 6, 5, 4};
    vector<int> ans = nextPermutation(arr);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}