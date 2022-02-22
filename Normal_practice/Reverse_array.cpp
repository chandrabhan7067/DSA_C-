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

void ReverseArray(int arr[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    print(arr,n);
}

int main()
{
    int arr[] = {1,5,3,6,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    ReverseArray(arr,n);
}