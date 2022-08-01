#include<iostream>
#include<stack>
using namespace std;

int countReversal(string s){

    if(s.size()%2 != 0)
        return -1;

    stack<char>st;
    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        if(ch == '{'){
            st.push(ch);
        }

        else{
            if(st.empty()){
                st.push('{');
                cnt++;
            }
            else{
                st.pop();
            }

        }
    }
// if overlaping is allowed
    return cnt + st.size()/2;
}

int main()
{
    string s = "{{}{{}";
    cout<<countReversal(s);
}