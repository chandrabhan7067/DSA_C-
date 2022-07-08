#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

// Lucy lives in house number X. She has a list of N house numbers in the society. Distance between houses can be determined by studying the difference between house numbers. Help her find out K closest neighbors.

// Note: If two houses are equidistant and Lucy has to pick only one, the house with the smaller house number is given preference.

vector<int>luckNeighbours(vector<int>arr, int n, int k, int x){
    priority_queue<pair<int,int>> maxHeap;

    for (int i = 0; i < n; i++)
    {
        int dist = abs(arr[i] - x);

        if(maxHeap.size() < k){
            maxHeap.push({dist, arr[i]});
        }

        else{
            pair<int,int>topp = maxHeap.top();

            if(topp.first >= dist){
                if(topp.first == dist){
                    if(topp.second > arr[i]){
                        maxHeap.pop();
                        maxHeap.push({dist,arr[i]});
                    }
                }
                else{
                    maxHeap.pop();
                    maxHeap.push({dist,arr[i]});
                }
            }
        }
    }

    vector<int>ans;

    while(!maxHeap.empty()){
        pair<int,int>topp = maxHeap.top();
        ans.push_back(topp.second);
        maxHeap.pop();
    }
    
    sort(ans.begin(), ans.end());
    return ans;

}

// 5 -11 3
// -13 -10 -9 -7 -15

int main()
{
    vector<int>arr{-21, 21, 4, -12, 20};
    int x = 0;
    int n = arr.size();
    int k = 4;

    vector<int>ans = luckNeighbours(arr,n,k,x);

    for(auto i:ans){
        cout<<i<<" ";
    }
}