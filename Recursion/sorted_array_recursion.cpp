#include <iostream>
using namespace std;

bool is_sorted(int arr[], int n)
{
    // base case

    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        is_sorted(arr + 1, n - 1);
        // return remainingpart;
    }
}

int main()
{
    int arr[] = {1, 2, 8, 4, 5};
    int n = 5;

    if (is_sorted(arr, 5))
    {
        cout << "Sorted";
    }
    else
    {
        cout << "Not sorted";
    }
}