#include <iostream>
#include <unordered_map>
using namespace std;

string removeDuplicate(string s, int n)
{
    unordered_map<char, int> map;
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (map[s[i]] == 0)
        {
            ans.push_back(s[i]);
        }
        map[s[i]]++;
    }
    return ans;
}

int main()
{
    string s = "geeksforgeeks";
    int n = s.size();
    cout << removeDuplicate(s, n);
}