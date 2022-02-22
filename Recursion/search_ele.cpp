#include <iostream>
using namespace std;

bool search(int arr[], int n, int key)
{
    if (n == 0)
    {
        return false;
    }
    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        bool ans = search(arr + 1, n - 1, key);
        return ans;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int key = 8;
    int n = 5;

    if (search(arr, n, key))
    {
        cout << "present";
    }
    else
    {
        cout << "not present";
    }
}