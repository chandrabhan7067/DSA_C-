#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void selection(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[key])
            {
                key = j;
            }
        }
        swap(arr[i], arr[key]);
    }
}

int main()
{
    int arr[] = {2, 6, 21, 5, 4, 12, 8};
    int n = 7;
    selection(arr, n);
    print(arr, n);
}