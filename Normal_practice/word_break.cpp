#include<iostream>
#include<unordered_map>
#include<vector>
#include<string.h>
using namespace std;

int solve(string s, vector<string> &B){
    unordered_map<string,int>dp;
    int sz = s.size();

    if(sz == 0){
        return 1;
    }

    if(dp[s] != 0){
        return dp[s];
    }

    for(int i = 1; i <= sz; i++){
        string ss = s.substr(0,i);
        int f = 0;
        for(int j = 0; j < B.size(); j++){
            if(ss.compare(B[j]) == 0){
                f == 1;
                dp[ss] = 1;
                break;
            }
        }
        if(f == 1 && solve(s.substr(i,sz),B) == 1){
            return 1;
        }
    }
    return 0;

}

int Word_break(string s, vector<string>&b){
    int ans = solve(s,b);
    if(ans == 1){
        return 1;
    }
    return 0;
}

int main()
{
    vector<string>B{ "i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream",
"man", "go", "mango"};
string A = "ilike";
cout<<Word_break(A,B);

}