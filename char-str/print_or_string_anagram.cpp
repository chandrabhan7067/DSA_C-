#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

// time O(m*nlong(n))  where n is the length of vector and m is the length of particular string

vector<vector<string>> AnagramString(vector<string> &s)
{
    map<string, vector<string>> m;

    for (int i = 0; i < s.size(); i++)
    {
        string temp = s[i];
        sort(temp.begin(), temp.end());
        m[temp].push_back(s[i]);
    }

    vector<vector<string>> ans;

    for (auto i : m)
    {
        int n = i.second.size();
        vector<string> temp;

        for (int j = 0; j < n; j++)
        {
            temp.push_back(i.second[j]);
        }
        ans.push_back(temp);
    }
    return ans;
}

// input
//  {act,god,cat,dog,tac}

// output
// act cat tac
// god dog

int main()
{
    vector<string> s{"no", "on", "is"};
    vector<vector<string>> ans = AnagramString(s);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}