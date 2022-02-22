#include <iostream>
using namespace std;

// we have given a value and our last is remove those value which is mached to given value ans return the len of array after removing the element

int removeVal(int arr[], int n, int val)
{
    int l = 0;
    int r = 0;

    while (r < n)
    {
        if (arr[r] != val)
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
    int arr[] = {3, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << removeVal(arr, n, 3);
}