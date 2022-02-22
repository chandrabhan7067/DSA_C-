#include <iostream>
using namespace std;

bool binary_search(int arr[], int s, int e, int key)
{
    if (s > e)
    {
        return false;
    }

    int mid = (s + e) / 2;

    if (arr[mid] == key)
    {
        return true;
    }

    if (arr[mid] < key)
    {
        binary_search(arr, mid + 1, e, key);
    }
    else
    {
        binary_search(arr, s, mid - 1, key);
    }
}

int main()
{
    int arr[] = {2, 4, 6, 8, 9};
    int n = 5;
    int key = 8;

    if (binary_search(arr, 0, n - 1, key))
    {
        cout << "present";
    }
    else
    {
        cout << "Not present";
    }
}