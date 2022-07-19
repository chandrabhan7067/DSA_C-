#include <iostream>
#include <limits.h>
#include <unordered_map>
using namespace std;

string secondRepeatingstr(string s[], int n)
{
    unordered_map<string, int> m;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
        maxi = max(m[s[i]], maxi);
    }

    int second_max = INT_MIN;
    
    for (auto i : m)
    {
        if (i.second != maxi)
        {
            second_max = max(second_max, i.second);
        }
    }

    if (second_max == INT_MIN)
    {
        return "";
    }

    for (auto i : m)
    {
        if (i.second == second_max)
        {
            return i.first;
        }
    }
}

int main()
{
    string s[] = {"aaa", "bbb", "ccc", "bbb", "aaa", "aaa"};
    int n = sizeof(s)/sizeof(s[0]);

    cout<<secondRepeatingstr(s,n);
}