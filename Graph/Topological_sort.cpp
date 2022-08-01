#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

void topologicalSort(int node, unordered_map<int, bool> &visited, vector<int> adj[], stack<int> &st)
{

    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
        {
            topologicalSort(adj[node][i], visited, adj, st);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> ans;
    unordered_map<int, bool> visited;
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topologicalSort(i, visited, adj, st);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    int v = 6;
    vector<int> adj[] = {{}, {1, 3}, {2, 3}, {}, {4, 0, 1}, {5, 2, 0}};

    vector<int> ans = topoSort(v, adj);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}