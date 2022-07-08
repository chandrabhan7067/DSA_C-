#include <iostream>
#include <queue>
using namespace std;

int kthLargest(int arr[4][4], int n, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (pq.size() < k)
            {
                pq.push(arr[i][j]);
            }
            else
            {
                if (pq.top() > arr[i][j])
                {
                    pq.pop();
                    pq.push(arr[i][j]);
                }
            }
        }
    }
    return pq.top();
}

int main()
{
    int arr[4][4] = {{10, 20, 30, 40},
                   {15, 25, 35, 45},
                   {24, 29, 37, 48},
                   {32, 33, 39, 50}};

    cout<<kthLargest(arr,4,7);
}