#include<iostream>
using namespace std;

int findParent(int parent[], int node){

    if(parent[node] == node){
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}

void union_(int u, int v, int parent[], int rank[]){

    u = findParent(parent,u);
    v = findParent(parent,v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }

    else if(rank[v] < rank[u]){
        parent[v] = u;
    }

    else{
        parent[v] = u;
        rank[u]++;
    }
}

bool isConnected(int x,int y, int par[], int rank1[]){

    x = findParent(par, x);
    y = findParent(par, y);

    if(x == y){
        return true;
    }
    return false;
}

int main()
{
    int parent[] = {0,1,2,3,4,5};
    int rank[] = {1,1,1,1,1,1};

    cout<<isConnected(1,2,parent,rank);
}