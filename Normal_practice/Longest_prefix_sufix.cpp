#include <iostream>
using namespace std;

int longestPrefixSufix(string s)
{
    int i = 1, j = 0, n = s.size();
    int *lps = new int[n];
    lps[j] = 0;

    while (i < n)
    {

        if (s[i] == s[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }

        else
        {

            if (j == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
// when overlapping is allowed
    return lps[n - 1];
}

int main()
{
    string s = "aaaa";
    cout << longestPrefixSufix(s);
}