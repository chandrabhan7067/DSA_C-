#include <iostream>
using namespace std;

int find(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
        else if (arr[i] > target)
        {
            return i;
        }
    }
    return n;
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6};
    int n = 5;
    int target = 7;
    cout << find(arr, n, target);
}