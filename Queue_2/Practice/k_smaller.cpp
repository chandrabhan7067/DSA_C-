#include <iostream>
#include <queue>
using namespace std;

int kth_smaller(int arr[], int left, int right, int k)
{
    // k = left + right - k;
    priority_queue<int> q;

    for (int i = 0; i < k; i++)
    {
        q.push(arr[i]);
    }
    // cout<<q.top();

    for (int i = k; i <= right; i++)
    {
        if (arr[i] < q.top())
        {
            q.pop();
            q.push(arr[i]);
        }
    }
    return q.top();
}

int main()
{
    int arr[] = {7,10,4,3,20,15};
    int r = 5;
    int l = 0;
    cout<<kth_smaller(arr,l,r,3);
}