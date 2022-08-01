#include <iostream>
using namespace std;

// time O(n)
// space O(1)

// Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring

int longestValidSubstring(string s)
{
    int open = 0, close = 0;
    int ans = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(')
        {
            open++;
        }
        else
        {
            close++;
        }

        if (close == open)
        {
            int len = open + close;
            ans = max(len, ans);
        }
        else if (close > open)
        {
            close = open = 0;
        }
    }

    open = close = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        char ch = s[i];

        if (ch == '(')
        {
            open++;
        }
        else
        {
            close++;
        }

        if (close == open)
        {
            int len = open + close;
            ans = max(len, ans);
        }
        else if (open > close)
        {
            close = open = 0;
        }
    }
    return ans;
}

int main()
{
    string s = "()(())(";
    cout << longestValidSubstring(s);
}