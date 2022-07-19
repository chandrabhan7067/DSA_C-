#include<iostream>
#include<vector>
using namespace std;

int MissingNumber(vector<int>& arr, int n) {
    // Your code goes here
    int sum = 0;
    
    for(int i = 0; i < n - 1; i++){
        sum += arr[i];
    }
    
    int sum1 = ((n) * (n + 1))/2;
    return sum1 - sum;
    
}

int main()
{
    vector<int>arr{6,1,2,8,3,4,7,10,5};
    int n = arr.size();
    // cout<<n<<endl;
    cout<<MissingNumber(arr,n+1);
}