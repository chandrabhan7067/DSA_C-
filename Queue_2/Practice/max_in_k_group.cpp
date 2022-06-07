#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> max_in_window(int arr[], int n, int k)
{
    deque<int> maxi;
    vector<int> ans;

    // process first k size window

    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }

        maxi.push_back(i);
    }

    ans.push_back(arr[maxi.front()]);

    // process remaining window

    for (int i = k; i < n; i++)
    {
        // removal
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }

        // addition same as first k size window process

        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }

        maxi.push_back(i);
        ans.push_back(arr[maxi.front()]);
    }

    return ans;
}

int main()
{

    int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int n = 10;
    int k = 4;
    vector<int>ans = max_in_window(arr,n,k);

    for(int i:ans){
        cout<<i<<" ";
    }
}