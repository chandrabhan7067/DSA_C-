#include <iostream>
#include <unordered_map>
#include <vector>
#include<queue>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, vector<int> adj[], unordered_map<int, bool> &dfsvisited)
{

    visited[node] = true;
    dfsvisited[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {

        if (!visited[adj[node][i]])
        {
            bool ans = checkCycleDFS(adj[node][i], visited, adj, dfsvisited);
            if (ans)
                return true;
        }
        else if (dfsvisited[adj[node][i]])
        {
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

bool DetectCycleDFS(int V, vector<int> adj[])
{
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool ans = checkCycleDFS(i, visited, adj, dfsvisited);
            if (ans)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCyclicBFS(int V, vector<int> adj[]) {
// detect cycle using BFS
// kahn's algorithm

    vector<int>indegree(V);
    int cnt = 0;
    
    for(int i = 0; i < V; i++){
        for(int j = 0; j < adj[i].size(); j++){
            indegree[adj[i][j]]++;
        }
    }
    
    queue<int>q;
    
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        cnt++;
        
        for(int i = 0; i < adj[front].size(); i++){
            indegree[adj[front][i]]--;
            
            if(indegree[adj[front][i]] == 0){
                q.push(adj[front][i]);
            }
            
        }
        
    }
// if we successfully find out tological sort of given graph then it's confirm graph is not contain cycle

    if(cnt == V){
        return false;
    }
    return true;
}

int main()
{
    int v = 3;
    vector<int>adj[] = {{0,1},{1,2}};
    // vector<int>adj[] = {{0,1},{1,2},{2,3},{3,3}};
    cout<<DetectCycleDFS(v,adj);
}