#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>
using namespace std;

unordered_map<string,int>m;

int minInvalidPara(string s){
    stack<char>st;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        if(ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    return st.size();
}


void solve(string s, int minInVal, vector<string>&ans){
    if(m[s] != 0){
        return;
    }
    else{
        m[s]++;
    }

    if(minInVal == 0){
        if(minInvalidPara(s) == 0){
            ans.push_back(s);
        }
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        string left = s.substr(0,i);
        string right = s.substr(i+1);
        solve(left+right, minInVal-1, ans);
    }
    
}

vector<string> removeInvalidParentheses(string s) {
        int minIn = minInvalidPara(s);
        vector<string>ans;
        solve(s,minIn,ans);
        return ans;
    }

int main()
{
    string s = "(a)())()";
    vector<string>ans = removeInvalidParentheses(s);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}