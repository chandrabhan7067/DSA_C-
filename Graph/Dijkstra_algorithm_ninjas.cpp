#include<istream>
#include<list>
#include<limits.h>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>>adj;

    for(int i = 0; i < edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int weight = vec[i][2];

        adj[u].push_back(make_pair(v,weight));
        adj[v].push_back(make_pair(u,weight));
    }

    vector<int>dist(vertices);

    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int,int>>st;

    st.insert(0,source);

    dist[source] = 0;

    while(!st.empty()){
            auto top = *(st.begin());
            
            int distance = top.first;
            int topNode = top.second;
            
            // erase top record
            st.erase(st.begin());
            
            for(auto i:adj[topNode]){
                if(distance + i.second < dist[i.first]){
                    
                    auto record = st.find(make_pair(dist[i.first],i.first));
                    
                    // record is find then erase it
                    if(record != st.end()){
                        st.erase(record);
                    }
                    
                    // update distance
                    dist[i.first] = distance + i.second;
                    
                    // insert it into set
                    st.insert(make_pair(dist[i.first], i.first));
                }
            }
        }
    return dist;
}