#include <iostream>
#include <unordered_map>
using namespace std;

int romanToDecimal(string &str)
{
    unordered_map<char, int> m;
    int n = str.size();

    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 && m[str[i]] < m[str[i + 1]])
        {
            sum -= m[str[i]];
        }
        else
        {
            sum += m[str[i]];
        }
    }
    return sum;
}

int main()
{
    string s = "VI";
    cout<<romanToDecimal(s);
}