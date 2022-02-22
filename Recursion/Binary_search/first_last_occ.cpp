#include <iostream>
using namespace std;

void print(int arr[], int s, int e)
{
    for (int i = 0; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int first = -1;

int first_occ(int arr[], int s, int e, int key)
{
    if (s > e)
    {
        return first;
    }

    int mid = (s + e) / 2;
    if (arr[mid] == key)
    {
        first = mid;
        return first_occ(arr, s, mid - 1, key);
    }

    if (arr[mid] < key)
    {
        return first_occ(arr, mid + 1, e, key);
    }
    else
    {
        return first_occ(arr, s, mid - 1, key);
    }
}

int last = -1;

int last_occ(int arr[], int s, int e, int key)
{
    if (s > e)
    {
        return last;
    }

    int mid = (s + e) / 2;
    if (arr[mid] == key)
    {
        last = mid;
        return first_occ(arr, mid + 1, e, key);
    }

    if (arr[mid] < key)
    {
        return first_occ(arr, mid + 1, e, key);
    }
    else
    {
        return first_occ(arr, s, mid - 1, key);
    }
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 6, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "first occ is " << first_occ(arr, 0, n - 1, 6);
    cout << "first occ is " << last_occ(arr, 0, n - 1, 6);
}