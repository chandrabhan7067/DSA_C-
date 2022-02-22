#include <iostream>
using namespace std;

void print(string st)
{
    for (int i = 0; i != st.size(); i++)
    {
        cout << st[i] << " ";
    }
    cout << endl;
}

string convert(string n)
{
    for (int i = 0; i != n.size(); i++)
    {
        if (n[i] == '0')
        {
            n[i] = '5';
        }
    }
    return n;
}

int main()
{
    int n = 1005;
    string st = to_string(n);
    // cout<<st.size();
    st = convert(st);
    print(st);
}