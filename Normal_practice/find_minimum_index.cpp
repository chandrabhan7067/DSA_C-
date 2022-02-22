#include <iostream>
using namespace std;

int main()
{
    int arr[] = {7, 9, 11, 12, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int count = 0;
    int minimum = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minimum)
        {
            minimum = arr[i];
            count = i;
        }
    }
    cout << "Minimum value index is:" << count;
}