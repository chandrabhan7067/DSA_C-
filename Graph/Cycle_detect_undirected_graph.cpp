#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool checkCycleBFS(int node, unordered_map<int, bool> &visited, vector<int> adj[])
{

    unordered_map<int, int> parent;
    queue<int> q;
    q.push(node);
    visited[node] = true;
    parent[node] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int i = 0; i < adj[front].size(); i++)
        {
            if (visited[adj[front][i]] == true && adj[front][i] != parent[front])
            {
                return true;
            }
            else if (!visited[adj[front][i]])
            {
                q.push(adj[front][i]);
                visited[adj[front][i]] = true;
                parent[adj[node][i]] = front;
            }
        }
    }
    return false;
}

bool checkCycleDFS(int node, int parent, vector<int> adj[],unordered_map<int,bool>&visited){
    visited[node] = true;
    
    for(int i = 0; i < adj[node].size(); i++){
        if(!visited[adj[node][i]]){
            bool ans = checkCycleDFS(adj[node][i], node, adj, visited);
            if(ans)
                return true;
        }
        else if(adj[node][i] != parent){
            return true;
        }
    }
    return false;
}

bool cycleDetection(int n, int m, vector<int> adj[])
{

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // bool ans = checkCycleBFS(i, visited, adj);
            bool ans = checkCycleDFS(i, -1, adj, visited);
            if (ans)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int v = 4;
    int e = 2;
    vector<int>adj[] = {{}, {2}, {1, 3}, {2}};
    cout<<cycleDetection(v,e,adj);
}