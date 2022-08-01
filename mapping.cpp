#include <iostream>
#include <map>
using namespace std;

int main()
{
    string st = "chand";
    int arr[] = {5, 6, 7, 4, 8};

    map<int, char> mapp;

    for (int i = 0; i < 5; i++)
    {
        // cout<<arr[i]<<" ";
        mapp[arr[i]] = st[i];
    }

    cout << mapp[8];
}