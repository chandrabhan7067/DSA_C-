#include <iostream>
using namespace std;

void sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << sum;
}

int main()
{
    int n;
    cout << "enter";
    cin >> n;

    // int *p = new int;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value\n";
        cin >> arr[i];
    }
    sum(arr, n);
}