#include <iostream>
#include <unordered_map>
#include <list>
#include<vector>
using namespace std;

// Print adjacency list         GFG
// Creating and Printing        Coding ninjas

class Graph
{
public:
    vector<vector<int>>adj;
    // direction = 0 -> undirected graph
    // direction = 1 -> directed graph

    void addEdge(int u, int v, bool direction)
    {

        adj[u][v] = 1;

        if (direction == 0)
        {
           adj[v][u] = 1;
        }
    }

    void print()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[0].size(); j++)
            {
                cout<<adj[i][j]<<" ";
            }
            
        }
        
    }
};

int main()
{
    int n, m;
    cout << "Enter number of nodes";
    cin >> n;

    cout << "Enter number of edges";
    cin >> m;

    Graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1);
    }

    g.print();
}