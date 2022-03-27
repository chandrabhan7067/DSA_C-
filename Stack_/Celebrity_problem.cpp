#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// time complexity is O(n)
// space complexity is  O(n)

bool knows(vector<vector<int>>&v, int a, int b,int n){
    if (v[a][b] == 1)
    {
        return true;
    }
    else{
        return false;
    }
}

int solve(vector<vector<int>>&v,int n){
    stack<int>st;
    
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while(st.size() > 1){
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if(knows(v,a,b,n)){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }
    
    int condidate = st.top();

    bool rowCheck = false;
    int zerocnt = 0;

    for (int i = 0; i < n; i++)
    {
        if(v[condidate][i] == 0){
            zerocnt++;
        }
    }
    if(zerocnt == n){
        rowCheck = true;
    }

    bool colCheck = false;
    int onecnt = 0;

    for (int i = 0; i < n; i++)
    {
        if(v[i][condidate] == 1){
            onecnt++;
        }
    }
    if(onecnt == n-1){
        colCheck = true;
    }

    if(rowCheck == true && colCheck == true){
        return condidate;
    }

    else{
        return -1;
    }
}

int main()
{
    vector<vector<int>>v{{0,1,0},
              {0,1,0},
              {0,1,0}};
    
    cout<<solve(v,3);
}