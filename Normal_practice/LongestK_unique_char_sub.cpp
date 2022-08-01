#include <iostream>
#include <unordered_map>
using namespace std;

// Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

int longest_k_UniqueSubstring(string s, int k)
{

    unordered_map<char, int> m;
    int i = 0, j = 0;
    int ans = -1;

    while(i < s.size()){

        m[s[i]]++;

        while (m.size() > k)
        {
            m[s[j]]--;

            if (m[s[j]] == 0)
            {
                m.erase(s[j]);
            }

            j++;
        }

        if (m.size() == k)
        {

            ans = max(ans, i - j + 1);
        }

        i++;

    }
    return ans;
}

int main()
{
    string s = "aaaa";
    int k = 2;

    cout<<longest_k_UniqueSubstring(s,k);
}