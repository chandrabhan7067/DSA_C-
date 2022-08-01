#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void bfs(vector<int> adj[], unordered_map<int, bool> visited, vector<int> &ans, int Node)
{
    queue<int> q;
    q.push(Node);
    visited[Node] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for (int i = 0; i < adj[frontNode].size(); i++)
        {

            if (!visited[adj[frontNode][i]])
            {
                q.push(adj[frontNode][i]);
                visited[adj[frontNode][i]] = true;
            }
        }
    }
}

int main()
{
    vector<int>ans;
    vector<int>adj[] = {{0,1,2,3},{1},{2,4},{3}};
    unordered_map<int,bool>visited;

    bfs(adj,visited,ans,0);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    

}