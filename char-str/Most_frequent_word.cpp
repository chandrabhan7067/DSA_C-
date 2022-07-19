#include <iostream>
#include <map>
using namespace std;

string mostFrequent(string arr[], int n)
{
    map<string, int> mapping;
    map<string, bool> vis;
    string ans = "";
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        mapping[arr[i]]++;
        vis[arr[i]] = false;

        if (mapping[arr[i]] > max)
        {
            max = mapping[arr[i]];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[arr[i]] == false && mapping[arr[i]] == max)
        {
            ans = arr[i];
            vis[arr[i]] = true;
        }
    }

    return ans;
}

int main()
{
    string arr[] = {"xejdcj", "xejdcj", "lvjpb", "tmyuiu", "lvjpb", "tmyuiu", "ovoba", "lvjpb", "lvjpb", "fqhyu", "fqhyu", "tmyuiu", "xejdcj", "tmyuiu", "fqhyu", "ovoba", "xejdcj"};
    int n = 17;
    cout<<mostFrequent(arr,n);
}
