#include <iostream>
using namespace std;

bool possible_solution(int arr[], int painter_num, int n, int mid)
{
    int sum = 0;
    int painterCount = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] + sum <= mid)
        {
            sum = sum + arr[i];
        }
        else
        {
            painterCount++;
            if (painterCount > painter_num || arr[i] > mid)
            {
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}

int Painter(int arr[], int painter_num, int n)
{
    int s = 0;
    int sum = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (possible_solution(arr,painter_num, n,  mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int arr[] = {5,5,5,5};
    cout << Painter(arr, 2, 4);
}