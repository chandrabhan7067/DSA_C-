#include<iostream>
#include<queue>
using namespace std;

int ArrayAddition(int arr[], int n, int k){

    priority_queue<int,vector<int>,greater<int>>mini;

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        mini.push(arr[i]);
    }

    while(mini.size() > 1){

        if(mini.top() >= k){
            break;
        }
        else{
            int a = mini.top();
            mini.pop();
            int b = mini.top();
            mini.pop();
            mini.push(a+b);
            cnt++;
        }
    }
    
    if(mini.top() < k){
        return -1;
    }
    return cnt;
}

int main()
{
    int arr[] = {5, 4, 6, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;

    cout<<ArrayAddition(arr,n,k);

}