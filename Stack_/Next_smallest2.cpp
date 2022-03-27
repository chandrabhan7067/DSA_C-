#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

void nextsmaller(int arr[], int n)
{
    int ans[n] = {0};

    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < temp)
            {
                temp = arr[j];
            }
        }
        ans[i] = temp;
    }
    ans[n - 1] = -1;
    print(ans, n);
}


void prevsmaller(int arr[], int n)
{
    int ans[n] = {0};

    for (int i = n-1; i >= 0; i--)
    {
        int temp = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < temp)
            {
                temp = arr[j];
            }
        }
        ans[i] = temp;
    }
    ans[0] = -1;
    print(ans, n);
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = 3;
    cout<<"previous smaller element is:"<<endl;
    prevsmaller(arr, n);
    cout<<"next smaller element is:"<<endl;
    nextsmaller(arr,n);
}