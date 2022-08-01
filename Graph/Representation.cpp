#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

// Print adjacency list         GFG
// Creating and Printing        Coding ninjas

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    // direction = 0 -> undirected graph
    // direction = 1 -> directed graph

    void addEdge(int u, int v, bool direction)
    {

        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";

            for (auto j : i.second)
            {
                cout << j << " ";
            }

            cout << endl;
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