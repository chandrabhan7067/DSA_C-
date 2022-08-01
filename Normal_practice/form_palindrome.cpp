#include <iostream>
using namespace std;

// Given a string, find the minimum number of characters to be inserted to convert it to palindrome.

string Reverse(string st)
{
    int s = 0;
    int e = st.length() - 1;

    while (s < e)
    {
        swap(st[s], st[e]);
        s++;
        e--;
    }
    return st;
}

int longest_common_sub(string s1, int n)
{
    string s2 = Reverse(s1);
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            else if (s2[i - 1] == s1[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int formPalindrome(string s){
    return s.length() - longest_common_sub(s,s.length());
}

int main()
{
    string s = "chabnhc";
    cout<<formPalindrome(s);
}