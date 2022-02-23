#include <iostream>
using namespace std;

int find(int arr[], int s, int e, int key)
{
    int mid = (s + e) / 2;
    int pos = -1;

    // if (s >= e)
    // {
    //     return e+1;
    // }


    if (s >= e)
    {
        return pos;
    }

    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[mid] < key)
    {
        find(arr, mid + 1, e, key);
    }
    else
    {
        find(arr, s, mid - 1, key);
        pos = mid;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6};
    int n = 5;
    int s = 0;
    int e = n - 1;
    int key = 4;
    cout << find(arr, s, e, key);
}