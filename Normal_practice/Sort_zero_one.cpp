#include <iostream>
using namespace std;

void Print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(int arr[], int n)
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
    Print(arr, n);
}

int main()
{
    int arr[] = {1, 0, 0, 1, 1, 0};
    int n = 6;
    Print(arr, n);
    sort(arr, n);
}