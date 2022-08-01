#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges){
    
    vector<vector<int>>vec(n);

    for(int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    vector<vector<int>>adj(n);

    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);

        for (int j = 0; j < vec[i].size(); j++)
        {
            adj[i].push_back(vec[i][j]);
        }
    }
}

int main()
{

}