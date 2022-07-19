#include <iostream>
using namespace std;

string reverse(string s)
{
    int st = 0;
    int e = s.size() - 1;

    while (st < e)
    {
        swap(s[st], s[e]);
        st++;
        e--;
    }
    return s;
}

int longestPalinSubseq(string A)
{
    string B = reverse(A);
    // cout<<B;
    // cout<<A<<endl;
    int n = A.size();

    int dp[n + 1][n + 1];

    for (int i = 0; i <= B.size(); i++)
    {
        for (int j = 0; j <= A.size(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            else if (B[i - 1] == A[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main()
{
    string s = "abcd";
    cout<<longestPalinSubseq(s);
}