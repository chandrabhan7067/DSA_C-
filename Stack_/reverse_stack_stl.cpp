#include<iostream>
#include<stack>
using namespace std;

// time complexity is  O(n)
// space  complexity is  O(n)

int main()
{
    string st = "chan";
    stack<char>c;

    for (int i = 0; i < st.length(); i++)
    {
        char ch = st[i];
        c.push(ch);
    }
    
    string ans = "";

    while(!c.empty()){
        char last = c.top();
        ans.push_back(last);
        c.pop();
    }
    cout<<ans;
}