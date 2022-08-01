#include<iostream>
#include<limits.h>
#include<unordered_map>
#include<vector>
#include<list>
#include<stack>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<pair<int,int>>>adj;

        void addEge(int u, int v, int weight){
            pair<int,int>p = make_pair(v,weight);
            adj[u].push_back(p);
        }

        void printADJ(){
            for(auto i:adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<"("<<j.first<<","<<j.second<<")";
                }
                cout<<endl;
            }
        }

        void topologicalSort(int node, stack<int>&st,unordered_map<int,bool>&visited){
            visited[node] = true;

            for(auto i:adj[node]){
                if(!visited[i.first]){
                    topologicalSort(i.first, st, visited);
                }
            }
        st.push(node);
        }


    void getShortestPath(int src, stack<int>&st, vector<int>&dis){
        dis[src] = 0;

        while(!st.empty()){
            int top = st.top();
            st.pop();

            if(dis[top] != INT_MAX){
                for(auto i:adj[top]){
                    if(dis[top] + i.second < dis[i.first]){
                        dis[i.first] = dis[top] + i.second;
                    }
                }
            }
        }
    }

};

int main()
{
    Graph g;

    g.addEge(0,1,3);
    g.addEge(0,2,3);
    g.addEge(1,2,2);
    g.addEge(1,3,6);
    g.addEge(2,3,7);
    g.addEge(2,4,4);
    g.addEge(2,5,2);
    g.addEge(3,4,-1);
    g.addEge(4,5,-2);

    g.printADJ();

    int n = 6;

    unordered_map<int,bool>visited;
    stack<int>st;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            g.topologicalSort(i, st, visited);
        }
    }

    int src = 1;
    vector<int>dist(n);

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    
    g.getShortestPath(src, st, dist);

    for(auto i:dist){
        cout<<i<<" ";
    }
}