#include <iostream>
#include<limits.h>
#include<set>
#include <vector>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int>dist(V);

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int,int>>st;

    st.insert(make_pair(0,S));

    dist[S] = 0;

    while(!st.empty()){
        auto top = *(st.begin());
        st.erase(st.begin());

        int node = top.second;
        int distance = top.first;

        auto children = adj[node];

        for(int i = 0; i < children.size(); i++){

            if(distance + children[i][1] < dist[children[i][0]]){

                auto record = st.find(make_pair(dist[children[i][0]], children[i][0]));

                if(record != st.end()){
                    st.erase(record);
                }

                dist[children[i][0]] = distance + children[i][1];
                st.insert(make_pair(dist[children[i][0]], children[i][0]));
            }

        }
    }
    return dist;
}

int main()
{
    vector<vector<int>>adj[] = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}};
    int v = 3;
    int s = 2;

    vector<int>ans = dijkstra(v, adj, s);

    for(auto i:ans){
        cout<<i<<" ";
    }
}