#include <iostream>
#include <map>
using namespace std;

int majorityEle(int arr[], int n)
{
    map<int, int> mapping;

    for (int i = 0; i < n; i++)
    {
        mapping[arr[i]]++;
    }

    int majority = n / 2;
    for (int i = 0; i < n; i++)
    {
        if (mapping[arr[i]] > majority)
        {
            return arr[i];
        }
    }
    return -1;
}

int main()
{
    int arr[] = {3,1,1,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<majorityEle(arr,n);
}