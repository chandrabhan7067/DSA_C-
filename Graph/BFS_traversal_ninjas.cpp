#include <iostream>
#include <vector>
#include <unordered_map>
#include<set>
#include <queue>
using namespace std;

void makeADj(unordered_map<int,set<int>>&adj, vector<pair<int, int>> edges){

    for(auto i:edges){
        int u = i.first;
        int v = i.second;

        adj[u].insert(v);
        adj[v].insert(u);
    }

}

void bfs(unordered_map<int,set<int>>&adj, unordered_map<int, bool>&visited, vector<int> &ans, int Node)
{
    queue<int> q;
    q.push(Node);
    visited[Node] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for (auto i:adj[frontNode])
        {

            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int v = 4;
    vector<int>ans;
    unordered_map<int,set<int>>adj;
    vector<pair<int, int>> edges{{0,1},{0,2},{0,3},{2,4}};
    unordered_map<int,bool>visited;

    makeADj(adj,edges);

// for disconnected graph
    for(int i = 0; i < v; i++){
        if(!visited[i])
            bfs(adj,visited,ans,0);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    

}