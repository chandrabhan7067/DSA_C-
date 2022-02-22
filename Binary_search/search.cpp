#include <iostream>
using namespace std;

void IsPresent(int arr[], int s, int e, int value)
{
    int mid = (s + e) / 2;
    while (s <= e)
    {
        if (arr[mid] == value)
        {
            cout << "present" << endl;
            return;
        }
        if (value < arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = (s + e) / 2;
    }
    cout << " Not present" << endl;
    return;
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6};
    int n = 5;
    IsPresent(arr, 0, n - 1, 6);
}