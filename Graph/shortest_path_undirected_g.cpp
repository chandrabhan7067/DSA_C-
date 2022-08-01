#include<iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;

vector<int>ShortestPath(int ser, int des,vector<pair<int,int>> edges){
    unordered_map<int,list<int>>adj;

    for(auto i:edges){
        int u = i.first;
        int v = i.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,int>parent;
    unordered_map<int,bool>visited;
    queue<int>q;
        
    q.push(ser);
    visited[ser] = true;
    parent[ser] = -1;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i:adj[front]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }

    vector<int>ans;
    ans.push_back(des);
    int curr = des;

    while(curr != ser){
        curr = parent[curr];
        ans.push_back(curr);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<pair<int,int>>edges{{1,4},{1,2},{2,3},{3,4},{1,3}};
    int s = 1;
    int des = 4;

    vector<int>ans = ShortestPath(s,des,edges);

    for(auto i:ans){
        cout<<i<<" ";
    }
}