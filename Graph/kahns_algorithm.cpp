#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int>ans;
    vector<int>indegree(V);

    for (int i = 0; i < V; i++)
    {
        for(int j = 0; j < adj[i].size(); j++){
            indegree[adj[i][j]]++;
        }
    }
    
    queue<int>q;

    for (int i = 0; i < V; i++)
    {
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (int i = 0; i < adj[front].size(); i++)
        {
            indegree[adj[front][i]]--;

            if(indegree[adj[front][i]] == 0){
                q.push(adj[front][i]);
            }
        }
        

    }

    return ans;
}

int main()
{
    int v = 4;
    // vector<int>adj[] = {{},{1,3},{2,3},{},{4,0,1},{5,2,0}};
    vector<int>adj[] = {{},{1,0},{2,0},{3,0}};

    vector<int>ans = topoSort(v,adj);

    for(auto i:ans){
        cout<<i<<" ";
    }
}