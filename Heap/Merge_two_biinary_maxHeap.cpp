#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>&arr, int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i+2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

int main()
{

    vector<int>arr1{10, 5, 6, 2};
    vector<int>arr2{12, 7, 9};
    vector<int>ans;

    for(auto i:arr1){
        ans.push_back(i);
    }

    for(auto i:arr2){
        ans.push_back(i);
    }

    int n = ans.size();
    // build heap
    for(int i = n/2-1; i >= 0; i--){
        heapify(ans,n,i);
    }
    
    for(auto i:ans){
        cout<<i<<" ";
    }
}