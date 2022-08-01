#include <iostream>
#include <unordered_map>
using namespace std;

// pure character nhi bhi ho to chlega bs find longest with distring character
// acdcb
// 3

int longestSubstrDistinctChars(string s)
{
    int i = 0, j = 0, ans = 0;
    unordered_map<char, int> m;

    while (j < s.size())
    {
        m[s[j]]++;

        while (m[s[j]] > 1)
        {
            m[s[i]]--;
            i++;
        }

        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}

int main()
{
    string s = "acdcb";
    cout<<longestSubstrDistinctChars(s);
}