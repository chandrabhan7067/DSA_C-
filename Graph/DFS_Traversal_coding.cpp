#include <iostream>
#include <vector>
#include<list>
#include <unordered_map>
using namespace std;

void dfs(int node, unordered_map<int,list<int>>&adj, unordered_map<int, bool> &visited, vector<int> &ans)
{

    ans.push_back(node);
    visited[node] = true;

    for (auto i:adj[node])
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, ans);
        }
    }
}

int main()
{
    vector<vector<int>>edges = {{1,2,4},{0},{0},{0,3},{4}};
    unordered_map<int,bool>visited;
    unordered_map<int,list<int>>adj;
    int V = 5;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>>ans; 

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            vector<int>component;
            dfs(i, adj, visited, component);
            ans.push_back(component);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        
    }
    
}
