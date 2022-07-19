#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

// Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
// For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

int smallestDistinctWindow(string str)
{
    set<char> st;

    for (int i = 0; i < str.size(); i++)
    {
        st.insert(str[i]);
    }

    int n = str.size();
    int ans = st.size();
    int i = 0;
    int j = 0;
    unordered_map<char, int> m;

    while (i < str.size())
    {
        m[str[i]]++;

        if (m.size() == n)
        {
            while (m[str[j]] > 1)
            {
                m[str[j]]--;
                j++;
            }
            ans = min(ans, i - j + 1);
        }
        i++;
    }
    return ans;
}

int main()
{
    string s = "AABBBCBBAC";
    cout<<smallestDistinctWindow(s);
}