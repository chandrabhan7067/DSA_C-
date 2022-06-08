#include <iostream>
#include <stack>
using namespace std;

bool isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return true;
    }
    return false;
}

int precedence(char ch)
{
    if (ch == '/' || ch == '*')
    {
        return 3;
    }

    else if (ch == '+' || ch == '-')
    {
        return 2;
    }

    else
    {
        return 0;
    }
}

void infix_to_postfix(string infix)
{
    stack<int> st;
    string postfix = "";
    int i = 0;

    while (i != infix.length())
    {
        if (!isoperator(infix[i]))
        {
            postfix.push_back(infix[i]);
            i++;
        }

        else
        {
            if (st.empty() || (precedence(infix[i])) > precedence(st.top()))
            {
                st.push(infix[i]);
                i++;
            }

            else
            {
                postfix.push_back(st.top());
                st.pop();
            }
        }
    }

    while (!st.empty())
    {
        postfix.push_back(st.top());
        st.pop();
    }

    cout << postfix;
}

int main()
{
    string ch = "a+b-c*d/e";
    infix_to_postfix(ch);
}