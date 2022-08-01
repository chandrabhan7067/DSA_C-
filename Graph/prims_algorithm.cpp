#include <iostream>
#include<limits.h>
#include <unordered_map>
#include <vector>
using namespace std;

int spanningTree(int n, vector<vector<int>> adj[])
{
    vector<int>key(n,INT_MAX);
    vector<int>parent(n,-1);
    vector<int>mst(n,false);

    key[0] = 0;

    for (int i = 0; i < n; i++)
    {
        // first find the minimum value in key array
        int mini = INT_MAX;
        int u;

        for (int j = 0; j < n; j++)
        {
            if(mst[j] == false && key[j] < mini){
                mini = key[j];
                u = j;
            }
        }

        mst[u] = true;
        
        auto children = adj[u];

        for (int i = 0; i < children.size(); i++)
        {
            int v = children[i][0];
            int w = children[i][1];

            if(mst[v] == false && key[v] > w){
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += key[i];
    }
    return sum;
}

int main()
{
    vector<vector<int>>adj[] = {{{1,5}},{{0,5}}};

    cout<<spanningTree(2,adj);
}