
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int>min_in_K_group(int arr[], int n, int k){
    deque<int>mini;
    vector<int>ans;

    for (int i = 0; i < k; i++)
    {
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        mini.push_back(i);
    }
    ans.push_back(arr[mini.front()]);


    for (int i = k; i < n; i++)
    {
        // removal 

        while(!mini.empty() && i - mini.front() >= k){
            mini.pop_front();
        }

        // addition

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        mini.push_back(i);
        ans.push_back(arr[mini.front()]);
    }
    return ans;
    
}

int main()
{
    int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int n = 10;
    int k = 4;
    vector<int>ans = min_in_K_group(arr,n,k);

    for(int i:ans){
        cout<<i<<" ";
    }

}

