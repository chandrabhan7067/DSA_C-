#include <iostream>
using namespace std;

int print_sum(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = arr[0];
    return ans + print_sum(arr + 1, n - 1);
}

int main()
{
    int arr[] = {2, 3, 4, 1, 5};
    int n = 5;
    cout << "sum is " << print_sum(arr, n);
}