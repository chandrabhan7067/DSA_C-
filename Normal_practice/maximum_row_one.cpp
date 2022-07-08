#include <iostream>
#include<vector>
using namespace std;

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int ans = 0;
    int row = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
            }
        }

        if (ans < count)
        {
            ans = count;
            row = i;
        }
    }
    return row;
}

int main()
{
    vector<vector<int> >arr {{0, 0}, {1, 1}};

    int n = arr.size();
    int m = arr[0].size();
    cout<<rowWithMax1s(arr,n,m);
}