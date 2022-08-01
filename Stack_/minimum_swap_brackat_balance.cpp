#include <iostream>
using namespace std;

int minimumNumberOfSwaps(string s)
{
    int open = 0, cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
        {
            open++;
        }
        else
        {
            open--;
            if (open < 0)
            {
                cnt = cnt - open;
            }
        }
    }
    return cnt;
}

int main()
{
    string s = "[]][][";
    cout << minimumNumberOfSwaps(s);
}