#include <iostream>
using namespace std;

int *bubble(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if ((arr[j] > arr[j + 1]))
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

int duplicate(int arr[], int n)
{
    int *New_array = bubble(arr, n);
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        if (New_array[i] == New_array[i + 1])
        {
            ans = New_array[i];
            return ans;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {5, 3, 6, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << duplicate(arr, n);
}