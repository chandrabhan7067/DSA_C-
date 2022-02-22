#include <iostream>
using namespace std;

int Unique(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

// int ans = 0;
// cout<<(0^3)<<endl;
// cout<<(3^4)<<endl;
// cout<<(7^5)<<endl;
// cout<<(3^2)<<endl;
// cout<<(1^4)<<endl;

int main()
{
    int arr[] = {3, 4, 5, 3, 4};
    int n = 5;
    cout << Unique(arr, n);
}