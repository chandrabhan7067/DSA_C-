#include <iostream>
#include<queue>
#include <vector>
using namespace std;

// he initial and the target position coordinates of Knight have been given according to 1-base indexing.

bool isSafe(int x, int y, vector<vector<int>>&vis, int n){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && (vis[x][y] == 0)){
        return true;
    }
    return false;
}

int minStepToReachTarget(vector<int> &K, vector<int> &T, int n)
{
    if(K[0] == T[0] && K[1] == T[1]){
        return 0;
    }

    vector<vector<int>>vis(n,vector<int>(n,0));
    queue<pair<int,int>>q;
    
    int x = K[0]-1, y = K[1]-1;

    q.push({x,y});

    while(!q.empty()){

        auto front = q.front();
        q.pop();

        x = front.first;
        y = front.second;

// eight ways to move knight

        if(x == T[0]-1 && y == T[1]-1){
            return vis[x][y];
        }

        if(isSafe(x-2, y-1, vis, n)){
            vis[x-2][y-1] = vis[x][y] + 1;
            q.push({x-2, y-1});
        }

        if(isSafe(x-2, y+1, vis, n)){
            vis[x-2][y+1] = vis[x][y] + 1;
            q.push({x-2, y+1});
        }

        if(isSafe(x+1, y+2, vis, n)){
            vis[x+1][y+2] = vis[x][y] + 1;
            q.push({x+1, y+2});
        }

        if(isSafe(x-1, y+2, vis, n)){
            vis[x-1][y+2] = vis[x][y] + 1;
            q.push({x-1, y+2});
        }

        if(isSafe(x+2, y-1, vis, n)){
            vis[x+2][y-1] = vis[x][y] + 1;
            q.push({x+2, y-1});
        }

        if(isSafe(x+2, y+1, vis, n)){
            vis[x+2][y+1] = vis[x][y] + 1;
            q.push({x+2, y+1});
        }

        if(isSafe(x-1, y-2, vis, n)){
            vis[x-1][y-2] = vis[x][y] + 1;
            q.push({x-1, y-2});
        }

        if(isSafe(x+1, y-2, vis, n)){
            vis[x+1][y-2] = vis[x][y] + 1;
            q.push({x+1, y-2});
        }
    }
    return -1;
}

int main()
{
    vector<int>k{4, 5};
    vector<int>t{1, 1};
    int n = 6;

    cout<<minStepToReachTarget(k,t,n);
}