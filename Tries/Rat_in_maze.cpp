#include<iostream>
#include<vector>
using namespace std;

// time  O(4^n^2)
// space  O(n*m)

bool isSafe(int x, int y, vector<vector<int>>&arr, vector<vector<bool>>&vis, int n){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && (vis[x][y] != 1) && (arr[x][y] == 1)){
        return true;
    }
    else{
        return false;
    }
}

void solve(int x, int y, vector<vector<int>>&arr, vector<vector<bool>>&vis, int n,vector<string>&ans, string path){
    if((x == n - 1) && (y == n - 1)){
        ans.push_back(path);
        return;
    }

    vis[x][y] = 1;

    if(isSafe(x + 1, y, arr,vis,n)){
        solve(x + 1, y, arr,vis,n,ans,path + 'D');
    }
    

    if(isSafe(x, y - 1, arr,vis,n)){
        solve(x, y - 1, arr,vis,n,ans,path + 'L');
    }

    if(isSafe(x, y + 1, arr,vis,n)){
        solve(x, y + 1, arr,vis,n,ans,path + 'R');
    }

    if(isSafe(x - 1, y, arr,vis,n)){
        solve(x - 1, y, arr,vis,n,ans,path + 'U');

    }
    vis[x][y] = 0;
}  

vector<string>Rate_maze(vector<vector<int>>&arr, int n){
    vector<string>ans;
    string path = "";
    vector<vector<bool>>visited(n,vector<bool>(n,0));

    if(arr[0][0] == 0){
        return ans;
    }

    solve(0,0,arr,visited,n,ans,path);
    return ans;
}

int main()
{
    vector<vector<int>>arr{{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}};
    int n = arr.size();
    cout<<n<<endl;

    vector<string>ans = Rate_maze(arr,n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}