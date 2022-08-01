#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int solve(string A, string B, string C, int n, int m, int len)
{
    if (len == 0)
    {
        return 1;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    int a = 0, b = 0;

    if (n - 1 >= 0 && A[n - 1] == C[len - 1])
    {
        a = solve(A, B, C, n - 1, m, len - 1);
    }

    if (m - 1 >= 0 && B[m - 1] == C[len - 1])
    {
        b = solve(A, B, C, n, m - 1, len - 1);
    }

    return dp[n][m] = (a || b);
}

bool isInterleave(string A, string B, string C)
{
    int n = A.size(), m = B.size(), len = C.size();

    if (n + m != len)
    {
        return 0;
    }

    dp[n][m];

    memset(dp, -1, sizeof(dp));

    return solve(A, B, C, n, m, len);
}

int main()
{
    string a = "YX", b = "X", c = "XXY";

    cout<<isInterleave(a,b,c);
}