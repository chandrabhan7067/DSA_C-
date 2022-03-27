#include <iostream>
#include <stack>
using namespace std;

// time complexity  O(n)
// space complexity  O(n)


bool redundant_bra(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }

        else
        {
            if (ch == ')')
            {
                bool redundant = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        redundant = false;
                    }
                    st.pop();
                }

                if (redundant == true)
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string s = "((a+b))";
    cout << endl;
    if (redundant_bra(s))
    {
        cout << "redundant brackedt is present";
    }
    else
    {
        cout << "redundant brackedt is not present";
    }
    cout << endl
         << endl;
    ;
}