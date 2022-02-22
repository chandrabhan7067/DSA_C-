#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void find(int arr[], int n)
{
    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        int value = i;
        for (int j = 0; j < n; j++)
        {
            if (value == arr[j])
            {
                a[i] = value;
                break;
            }
            else
            {
                a[i] = -1;
            }
        }
    }
    print(a, n);
}

int main()
{
    int arr[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    find(arr, n);
}
// -1, 1, 2, 3, 4, -1, 6, -1, -1, 9]