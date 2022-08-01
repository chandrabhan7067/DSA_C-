#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string reverseEachWord(string s){

    string ans = "";
    stack<char>st;


    for (int i = 0; i < s.size(); i++)
    {
        
        if(s[i] != '.'){
            st.push(s[i]);
        }
        else{
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
            ans+='.';
        }

    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;


}

int main()
{
    string s = "pqr.mno";
    cout<<reverseEachWord(s);
}