#include <iostream>
using namespace std;

int *bubble(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

void find_duplicate(int arr[], int n)
{
    int *new_array = bubble(arr, n);

    for (int i = 0; i < n - 1; i++)
    {
        if (new_array[i] == new_array[i + 1])
        {
            cout << new_array[i]<<endl;
        }
    }
}

int main()
{
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    find_duplicate(arr, n);
}