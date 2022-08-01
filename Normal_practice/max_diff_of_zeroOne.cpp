#include <iostream>
#include <limits.h>
using namespace std;

// Given a binary string S consisting of 0s and 1s. The task is to find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in the substrings of a string.

int maxSubstring(string s)
{
    int sum = 0;
    int ans = INT_MIN;
    for (int i = 0; i < s.size(); i++)
    {
        int x;

        if (s[i] == '0')
        {
            x = 1;
        }
        else
        {
            x = -1;
        }

        sum += x;
        ans = max(sum, ans);

        if (sum < 0)
        {
            sum = 0;
        }
    }
    return ans;
}

int main()
{
    string str = "11000010001";
    cout<<maxSubstring(str);
}