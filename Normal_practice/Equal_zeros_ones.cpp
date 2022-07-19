#include <iostream>
using namespace std;

int EqualZeroOnes(string s)
{
    int zeros = 0;
    int ones = 0;
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            zeros++;
        else
            ones++;
        if (zeros == ones)
            ans++;
    }

    if (zeros != ones)
    {
        return -1;
    }
    return ans;
}

int main()
{
    string s = "0111100010";
    cout<<EqualZeroOnes(s);
}