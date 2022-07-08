#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long minCost(long long arr[], int n)
{
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
    }

    long long ans = 0;

    while (minHeap.size() >= 2)
    {
        long long a = minHeap.top();
        minHeap.pop();

        long long b = minHeap.top();
        minHeap.pop();

        minHeap.push(a + b);
        ans += a + b;
    }
    return ans;
}

int main()
{
    long long arr[] = {4, 2, 7, 6, 9};
    int n = 5;
    cout<<minCost(arr,n);
}

// First, connect ropes 4 and 2, which makes
// the array {6,7,6,9}. Next, add ropes 6 and
// 6, which results in {12,7,9}. Then, add 7
// and 9, which makes the array {12,16}. And
// finally add these two which gives {28}.
// Hence, the total cost is 6 + 12 + 16 + 
// 28 = 62.