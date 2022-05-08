#include <iostream>
#include <queue>
using namespace std;

string solve(string st)
{
    int arr[26] = {0};
    queue<char> q;
    string ans;

    for (int i = 0; i < st.size(); i++)
    {
        char ch = st[i];
        arr[ch - 'a']++;
        q.push(ch);

        while (!q.empty())
        {
            if (arr[q.front() - 'a'] > 1)
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
    string ans = solve(st);
    cout << ans;
}