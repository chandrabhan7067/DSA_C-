#include <iostream>
using namespace std;

int longestRepeatingSubsequence(string s1)
{

    string s2 = s1;
    int n = s1.size();

    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            else if (s1[i - 1] == s2[j - 1] && i != j)
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

int main()
{
    string str = "axxxy";
    cout<<longestRepeatingSubsequence(str);
}
