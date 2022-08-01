#include <iostream>
using namespace std;

// Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.

string shortestCommonSupersequence(string X, string Y, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            else if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

// when we have to return only length of string 
    // return (m + n - dp[m][n]);


// when we have to return string 

    int i = m, j = n;
    string ans = "";

    while(i > 0 && j > 0){
        if(X[i-1] == Y[j-1]){
            ans += X[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                ans += X[i-1];
                i--;
            }
            else{
                ans += Y[j-1];
                j--;
            }
        }
    }


    while(i > 0){
        ans += X[i-1];
        i--;
    }

    while(j > 0){
        ans += Y[j-1];
        j--;
    }

    return ans;
}

int main()
{
   string X = "abac", Y = "cab";
   int m = X.size(), n = Y.size();

   cout<<shortestCommonSupersequence(X,Y,m,n);
}