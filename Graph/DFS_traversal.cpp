#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(int node, vector<int> adj[], unordered_map<int, bool> &visited, vector<int> &ans)
{

    ans.push_back(node);
    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
        {
            dfs(adj[node][i], adj, visited, ans);
        }
    }
}

int main()
{
    vector<int>adj[] = {{0,1,2,4},{1,0},{2,0},{4,0,3},{3,4}};
    unordered_map<int,bool>visited;
    vector<int>ans;
    dfs(0,adj, visited, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}
