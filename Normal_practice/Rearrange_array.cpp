#include <iostream>
using namespace std;

void reArrange(int arr[], int n)
{
    int mini = 0;
    int maxi = n - 1;
    int maxEle = arr[n - 1] + 1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] += (arr[maxi] % maxEle) * maxEle;
            maxi--;
        }

        else
        {
            arr[i] += (arr[mini] % maxEle) * maxEle;
            mini++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] /= maxEle;
    }

}
int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    reArrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}