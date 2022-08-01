#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string ReverseWord(string s)
{

    string temp = "";
    string ans = "";
    vector<string> v;

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] != '.')
        {
            temp += s[i];
        }
        else
        {
            v.push_back(temp);
            temp = "";
        }
    }

    if (!temp.empty())
        v.push_back(temp);

    for (int i = v.size() - 1; i >= 0; i--)
    {
        ans += v[i];

        if (i != 0)
        {
            ans.push_back('.');
        }
    }
    return ans;
}

int main()
{
    string s = "i.like.this.program.very.much";
    cout << ReverseWord(s);
}