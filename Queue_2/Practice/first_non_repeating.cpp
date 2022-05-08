#include <iostream>
#include <queue>
#include <map>
using namespace std;

string Non_repeating(string &st)
{
    string ans = "";
    map<char, int> count;
    queue<char> q;

    for (int i = 0; i < st.size(); i++)
    {
        char ch = st[i];
        count[ch]++;
        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    string st = "aabc";
    string ans = Non_repeating(st);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}