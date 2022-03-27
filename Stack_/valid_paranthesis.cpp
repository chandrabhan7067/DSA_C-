#include <iostream>
#include <stack>
using namespace std;

// time complexity O(n)
// space complexity O(n`-)

bool solve(string st)
{
// creating a stack 
    stack<char> s;
    
    for (int i = 0; i < st.length(); i++)
    {

        char ch = st[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
        return true;
    else
        return false;
}

int main()
{
    string st = "[({})]";
    if(solve(st)){
        cout<<"paranthes is is matched"<<endl;
    }
    else{
        cout<<"paranthes is is not matched"<<endl;
    }
}