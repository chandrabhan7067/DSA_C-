#include<iostream>
#include<limits.h>
using namespace std;

int LCS(string str1, string str2, int n, int m){
    int LCS_matrix[n+1][m+1];
    int ans = INT_MIN;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0){
                LCS_matrix[i][j] = 0;
            }
            else if(str1[i-1] == str2[j-1]){
                    LCS_matrix[i][j] = LCS_matrix[i-1][j-1] + 1;
                    ans = max(ans,LCS_matrix[i][j]);
            }
            else{
                LCS_matrix[i][j] = 0;
            }
        }
        
    }
    if(ans == INT_MIN){
        return 0;
    }
    return ans;
}

int main()
{
    string s1 = "ABC";
    string s2 = "ACB";
    int n = s1.size();
    int m = s2.size();
    cout<<LCS(s1,s2,n,m);
}