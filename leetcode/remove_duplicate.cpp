#include <iostream>
using namespace std;

int remove_duplicates(int arr[], int n)
{
    int l = 1;
    int r = 1;
    while (r < n)
    {
        if (arr[r] != arr[r - 1])
        {
            arr[l] = arr[r];
            l++;
        }
        r++;
    }
    return l;
}

int main()
{
    int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << remove_duplicates(arr, n);
}