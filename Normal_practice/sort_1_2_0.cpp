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

void sort012(int *arr, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            swap(arr[s], arr[i]);
            s++;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count++;
        }
        else if (arr[i] == 1)
        {
            swap(arr[count], arr[i]);
            count++;
        }
    }
    print(arr, n);
}

int main()
{
    int arr[] = {0, 1, 2, 1, 2, 1, 2};
    int n = 7;
    sort012(arr, n);
}