#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void setValue(vector<int> &parent, vector<int> &rank, int n)
{

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }

    // path compression
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }

    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }

    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    setValue(parent,rank,n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int w = edges[i][2];

        if (u != v)
        {
            ans += w;
            unionSet(u, v, parent, rank);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>>edges{{0,1,3},{0,3,5},{1,2,1},{2,3,8}};
    int n = 4;

    cout<<minimumSpanningTree(edges,n);
}