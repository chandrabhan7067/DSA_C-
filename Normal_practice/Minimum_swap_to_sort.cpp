#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

// time   O(n log n)
// space  O(n)

int minimumSwap(vector<int>arr, int n){

    vector<int>temp(arr.begin(), arr.end());
    map<int, int>mapping;

    for (int i = 0; i < n; i++)
    {
        mapping[arr[i]] = i;
    }
    
    sort(temp.begin(), temp.end());
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if(temp[i] != arr[i]){
            ans++;
            int ele = arr[i];
            int index = mapping[temp[i]];
            swap(arr[index], arr[i]);
            mapping[ele] = index;
            mapping[arr[i]] = i;
        }
    }
    return ans;
    
}

int main()
{
    vector<int>arr{8, 3, 14, 17, 15, 1, 12};
    cout<<minimumSwap(arr,arr.size());
}