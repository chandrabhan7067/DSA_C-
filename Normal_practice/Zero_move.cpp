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

void Move_zero_right(int arr[], int n)
{
    int first = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[first]);
            first++;
        }
    }
    print(arr, n);
}

int main()
{
    int arr[] = {1, 0, 6, 0, 0, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<1%4<<endl;
    Move_zero_right(arr, n);
}